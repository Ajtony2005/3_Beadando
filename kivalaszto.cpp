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



kivalaszto::kivalaszto(window* a, int x_kor, int y_kor, int meretx, int merety, vector<string> nevek, int hanyadik, bool lenyilt, int gorgo) : os(a, x_kor, y_kor, meretx, merety), nevek(nevek) , hanyadik(hanyadik), lenyilt(lenyilt), gorgo(gorgo) {}
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
void kivalaszto::lenyit(){
    int k=1;
            for (size_t j=0;j<nevek.size();j++) {
                    if (j<4){
                        if (j!=hanyadik){
                        gout << move_to(x_kor, y_kor+(merety*(j+k))) << box(meretx, merety);
                        gout << color (0, 0 ,0);
                        gout << move_to(x_kor+5, y_kor+(merety*(j+k))+5) << box(meretx-10, merety-10);
                        gout << color (255, 255 , 255);
                        gout << move_to((x_kor+15), (y_kor+5+(merety*(j+k))));
                        gout << text(nevek[j+gorgo]);

            }   else k=0;}}



}


void kivalaszto::fogantyu(event ev){

    if (lenyilt){
        if (gorgo < nevek.size()-4){
            if (ev.button==btn_wheelup) gorgo++;}
        if (gorgo > 0){
            if (ev.button==btn_wheeldown) gorgo--;}
            cout << gorgo << endl;
            torol();
            lenyit();

    }







    int k=1;
    if (ev.button==btn_left){
        if (lenyilt){
            for (size_t j=0;j<nevek.size();j++){
                if (j!=hanyadik){
                    if (ev.pos_x >= x_kor && ev.pos_x <= x_kor+meretx ){
                    if (ev.pos_y > y_kor+(merety*(j+k)) && ev.pos_y < y_kor+(merety*(j+k))+merety){
                    hanyadik=j+gorgo;
                    lenyilt=0;
                    torol();

                }
            }
                }else k=0;
            }
        }else {
        if (ev.pos_x > x_kor+meretx-(meretx/6) && ev.pos_x < x_kor+meretx ){
            if (ev.pos_y > y_kor && ev.pos_y < y_kor+merety){
                lenyit();
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

