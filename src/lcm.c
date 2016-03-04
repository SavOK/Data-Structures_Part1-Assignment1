#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  MIN(a,b) (((a)<(b))?(a):(b))
#define  MAX(a,b) (((a)>(b))?(a):(b))

long gcd(long a, long b);
long lcm(long a, long b); 

long gcd(long a, long b) {
    if (b == 0)
        return a; 
    else
        return gcd(b, a % b);
}

long lcm(long a, long b) {
  return (long)(a * b) /gcd(MAX(a, b), MIN(a, b));
}

int main() {
    long a, b;
    long LCM;
    int K = scanf("%ld %ld", &a, &b);
    if ( K != 2) 
        return 1;
    LCM = lcm(a, b); 
    printf("%ld\n", LCM);
    return 0;
}
