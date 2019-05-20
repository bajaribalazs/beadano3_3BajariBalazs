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
    int p=-1;
    bool used;
public:
    checkbox(int x, int y, int sx, int sy);
    bool is_focused();
    virtual void unselect();
    //virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    std::string get_value();
    int statusz=0;
    int* counter;
    int get_statusz();
    void player_1();
    void player_2();
    bool is_used();
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
