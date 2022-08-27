#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "equation.h"
#include "assertp.h"
#include "Test_equation.h"

const int ARG_NOT_FOUND = -1;
int parseArg(int argc, const char* argv[], const char* arg_to_find){
    for (int x = 1; x < argc; x++) { //i
        if (strcmp(argv[x], arg_to_find) == 0){
            return x;
        }
    }
    return ARG_NOT_FOUND;
}

int main(int argc, const char* argv[])
{
    if (parseArg(argc, argv, "--test") != ARG_NOT_FOUND) {
        if (checkOnAllTests()) {
            printf("All tests passed\n");
        }
        else {
            printf("Testing failed\n");
        }
        return 0;
    }

    printf("Enter coeficients a,b,c for equation ax^2 + bx + c = 0\n");
    double a  = NAN,
           b  = NAN,
           c  = NAN,
           x1 = NAN,
           x2 = NAN;

    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Inputs should be three correct dechimal numbers\n");
        return 0;
    }

    enum number_of_roots nroots = solveSquare(a, b, c, &x1, &x2);
    switch (nroots) {
        case ROOTS_NONE:
            printf("No solutions\n");
            break;
        case ROOTS_INFINITE:
            printf("Solution: any number\n");
            break;
        case ROOTS_ONE:
            printf("x = %lf\n", x1);
            break;
        case ROOTS_TWO:
            printf("x1 = %lf; x2 = %lf\n", x1, x2);
            break;
        default:
            printf("Something bad happened. This is a bug\n");
            break;
    }

    return 0;
}
