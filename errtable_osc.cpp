#include <cmath>
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <cstdlib>
#include "integrators.hpp"

// f(x) = sin(omega * x)
static double omega_g = 5000.0;
static inline double f_osc(double x){ return std::sin(omega_g * x); }

int main(int argc, char** argv){
 
  int argi = 1;
  if (argc >= 2){
    omega_g = std::atof(argv[argi++]);
  }
  std::vector<unsigned> Ns;
  for (; argi < argc; ++argi) Ns.push_back((unsigned)std::stoul(argv[argi]));
  if (Ns.empty()) Ns = {2,10,20,40,80,160};

  const double a=0.0, b=1.0;
  const double I_exact = (1.0 - std::cos(omega_g)) / omega_g;

  std::cout << "N\te_T\te_S\te_G\n";
  std::cout.setf(std::ios::scientific);
  std::cout << std::setprecision(16);

  for (auto N : Ns){
    double It = trapez(f_osc, N, a, b);
    double eT = std::fabs((It - I_exact)/I_exact);
    double Is = simpson(f_osc, N, a, b);
    bool S_ok = !std::isnan(Is);
    double eS = S_ok ? std::fabs((Is - I_exact)/I_exact) : 0.0;
    double Ig = gaussint(f_osc, N, a, b);
    double eG = std::fabs((Ig - I_exact)/I_exact);

    std::cout << N << '\t' << eT << '\t';
    if (S_ok) std::cout << eS << '\t'; else std::cout << '\t';
    std::cout << eG << '\n';
  }
  return 0;
}

