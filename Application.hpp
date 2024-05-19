#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED
#include "os.hpp"
#include <iostream>
#include <vector>

using namespace std;

class os;


class window{
public:
    int index=-1;
    vector<os*>* lajos;
    vector<os*> kezdo;
    vector<os*> lerakas;
    vector<os*> leiras;
    vector<os*> jatek;
    vector<os*> nyertem;
    vector<os*> vesztettem;
public:
    void event_loop();
    window(int XX, int YY);
    void osadas(os* a){
        if (index < 0)lajos->push_back(a);
        else {
            switch (index){
        case 0:
            kezdo.push_back(a);
            break;
        case 1:
            lerakas.push_back(a);
            break;
        case 2:
            leiras.push_back(a);
            break;
        case 3:
            jatek.push_back(a);
            break;
        case 4:
            nyertem.push_back(a);
            break;
       case 5:
            vesztettem.push_back(a);
            break;
        }
        }
        }

    void beall(int index);
};


#endif // APPLICATION_HPP_INCLUDED
