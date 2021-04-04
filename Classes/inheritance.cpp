#include <string>
#include <iostream>

using namespace std;
// Define base class Animal
class Animal
{
        public:
            string color;
            string name;
            int age;
};

// Declare derived class Snake
class Snake : public Animal
{
    public:
        int length;
        
        Snake(int length, string color, string name, int age) : length(length)
        {
            this->color = color;
            this->name = name;
            this->age = age;
        }
        
        void MakeSound() 
        {
            cout << "hiss" << endl;
        };
};

// Declare derived class Cat
class Cat : public Animal
{
    public:
        int height;
                
        Cat(int height, string color, string name, int age) : height(height)
        {
            this->color = color;
            this->name = name;
            this->age = age;
        }
            
        void MakeSound() 
        {
            cout << "meow" << endl;
        };
};

// Test in main()
int main()
{
    Snake snake(50, "sammy", "green", 2);
    Cat cat(20, "tammy", "brown", 5);
    
    snake.MakeSound();
    cat.MakeSound();
};