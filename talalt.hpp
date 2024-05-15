#ifndef TALALT_HPP_INCLUDED
#define TALALT_HPP_INCLUDED

#include "os.hpp"

using namespace std;

class talalt: public os{
    bool megnyomva;
    bool vane;
public:
    talalt(window* a, int x_kor, int y_kor, int meretx, int merety, bool vane);
    void rajzol();
    void fogantyu(genv::event ev);

};


#endif // TALALT_HPP_INCLUDED
