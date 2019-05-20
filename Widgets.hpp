#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

class Widgets
{
    protected:

        int _x, _y, _size_x, _size_y;

    public:

        Widgets(int x, int y, int sx, int sy);
        virtual bool is_selected(int mouse_x, int mouse_y);
        virtual void draw() = 0;
        virtual void handle(genv::event ev) = 0;
        virtual std::string get_value()= 0;

        bool focus = false;
        virtual int get_statusz() = 0;
        virtual bool is_used() = 0;
        virtual void player_1() = 0;
        virtual void player_2() = 0;

};

#endif // WIDGETS_HPP_INCLUDED
