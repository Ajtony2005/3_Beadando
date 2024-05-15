#include "graphics.hpp"
#include <iostream>
#include "os.hpp"
#include "Application.hpp"

using namespace std;
using namespace genv;


os::os(window* a, int x, int y, int mx, int my) : ablak(a), x_kor  (x), y_kor(y), meretx(mx), merety(my){

    a->osadas(this);

}


bool os::aktiv(int evx, int evy){
    if (evx > x_kor && evx < x_kor + meretx){
        if (evy > y_kor && evy < y_kor + merety){
            return true;
        }
    }
    return false;
}
