#ifndef SETNUMBER_HPP_INCLUDED
#define SETNUMBER_HPP_INCLUDED

#include "graphics.hpp"
#include "Widgets.hpp"
#include <string>

using namespace std;
using namespace genv;

class Setnumber : public Widgets
{
    public:
        Setnumber(int x, int y, int sx, int sy, int ertek,int maximum, int minimum);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual bool is_focused();
        virtual void s_num(int ertek);
        virtual std::string get_value(){};
        string ertek();
        virtual int get_statusz() = 0;

     protected:
        string str;
        bool _focused;
        int value;
        int meret_x;
        int meret_y;
        int magassag;
        int hossz;
        bool bennevan_up;
        bool bennevan_down;
        bool bennevan;
        int _max;
        int _min;
        string get_num;



};

#endif // SETNUMBER_HPP_INCLUDED
