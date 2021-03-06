#include "Button.hpp"
#include <functional>
#include <iostream>

using namespace genv;

Button::Button(int x, int y, int sx, int sy,  string text, function <void()>_funk)
    : Widgets(x,y,sx,sy)
{
    funk=_funk;
    str=text;
    _focused=false;
    on_clicked=false;
}
void Button::draw()
{
    if (_focused)
    {
        gout << move_to(_x, _y) << color(255,0,0) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    }
    else
    {
        gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    }
        gout << color(255,255,255)<<move_to(_x+5,_y+14)<< text(str);
}

void Button::handle(event ev)
{

    if (ev.type == ev_mouse && ev.button==btn_left)
    {
        if ( is_selected(ev.pos_x, ev.pos_y) )
        {
            on_clicked=true;
            _focused=true;
            funk();
        }
        else
        {
            _focused=false;
        }
    }

}
bool Button::is_focused()
{
    return _focused;
}
void Button:: set_click(){
    on_clicked=false;
}
bool Button:: get_click(){
    return on_clicked;
}
