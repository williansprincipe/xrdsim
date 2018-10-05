// xrdsim.cpp
// xrd simulator (basics)
// wpf 20180927 16h20min
//

#include <iostream>
#include <string>
#include "accessories.h"
#include "Cluster.h"

int main(int argc, char * argv [])
{ int rvOk=0;// int rvError=1; // 0=ok, 1=error
  msgToUserHeader();
  if(wrongNumberOfArgs(argc))
  { msgToUserUsage(argc);
    return (argc-1);
  }
  vector_t a; vector_t b; vector_t c;
  int Na=0; int Nb=0; int Nc=0; double r=12.0; double L=20.0; int n=20;
  parseArguments(argc,argv,a,b,c,Na,Nb,Nc,r,L,n);
  Cluster cluster(a,b,c,Na,Nb,Nc);
  msgdbg1(Na,Nb,Nc,cluster);
  std::cout << "The execution ended normally!\n";
  return rvOk;
}
//
// end of file xrd1.cpp
