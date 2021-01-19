#include <iostream>
#include "school.h"
#include "studentFactory.h"
using namespace std;
using namespace edu::neu::csye6205;
int main()
{
    studentFactory sch;
    school *school=sch.getObject();
    (*school).demo();
    return 0;
}
//Output Result:
//Teacher:
//0020, Ernst, Pauli, 45, 10023.400000
//Student:
//1011, 1, Dan, Peters, 17, 4.000000
//3092, 2, Marie, Curie, 20, 3.560000
//8092, 3, Albert, Einstein, 23, 3.730000
//4908, 4, NewTon, Isaac, 22, 3.980000
//2032, 5, Tesla, Nikola, 15, 3.230000
