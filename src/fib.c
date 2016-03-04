#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*!
 * \brief Calculate Fibonacci Nth number
 *
 * Iterative implementation to calculate Fibonacci Nth number
 * \param[in] N Nth position in Fibonacci sequence N <= 90 (int)
 * \return Nth Fibonacci number (long)
 * */
long calc_fib(int N) {
    if (N == 0) {
       return 0; 
    }
    long Fn, Fn1, temp;
    Fn = 1;
    Fn1 = temp = 0; 
    int i ;
    for ( i = 1; i <  N; ++i) {
        temp = Fn;
        Fn = Fn1 + Fn;
        Fn1 = temp;
    } 
    return Fn;
}

int main() {
    long n = 0;
    long fib;
    char buffer[100];
    fgets(buffer, 100, stdin);
    n = atoi(buffer);
    if (n > 90) {
        return -1;
    }
    fib = calc_fib(n);
    printf("%ld\n", fib); 
    return 0;
}
