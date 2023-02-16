//
// Created by Sam Carozzi on 11/10/22.
//
#pragma once


struct Pixel{

    unsigned char red;
    unsigned char green;
    unsigned char blue;

    Pixel(){
        red = 0;
        green = 0;
        blue = 0;
    };
    Pixel(unsigned char _red, unsigned char _green, unsigned char _blue) {
        red = _red;
        green = _green;
        blue = _blue;
    }
};