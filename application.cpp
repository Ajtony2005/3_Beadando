#include "Application.hpp"
#include "graphics.hpp"
#include <iostream>
#include <vector>
#include <fstream>

using namespace genv;
using namespace std;

window::window(int XX, int YY) {

gout.open(XX, YY);
}
bool megnyitva=true;

void window::beall(int i){
    index=i;
}
void nullaz(){
gout << color(0, 0, 0);
gout << move_to(0, 0) << box(800, 800);
gout << color(255, 255, 255);
}

void window::event_loop(){
    for (os * aliz : *lajos) {
        aliz->rajzol();
    }
    gout << refresh;
    event ev;
    int pista = -1;
    while (gin >> ev && megnyitva){
        for (size_t i=0;i<lajos->size();i++) {
                    if ((*lajos)[i]->aktiv(ev.pos_x, ev.pos_y)) {
                        pista=i;

                }

        }
         if (ev.type == ev_mouse && ev.button==btn_left) {
                for (size_t i=0;i<lajos->size();i++) {
                    if ((*lajos)[i]->aktiv(ev.pos_x, ev.pos_y)) {
                        pista=i;

                }
                }

            }
        if (pista!=-1) {
            (*lajos)[pista]->fogantyu(ev);
        }
        for (os* aliz : *lajos) {
            aliz->rajzol();
        }
        gout << refresh;
        if (index >= 0){
        switch (index){
        case 0:
            lajos=&kezdo;
            break;
        case 1:
            lajos=&lerakas;
            break;
        case 2:
            lajos=&leiras;
            break;
        case 3:
            lajos=&jatek;
            break;
        case 4:
            lajos=&nyertem;
            break;
        case 5:
            lajos=&vesztettem;
            break;
        }
        index=-1;
        pista=-1;
        nullaz();

        }
}
}








