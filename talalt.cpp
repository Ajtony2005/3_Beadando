#include "graphics.hpp"
#include "os.hpp"
#include "Application.hpp"
#include "talalt.hpp"


using namespace std;
using namespace genv;


talalt::talalt(window* a, int x_kor, int y_kor, int meretx, int merety, bool vane)  : os(a, x_kor, y_kor, meretx, merety), vane(vane),  megnyomva(false)  {}
void talalt::rajzol(){
    if (megnyomva){
        if (vane) gout << color (255, 0, 0);
        else gout << color (0, 255, 0);
    }
    gout << move_to(x_kor, y_kor) << box(meretx, merety);
    gout << color (0, 0, 0);
    gout << move_to((x_kor+5), (y_kor+5)) << box (meretx-10, merety-10);
    gout << color (255, 255 ,255);
    if (megnyomva){
        if (vane){
        gout << color (255, 0, 0);
        gout << move_to(x_kor+10, y_kor+10) << line_to(x_kor+meretx-10, y_kor+merety-10);
        gout << move_to(x_kor+meretx-10, y_kor+10) << line_to(x_kor+10, y_kor+merety-10);
        gout << color (255, 255 ,255);
    } else {
        gout << color (0, 255, 0);
        gout << move_to(x_kor+10, y_kor+10) << line_to(x_kor+meretx-10, y_kor+merety-10);
        gout << move_to(x_kor+meretx-10, y_kor+10) << line_to(x_kor+10, y_kor+merety-10);
        gout << color (255, 255 ,255);
    }
}
}


void talalt::fogantyu(event ev){

    if (ev.button==btn_left){
        if (ev.pos_x > x_kor && ev.pos_x < x_kor + meretx){
            if (ev.pos_y > y_kor && ev.pos_y < y_kor + merety){

                    megnyomva=true;

        }
    }


}
}


