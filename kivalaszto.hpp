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
    bool lenyilt;
    int gorgo;
public:
    kivalaszto(window* a, int x_kor, int y_kor, int meretx, int merety, vector<string> nevek, int hanyadik, bool lenyilt, int gorgo);
    void rajzol();
    void fogantyu(genv::event ev);
    void mentes();
    void lenyit();
};


#endif // KIVALASZTO_HPP_INCLUDED
