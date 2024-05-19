#ifndef SZOVEG_HPP_INCLUDED
#define SZOVEG_HPP_INCLUDED

#include <string>
#include "os.hpp"

using namespace std;

class szoveg: public os{
    string kiir;
public:
    szoveg(window* a, int x_kor, int y_kor, int meretx, int merety, string kiir);
    void rajzol();
    void fogantyu(genv::event ev);
    void mentes();
    void setKiir(const string& ujKiir);
    void torol();

};


#endif // SZOVEG_HPP_INCLUDED
