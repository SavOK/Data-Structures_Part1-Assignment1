#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  MIN(a,b) (((a)<(b))?(a):(b))
#define  MAX(a,b) (((a)>(b))?(a):(b))

/*! 
 * \brief Calculate  GCD
 *
 * Recursive implementation of Euclidean algorithm to find Greatest Common Denominator(GCD) between numbers A and B
 * \param[in] A (long)
 * \param[in] B (long)
 * \return  GCD (long)
 * */
long gcd(long A, long B) {
    if (A == 0) 
        return A; 
    else
        return gcd(B, A % B);
}

int main() {
    long a, b, GCD;
    int K = scanf("%ld %ld", &a, &b);
    if ( K != 2) 
        return 1;
    GCD = gcd(MAX(a, b), MIN(a, b)); 
    printf("%ld\n", GCD);
    return 0;
}
