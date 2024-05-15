#ifndef GOMB_HPP_INCLUDED
#define GOMB_HPP_INCLUDED

#include <iostream>
#include <string>
#include "os.hpp"
#include <vector>
#include <functional>

using namespace std;

class gomb: public os{
    string szoveg;
    function<void()> f;
    bool megnyomva;
public:
    gomb(window* a, int x_kor, int y_kor, int meretx, int merety, string szoveg, function<void()> f);
    void rajzol();
    void fogantyu(genv::event ev);
    void mentes();

};


#endif // GOMB_HPP_INCLUDED
