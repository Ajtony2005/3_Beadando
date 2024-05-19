#ifndef HAJOK_HPP_INCLUDED
#define HAJOK_HPP_INCLUDED

using namespace std;

class hajok: public os{
    int mekkora;
    bool forditas;
    bool lenyomva;
public:
    hajok(window* a, int x_kor, int y_kor, int meretx, int merety, int mekkora);
    void rajzol();
    void fogantyu(genv::event ev);
    void torol();

};

#endif // HAJOK_HPP_INCLUDED
