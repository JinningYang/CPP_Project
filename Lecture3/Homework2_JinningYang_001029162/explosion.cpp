#include "explosion.h"
#include "vector"
using namespace std;
namespace edu{
namespace neu{
namespace csye6205{

explosion::explosion(){}
explosion::~explosion(){}
explosion::explosion(string name,double size){
    this->name=name;
    this->size=size;
}
ostream &operator<<( ostream &output, const explosion &E )
  {
     output << E.name << ": " << E.size;
     return output;
  }
void explode(){
    cout << "\n\t Explosion.explode()..." << endl;
    //Add Objects
    vector<explosion> vec;
    vec.emplace_back("CheryBomb",20.09);
    vec.emplace_back("MustardBomb",30.01);
    vec.emplace_back("PomegranateBomb",30.02);
    cout << "BOOM!!Escape!!" << endl;
    for(explosion exp:vec){
        cout << exp<< endl;
    }
}
void explosion::explode() {
}


}
}
}
