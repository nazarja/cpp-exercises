#include <iostream>
#include <string>

using namespace std;

class Human
{
    public:
        void Hello()
        {
            cout << "hello" << endl;
        };
        
        void Hello(string s)
        {
            cout << "hello, " << s << endl;
        };
};

int main() 
{
    Human human;

    human.Hello();
    human.Hello("Sean");
}