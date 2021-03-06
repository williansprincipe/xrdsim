// accessories.cpp
// functions of general use
//

#include"accessories.h"
#include<iostream>

int msgToUserHeader()
{ std::cout << "xrdsim -- v 0.2 -- 20180927_16h20min\n";
  return 0;
}

int msgToUserUsage(int argc)
{ std::cout << "This little program calculates the diffraction pattern\n"
    << "produced by plane monochromatic x-ray scattering through a \n"
    << "finite piece of a lattice (a cluster).\n"
    << "Usage:\n"
    << "\txrdsim a1 a2 a3 b1 b2 b3 c1 c2 c3 Na Nb Nc d L n\n"
    << "\twhere\n"
    << "\t\ta1 is the x component of the first lattice vector in angstroms,\n"
    << "\t\ta2 is the y component of the first lattice vector in angstroms,\n"
    << "\t\ta3 is the z component of the first lattice vector in angstroms,\n"
    << "\t\tb1 is the x component of the second lattice vector in angstroms,\n"
    << "\t\tb2 is the y component of the second lattice vector in angstroms,\n"
    << "\t\tb3 is the z component of the second lattice vector in angstroms,\n"
    << "\t\tc1 is the x component of the third lattice vector in angstroms,\n"
    << "\t\tc2 is the y component of the third lattice vector in angstroms,\n"
    << "\t\tc3 is the z component of the third lattice vector in angstroms,\n"
    << "\t\tNa is the number of lattice points in cluster in the a direction,\n"
    << "\t\tNb is the number of lattice points in cluster in the b direction,\n"
    << "\t\tNc is the number of lattice points in cluster in the c direction,\n"
    << "\t\td is the distance from the sample to the screen in cm,\n"
    << "\t\tL is the screen size in cm (square screen normal to z axis) and\n"
    << "\t\tn is the number of points per screen dimension.\n";
    std::cout << "Nothing done.\n";
    std::cout << (argc==0?
                  "Execution terminated well.\n":
                  "Execution terminated with error.\nError code equals number of given arguments.\n");
  return 0;
}

int parseArguments(const int argc, char ** argv,
      vector_t & a, vector_t & b, vector_t & c,
      int & Na, int & Nb, int & Nc,
      double & d, double & L, int & n)
{
  a.x(std::stod(argv[1]));
  a.y(std::stod(argv[2]));
  a.z(std::stod(argv[3]));
  b.x(std::stod(argv[4]));
  b.y(std::stod(argv[5]));
  b.z(std::stod(argv[6]));
  c.x(std::stod(argv[7]));
  c.y(std::stod(argv[8]));
  c.z(std::stod(argv[9]));
  Na = std::stod(argv[10]);
  Nb = std::stod(argv[11]);
  Nc = std::stod(argv[12]);
  d = std::stod(argv[13]);
  L = std::stod(argv[14]);
  n = std::stoi(argv[15]);
  return 0;
}

/*
int msgdbg1(const int N, const double a, const double d,
    const double L, const int n)
{ std::cout << "Argument values\n"
    << "\tNumber of lattice points per dimension: N = " << N << ",\n"
    << "\tLattice constant (cubic lattice): a = " << a << " angstroms,\n"
    << "\tDistance from the sample to the screen: d = " << d << " cm,\n"
    << "\tScreen size: L = " << L << " cm,\n"
    << "\tNumber of points per screen dimension: n = " << n << ".\n";
  return 0;
}
*/

bool wrongNumberOfArgs(int argc)
{ return argc!=16;
}

int msgdbg1(int Na, int Nb, int Nc, const Cluster & cluster)
{ std::cout << "Na = " << Na << ", Nb = " << Nb << ", Nc = " << Nc << ".\n";
  std::cout << "Cluster size: " << cluster.size() << ".\n";
  for (auto & plane : cluster.lattice())
  { 
    for (auto & row : plane)
    { for (auto & point : row)
      { std::cout << "("<<point.x()<<", "<<point.y()<<", "<<point.z()<<").\n";
      }
    }
  }
  point_t onePoint = cluster.lattice()[1][1][1];
  std::cout << "element cluster[1][1][1]= ("<<onePoint.x()<<", "<<onePoint.y()<<", "<<onePoint.z()<<").\n";
  return 0;
}

// eof accessories.cpp
