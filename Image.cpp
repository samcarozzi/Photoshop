
#include "Image.h"


Image::Image() {
    imageHeader = Header();
}

Image::Image(Header _imageHeader, vector<Pixel> _pixels) {
    imageHeader = _imageHeader;
    pixels = _pixels;
}

Image Image::readFile(const string &fileName) {

    Header _imageHeader;
    vector<Pixel> _pixels;

    ifstream file(fileName, ios_base::binary);

    if(file.is_open()) {
        char _idLength, _colorMapType, _dataTypeCode;
        short _colorMapOrigin, _colorMapLength;
        char _colorMapDepth;
        short _xOrigin, _yOrigin, _width, _height;
        char _bitsPerPixel, _imageDescriptor;

        file.read(&_idLength,1);

        file.read(&_colorMapType,1);

        file.read(&_dataTypeCode,1);

        file.read(reinterpret_cast<char*>(&_colorMapOrigin),2);

        file.read(reinterpret_cast<char*>(&_colorMapLength),2);

        file.read(&_colorMapDepth,1);

        file.read(reinterpret_cast<char*>(&_xOrigin),2);

        file.read(reinterpret_cast<char*>(&_yOrigin),2);

        file.read(reinterpret_cast<char*>(&_width),2);

        file.read(reinterpret_cast<char*>(&_height),2);

        file.read(&_bitsPerPixel,1);

        file.read(&_imageDescriptor,1);

        _imageHeader = Header(_idLength, _colorMapType, _dataTypeCode, _colorMapOrigin,
                      _colorMapLength,_colorMapDepth, _xOrigin,  _yOrigin, _width, _height,  _bitsPerPixel,
                      _imageDescriptor);

        unsigned int pixelCount = _imageHeader.width * _imageHeader.height;

        for(unsigned int i = 0; i < pixelCount; i++) {
            unsigned char red;
            unsigned char green;
            unsigned char blue;

            file.read(reinterpret_cast<char *>(&blue), 1);
            file.read(reinterpret_cast<char *>(&green), 1);
            file.read(reinterpret_cast<char *>(&red), 1);

            _pixels.push_back(Pixel(red,green,blue));
        }

        return Image(_imageHeader, _pixels);

    }
    else{
        cout << "error";
        return Image();
    }
}

void Image::writeFile(const string &fileName) {


    ofstream file(fileName, ios_base::binary);

    if(file.is_open()) {

        file.write(&imageHeader.idLength,1);

        file.write(&imageHeader.colorMapType,1);

        file.write(&imageHeader.dataTypeCode,1);

        file.write(reinterpret_cast<char*>(&imageHeader.colorMapOrigin),2);

        file.write(reinterpret_cast<char*>(&imageHeader.colorMapLength),2);

        file.write(&imageHeader.colorMapDepth,1);

        file.write(reinterpret_cast<char*>(&imageHeader.xOrigin),2);

        file.write(reinterpret_cast<char*>(&imageHeader.yOrigin),2);

        file.write(reinterpret_cast<char*>(&imageHeader.width),2);

        file.write(reinterpret_cast<char*>(&imageHeader.height),2);

        file.write(&imageHeader.bitsPerPixel,1);

        file.write(&imageHeader.imageDescriptor,1);


        unsigned int pixelCount = imageHeader.width * imageHeader.height;

        for(unsigned int i = 0; i < pixels.size(); i++) {

            Pixel currentPixel = pixels[i];

            file.write(reinterpret_cast<char *>(&currentPixel.blue), 1);
            file.write(reinterpret_cast<char *>(&currentPixel.green), 1);
            file.write(reinterpret_cast<char *>(&currentPixel.red), 1);

        }

    }
    else{
        cout << "error";
    }
}

Image Image::Multiply (Image& topLayer, Image& bottomLayer) {

    Image multipliedImage;
    vector<Pixel> _pixels;

    for(unsigned int i = 0; i < topLayer.pixels.size(); i++) {

        Pixel topPixel = topLayer.pixels[i];
        Pixel bottomPixel = bottomLayer.pixels[i];

        int _blue;
        int _green;
        int _red;

        _blue = topPixel.blue * (int) bottomPixel.blue / 255.0f + 0.5f;
        _green = topPixel.green * (int) bottomPixel.green / 255.0f + 0.5f;
        _red = topPixel.red * (int) bottomPixel.red / 255.0f + 0.5f;

        Pixel multipliedPixel = Pixel((unsigned char)_red,(unsigned char)_green,(unsigned char)_blue);
        _pixels.push_back(multipliedPixel);

    }

    multipliedImage = Image(topLayer.imageHeader, _pixels);
    return multipliedImage;
}

Image Image::Subtract(Image& topLayer, Image& bottomLayer) {

    Image subtractedImage;
    vector<Pixel> _pixels;

    for(unsigned int i = 0; i < topLayer.pixels.size(); i++) {

        Pixel topPixel = topLayer.pixels[i];
        Pixel bottomPixel = bottomLayer.pixels[i];

        int _blue;
        int _green;
        int _red;

        _blue = (int) bottomPixel.blue - (int) topPixel.blue;
        _green = (int) bottomPixel.green - (int) topPixel.green;
        _red =  (int) bottomPixel.red - (int) topPixel.red;

        if(_blue<0)
            _blue = 0;
        if(_green<0)
            _green = 0;
        if(_red<0)
            _red = 0;


        Pixel subtractedPixel = Pixel((unsigned char)_red,(unsigned char)_green,(unsigned char)_blue);
        _pixels.push_back(subtractedPixel);

    }

    subtractedImage = Image(topLayer.imageHeader, _pixels);
    return subtractedImage;
}

