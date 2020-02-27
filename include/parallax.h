#ifndef PARALLAX_H
#define PARALLAX_H
#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
#include<textLoader.h>
using namespace std;



class parallax
{
    public:
        parallax();
        virtual ~parallax();
        void drawSquare(float , float);
        void parallaxinit(char*);
        void scroll(bool, string x, float);

        float xMax, yMax, xMin, yMin;
    protected:

    private:
};

#endif // PARALLAX_H
