#include "graphics.hpp"
#include "szamolos.hpp"
#include "os.hpp"
#include <iostream>
#include <fstream>

using namespace std;
using namespace genv;


szamolos::szamolos(window* a, int x_kor, int y_kor, int meretx, int merety, int szam, int minimum, int maximum) : os(a, x_kor, y_kor, meretx, merety) , szam(szam), minimum(minimum), maximum(maximum) {}

void szamolos::rajzol(){
    gout << move_to(x_kor, y_kor) << box(meretx, merety);
    gout << color (0, 0 ,0);
    gout << move_to(x_kor+5, y_kor+5) << box(meretx-10, merety-10);
    gout << color (255, 255 , 255);
    gout << font("LiberationSans-Regular.ttf",merety-10);
    gout << move_to((x_kor+meretx-(meretx/6)), y_kor) << box (5, merety);
    gout << move_to((x_kor+meretx-(meretx/6)), y_kor+(merety/2-2)) << box ((meretx/6),4);
    gout << move_to((x_kor+15), (y_kor+5));
    gout << text(to_string(szam));




}
void szamolos::fogantyu(event ev){
    if (szam < maximum){
        if (ev.keycode==key_up)   szam++;
        if (szam+10 <= maximum){
        if (ev.keycode==key_pgup) szam+=10;}
        if (ev.button==btn_left){
        if (ev.pos_x > x_kor+meretx-(meretx/6) && ev.pos_x < x_kor+meretx ){
            if (ev.pos_y > y_kor && ev.pos_y < y_kor+(merety/2-2)) szam++;
        }
    }
    }
    if (szam > minimum){

    if (ev.keycode==key_down) szam--;
    if (szam-10 >= minimum){
    if (ev.keycode==key_pgdn) szam-=10;}
    if (ev.button==btn_left){
    if (ev.pos_x > x_kor+meretx-(meretx/6) && ev.pos_x < x_kor+meretx ){
            if (ev.pos_y > y_kor+(merety/2-2) && ev.pos_y <y_kor+merety) szam--;
        }
    }}

}


void szamolos::mentes(){
    ofstream file("mentes.txt", ios::app);
    file << "Szamolos:" << szam <<endl;
    file.close();
}