bool Image::Equal(Image& image1, Image& image2) {
    for(unsigned int i = 0; i < image1.pixels.size(); i++) {

        Pixel topPixel = image1.pixels[i];
        Pixel bottomPixel = image2.pixels[i];

        if(topPixel.blue != bottomPixel.blue){

            return false;
        }
        if(topPixel.green != bottomPixel.green){

            return false;
        }
        if(topPixel.red != bottomPixel.red){

            return false;
        }
    }
    return true;
}

Image Image::Screen(Image& topLayer, Image& bottomLayer) {
    Image screenedImage;
    vector<Pixel> _pixels;

    for(unsigned int i = 0; i < topLayer.pixels.size(); i++) {

        Pixel topPixel = topLayer.pixels[i];
        Pixel bottomPixel = bottomLayer.pixels[i];

        int _blue;
        int _green;
        int _red;

        _blue = 255-((255-topPixel.blue) * (255-bottomPixel.blue) / 255.0f - 0.5f);
        _green = 255-((255-topPixel.green) * (255-bottomPixel.green) / 255.0f - 0.5f);
        _red = 255-((255-topPixel.red) * (255-bottomPixel.red) / 255.0f - 0.5f);

        Pixel screenedPixel = Pixel((unsigned char)_red,(unsigned char)_green,(unsigned char)_blue);
        _pixels.push_back(screenedPixel);

    }

    screenedImage = Image(topLayer.imageHeader, _pixels);
    return screenedImage;
}

Image Image::Overlay(Image& topLayer, Image& bottomLayer) {
    Image overlaidImage;
    vector<Pixel> _pixels;

    for(unsigned int i = 0; i < topLayer.pixels.size(); i++) {

        Pixel topPixel = bottomLayer.pixels[i];
        Pixel bottomPixel = topLayer.pixels[i];

        int _blue;
        int _green;
        int _red;

        if(topPixel.blue/255.0f <= 0.5)
            _blue = 2 * topPixel.blue * (int) bottomPixel.blue / 255.0f + 0.5f;
        else if(topPixel.blue/255.0f > 0.5)
            _blue = 255-(2 * (255-topPixel.blue) * (255-bottomPixel.blue) / 255.0f - 0.5f);

        if(topPixel.green/255.0f <= 0.5)
            _green = 2 * topPixel.green * (int) bottomPixel.green / 255.0f + 0.5f;
        else if(topPixel.green/255.0f > 0.5)
            _green = 255-(2 * (255-topPixel.green) * (255-bottomPixel.green) / 255.0f - 0.5f);

        if(topPixel.red/255.0f <= 0.5)
            _red = 2 * topPixel.red * (int) bottomPixel.red / 255.0f + 0.5f;
        else if(topPixel.red/255.0f > 0.5)
            _red = 255-(2 * (255-topPixel.red) * (255-bottomPixel.red) / 255.0f - 0.5f);


        _pixels.push_back(Pixel((unsigned char)_red,(unsigned char)_green,(unsigned char)_blue));

    }

    overlaidImage = Image(topLayer.imageHeader, _pixels);
    return overlaidImage;
}

void Image::addGreen() {
    for(unsigned int i = 0; i<pixels.size(); i++) {
        int _green;
        _green = 200 + pixels[i].green;

        if(_green>255)
            pixels[i].green = 255;
        else
            pixels[i].green = _green;
    }
}

void Image::multiplyRedBlue() {
    for(unsigned int i = 0; i<pixels.size(); i++) {
        int _red;
        _red = 4 * pixels[i].red;

        if(_red>255)
            pixels[i].red = 255;
        else
            pixels[i].red = _red;

        pixels[i].blue = 0;
    }
}

Image Image::Red() const {
    vector<Pixel> _pixels = pixels;

    for(unsigned int i = 0; i<pixels.size(); i++){
        _pixels[i].green = _pixels[i].red;
        _pixels[i].blue = _pixels[i].red;
    }

    Image duplicate = Image(imageHeader, _pixels);
    return duplicate;
}

Image Image::Green() const {
    vector<Pixel> _pixels = pixels;

    for(unsigned int i = 0; i<pixels.size(); i++){
        _pixels[i].red = _pixels[i].green;
        _pixels[i].blue = _pixels[i].green;
    }

    Image duplicate = Image(imageHeader, _pixels);
    return duplicate;
}

Image Image::Blue() const {
    vector<Pixel> _pixels = pixels;

    for(unsigned int i = 0; i<pixels.size(); i++){
        _pixels[i].green = _pixels[i].blue;
        _pixels[i].red = _pixels[i].blue;
    }

    Image duplicate = Image(imageHeader, _pixels);
    return duplicate;
}

Image Image::loadColors(Image& red, Image& green, Image& blue) {

    vector<Pixel> _pixels;

    for(unsigned int i = 0; i<red.pixels.size(); i++){
        _pixels.push_back(Pixel(red.pixels[i].red,green.pixels[i].green,blue.pixels[i].blue));
    }


    return Image(red.imageHeader, _pixels);
}

void Image::Rotate() {
    reverse(pixels.begin(), pixels.end());
}












