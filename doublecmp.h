#ifndef DOUBLECMP_H_INCLUDED
#define DOUBLECMP_H_INCLUDED

const double eps = 0.0001;
//! checks if argument is closer to 0 then eps
//! @param [in] n number to compare (double)
//! @return true if n is close enough to 0
bool zeroEps(double n);

#endif // DOUBLECMP_H_INCLUDED
