#include "graphics.hpp"
#include "gomb.hpp"
#include "os.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Application.hpp"
#include <functional>


using namespace std;
using namespace genv;


gomb::gomb(window* a, int x_kor, int y_kor, int meretx, int merety, string szoveg, function<void()> f) : os(a, x_kor, y_kor, meretx, merety), szoveg(szoveg) , f(f),  megnyomva(false) {}
void gomb::rajzol(){
    gout << color (255, 255, 255);
    gout << move_to(x_kor, y_kor) << box(meretx, merety);

    gout << color (0, 0, 0);
    gout << font("LiberationSans-Regular.ttf",30);

    if (megnyomva){
        gout <<color (102, 102, 102);
        gout << move_to(x_kor+5, y_kor+5) << box(meretx-10, merety-10);
    } else {
        gout << color (204, 204, 204);
        gout << move_to(x_kor+5, y_kor+5) << box(meretx-10, merety-10);
    }
    gout << color (0, 0 ,0);
    gout << move_to((x_kor+5), (y_kor+5));
    gout << text(szoveg);
    gout << color (255, 255 ,255);
}




void gomb::fogantyu(event ev){

    if (ev.button==btn_left){
        if (ev.pos_x > x_kor && ev.pos_x < x_kor + meretx){
            if (ev.pos_y > y_kor && ev.pos_y < y_kor + merety){

                    megnyomva=true;
        f();

        }
    }


}
    if (ev.button!=btn_left){
            megnyomva=false;


}
}

void gomb::mentes(){
    cout << "bejön" << endl;
    ofstream file("mentes.txt", ios::app);

    file << "Valasztott:" << megnyomva << endl;
    file.close();
}

