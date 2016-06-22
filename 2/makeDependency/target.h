#ifndef _TARGET_H_
#define _TARGET_H_
#include <iostream>
#include <string>

const int maxDepends = 10;


struct Target {  // You may add fields and methods as you see fit
  std::ostream &out;  // Stream where Target will print its output
  std::string name;
    //Updated goes to true everytime a touch happens to leaf
    bool updated = false;
    int updatedtime = 0;
    //pointer array for every target and showing their dependence
    Target **dependence = new Target*[10]{nullptr};
    int targetDepSize = 0;
     ~Target();


  
    
  Target(const std::string &name, std::ostream &out = std::cout);
  bool isLeaf() const;
  void addDepend(Target *d);
  void update(int time);
  int lastUpdated() const;
  bool build();

};

#endif
