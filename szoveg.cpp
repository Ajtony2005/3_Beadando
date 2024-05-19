#include "graphics.hpp"
#include "szoveg.hpp"
#include "os.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include "Application.hpp"


using namespace std;
using namespace genv;


szoveg::szoveg(window* a, int x_kor, int y_kor, int meretx, int merety, string kiir) : os(a, x_kor, y_kor, meretx, merety), kiir(kiir) {}
void szoveg::rajzol(){
    gout << color (255, 255, 255);

    gout << font("LiberationSans-Regular.ttf", 30);
    gout << move_to((x_kor), (y_kor));
    gout << text(kiir);
    gout << color (255, 255 ,255);
}

void szoveg::torol(){
    gout << color (0, 0, 0);
    gout << move_to(0, 0) << box (800, 800);
}

void szoveg::setKiir(const string& ujKiir) {
        kiir = ujKiir;
        torol();
}

void szoveg::fogantyu(event ev){

}


void szoveg::mentes(){

}

