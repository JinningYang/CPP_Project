#include "grenade.h"

namespace edu{
namespace neu{
namespace csye6205{

grenade::grenade(){};
grenade::grenade(string name,double size,double weight){
    this->name=name;
    this->size=size;
    this->weight=weight;
}

grenade::~grenade(){};

void grenade::explode(){
    cout << "\n\t Grenade.demo()..."<< endl;
    grenade gre("AppleBomb",15.45,23.45);
    cout << gre<< endl;
    cout << "\n\t Grenade.demo()...done!!!" << endl;
}
ostream &operator<<( ostream &output, const grenade &G )
{
     output << G.name << " size: " << G.size<<" weight: "<<G.weight;
     return output;
}
}
}
}
