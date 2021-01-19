#ifndef EXPLOSION_H_INCLUDED
#define EXPLOSION_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

namespace edu{
namespace neu{
namespace csye6205{
class explosion{
protected:
    double size;
    string name;
public:
    explosion();
    explosion(string name,double size);
    virtual ~explosion();
    virtual void explode();
    friend ostream &operator<<( ostream &output,
                                       const explosion &E );
};
}
}
}

#endif // EXPLOSION_H_INCLUDED
