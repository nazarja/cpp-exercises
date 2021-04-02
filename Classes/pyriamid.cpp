#include <iostream>

class Pyramid
{
    private:
    int length;
    int width;
    int height;

    public:
    Pyramid(int l, int w, int h) : length(l), width(w), height(h)
    {};

    int GetLength() { return this->length;};
    int GetWidth() { return this->width;};
    int GetHeight() { return this->height;};

    void SetLength(int l) { this->length = l;};
    void SetWidth(int w) { this->width = w;};
    void SetHeight(int h) { this->height = h;};

    int CalculateVolume();

};

int Pyramid::CalculateVolume()
{
    return (height * width * length) / 3;
}

int main()
{
    Pyramid pyramid (10,20,30);
    std::cout << pyramid.CalculateVolume() << std::endl;
}