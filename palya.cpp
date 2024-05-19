#include "graphics.hpp"
#include "os.hpp"
#include "Application.hpp"
#include "palya.hpp"

using namespace std;
using namespace genv;


palya::palya(window* a, int x_kor, int y_kor, int meretx, int merety)  : os(a, x_kor, y_kor, meretx, merety){}
void palya::rajzol(){
    gout << move_to(x_kor, y_kor) << box(meretx, merety);
    gout << color (0, 0, 0);
    gout << move_to((x_kor+5), (y_kor+5)) << box (meretx-10, merety-10);
    gout << color (255, 255 ,255);


}


void palya::fogantyu(event ev){

}


