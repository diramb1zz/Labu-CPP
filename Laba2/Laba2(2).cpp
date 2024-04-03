#include <cmath>
#include <iostream>


using namespace std;
const double pi = 3.14159265358979323846; //ологошення зовнішньої змінної ПІ

template <class T> void Calculate(T&r,T&h,T&Volume,T&CircleArea){

    Volume = pi * r * r * h;
    CircleArea = 2 * pi * r * h;

}// функція, яка знаходить об’єм та площу бокової поверхні циліндра


int main()
{

    double radius = 7.6;
    double height = 12.8;
    double Volume, CircleArea;

    Calculate(radius, height, Volume, CircleArea);

    cout << "Volume: " << Volume << endl;
    cout << "CircleArea: " << CircleArea << endl;

    int radius1 = 10;
    int height1 = 15;
    int Volume1, CircleArea1;
    Calculate(radius1, height1, Volume1, CircleArea1);

    cout << "Volume: " << Volume1 << endl;
    cout << "CircleArea: " << CircleArea1 << endl;


    return 0;

}