#include "Header.h"


Header::Header() {
    idLength = 0;
    colorMapType = 0;
    dataTypeCode = 0;
    colorMapOrigin = 0;
    colorMapLength = 0;
    colorMapDepth = 0;
    xOrigin = 0;
    yOrigin = 0;
    width = 0;
    height = 0;
    bitsPerPixel = 0;
    imageDescriptor = 0;
}

Header::Header(char _idLength, char _colorMapType, char _dataTypeCode, short _colorMapOrigin, short _colorMapLength,
               char _colorMapDepth, short _xOrigin, short _yOrigin, short _width, short _height, char _bitsPerPixel,
               char _imageDescriptor) {
    idLength = _idLength;
    colorMapType = _colorMapType;
    dataTypeCode = _dataTypeCode;
    colorMapOrigin = _colorMapOrigin;
    colorMapLength = _colorMapLength;
    colorMapDepth = _colorMapDepth;
    xOrigin = _xOrigin;
    yOrigin = _yOrigin;
    width = _width;
    height = _height;
    bitsPerPixel = _bitsPerPixel;
    imageDescriptor = _imageDescriptor;
}


void Header::toString() {
    cout << "ID Length: " << (int)idLength << endl;
    cout << "Color Map Type: " << (int)colorMapType << endl;
    cout << "Data Type Code: " << (int)dataTypeCode << endl;
    cout << "Color Map Origin: " << colorMapOrigin << endl;
    cout << "Color Map Length: " << colorMapLength << endl;
    cout << "Color Map Depth: " << (int)colorMapDepth << endl;
    cout << "X Origin: " << xOrigin << endl;
    cout << "Y Origin: " << yOrigin<< endl;
    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;
    cout << "Bits Per Pixel: " << (int)bitsPerPixel << endl;
    cout << "Image Descriptor: " << (int)imageDescriptor << endl;

}






