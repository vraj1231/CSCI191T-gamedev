#ifndef _GLSCENE_H
#define _GLSCENE_H

#include <windows.h>
#include<GL/glut.h>

#include<iostream>

using namespace std;

class _glScene
{
    public:
        _glScene();               // constructor
        virtual ~_glScene();      // Deconstructor
        GLint initGL();           // initialize OpenGL
        GLint drawScene();        // Renderer
        GLvoid reSizeScene(GLsizei, GLsizei); // screen size changes

        int winMsg(HWND, UINT, WPARAM, LPARAM);	// Callback of inputs

        //WPARAM wParm;

       //float winMsg(HWND, UINT, WPARAM, LPARAM);
       float screenwidth, screenheight;
    protected:

    private:
};

#endif // _GLSCENE_H
