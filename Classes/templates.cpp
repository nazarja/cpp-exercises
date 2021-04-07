#include <iostream>

using namespace std;

template <typename T>
T Product(T a, T b)
{
    return a * b;
};

template <typename M>
M Max(M a, M b)
{
    return a > b ? a : b;
};

int main() 
{
    int result = Product(5, 10);
    bool max_result = Max(10, 50) == 50;
    cout << result << endl;
    cout << max_result << endl;
}