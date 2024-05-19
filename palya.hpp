#ifndef PALYA_HPP_INCLUDED
#define PALYA_HPP_INCLUDED

#include "os.hpp"

using namespace std;

class palya: public os {
public:
    palya(window* a, int x_kor, int y_kor, int meretx, int merety);
    void rajzol();
    void fogantyu(genv::event ev);
};

#endif // PALYA_HPP_INCLUDED
