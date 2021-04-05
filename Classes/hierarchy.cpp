#include <iostream>

using namespace std;

class Vehicle
{
public:
    bool trunk {true};
    int seats {4};
    int wheels {4};
};

class Car : public Vehicle
{};

class Sedan : public Car
{};

int main() 
{
    Sedan sedan;
    cout << sedan.trunk << endl;
    cout << sedan.seats << endl;
    cout << sedan.wheels << endl;
}