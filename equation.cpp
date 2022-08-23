#include<stdio.h>
#include<math.h>
#include<assert.h>
const int EQ_anyroot = -1;

int solveLinear(double a,double b,double* const x){
    assert(x);
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    if(a == 0){
        if(b == 0){
            return EQ_anyroot;
        }
        else{
            return 0;
        }
    }
    else{
        *x = -b/a;
        return 1;
    }
}

int solveSqare(double a,double b,double c,double* const x1,double* const x2){
    assert(x1);
    assert(x2);
    assert(x1 != x2);
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));
    if(a == 0){
        return solveLinear(b,c,x1);
    }
    float discriminant = (b*b)-(4*a*c);
    if(discriminant < 0){
        return 0;
    }
    else if(discriminant == 0){
        *x1 = -b/(2*a);
        return 1;
    }
    else{
        float sqrtdisc = sqrt(discriminant);
        *x1 = (sqrtdisc-b)/(2*a);
        *x2 = (-sqrtdisc-b)/(2*a);
        return 2;
    }
}
