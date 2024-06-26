#include "graphics.hpp"
#include "os.hpp"
#include "Application.hpp"
#include "hajok.hpp"


using namespace std;
using namespace genv;


hajok::hajok(window* a, int x_kor, int y_kor, int meretx, int merety, int mekkora)  : os(a, x_kor, y_kor, meretx, merety), mekkora(mekkora), forditas(false), lenyomva(false)  {}
void hajok::rajzol(){
    for (int i=0; i<mekkora; i++){
            if (forditas){
                gout << color (0, 0, 255);
                gout << move_to(x_kor, y_kor+i*merety) << box(meretx, merety);
                gout << color (0, 0, 0);
                gout << move_to((x_kor+5), (y_kor+5+i*merety)) << box (meretx-10, merety-10);
                gout << color (255, 255 ,255);
            } else {
                gout << color (0, 0, 255);
                gout << move_to(x_kor+i*meretx, y_kor) << box(meretx, merety);
                gout << color (0, 0, 0);
                gout << move_to((x_kor+5+i*meretx), (y_kor+5)) << box (meretx-10, merety-10);
                gout << color (255, 255 ,255);
    }


}
}
void hajok::torol(){
    gout << color (0, 0, 0);
    gout << move_to(0, 0) << box (800, 800);
}

void hajok::fogantyu(event ev){

    if (ev.button==btn_right){
        if (ev.pos_x > x_kor && ev.pos_x < x_kor + meretx){
            if (ev.pos_y > y_kor && ev.pos_y < y_kor + merety){
                if (forditas) forditas=false;
                else forditas=true;
                torol();

        }
    }
    }
    if (ev.button==btn_left){
        if (lenyomva){
          lenyomva=false;
          if (x_kor > 200 && x_kor < 600){
            if (y_kor > 200 && y_kor < 600){
                x_kor=(x_kor/40)*40;
                y_kor=(y_kor/40)*40;
            }
          }


        }
        else lenyomva=true;
    }
    if (ev.type==ev_mouse && lenyomva){
                    x_kor=ev.pos_x-meretx/2;
                    y_kor=ev.pos_y-meretx/2;
                    torol();




}
}
int hajok::getXKor() const {
    return x_kor;
}

int hajok::getYKor() const {
    return y_kor;
}

bool hajok::getForditas() const {
    return forditas;
}

int hajok::getMekkora() const {
    return mekkora;
}





