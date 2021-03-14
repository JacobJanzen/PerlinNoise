#pragma once

#include <vector>

class PerlinNoise{
private:
    static int repeat;
    static int p[512];
    static int permutation[];

    static double fade(double t);
    static double lerp(double t, double a, double b);
    static double grad(int hash, double x, double y, double z);
    static int inc(int num);
public:
    static void initialize();
    static double perlin(double x, double y, double z);
    static void generateNewPermutation();
    static void generateNewPermutation(unsigned int seed);
};