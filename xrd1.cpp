// xrd1.cpp
// xrd basics
// wpf 20180926 07h50min
//
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
int main(int argc, char * argv [])
{ int rvOk=0; int rvError=1; // 0=ok, 1=error
  std::cout << "xrd1 -- v 0.1 -- 20180926_07h50min\n";
  if(argc!=6)
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
      return rvOk;
  }
  double N = std::stod(argv[1]);
  double a = std::stod(argv[2]);
  double r = std::stod(argv[3]);
  double L = std::stod(argv[4]);
  double l = L / 2;
  int n = std::stoi(argv[5]);
  std::cout << "Argument values\n"
    << "\tNumber of lattice points per dimension: n = " << n << " angstroms,\n"
    << "\tLattice constant (cubic lattice): a = " << a << " angstroms,\n"
    << "\tDistance from the sample to the screen: r = " << r << " cm,\n"
    << "\tScreen size: L = " << L << " cm,\n"
    << "\tNumber of points per screen dimension: n = " << n << ".\n";
  typedef std::array<double,4> Point;
  std::vector<Point> cluster;
  unsigned int il=0; // index of the atom in the lattice
  // cluster
  for(int i3=0;i3<N;++i3)
  { double x3=-((N-1)*a)/2+a*i3;
    for(int i2=0;i2<N;++i2)
    { double x2=-((N-1)*a)/2+a*i2;
      for(int i1=0;i1<N;++i1)
      { double x1=-((N-1)*a)/2+a*i1;
        cluster.push_back({0.0,x1,x2,x3});
        //lattice[i1][i2][i3]={x1,x2,x3};
        std::cout << "cluster.size()="<<cluster.size()<<" from ["<<i1<<"]["<<i2<<"]["<<i3<<"]: cluster["<<il<<"] = ("
                  << cluster[il][1] <<", "
                  << cluster[il][2] <<", "
                  << cluster[il][3] <<")\n";
        ++il;
      }
    }
  }
  // screen
  unsigned int is=0;
  for(int i2=0;i2<n;++i2)
  { double x2=-l+L*i2/n;
    for(int i1=0;i1<n;++i1)
    { double x1=-l+L*i1/n;
      std::cout << "i1="<<i1<<", i2="<<i2<<", x1="<<x1<<", x2="<<x2<<".\n";
      ++is;
    }
  }
  std::cout << "The execution ended normally!\n";
  return rvOk;
}
//
// end of file xrd1.cpp
