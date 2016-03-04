#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long calc_fib_last_digit(long n) {
    if (n == 0) 
       return 0; 
    long Fn, Fn1, temp;
    Fn = 1;
    Fn1 = temp = 0; 
    int i ;
    for ( i = 1; i <  n; ++i) {
        temp = Fn ;
        Fn = (Fn1 + Fn) % 10;
        Fn1 = temp;
    } 
    return Fn;
}

int main() {
    long n = 0;
    long fib;
    char buffer[100];
    fgets(buffer, 100, stdin);
    n = atol(buffer);
    fib = calc_fib_last_digit(n);
    printf("%ld\n", fib); 
    return 0;
}
