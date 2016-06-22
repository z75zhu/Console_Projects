#include "makefile.h"
#include <iostream>
#include <string>
using namespace std;

Makefile::Makefile(ostream &out) : out{out} {}

//destructor for pointerarray in makefile
Makefile::~Makefile() {
    for (int i = 0; i < size; i++){
        delete totaltargets[i];
    }
    delete []totaltargets;
}

//get that object in pointerarray
//return nullptr if it does not exist
Target* Makefile::getTarget(string t){
    for (int i = 0; i <20; i++){
        if (totaltargets[i] == nullptr){
            return nullptr;
        }
        if (totaltargets[i]->name == t){
            return totaltargets[i];
        }
    }
    return nullptr;
}

//check if target exist
//if not create them and call addDepend for target level
//add to that pointer array in makefile
void Makefile::addDepend(const string &t, const string &d) {
    Target *target = getTarget(t);
    Target *dependence = getTarget(d);
    
    if (target == nullptr){
        if (size==20){
            out<<"Max targets exceeded"<<endl;
            return;
        }
        target = new Target(t);
        totaltargets[size] = target;
        size++;
    }
    if (dependence == nullptr){
        if (size==20){
            out<<"Max targets exceeded"<<endl;
            return;
        }
        dependence = new Target(d);
        totaltargets[size] = dependence;
        size++;
    }
    target->addDepend(dependence);
    
}

//needAdd is the clock
//i checked with the executable, if a and b are both leaves
//touch a will result in b's clock add 1
//so I used only one clock for all the targets,
//updateTime does not do anthing it's just 0(I had it because I initially thought different targets should have different clocks)
void Makefile::changeTarget(const string &t) {
    if (getTarget(t)==nullptr){
        return;
    }else{
        Target *target = getTarget(t);
        if(target->isLeaf()){
            //target->updatedtime++;
            needAdd++;
            out<<target->name<<" updated at time "<<target->updatedtime+needAdd<<endl;
            //needAdd = 0;
            target->updated = true;
            resetUpper(target);
        }else{
            out<<"Cannot update non-leaf object"<<endl;
            needAdd++;
        }
    }
    
}
//check then go build()
void Makefile::rebuild(const string &t) {
    if ((getTarget(t)==nullptr)||(getTarget(t)->isLeaf())){
        return;
    }else{
        Target *target = getTarget(t);
        target->build();
    }
    
}
//reset the upper
void Makefile::resetUpper(Target *d){
     for (int i = 0; i < size; i++){
         for (int j = 0; j<10;j++){
             if (totaltargets[i]->dependence[j] == d){
                 totaltargets[i]->updated = false;
                 resetUpper(totaltargets[i]);
             }
         }
     }
}

