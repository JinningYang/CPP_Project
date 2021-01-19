#ifndef MINE_H_INCLUDED
#define MINE_H_INCLUDED

#include "explosion.h"
#include <string>
using namespace std;

namespace edu{
namespace neu{
namespace csye6205{
class mine:public explosion{
private:
    string material;
public:
    mine();
    mine(string name,double size,string material);
    virtual~mine();
    void explode();
    friend ostream &operator<<( ostream &output,
                                       const mine &M );
};
}
}
}

#endif // MINE_H_INCLUDED
