#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "graphics.hpp"
#include "Widgets.hpp"
#include <string>
#include <vector>
using namespace std;
using namespace genv;

class Menu : public Widgets
{
    public:
        Menu(int x, int y, int sx, int sy, vector<string> elemek, int hossz);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual bool is_focused();
        virtual std::string get_value(){};
        string ertek_w();
        virtual int get_statusz() = 0;

     protected:
        vector<string>menu;
        bool _focused;
        int length;
        int meret_x;
        int meret_y;
        string str = "";
        int magassag;
        bool bennevan=false;
        string ertekek;
};

#endif // STATICTEXT_HPP_INCLUDED
