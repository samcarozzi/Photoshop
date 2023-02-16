#include <vector>
#include <iostream>
#include <iomanip>
#include <climits>
#include <fstream>
#include <sstream>
#include <string>

#pragma once
using namespace std;


struct Header {
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
    int* pixels;


    Header();
    Header(char _idLength, char _colorMapType, char _dataTypeCode, short _colorMapOrigin, short _colorMapLength, char _colorMapDepth,
           short _xOrigin, short _yOrigin, short _width, short _height, char _bitsPerPixel, char _imageDescriptor);


    void toString();

};

