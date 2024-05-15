#ifndef KIVALASZTO_HPP_INCLUDED
#define KIVALASZTO_HPP_INCLUDED

#include <iostream>
#include <string>
#include "os.hpp"
#include <vector>
using namespace std;

class kivalaszto: public os{
    vector <string> nevek;
    int hanyadik;
public:
    kivalaszto(window* a, int x_kor, int y_kor, int meretx, int merety, vector<string> nevek, int hanyadik);
    void rajzol();
    void fogantyu(genv::event ev);
    void mentes();

};


#endif // KIVALASZTO_HPP_INCLUDED
