#include <stdio.h>
#include <math.h>

#include "equation.h"
#include "doublecmp.h"

struct TestCase {
    double a, b, c;
    number_of_roots nroots;
    double x1, x2;
};

bool runTest(TestCase* test){
    double x1 = 0,
           x2 = 0;
    number_of_roots nroots = solveSquare(test->a, test->b, test->c, &x1, &x2);
    if (nroots != test->nroots || x1 !=  test->x1 || x2 != test->x2) {
        printf( "Test failed: a=%lf b=%lf c=%lf \n"
                "Expected %d roots, x1=%lf, x2=%lf \n"
                "Got      %d roots, x1=%lf, x2=%lf \n",
                test->a,      test->b , test->c,
                test->nroots, test->x1, test->x2,
                nroots,        x1,       x2);
        return false;
    }


    return true;
}

bool checkOnBuiltinTests(){
    printf("Checking on builtin tests\n");
    bool tests_passed = true;
    TestCase tests[] = {
                        /*a, b, c, number_of_roots, x1, x2 */
                         {0, 0, 0, ROOTS_INFINITE,  0 ,  0 },
                         {0, 0, 1, ROOTS_NONE,      0 ,  0 },
                         {0, 1, 1, ROOTS_ONE,      -1 ,  0 },
                         {1, 1, 1, ROOTS_NONE,      0 ,  0 },
                         {1,-2, 1, ROOTS_ONE,       1 ,  0 },
                         {1, 0,-1, ROOTS_TWO,       1 , -1 }};

    const int ntests = sizeof(tests) / sizeof(tests[0]);
    for (int x = 0; x < ntests; x++) {
        if (!runTest(&tests[x])) {
            printf("Builtin test %d failed\n", x);
            tests_passed = false;
        }
    }
    if(tests_passed){
        printf("All builtin tests passed\n");
    }
    return tests_passed;
}
bool checkOnTestsFromFile(const char* filename){
    printf("Checking on tests from file %s\n", filename);
    bool tests_passed = true;
    FILE* tests_file = fopen(filename, "r");

    if(tests_file == nullptr){
        printf("Can not open target file. File specified incorrectly or does not exist\n");
        return false;
    }

    int test_count = 0, test_n = 0;
    if(fscanf(tests_file, "N%d", &test_count) != 1){
        printf("Can not read number of tests. File is empty or corrupted\n");
        return false;
    }

    TestCase test = {0, 0, 0, ROOTS_INFINITE, 0, 0};
    while(fscanf(tests_file, " a=%lf b=%lf c=%lf nr=%d x1=%lf x2=%lf", &test.a, &test.b, &test.c, (int*)&test.nroots, &test.x1, &test.x2) == 6){
        if(!runTest(&test)){
            tests_passed = false;
            printf("File test %d failed\n", test_n);
        }
        test_n++;
    }

    if(test_n != test_count){
        printf("Number of tests found in file does not match the count declared in it. Declared: %d, Found: %d\n", test_count, test_n);
        return 0;
    }
    if(tests_passed){
        printf("File tests passed\n");
    }

    return tests_passed;
}

bool checkOnAllTests(){
    checkOnBuiltinTests();
    checkOnTestsFromFile("tests.txt");
}
