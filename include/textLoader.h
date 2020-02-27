#ifndef TEXTLOADER_H
#define TEXTLOADER_H

#include<SOIL.h>
#include<gl/gl.h>


class textLoader
{
    public:
        textLoader();
        virtual ~textLoader();
        void loadTexture(char *);
        void TextureBinder();
        unsigned char* image;
        int width, height;
        GLuint tex;

    protected:

    private:
};

#endif // TEXTLOADER_H
