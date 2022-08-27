#include <stdio.h>
#include <process.h>
#include <windows.h>
#include <math.h>
#define equ_res(x) ((x)*(x)*a + (x)*b + c)
const double eps = 0.00001;
const int nroots_inf = -1;
bool zero_eps(double n){
    return ((n < eps) && (n > -eps));
}
int check_nroots(double a,double b,double c){
    if(a == 0){
        if(b == 0){
            if(c == 0){
                return nroots_inf;
            }
            return 0;
        }
        return 1;
    }
    double discriminant = (b*b)-(4*a*c);
    if(discriminant < 0){
        return 0;
    }
    if(discriminant < eps){
        return 1;
    }
    return 2;
}
bool run_test(double a,double b,double c){
    FILE* input_f = fopen("input.txt","w");
    fprintf(input_f,"%lf %lf %lf\n",a,b,c);
    fclose(input_f);

    system("Quadratka.exe < input.txt > output.txt");
    Sleep(100);

    FILE* output_f = fopen("output.txt","r");
    char str[100];
    fgets(str,100,output_f);
    if(strcmp(str, "Enter coeficients a,b,c for equation ax^2 + bx + c = 0\n") != 0){
        printf("Incorrect request format");
        return false;
    }

    int nroots = check_nroots(a,b,c);
    double x1 = NAN,
           x2 = NAN;
    switch(nroots){
    case nroots_inf:
        fgets(str,100,output_f);
        if(strcmp(str,"Solution: any number\n") != 0){
            printf("Incorrect inf solutios format");
            return 0;
        }
        return 1;
    case 0:
        fgets(str,100,output_f);
        if(strcmp(str,"No solutions\n") != 0){
            printf("Incorrect no solution format");
            return 0;
        }
        return 1;
    case 1:
        if(fscanf(output_f,"x = %lf",&x1) != 1){
            printf("incorrect output format for one root\n");
            return false;
        }
        if(!zero_eps(equ_res(x1))){
            printf("x = %lf result = %lf\n",x1,equ_res(x1));
            return false;
        }
        return true;
    case 2:
        if(fscanf(output_f,"x1 = %lf; x2 = %lf\n",&x1,&x2) != 2){
            printf("incorrect output format for two roots\n");
            return false;
        }
        if(!zero_eps(equ_res(x1))){
            printf("x1 = %lf result = %lf\n",x1,equ_res(x1));
            return false;
        }
        if(!zero_eps(equ_res(x2))){
            printf("x2 = %lf result = %lf\n",x2,equ_res(x2));
            return false;
        }
        return true;
    default:
        return false;
    }

}
int main(){
    double tests[6][3] = {{0,0,0},
                      {0,0,1},
                      {0,1,1},
                      {1,-2,1},
                      {1,1,1},
                      {1,0,-1}};
    for(int i = 0;i < 6;i++){
        double a = tests[i][1],
               b = tests[i][2],
               c = tests[i][3];
        if(!run_test(a,b,c)){
            printf("Standard test failed!\na=%lf b=%lf c = %lf\n",a,b,c);
        }
    }
    for(int i = 0;i < 100;i++){
        double  a = rand()%100,
                b = rand()%100,
                c = rand()%100;
        if(!run_test(a,b,c)){
            printf("Random test failed!\na=%lf b=%lf c = %lf\n",a,b,c);
        }
    }

}
