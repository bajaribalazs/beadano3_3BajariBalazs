#ifndef CHECKBOX_HPP_INCLUDED
#define CHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "Statictext.hpp"
class checkbox : public Widgets {
protected:
    bool _checked;
    const static bool _focusable = true;
    bool _focused = false;
public:
    checkbox(int x, int y, int sx, int sy);
    bool is_focused();
    virtual void unselect();
    //virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    std::string get_value();
    int statusz;
    int counter=1;

    int get_statusz();
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
