#include"rehuel.hpp"
#include "tetrahedral.h"
using namespace std;


struct vdpol
{
    typedef arma::mat jac_type;
    vdpol(double mu = 1.0) : mu(mu) {}

    arma::vec fun(double t, const arma::vec& y)
    {
        return { y[1], ((1 - y[0] * y[0]) * y[1] - y[0]) / mu };
    }

    jac_type jac(double t, const arma::vec& y)
    {
        jac_type J(2, 2);
        J(0, 0) = 0.0;
        J(0, 1) = 1.0;

        J(1, 0) = -(2.0 * y[0] * y[1] + 1.0) / mu;
        J(1, 1) = (1.0 - y[0] * y[0]) / mu;

        return J;
    }

    double mu;
};

int calculate(FEM& BodyA, FEM& BodyB)
{
    vdpol V(1.0);
    double t0 = 0.0;             // Initial time
    double t1 = 3000.0;          // Final time
    arma::vec Y0 = { 2.0, 0.0 }; // Initial vector
    // erk is a good place to start. If your problem is stiff, you will find out.
    auto sol = erk::odeint(V, t0, t1, Y0);
    std::cerr << "Solving took " << sol.elapsed_time << " ms.\n";
    // Write the solution to stdout:
    std::size_t Nt = sol.t_vals.size();
    for (std::size_t nt = 0; nt < Nt; ++nt) {
        std::cout << sol.t_vals[nt];
        for (std::size_t j = 0; j < sol.y_vals[nt].size(); ++j) {
            std::cout << " " << sol.y_vals[nt](j);
        }
        std::cout << "\n";
    }

    return 0;
}