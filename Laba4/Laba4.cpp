#include <iostream>
#include <string>

using namespace std;

class Car {
private: 
    string Model;
    int Year;
public:
    Car(string model, int year) : Model(model), Year(year) {}

    int GetYear() const {
        return Year;
    }

    void SetYear(int year) {
        Year = year;
    }

    
    string GetModel() const {
        return Model;
    }

    void SetModel(string model) {
        Model = model;
    }
};

class Race : public Car {
private:
    string Number;
    string Road;
    float Length;
public:
    Race(string model, int year, string number, string road, float length)
        : Car(model, year), Number(number), Road(road), Length(length) {}

    string GetRoad() const {
        return Road;
    }

    void SetRoad(string road) {
        Road = road;
    }
};
