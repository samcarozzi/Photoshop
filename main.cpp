#include "Image.h"

using namespace std;

int main() {

    //Part 1
    Image layer1 = Image::readFile("input/layer1.tga");
    Image pattern1 = Image::readFile("input/pattern1.tga");

    Image multiplied = Image::Multiply(layer1, pattern1);
    multiplied.writeFile("output/part1.tga");

    //Part 2
    Image car = Image::readFile("input/car.tga");
    Image layer2 = Image::readFile("input/layer2.tga");

    Image subtracted = Image::Subtract(layer2, car);
    subtracted.writeFile("output/part2.tga");

    //Part 3
    Image pattern2 = Image::readFile("input/pattern2.tga");
    Image multipliedTemp = Image::Multiply(layer1, pattern2);

    Image text = Image::readFile("input/text.tga");

    Image screened = Image::Screen(text, multipliedTemp);
    screened.writeFile("output/part3.tga");

    //Part 4
    Image circles = Image::readFile("input/circles.tga");

    multipliedTemp = Image::Multiply(layer2, circles);

    subtracted = Image::Subtract(pattern2, multipliedTemp);
    subtracted.writeFile("output/part4.tga");

    //Part 5
    Image overlaid = Image::Overlay(layer1,pattern1);
    overlaid.writeFile("output/part5.tga");

    //Part 6
    Image greenCar = Image::readFile("input/car.tga");

    greenCar.addGreen();
    greenCar.writeFile("output/part6.tga");

    //Part 7
    Image redBlueCar = Image::readFile("input/car.tga");

    redBlueCar.multiplyRedBlue();
    redBlueCar.writeFile("output/part7.tga");

    //Part 8
    car.Red().writeFile("output/part8_r.tga");
    car.Green().writeFile("output/part8_g.tga");
    car.Blue().writeFile("output/part8_b.tga");

    //Part 9
    Image red = Image::readFile("input/layer_red.tga");
    Image green = Image::readFile("input/layer_green.tga");
    Image blue = Image::readFile("input/layer_blue.tga");

    Image::loadColors(red,green,blue).writeFile("output/part9.tga");

    //Part 10
    Image text2 = Image::readFile("input/text2.tga");
    text2.Rotate();
    text2.writeFile("output/part10.tga");


    return 0;
}