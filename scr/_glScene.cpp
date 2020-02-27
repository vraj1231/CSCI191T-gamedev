#include "_glScene.h"
#include <_glLight.h>
#include <_Model.h>
#include <_inputs.h>
#include<parallax.h>
parallax *plx = new parallax();
_Model *myModel = new _Model();
_inputs *kBMs = new _inputs();

_glScene::_glScene()
{
    //ctor
    screenwidth = GetSystemMetrics(SM_CXSCREEN);
    screenheight = GetSystemMetrics(SM_CYSCREEN);
}

_glScene::~_glScene()
{
    //dtor
}
GLint _glScene::initGL()
{
   glShadeModel(GL_SMOOTH);    // to make graphics nicer
   glClearColor(0.0,0.0f,0.0f,0.0f); // background color R,G,B,Alpha
   glClearDepth(1.0f);          // Depth Clearance
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);

   glEnable(GL_COLOR_MATERIAL);
   _glLight Light(GL_LIGHT0);
   glEnable(GL_TEXTURE_2D);
   myModel->modelInit();
   plx->parallaxinit("images/px1.jpg");

   return true;
}

GLint _glScene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();

	glTranslated(0,0,-8.0);              //placing objects
    glColor3f(1.0,0.0,0.0);

    glPushMatrix();
    glScalef(33.3,33.3,1);
    plx ->drawSquare(screenwidth, screenheight);
    glPopMatrix();             // setting colors

	glPushMatrix();                      // grouping starts
  //  glutSolidTeapot(1.5);                // inbuilt model
    myModel->drawModel();

    glPopMatrix();                       // grouping ends
}

GLvoid _glScene::reSizeScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)width/(GLfloat) height; // ratio for window mode
    glViewport(0,0,width,height);                          // setting view port
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,aspectRatio,0.1,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int _glScene::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_KEYDOWN:

             kBMs->wParam = wParam;
             kBMs->keyPressed(myModel);


             break;

        case WM_KEYUP: break;

        case WM_LBUTTONDOWN:
            kBMs->wParam = wParam;
            kBMs->mouseEventDown(myModel,LOWORD(lParam),HIWORD(lParam));
            break;
        case WM_RBUTTONDOWN:
            kBMs->wParam = wParam;
            kBMs->mouseEventDown(myModel,LOWORD(lParam),HIWORD(lParam));
            break;
        case WM_MBUTTONDOWN:
            kBMs->wParam = wParam;
            kBMs->mouseEventDown(myModel,LOWORD(lParam),HIWORD(lParam));
            break;

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
            kBMs->mouseEventUp();
            break;

        case WM_MOUSEMOVE:
              kBMs->mouseMove(myModel,LOWORD(lParam),HIWORD(lParam));
             break;
        case WM_MOUSEWHEEL:
             kBMs->mouseWheel(myModel,(double)GET_WHEEL_DELTA_WPARAM(wParam));
            break;
    }
}
