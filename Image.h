//
// Created by Sam Carozzi on 11/9/22.
//
#include "Header.h"
#include "Pixel.h"

struct Image{

    Header imageHeader;
    vector<Pixel> pixels;

    Image();
    Image(Header _imageHeader, vector<Pixel> _pixels);

    static Image readFile(const string & fileName);
    void writeFile(const string& fileName);

    static Image Multiply (Image& topLayer, Image& bottomLayer);
    static Image Subtract(Image& topLayer, Image& bottomLayer);
    static Image Screen(Image& topLayer, Image& bottomLayer);
    static Image Overlay(Image& topLayer, Image& bottomLayer);

    void addGreen();
    void multiplyRedBlue();

    Image Red() const;
    Image Green() const;
    Image Blue() const;

    static Image loadColors(Image& red, Image& green, Image& blue);

    void Rotate();

    static bool Equal(Image& image1, Image& image2);


};

