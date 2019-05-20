#include "jatek.hpp"
#include "Widgets.hpp"
#include <vector>
#include <iostream>
using namespace std;

bool check(std :: vector<Widgets*>elemek){
    int ellenoriz;
    for(int i = 0;i<10;i++){

        if(elemek[i] -> get_statusz() == elemek[i+1] -> get_statusz() && i%10 != 0){
            ellenoriz=ellenoriz+1;
            if (ellenoriz=5){
                    cout<<"vege"<<endl;
            }
        } else{
            ellenoriz = 0;
        }

    }

}

