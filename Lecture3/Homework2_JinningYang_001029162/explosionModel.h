#ifndef EXPLOSIONMODEL_H_INCLUDED
#define EXPLOSIONMODEL_H_INCLUDED
#include <iostream>
#include <string>
#include<vector>
#include "grenade.h"
#include "mine.h"
#include "gunshot.h"
using namespace std;

namespace edu{
namespace neu{
namespace csye6205{
class explosionModel{
private:
    std::vector<explosion *>explosions;
public:
    explosionModel();
    virtual ~explosionModel();
    void load();
    void add(explosion *e);
    void explodeAll();
    static void demo();
    friend ostream &operator<<( ostream &output,
                                       const explosion &E );
};
}
}
}

#endif // EXPLOSIONMODEL_H_INCLUDED
