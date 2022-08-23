#include<stdio.h>
#include<math.h>
#include<assert.h>
#include "equation.h"
int main()
{
    printf("Enter coeficients a,b,c for equation ax^2 + bx + c = 0\n");
    double a=NAN,b=NAN,c=NAN,x1=NAN,x2=NAN;
    if(scanf("%lf %lf %lf",&a,&b,&c) != 3){
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

