#include "parallax.h"
#include "textLoader.h"

textLoader *btex = new textLoader();

parallax::parallax()
{
    xMax = 0.0;
    yMax = 0.0;
    xMin = 1.0;
    yMin = 1.0;
}

parallax::~parallax()
{
    //dtor
}

void parallax:: drawSquare(float width, float height){

    glColor3f(1.0,1.0,1.0);
    btex->TextureBinder();
    glBegin(GL_POLYGON);

    glTexCoord2f(xMin, yMin);

    glVertex3f(-width/height, -1, -30.0f);// square
    glTexCoord2f(xMax, yMin);
    glVertex3f(width/height, -1, -30.0f);
    glTexCoord2f(xMax, yMax);
    glVertex3f(width/height, 1, -30.0f);
    glTexCoord2f(xMin, yMax);
    glVertex3f(-width/height, 1, -30.0f);


    glEnd();
}
void parallax:: parallaxinit(char* filename){

 btex->loadTexture(filename);
}

void parallax::scroll(bool, string x, float)
{

}
