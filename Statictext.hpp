#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED

#include "graphics.hpp"
#include "Widgets.hpp"
#include <string>

using namespace std;
using namespace genv;

class Statictext : public Widgets
{
    public:
        Statictext(int x, int y, int sx, int sy, string szoveg);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual bool is_focused();
        virtual void s_text(string szoveg);
        virtual std::string get_value(){};
        virtual int get_statusz() = 0;

     protected:
        string str;
        bool _focused;



};

#endif // STATICTEXT_HPP_INCLUDED
