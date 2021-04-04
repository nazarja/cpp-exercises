#include "AddOneToEach.h"

int SumVector(vector<int> v)
{
    int total = 0;
    AddOneToEach(v);

    for (auto i : v)
    {
        total += 1;
    }

    return total;
}