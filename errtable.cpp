#include <cmath>
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include "integrators.hpp"

static inline double f(double x){ return std::exp(-x); }

int main(int argc, char** argv){
  std::vector<unsigned> Ns;
  if (argc > 1) for (int i=1;i<argc;++i) Ns.push_back((unsigned)std::stoul(argv[i]));
  else Ns = {2,10,20,40,80,160};

  const double a=0.0, b=1.0, I_exact = 1.0 - std::exp(-1.0);

  std::cout << "N\te_T\te_S\te_G\n";
  std::cout.setf(std::ios::scientific); std::cout << std::setprecision(16);

  for (auto N : Ns){
    double It = trapez(f, N, a, b);
    double eT = std::fabs((It - I_exact)/I_exact);

    double Is = simpson(f, N, a, b);
    bool S_ok = !std::isnan(Is);
    double eS = S_ok ? std::fabs((Is - I_exact)/I_exact) : 0.0;

    double Ig = gaussint(f, N, a, b);
    double eG = std::fabs((Ig - I_exact)/I_exact);

    std::cout << N << '\t' << eT << '\t';
    if (S_ok) std::cout << eS << '\t'; else std::cout << '\t';
    std::cout << eG << '\n';
  }
  return 0;
}
