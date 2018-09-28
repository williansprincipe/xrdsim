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
{ int rvOk=0; // int rvError=1; // 0=ok, 1=error
  msgToUserHeader();
  if(argc!=6)
  { msgToUserUsage();
    return rvOk;
  }
  int N; double a; double r; double L; int n;
  parseArguments(argc,argv,N,a,r,L,n);
  msgdbg1(N,a,r,L,n);

  std::cout << "The execution ended normally!\n";
  return rvOk;
}
//
// end of file xrd1.cpp
