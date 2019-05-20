#include "Menu.hpp"
#include <iostream>

using namespace genv;
using namespace std;


Menu::Menu(int x, int y, int sx, int sy, vector<string> elemek, int hossz) : Widgets(x,y,sx,sy)
{
menu=elemek;
_focused = false;
length = hossz;
meret_x = x + sx;
magassag = sy;
meret_y = y + sy;
}


void Menu::draw()
{

        gout << move_to(_x, _y) << color(150,150,255) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
        gout << color(255,255,255)<<move_to(_x+5,_y+20)<< text(str);
        gout << color(150,150,255) << move_to(meret_x-30,meret_y-magassag)<<box(magassag,magassag);
        gout << color(0,0,0) << move_to(meret_x+2-30,meret_y+2-magassag)<<box(magassag-4,magassag-4)<<move_to(meret_x+10-30,meret_y-magassag+18)<<color(255,255,255)<<text("V");


    if(bennevan){
        for(int i = 0; i<length; i++){
            gout << move_to(_x, magassag*i+meret_y) << color(150,150,255) << box(_size_x, _size_y);
            gout << move_to(_x+2, (magassag*i+meret_y)+2) << color(30,30,30) << box(_size_x-4, _size_y-4);
            gout << color(255,255,255)<<move_to(_x+5,magassag*i+meret_y+18)<< text(menu[i]);

        }
    }else {for(int i = 0; i<length; i++){
            gout << move_to(_x, magassag*i+meret_y) << color(0,0,0) << box(_size_x, _size_y);

            }
        }
}


void Menu::handle(event ev)
{

    if(bennevan){
        for(int i=0;i<length;i++){
            if(ev.pos_x > _x && ev.pos_x < meret_x && ev.pos_y > magassag*i+meret_y && ev.pos_y < magassag*i+meret_y+magassag &&  ev.button == btn_left){
                    str = menu[i];
                    cout<<str;
            }

            /*if(ev.pos_x > _x && ev.pos_x < meret_x && ev.pos_y > magassag*i+meret_y && ev.pos_y < magassag*i+meret_y+magassag){
                cout<<"ok";

            }*/

        }
    }


    if(ev.button == btn_left && ev.type == ev_mouse)
    {
        if (is_selected(ev.pos_x, ev.pos_y))
        {
            _focused = true;
        }

        else
        {
            _focused = false;
           bennevan = false;

        }

    }
    if(ev.pos_x > meret_x-30 && ev.pos_x < meret_x && ev.pos_y > meret_y-magassag && ev.pos_y < meret_y-magassag + 30 &&  ev.button == btn_left){
        bennevan = true;
    }




}

/*string Menu :: ertek_w(){
return menu;
}*/



bool Menu::is_focused(){
    return _focused;
}



