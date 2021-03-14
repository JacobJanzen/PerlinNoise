#pragma once

// this class uses ncurses to print a slice of Perlin Noise
class Screen{
private:
    // height and width of the window
    int height;
    int width;
    // assigns a character based on an inputted double
    // between 0.0 and 1.0.
    // Higher values get graphically denser characters
    // There are 10 levels of the gradient
    char getDepthChar(double);
    unsigned int getSeed();
public:
    // initializes ncurses and 
    // gets a seed from the user
    // initializes the perlin noise values
    // from the seed
    Screen();

    // stops the ncurses window
    ~Screen();

    // finds the correct character for each
    // point on the screen from its perlin value
    void printPerlin();
};