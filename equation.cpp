#include <stdio.h>
#include <math.h>

#include "assertp.h"
#include "doublecmp.h"
#include "equation.h"

enum number_of_roots solveLinear(double a, double b, double* const x){
    assertp(x != nullptr);
    assertp(std::isfinite(a));
    assertp(std::isfinite(b));

    if(zeroEps(a)){
        if(zeroEps(b)){
            return ROOTS_INFINITE;
        }
        else{
            return ROOTS_NONE;
        }
    }

    *x = -b / a;
    return ROOTS_ONE;
}

enum number_of_roots solveSquare(double a, double b, double c, double* const x1, double* const x2){
    assertp(x1 != nullptr);
    assertp(x2 != nullptr);
    assertp(x1 != x2);
    assertp(std::isfinite(a));
    assertp(std::isfinite(b));
    assertp(std::isfinite(c));

    if (zeroEps(a)) {
        return solveLinear(b, c, x1);
    }

    double discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        return ROOTS_NONE;
    }

    if (discriminant < eps) {
        *x1 = -b / (2*a);
        return ROOTS_ONE;
    }

    double sqrtdisc = sqrt(discriminant);
    *x1 = ( sqrtdisc-b) / (2*a);
    *x2 = (-sqrtdisc-b) / (2*a);
    return ROOTS_TWO;
}
