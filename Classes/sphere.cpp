#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>

// TODO: Define class Sphere
class Sphere
{
    public:
    Sphere(int radius) : radius(radius) , volume(M_PI * 4 / 3 * pow(this->radius, 3)) {};

    int GetRadius()
    {
        return this->radius;
    }

    int Volume() const;

    private:
    int radius;
    int volume;
};

int Sphere::Volume() const
{
    return this->volume;
}

// Test
int main(void)
{
    Sphere sphere(5);
    std::cout << sphere.Volume() << std::endl;
    assert(sphere.GetRadius() == 5);
    assert(abs(sphere.Volume() - 523.6) < 1);
}