#include <iostream>
#include "calc.h"
#include "calcInt.h"
#include "calcDoub.h"

using namespace std;

int main() {
    //The Integer Calculate Output:
    //a+b = 5, a-b = -1, a*b = 6, a/b = 0
    //The Double Calculate Output:
    //a+b = 5, a-b = -1, a*b = 6, a/b = 0.666667
    double a=2.0;
    double b=3.0;
    cout << "The Integer Calculate Output: " << endl;
    edu::neu::csye6205::calcInt cint;
    cint.demo(a,b);
    cout << "The Double Calculate Output: " << endl;
    edu::neu::csye6205::calcDoub cdouble;
    cdouble.demo(a,b);
    return 0;
}
