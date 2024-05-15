#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED
#include "os.hpp"
#include <iostream>
#include <vector>

using namespace std;

class os;


class window{
public:
    vector<os*> lajos;
public:
    void event_loop();
    window(int XX, int YY);
    void osadas(os* a){lajos.push_back(a);}
};


#endif // APPLICATION_HPP_INCLUDED
