#include <vector>
#include <cmath>
#include <cstdlib>
#include "os.hpp"
#include "Application.hpp"
#include "talalt.hpp"
#include "graphics.hpp"
#include "hajok.hpp"
const int XX = 800;
const int YY = 800;


using namespace std;
using namespace genv;



int main(){

    bool haj [10][10];
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (j==4 && i==4)haj[i][j]=1;
            else haj[i][j]=0;
        }
    }
    window* b= new window(XX, YY);
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            new talalt(b, i*40+200, j*40+200, 40, 40, haj[i][j]);
        }
    }
    new hajok(b, 10, 10, 40, 40, 2);
    new hajok(b, 10, 200, 40, 40, 3);
    new hajok(b, 10, 350, 40, 40, 1);
    new hajok(b, 10, 400, 40, 40, 4);


    b->event_loop();
    return 0;
}
