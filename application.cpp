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

void window::event_loop(){
    for (os * aliz : lajos) {
        aliz->rajzol();
    }
    gout << refresh;
    event ev;
    int pista = -1;
    while (gin >> ev && megnyitva){
        if (ev.keycode ==key_escape){
            ofstream fajl("mentes.txt", ios::trunc);
            fajl.close();
            for (size_t i=0;i<lajos.size();i++) lajos[i]->mentes();
            megnyitva=false;

        }
        for (size_t i=0;i<lajos.size();i++) {
                    if (lajos[i]->aktiv(ev.pos_x, ev.pos_y)) {
                        pista=i;

                }

        }
         if (ev.type == ev_mouse && ev.button==btn_left) {
                for (size_t i=0;i<lajos.size();i++) {
                    if (lajos[i]->aktiv(ev.pos_x, ev.pos_y)) {
                        pista=i;

                }
                }

            }
        if (pista!=-1) {
            lajos[pista]->fogantyu(ev);
        }
        for (os* aliz : lajos) {
            aliz->rajzol();
        }
        gout << refresh;

}
}







