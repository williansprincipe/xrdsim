// xrdsim.cpp
// xrd simulator (basics)
// wpf 20180927 16h20min
//

#include <iostream>
#include <string>
#include "accessories.h"
#include "Cluster.h"
#include "Detector.h"

int main(int argc, char * argv [])
{ int rvOk=0;// int rvError=1; // 0=ok, 1=error
  msgToUserHeader();
  if(wrongNumberOfArgs(argc))
  { msgToUserUsage(argc);
    return (argc-1);
  }
  vector_t a; vector_t b; vector_t c;
  int Na=0; int Nb=0; int Nc=0; double d=12.0; double L=20.0; int n=20;
  parseArguments(argc,argv,a,b,c,Na,Nb,Nc,d,L,n);
  Cluster cluster(a,b,c,Na,Nb,Nc);
  msgdbg1(Na,Nb,Nc,cluster);
  Detector detector(L,n);
  vector_t k;
  k.x(0.0); k.y(0.0); k.z(1.0); 
  vector_t kp;
  kp = k;
  detector.detect(cluster,k,kp,d); // real processing of the pattern
  std::cout << "The execution ended normally!\n";
  return rvOk;
}
//
// end of file xrd1.cpp
