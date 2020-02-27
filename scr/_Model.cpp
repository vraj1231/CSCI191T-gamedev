#include "_Model.h"
#include<textLoader.h>

textLoader* tex = new textLoader();
_Model::_Model()
{
    //ctor

   rotateX=0.0;
   rotateY=0.0;
   rotateZ=0.0;

   posX=0.0;
   posY=0.0;
   posZ=-8.0;

   scale=1.0;

}

_Model::~_Model()
{
    //dtor
}
void _Model::modelInit()
{
    tex->TextureBinder();
    tex->loadTexture("images/wall.jpg");
}


void _Model::drawModel()
{
    tex ->TextureBinder();
    glColor3f(1.0,0.5,0.2);

    glTranslated(posX,posY,posZ);
    glRotated(rotateX,1,0,0);
    glRotated(rotateY,0,1,0);
    glRotated(rotateZ,0,0,1);
    glScaled(scale,scale,scale);
    glutSolidTeapot(1.5);
}
