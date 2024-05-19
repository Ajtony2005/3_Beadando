#include <vector>
#include <cmath>
#include <cstdlib>
#include "os.hpp"
#include "Application.hpp"
#include "talalt.hpp"
#include "graphics.hpp"
#include "hajok.hpp"
#include "gomb.hpp"
#include <functional>
#include "szoveg.hpp"
const int XX = 800;
const int YY = 800;
window* b;
szoveg* uzenet;
bool haj[10][10] = {false};
function<void()> f;
function<void()> l;
function<void()> s;
using namespace std;
using namespace genv;

void kesz() {
    bool osszesElhelyezve = true;

    // Clear haj array before checking the placement
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            haj[i][j] = false;
        }
    }

    for (auto obj : *(b->lajos)) {
        hajok* hajo = dynamic_cast<hajok*>(obj);
        if (hajo) {
            int x_kor = hajo->getXKor();
            int y_kor = hajo->getYKor();
            if (!(x_kor >= 200 && x_kor <= 560 && y_kor >= 200 && y_kor <= 560)) {
                osszesElhelyezve = false;
                break;
            } else {
                int x = (x_kor - 200) / 40;
                int y = (y_kor - 200) / 40;
                int elforditot = hajo->getForditas();
                int mekkora = hajo->getMekkora();

                if (elforditot) {
                    if (y + mekkora > 10) {
                        osszesElhelyezve = false;
                        break;
                    }
                    for (int i = 0; i < mekkora; i++) {
                        if (haj[y + i][x]) {
                            osszesElhelyezve = false;
                            break;
                        }
                    }
                    if (!osszesElhelyezve) break;
                    for (int i = 0; i < mekkora; i++) {
                        haj[y + i][x] = true;
                    }
                } else {
                    if (x + mekkora > 10) {
                        osszesElhelyezve = false;
                        break;
                    }
                    for (int i = 0; i < mekkora; i++) {
                        if (haj[y][x + i]) {
                            osszesElhelyezve = false;
                            break;
                        }
                    }
                    if (!osszesElhelyezve) break;
                    for (int i = 0; i < mekkora; i++) {
                        haj[y][x + i] = true;
                    }
                }
            }
        }
    }

    if (osszesElhelyezve) {
        uzenet->setKiir("Összes hajó elhelyezve!");
        b->beall(3);
    } else {
        uzenet->setKiir("Nincs az összes hajó jól elhelyezve");
    }


}

void lerakas(){
    b->beall(1);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            new talalt(b, i * 40 + 200, j * 40 + 200, 40, 40, haj[i][j]);
        }
    }
    new hajok(b, 10, 10, 40, 40, 2);
    new hajok(b, 10, 200, 40, 40, 3);
    new hajok(b, 10, 350, 40, 40, 1);
    new hajok(b, 10, 400, 40, 40, 4);
    uzenet = new szoveg(b, 400, 50, 50, 50, "");
    new gomb(b, 400, 700, 50, 50, "kesz", f);
}
void leiras(){
    b->beall(2);
    new szoveg(b, 10, 10, 0, 0, "Leírás");
}
void kezdo(){
    b->beall(0);
    new gomb(b, 400, 350, 80, 100, "Leiras", l);
    new gomb(b, 200, 350, 80, 100, "Start", s);

}


int main() {

    f = kesz;
    s = lerakas;
    l = leiras;
    b = new window(XX, YY);
    b->lajos = &b->kezdo;
    kezdo();
    b->event_loop();
    return 0;
}
