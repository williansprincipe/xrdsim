// accessories.cpp
// functions of general use
//
#include<iostream>
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
int msgdbg1(int N, double a, double r, double L, int n)
{ std::cout << "Argument values\n"
    << "\tNumber of lattice points per dimension: N = " << N << ",\n"
    << "\tLattice constant (cubic lattice): a = " << a << " angstroms,\n"
    << "\tDistance from the sample to the screen: r = " << r << " cm,\n"
    << "\tScreen size: L = " << L << " cm,\n"
    << "\tNumber of points per screen dimension: n = " << n << ".\n";
  return 0;
}

int clusterConstruct(VectorOf3DPoints cluster)
{
  unsigned int il=0; // index of the atom in the lattice
  for(int i3=0;i3<N;++i3)
  { double x3=-((N-1)*a)/2+a*i3;
    for(int i2=0;i2<N;++i2)
    { double x2=-((N-1)*a)/2+a*i2;
      for(int i1=0;i1<N;++i1)
      { double x1=-((N-1)*a)/2+a*i1;
        cluster.push_back({0.0,x1,x2,x3});
        //lattice[i1][i2][i3]={x1,x2,x3};
        std::cout << "cluster.size()="<<cluster.size()
          <<" from ["<<i1<<"]["<<i2<<"]["<<i3
          <<"]: cluster["<<il<<"] = ("
          << cluster[il][1] <<", "
          << cluster[il][2] <<", "
          << cluster[il][3] <<")\n";
        ++il;
      }
    }
  }
  return 0;
}

int msgdbg2(const Grid2D screen)
{

  unsigned int is2=0;
  for(int i2=0;i2<n;++i2)
  { double x2=-l+L*i2/n;
    unsigned int is1=0;
    for(int i1=0;i1<n;++i1)
    { double x1=-l+L*i1/n;
      std::cout << "screen["<<i1<<"]["<<i2
        <<"] = "<<screen[i1][i2]<<".\n";
      ++is1;
    }
  }
  return 0;
}

Class Cluster
{// Cluster()=default;
 //~Cluster()=default;
 int const size()
 { return cluster_.size();
 }
 pos3d(int 
 private:
  std::vector<std::array<double,4>> cluster_;
 public:
};

// eof accessories.cpp
