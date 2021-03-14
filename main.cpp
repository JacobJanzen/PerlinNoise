#include <iostream>
#include "PerlinNoise.h"

#define HEIGHT 49
#define WIDTH 190

int main(){
    PerlinNoise::generateNewPermutation();
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            double noiseVal = PerlinNoise::perlin((double)i/HEIGHT+1,(double)j/WIDTH+1,1);

            if(noiseVal > .75)
                std::cout << "░";
            else if(noiseVal > .5)
                std::cout << "▒";
            else if(noiseVal > .25)
                std::cout << "▓";
            else
                std::cout << "█";
        }
        std::cout << std::endl;
    }
    return 0;
}