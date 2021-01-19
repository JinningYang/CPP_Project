#ifndef GRENADE_H_INCLUDED
#define GRENADE_H_INCLUDED

#include "explosion.h"
#include <string>
using namespace std;

namespace edu{
namespace neu{
namespace csye6205{
class grenade:public explosion{
private:
    double weight;
public:
    grenade();
    grenade(string name,double size,double weight);
    virtual ~grenade();
    void explode();
    friend ostream &operator<<( ostream &output,
                                       const grenade &E );
};
}
}
}


#endif // GRENADE_H_INCLUDED
