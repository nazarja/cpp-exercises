#include <iostream>

using namespace std;

class Point
{
    public:
        Point(int x, int y) : x(x), y(y)
        {};
        
        Point operator+(const Point &addend)
        {
            Point sum(0,0);
            sum.x = this->x + addend.x;
            sum.y = this->y + addend.y;
            return sum;
        };
    
        int GetX() 
        { return this->x; };
        
        int GetY()
        { return this->y; };
        
    private:
        int x;
        int y;    
};

int main() 
{
    Point p1(10, 5), p2(2, 4);
    Point p3 = p1 + p2;
    cout << p3.GetX() << " : " << p3.GetY() << endl;
}