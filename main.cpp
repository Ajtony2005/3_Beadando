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


const int XX = 800;
const int YY = 800;


using namespace std;
using namespace genv;


void igen(){
    cout << "nem" << endl;
}

void nem(){
    cout << "igen" << endl;
}


int main(){
    function<void()> f;
    f = igen;
    function<void()> k;
    k = nem;
    window* b= new window(XX, YY);
    vector<string> gyumolcsok = {"alma", "körte", "banán", "szőlő", "narancs"};
    vector<string> autok = {"Audi", "BMW", "Kia", "Porsche", "Lexus", "Toyota"};
    //new szamolos(b, 50, 50, 150, 50, 0, 0, 100);
    //new szamolos(b, 300, 100, 150, 50, 0, 0, 670);
    new kivalaszto(b, 550, 400, 210, 50, gyumolcsok, 0);
    new kivalaszto(b, 50, 400, 210, 50, autok, 0);
    new gomb(b, 300, 400, 100, 50, "Nem", f);
    new gomb(b, 410, 400, 100, 50, "Igen", k);
    b->event_loop();
    return 0;
}
