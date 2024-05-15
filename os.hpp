#ifndef OS_HPP_INCLUDED
#define OS_HPP_INCLUDED
#include "graphics.hpp"
#include "Application.hpp"

class window;

class os{
protected:
    window* ablak;
    int x_kor, y_kor , meretx, merety;
public:
    os(window* ablak, int x_kor, int y_kor, int meretx, int merety);
    virtual bool aktiv(int evx, int evy);
    virtual void rajzol()=0;
    virtual void fogantyu(genv::event ev) = 0;
    virtual void mentes()=0;
};



#endif // OS_HPP_INCLUDED
