#include <iostream>

using namespace std;

class Square
{
    private:
        friend class Rectangle;
        int side;
        
    public:
        Square(int side) : side(side)
        {};
};

class Rectangle
{
    private:
        int width;
        int height;
        
        
    public:
        Rectangle(const Square &square) : width(square.side) , height(square.side)
        {};
        
        int GetArea() const
        { return this->width * this->height; };
};



int main() 
{
    Square square(4);
    Rectangle rectangle(square);
    
    cout << rectangle.GetArea() << endl;
}