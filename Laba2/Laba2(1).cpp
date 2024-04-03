#include <cmath>
#include <iostream>


using namespace std;
const double pi = 3.14159265358979323846; //ологошення зовнішньої змінної ПІ



void Calculate(double r, double h, double& Volume, double& CircleArea) {

    Volume = pi * r * r * h;
    CircleArea = 2 * pi * r * h;
        
}// функція, яка знаходить об’єм та площу бокової поверхні циліндра


int main()
{
    
    double radius = 5.1;
    double height = 10.5;
    double Volume, CircleArea;

    Calculate(radius, height, Volume, CircleArea);

    cout << "Volume: " << Volume << endl;
    cout << "CircleArea: " << CircleArea << endl;

    return 0;

}
