#include "graphics.hpp"
#include <vector>
#include <cmath>
#include <cstdlib>
#include "os.hpp"
#include "szamolos.hpp"
#include "kivalaszto.hpp"
#include <fstream>
#include "Application.hpp"
#include "gomb.hpp"
#include <functional>
#include "talalt.hpp"

const int XX = 800;
const int YY = 800;


using namespace std;
using namespace genv;



int main(){
    bool hajok [10][10];
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (j==4 && i==4)hajok[i][j]=1;
            else hajok[i][j]=0;
        }
    }
    window* b= new window(XX, YY);
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            new talalt (b, i*40+200, j*40+200, 40, 40, hajok[i][j]);
        }
    }





    b->event_loop();
    return 0;
}
