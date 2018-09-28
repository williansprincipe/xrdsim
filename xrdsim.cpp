// xrdsim.cpp
// xrd simulator (basics)
// wpf 20180927 16h20min
//
#include<iostream>
#include<vector>
#include<string>
#include<array>
#include"accessories.h"
int main(int argc, char * argv [])
{ int rvOk=0; int rvError=1; // 0=ok, 1=error
  msgToUserHeader();
  if(wrongNumberOfArgs(argc))
  { msgToUserUsage();
    std::cout << "Nothing done.\n";
    if (argc==1)
    { std::cout << "Execution terminated well.\n";
      return rvOk;
    }
    else
    { std::cout << "Execution terminated with error code 1.\n";
      return rvError;
    }
  }
  std::array<double,4> a; std::array<double,4> b; std::array<double,4> c; int Na=0; int Nb=0; int Nc=0; double r=12.0; double L=20.0; int n=20;
  parseArguments(argc,argv,a,b,c,Na,Nb,Nc,r,L,n);
//  msgdbg1(N,a,r,L,n);

  std::cout << "The execution ended normally!\n";
  return rvOk;
}
//
// end of file xrd1.cpp
