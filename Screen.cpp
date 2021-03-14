#include <functional>
#include <ncurses.h>
#include <string.h>
#include <string>
#include <time.h>
#include "PerlinNoise.h"
#include "Screen.h"

#define MAX_INPUT_LENGTH 100 // the maximum length of the input for generating a seed

Screen::Screen(){
    initscr();
    getmaxyx(stdscr,height,width);
    PerlinNoise::generateNewPermutation(getSeed());
}

Screen::~Screen(){
    getch();    // wait for user input before exiting
    endwin();
}

void Screen::printPerlin(){
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++){
            double noiseVal = PerlinNoise::perlin((double)i/height,(double)j/width,0);
            mvaddch(i,j,getDepthChar(noiseVal));
        }
    refresh();
}

char Screen::getDepthChar(double depth){
    if(depth < .1)
        return ' ';
    else if(depth < .2)
        return '.';
    else if(depth < .3)
        return ':';
    else if(depth < .4)
        return ';';
    else if(depth < .5)
        return '+';
    else if(depth < .6)
        return '=';
    else if(depth < .7)
        return 'x';
    else if(depth < .8)
        return 'X';
    else if(depth < .9)
        return '$';
    return '&';
}

unsigned int Screen::getSeed(){
    const char mesg[] = "Enter a seed. (Just press ENTER to use random seed): ";
    char str[MAX_INPUT_LENGTH];

    // print a prompt for a seed
    mvprintw(height/2,(width-strlen(mesg))/2, "%s", mesg);
    move(height/2+1,width/2);
    getstr(str);

    // if a seed was inputted
    // hash the string
    if(strlen(str) > 0){
        std::string seedString = str;
        std::hash<std::string> hasher;
        return hasher(str);
    // otherwise base the string off the current time
    }else{
        return time(nullptr);
    }
}