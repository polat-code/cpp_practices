#include <iostream>

#include "../include/math/MathOperations.hpp"
using namespace std;
using namespace my_math;
int main()
{
    MathOperations math_operations;
    cout << math_operations.add(1,2) << endl;
    cout <<math_operations.subtract(1,2) << endl;
    return 0;
}
