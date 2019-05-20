#include "Setnumber.hpp"
#include <iostream>

using namespace genv;
using namespace std;

Setnumber::Setnumber(int x, int y, int sx, int sy, int ertek,int maximum, int minimum) : Widgets(x,y,sx,sy)
{
value = ertek;
_focused = false;
meret_x =x+sx;
magassag =sy;
hossz=sx;
meret_y = y+sy;
_max = maximum;
_min = minimum;
get_num = to_string(value);

}


void Setnumber::draw()
{
        gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(50,50,50) << box(_size_x-4, _size_y-4);
        gout << color(255,255,255)<<move_to(_x+hossz/2-30,_y+magassag/2+5)<< text(to_string(value));

        gout << move_to(_x+hossz-25,_y+2)<<color(255,255,255)<<box(23,magassag/2-2);
        gout << move_to(_x+hossz-23,_y+4)<<color(100,100,100)<<box(23-4,magassag/2-6)<<move_to(_x+hossz-35/2,_y+magassag/2-9/2)<<color(255,255,255)<<text("+");

        gout << move_to(_x+hossz-25,_y+magassag/2)<<color(255,255,255)<<box(23,magassag/2-2);
        gout << move_to(_x+hossz-23,_y+magassag/2+2)<<color(100,100,100)<<box(19,magassag/2-6)<<move_to(_x+hossz-35/2,_y+magassag/2+13)<<color(255,255,255)<<text("-");

        if (bennevan_up){
            gout << move_to(_x+hossz-25,_y+2)<<color(255,255,255)<<box(23,magassag/2-2);
            gout << move_to(_x+hossz-23,_y+4)<<color(50,50,0)<<box(23-4,magassag/2-6)<<move_to(_x+hossz-35/2,_y+magassag/2-9/2)<<color(255,255,255)<<text("+");
        }

        if (bennevan_down){
            gout << move_to(_x+hossz-25,_y+magassag/2)<<color(255,255,255)<<box(23,magassag/2-2);
            gout << move_to(_x+hossz-23,_y+magassag/2+2)<<color(50,50,0)<<box(19,magassag/2-6)<<move_to(_x+hossz-35/2,_y+magassag/2+13)<<color(255,255,255)<<text("-");

        }

}





void Setnumber::handle(event ev)
{
    if(ev.button == btn_left && ev.type == ev_mouse)
    {
        if (is_selected(ev.pos_x, ev.pos_y))
        {
            _focused = true;
        }

        else
        {
            _focused = false;
        }

    }



    if(ev.pos_x > meret_x-25 && ev.pos_x < meret_x && ev.pos_y > meret_y-magassag && ev.pos_y < meret_y-magassag + 20 &&  ev.button == btn_left){
        bennevan_up = true;
                cout<<"fel"<<endl;                            ///debug
    }
    else if(bennevan_up){
        bennevan_up = false;
    }



    if(ev.pos_x > meret_x-25 && ev.pos_x < meret_x && ev.pos_y > meret_y-magassag+20 && ev.pos_y < meret_y-magassag + 40 &&  ev.button == btn_left){
        bennevan_down = true;
        cout<<"le"<<endl;                            ///debug
    }
    else if(bennevan_down){
        bennevan_down = false;
    }



    if(ev.pos_x > meret_x-hossz && ev.pos_x < meret_x && ev.pos_y > meret_y-magassag && ev.pos_y < meret_y  &&  ev.button == btn_left){
        bennevan = true;
        cout<<"benne"<<endl;                            ///debug
    }else if(bennevan){
        bennevan = false;
    }


    if (ev.keycode == key_down || bennevan_down){
            cout<<"valami"<<endl;                            ///debug
        value = value-1;
    }

    if (ev.keycode == key_up || bennevan_up){
        value = value+1;
    }


    if (ev.keycode == key_pgup){
        value = value+10;
    }

    if (ev.keycode == key_pgdn){
        value = value-10;
    }

    if(value>_max){
        value=_max;
    }

    if(value<_min){
        value=_min;
    }

}

string Setnumber :: ertek(){
return get_num;
}

void Setnumber::s_num(int ertek) {
    value = ertek;
}

bool Setnumber::is_focused(){
    return _focused;
}



