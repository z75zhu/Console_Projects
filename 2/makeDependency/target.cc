#include "target.h"
#include <string>
using namespace std;

//bool needprint = false;
//bool branchprinted = false;
Target::~Target() {
    /*for (int i = 0; i < targetDepSize; i++){
        delete dependence[i];
    }*/
    delete []dependence;
}

bool Target::isLeaf() const {
  return (targetDepSize==0);
}
//add depences to that pointer array
void Target::addDepend(Target *d) {
    if (targetDepSize == 10){
        out<<"Max dependencies exceeded"<<endl;
        
    }else{
    this->dependence[targetDepSize] = d;
    targetDepSize++;
    }
}

Target::Target(const string &name, ostream &out) : out{out}, name{name} {
    
}

void Target::update(int time) {
}

int Target::lastUpdated() const {
  return 0;
}
//recursively go through that target dependence array
//two booleans to make sure if needs to print
//refresh is for branching, since branch to a non-needprint branch will mess up the logic of upper level, so
//i added a refresh for it
bool Target::build() {

    bool needprint = false;
    bool refresh = false;
    for (int i = 0; i < targetDepSize; i++){
        if (needprint){
            refresh = true;
        }
            needprint = dependence[i]->build();
        if ((refresh)||(dependence[i]->updated)){
            needprint = true;
        }

    }
    //if it's leaf and been touched return ture to update so its upper level wil print
    if (isLeaf()&&updated){
        return true;
    }
    if (!isLeaf()&&updated){
        needprint = false;
    }
    if (needprint){
        updated = true;
        out<<"Building "<<name<<endl;
        return true;
    }
    return false;
    
}



