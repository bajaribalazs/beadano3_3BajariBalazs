#include "checkbox.hpp"
#include "graphics.hpp"
using namespace genv;

checkbox::checkbox(int x, int y, int sx, int sy)
    : Widgets(x,y,sx,sy)
{
    focus=false;
}

void checkbox::unselect()
{
    _focused = false;
}

void checkbox::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    if(focus)
    {
        gout << color(255,0,0);
        gout << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
        gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);

    }


}

void checkbox::handle(event ev)
{
    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' '))
    {
        focus = !focus;
    }
    if (is_selected(ev.pos_x, ev.pos_y) && ev.type == ev_mouse && ev.button==btn_left)
    {
        focus = !focus;
        statusz=1;
    }


}

void checkbox::player_1()
{
    if (!focus&&used==false)
    {
        gout << color(0,0,255);
        gout << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
        gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);
        used=true;
        p=0;
    }
}
void checkbox::player_2()
{
    if (!focus&&used==false)
    {
        gout << color(255,0,0);
        gout << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
        gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);
        used=true;
        p=1;
    }
}

bool checkbox::is_used()
{
    return used;
}


bool checkbox::is_focused()
{
    return _focused;
}

string checkbox::get_value()
{

}

int checkbox::get_statusz()
{
    return statusz;

}
