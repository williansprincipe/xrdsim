// accessories.cpp
// functions of general use
//
#include"accessories.h"
#include<iostream>
int msgToUserHeader()
{ std::cout << "xrd1 -- v 0.2 -- 20180927_16h20min\n";
  return 0;
}

int msgToUserUsage()
{ std::cout << "This little program calculates the diffraction pattern\n"
    << "produced by plane monochromatic x-ray scattering through a \n"
    << "finite piece of a cubic lattice (a cluster).\n"
    << "Usage:\n"
    << "\txrd1 N a r L n\n"
    << "\twhere\n"
    << "\t\tN is the number of lattice points per dimension,\n"
    << "\t\ta is the lattice parameter in angstroms and\n"
    << "\t\tr is the distance from the sample to the screen in cm,\n"
    << "\t\tL is the screen size in cm (square screen normal to z axis),\n"
    << "\t\tn is the number of points per screen dimension.\n";
    std::cout << "Nothing done. Execution terminated well.\n";
  return 0;
}

int parseArguments(const int argc, char ** argv, int N, double a,
                   double r, double L, int n)
{ N = std::stod(argv[1]);
  a = std::stod(argv[2]);
  r = std::stod(argv[3]);
  L = std::stod(argv[4]);
  n = std::stoi(argv[5]);
  return 0;
}

int msgdbg1(const int N, const double a, const double r,
    const double L, const int n)
{ std::cout << "Argument values\n"
    << "\tNumber of lattice points per dimension: N = " << N << ",\n"
    << "\tLattice constant (cubic lattice): a = " << a << " angstroms,\n"
    << "\tDistance from the sample to the screen: r = " << r << " cm,\n"
    << "\tScreen size: L = " << L << " cm,\n"
    << "\tNumber of points per screen dimension: n = " << n << ".\n";
  return 0;
}

// eof accessories.cpp
