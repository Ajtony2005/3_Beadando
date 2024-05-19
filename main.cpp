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
#include <ctime>
#include <cstdlib>
#include "palya.hpp"
#include <string>
#include "kivalaszto.hpp"

vector<vector<talalt*>> ellenfeltabla(10, vector<talalt*>(10));
vector<string> robanas = {" ", "Atom", "Sor", "Oszlop"};
const int XX = 800;
const int YY = 800;
window* b;
szoveg* uzenet;
szoveg* enpont;
szoveg* ellenfelpont;
szoveg* ki;
bool kim=false;
bool haj[10][10] = {false};
bool ellenfel[10][10] = {false};
function<void()> f;
function<void()> u;
function<void()> l;
function<void()> s;
function<void()> p;
function<void()> q;
function<void()> k;
function<void()> z;
using namespace std;
using namespace genv;

int enpontszam=0;
int ellenpontszam=0;



void nyertem(){
b->beall(4);
new szoveg(b, 300, 350, 0, 0,"NYERTEL!!" );
new gomb(b, 350, 430, 150, 50, "Uj jatek", z);
}

void vesztettem(){
b->beall(5);
new szoveg(b, 300, 350, 0, 0,"Vesztettel! :(" );
new gomb(b, 350, 430, 150, 50, "Uj jatek", z);
}


void randomtalalat(vector<vector<talalt*>>& talalat) {
    srand(time(0));

    int randomx = rand() % 10;
    int randomy = rand() % 10;

    talalat[randomx][randomy] -> megnyom(true);
}

void jatek(){
    b->beall(3);
    new szoveg(b, 320, 10, 0, 0, "Jatek");
    ki = new szoveg(b, 320, 60, 0, 0, "");
    new szoveg(b, 150, 100, 0, 0, "Ellenfel");
    new szoveg(b, 520, 100, 0, 0, "Sajat palya");
    new szoveg(b, 100, 160, 0, 0, "Pontszam: ");
    new szoveg(b, 470, 160, 0, 0, "Pontszam: ");
    enpont = new szoveg(b, 630, 160, 0, 0, to_string(0));
    ellenfelpont = new szoveg(b, 270, 160, 0, 0, to_string(0));
        for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            ellenfeltabla[j][i] = new talalt(b, i * 35 +10, j * 35+210 , 35, 35, haj[j][i], false, false,  q, k);
        }
    }
        for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            new talalt(b, i * 35 + 410, j * 35 + 210, 35, 35, haj[j][i], false, true,  p, k);
        }
    }



}
void pont(){
    enpontszam++;
    if (enpontszam >= 10) nyertem();
    enpont->setKiir(to_string(enpontszam));
    ellenfelpont->setKiir(to_string(ellenpontszam));
}

void bevan(){
    ellenpontszam++;
    if (ellenpontszam >= 10) vesztettem();
    enpont->setKiir(to_string(enpontszam));
    ellenfelpont->setKiir(to_string(ellenpontszam));
}
void gep(){
     randomtalalat(ellenfeltabla);
}

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
        jatek();
    } else {
        uzenet->setKiir("Nincs az összes hajó jól elhelyezve");
    }


}

void lerakas(){
    b->beall(1);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            new palya(b, i * 40 + 200, j * 40 + 200, 40, 40);
        }
    }
    new hajok(b, 10, 10, 40, 40, 2);
    new hajok(b, 10, 200, 40, 40, 3);
    new hajok(b, 10, 350, 40, 40, 1);
    new hajok(b, 10, 400, 40, 40, 4);
    new szoveg(b, 250, 10, 0, 0, "Helyezd el a hajokat!");
    uzenet = new szoveg(b, 200, 100, 50, 50, "");
    new gomb(b, 325, 700, 150, 50, "kesz", f);


}
void leiras(){
    b->beall(2);
    new szoveg(b, 320, 10, 0, 0, "Leiras");
    new szoveg(b, 10, 100, 0, 0, "Ez egy torpedojatek, ahol a cel az ellenfel hajoinak ");
    new szoveg(b, 10, 130, 0, 0, "elsullyesztese. A jatekot ket jatekos jatszhatja, de jelenleg ");
    new szoveg(b, 10, 160, 0, 0, "a jatek egy egyszerusitett verzioja van implementalva,");
    new szoveg(b, 10, 190, 0, 0, "Ezt kovetoen lehelyezheti a hajokat a palyan.");
    new szoveg(b, 10, 220, 0, 0, "A bal egergomb megnyomasaval helyezhet le egy hajot.");
    new szoveg(b, 10, 250, 0, 0, "Ha ujra megnyomja a bal egergombot, a hajot elengedi. ");
    new szoveg(b, 10, 280, 0, 0, "Fontos, hogy csak az elso negyzetben lehet a hajot ");
    new szoveg(b, 10, 310, 0, 0, "megfogni es mozgatni. A jobb egergomb megnyomasaval");
    new szoveg(b, 10, 340, 0, 0, "Miutan elhelyezte az osszes hajot, nyomja meg a Kesz");
    new szoveg(b, 10, 370, 0, 0, "gombot. Ekkor megjelenik a sajat tablaja es az ellenfel ");
    new szoveg(b, 10, 400, 0, 0, "tablaja. A sajat tablan kattintassal jelolje meg, ");
    new szoveg(b, 10, 430, 0, 0, "melyik mezot  szeretne tamadni az ellenfel hajoi ellen.");
    new szoveg(b, 10, 460, 0, 0, "Az ellenfel hajoi veletlenszeruen kerulnek elhelyezesre ");
    new szoveg(b, 10, 490, 0, 0, "a tablan. Minden talalat egy pontot er. ");
    new szoveg(b, 10, 520, 0, 0, "Az a jatekos nyer, aki eloszor eleri a 10 pontot.  ");
    new gomb(b, 320, 600, 160, 50, "Vissza", u);
}
void kezdo(){
    b->beall(0);
    new gomb(b, 400, 350, 150, 50, "Leiras", l);
    new gomb(b, 200, 350, 150, 50, "Start", s);

}
void Ujjatek(){
    for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        haj[i][j] = 0;
        ellenfeltabla[i][j] = nullptr;
    }
}
    enpontszam = 0;
    ellenpontszam = 0;
    if (enpont) enpont->setKiir(to_string(enpontszam));
    if (ellenfelpont) ellenfelpont->setKiir(to_string(ellenpontszam));
    if (uzenet) uzenet->setKiir("");
    lerakas();
}

int main() {
    z= Ujjatek;
    f = kesz;
    s = lerakas;
    l = leiras;
    p = pont;
    q = bevan;
    k = gep;
    u = kezdo;
    b = new window(XX, YY);
    b->lajos = &b->kezdo;
    kezdo();
    b->event_loop();
    srand(time(0));
    return 0;
}
