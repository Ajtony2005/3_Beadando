#ifndef SZAMOLOS_HPP_INCLUDED
#define SZAMOLOS_HPP_INCLUDED

#include "os.hpp"


class szamolos: public os{
    int szam;
    int minimum;
    int maximum;
public:
    szamolos(window* a, int x_kor, int y_kor, int meretx, int merety, int szam, int minimum, int maximum );
    void rajzol();
    void fogantyu(genv::event ev);
    void mentes();

};


#endif // SZAMOLOS_HPP_INCLUDED
