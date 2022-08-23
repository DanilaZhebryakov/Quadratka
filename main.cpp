#include<stdio.h>
#include<math.h>
#include<assert.h>
const int EQ_anyroot = -1;

int solveLinear(double a,double b,double* x){
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
int solveSqare(double a,double b,double c,double* x1,double* x2){
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
int main()
{
    printf("Enter coeficients a,b,c for equation ax^2 + bx + c = 0\n");
    double a=NAN,b=NAN,c=NAN,x1=NAN,x2=NAN;
    scanf("%lf %lf %lf",&a,&b,&c);
    if(!(std::isfinite(a) && std::isfinite(b) && std::isfinite(c))){
        printf("Inputs should be three correct dechimal numbers\n");
        return 0;
    }
    int nroots = solveSqare(a,b,c,&x1,&x2);
    switch(nroots){
    case 0:
        printf("No solutions\n");
        break;
    case EQ_anyroot:
        printf("Solution: any number\n");
        break;
    case 1:
        printf("x = %lf\n",x1);
        break;
    case 2:
        printf("x1 = %lf; x2 = %lf\n",x1,x2);
        break;
    }
    return 0;
}

