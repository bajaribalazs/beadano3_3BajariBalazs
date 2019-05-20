#include "graphics.hpp"
#include "Widgets.hpp"
#include "Statictext.hpp"
#include "setnumber.hpp"
#include "checkbox.hpp"
#include "Menu.hpp"
#include "Button.hpp"
#include "jatek.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace genv;
using namespace std;



int main()
{


srand(time(NULL));
gout.open(300,300);
vector<Widgets*> w;
vector<Widgets*> widgets;


checkbox * e1 = new checkbox (50,50,30,30);
widgets.push_back(e1);



for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            checkbox * e2 = new checkbox ((i*30),(j*30),30,30);
            widgets.push_back(e2);

        }

}



event ev;
    int focus = -1;
    while(gin >> ev && ev.keycode != key_escape ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
                else
                {

                }
            }
        }


        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }

        for (Widgets * w : widgets) {
            w->draw();
        }
        gout << refresh;
        }
return 0;
}
