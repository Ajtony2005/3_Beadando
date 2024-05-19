#ifndef TALALT_HPP_INCLUDED
#define TALALT_HPP_INCLUDED

#include "os.hpp"
#include <functional>
using namespace std;

class talalt: public os {
    bool megnyomva;
    bool vane;
    bool megnyomhato;
    function<void()> p;
    function<void()> k;
public:
    talalt(window* a, int x_kor, int y_kor, int meretx, int merety, bool vane, bool megnyomva, bool megnyomhato, function<void()> p, function<void()> k);
    void rajzol();
    void fogantyu(genv::event ev);
    void megnyom(bool allapot);
};

#endif // TALALT_HPP_INCLUDED
