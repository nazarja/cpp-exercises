#include <iostream>
#include <cmath>


using namespace std;


struct LineSegment
{
    public:
        double length;
        
};

class Circle
{
    private:
        LineSegment &radius;
        
    public:
        Circle(LineSegment &radius) : radius(radius) {};
        
        double GetArea()
        { return M_PI * (pow(this->radius.length, 2));};
};

int main() 
{
    LineSegment radius{3};
    Circle circle(radius);
    
    cout << circle.GetArea() << endl;
}