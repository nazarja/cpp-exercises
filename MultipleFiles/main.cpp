#include "SumVector.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v{1,2,3,4};
    int total = SumVector(v);
    cout << total << endl;
}