#include "Statictext.hpp"
#include <iostream>

using namespace genv;


Statictext::Statictext(int x, int y, int sx, int sy, string szoveg) : Widgets(x,y,sx,sy)
{
str=szoveg;
_focused = false;
}


void Statictext::draw()
{
        gout << move_to(_x, _y) << color(0,0,255) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
        gout << color(255,255,255)<<move_to(_x+5,_y+20)<< text(str);


}

void Statictext::handle(event ev)
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


}


void Statictext::s_text(string szoveg) {
    str = szoveg;
}

bool Statictext::is_focused(){
    return _focused;
}



