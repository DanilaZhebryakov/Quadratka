#include<stdio.h>
#include<math.h>
void solve_linear(float a,float b){
    if(a == 0){
        if(b == 0){
            printf("Solutions: any\n");
        }
        else{
            printf("No solutions\n");
        }
    }
    else{
        printf("Solution: %f\n", -b/a);
    }
}
int main()
{
    float a,b,c;
    scanf("%f %f %f",&a,&b,&c);
    if(a == 0){
        printf("Linear equation\n");
        solve_linear(b,c);
        return 0;
    }
    float discriminant = (b*b)-(4*a*c);
    if(discriminant < 0){
        printf("Equation has no solution\n");
    }
    else if(discriminant == 0){
        printf("Equation has one solution\n");
        printf("Solution: %f\n",-b/(2*a));
    }
    else{
        printf("Equation has two solutions\n");
        float sqrtdisc = sqrt(discriminant);
        printf("Solutions: %f; %f\n",(sqrtdisc-b)/(2*a),(-sqrtdisc-b)/(2*a));
    }
    return 0;
}

