#include <iostream>
#include "PerlinNoise.h"

#define HEIGHT 49
#define WIDTH 190

int main(){
    PerlinNoise::generateNewPermutation();
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            double noiseVal = PerlinNoise::perlin((double)i/HEIGHT+1,(double)j/WIDTH+1,0);
            if(noiseVal < .1)
                std::cout << ' ';
            else if(noiseVal < .2)
                std::cout << '.';
            else if(noiseVal < .3)
                std::cout << ':';
            else if(noiseVal < .4)
                std::cout << ';';
            else if(noiseVal < .5)
                std::cout << '+';
            else if(noiseVal < .6)
                std::cout << '=';
            else if(noiseVal < .7)
                std::cout << 'x';
            else if(noiseVal < .8)
                std::cout << 'X';
            else if(noiseVal < .9)
                std::cout << '$';
            else
                std::cout << '&';
/*
            if(noiseVal > .75)
                std::cout << "░";
            else if(noiseVal > .5)
                std::cout << "▒";
            else if(noiseVal > .25)
                std::cout << "▓";
            else
                std::cout << "█";
                */
        }
        std::cout << std::endl;
    }
    return 0;
}