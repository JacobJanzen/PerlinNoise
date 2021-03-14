#include <iostream>
#include "Screen.h"

int main(){
    Screen *screen = new Screen();
    screen->printPerlin();
    delete(screen);
    return 0;
}