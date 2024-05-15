#include "graphics.hpp"
#include "kivalaszto.hpp"
#include "os.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Application.hpp"


using namespace std;
using namespace genv;

bool lenyilt=0;

kivalaszto::kivalaszto(window* a, int x_kor, int y_kor, int meretx, int merety, vector<string> nevek, int hanyadik) : os(a, x_kor, y_kor, meretx, merety), nevek(nevek) , hanyadik(hanyadik) {}
void kivalaszto::rajzol(){
    gout << move_to(x_kor, y_kor) << box(meretx, merety);
    gout << color (0, 0 ,0);
    gout << move_to(x_kor+5, y_kor+5) << box(meretx-10, merety-10);
    gout << color (255, 255 , 255);
    gout << font("LiberationSans-Regular.ttf",merety-10);
    gout << move_to(x_kor+5, y_kor+5);
    gout << move_to((x_kor+meretx-(meretx/4)), y_kor) << box (5, merety);
    gout << move_to((x_kor+meretx-(meretx/5)), y_kor+merety/4) << line_to(x_kor+meretx-((meretx/8)),y_kor+(merety/4)*3) << line_to(x_kor+meretx-((meretx/20)),y_kor+(merety/4));
     gout << move_to((x_kor+15), (y_kor+5));
    gout << text(nevek[hanyadik]);



}

void  torol(){
    gout << color(0, 0 , 0);
    gout << move_to(0 , 0) << box(800, 800);
    gout << color(255, 255 , 255);


}


void kivalaszto::fogantyu(event ev){
    int k=1;
    if (ev.button==btn_left){
        if (lenyilt){
            for (size_t j=0;j<nevek.size();j++){
                if (j!=hanyadik){
                    if (ev.pos_x >= x_kor && ev.pos_x <= x_kor+meretx ){
                    if (ev.pos_y > y_kor+(merety*(j+k)) && ev.pos_y < y_kor+(merety*(j+k))+merety){
                    hanyadik=j;
                    lenyilt=0;
                    torol();

                }
            }
                }else k=0;
            }
        }else {
        if (ev.pos_x > x_kor+meretx-(meretx/6) && ev.pos_x < x_kor+meretx ){
            if (ev.pos_y > y_kor && ev.pos_y < y_kor+merety){
                for (size_t j=0;j<nevek.size();j++) {
                        if (j!=hanyadik){
                        gout << move_to(x_kor, y_kor+(merety*(j+k))) << box(meretx, merety);
                        gout << color (0, 0 ,0);
                        gout << move_to(x_kor+5, y_kor+(merety*(j+k))+5) << box(meretx-10, merety-10);
                        gout << color (255, 255 , 255);
                        gout << move_to((x_kor+15), (y_kor+5+(merety*(j+k))));
                        gout << text(nevek[j]);
            }   else k=0;}
            lenyilt=1;
        }
        }
        }
}
}

void kivalaszto::mentes(){
    cout << "bejön" << endl;
    ofstream file("mentes.txt", ios::app);

    file << "Valasztott:" << nevek[hanyadik] << endl;
    file.close();
}

