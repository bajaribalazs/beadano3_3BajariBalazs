#include "jatek.hpp"
#include "Widgets.hpp"
#include <vector>
#include <iostream>
using namespace std;

 bool jatek::check(std :: vector<Widgets*>elemek){
    int ellenoriz=0;
    for(int i = 1;i<elemek.size();i++){

        if(elemek[i-1] -> get_statusz()==1 && elemek[i] -> get_statusz()==1 && i%10 != 0){
                std::cout<<ellenoriz;                       ///debug celokra
            ellenoriz++;
            if (ellenoriz==5){
                    cout<<"vege"<<endl;                     ///debug celokra
                    return false;
            }
        } else{
            ellenoriz = 0;
        }


    }
    return true;

}

