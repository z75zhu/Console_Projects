#ifndef _MAKEFILE_
#define _MAKEFILE_
#include <string>
#include <iostream>
#include "target.h"

const int maxTargets = 20;

struct Makefile {   // You may add fields and methods as you see fit.
  std::ostream &out;  // Stream where Makefile will print its output.
                      // This class should output a value x by saying
                      // out << x, rather than cout << x.
    //poniter array for all targets of a makefile
    Target** totaltargets = new Target*[20]{nullptr};
    int size = 0;
    //my clock
    int needAdd = 0;
    //bool needupdate=false;
    Makefile(std::ostream &out = std::cout);
    ~Makefile();
    
  
  void addDepend(const std::string &t, const std::string &d);

  void changeTarget(const std::string &t);

  void rebuild(const std::string &t);
    Target* getTarget(std::string t);
    void resetUpper(Target *d);
};

#endif
