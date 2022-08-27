#ifndef EQUATION_H_INCLUDED
#define EQUATION_H_INCLUDED

//! enum for number of roots of square equation (returned by all solve functions)
enum number_of_roots {
    ROOTS_INFINITE = -1,
    ROOTS_NONE     =  0,
    ROOTS_ONE      =  1,
    ROOTS_TWO      =  2
};

//! Solves linear equation ax + b = 0
//! @param [in] a a
//! @param [in] b b
//! @param [out] x pointer for where to put solution
//! @return number of solutions found
//! @note returns EQ_anyroot if solution is any number
enum number_of_roots solveLinear(double a, double b, double* const x);

//! Solves sqare equation ax^2 + bx + c = 0
//! @param [in] a a
//! @param [in] b b
//! @param [in] c c
//! @param [out] x1 pointer for where to put solution 1
//! @param [out] x2 pointer for where to put solution 2
//! @return number of solutions found
//! @note returns EQ_anyroot if solution is any number
enum number_of_roots solveSquare(double a, double b, double c, double* const x1, double* const x2);

#endif // EQUATION_H_INCLUDED
