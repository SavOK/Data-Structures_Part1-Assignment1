#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*!
 * \brief Calulates Pisano number and sequence
 *
 * Calulates the Mth Pisano period, is the period with which the sequence of Fibonacci numbers taken modulo M repeats 
 * \param[in] M Mth Pisano number (long)
 * \param[out] Pseq pointer to array where the periodic sequnce of module M stored (long**)
 * \param[out] P pointer to where  Pisano number stored (long*)
 * \return size of the array where pisano sequence stored (size_t). 
 * */

size_t pisano_sequence( long M, long* *Pseq, long* P) {
    size_t array_s = 1024;
    (*Pseq) = (long*) realloc( (*Pseq), sizeof(long) * array_s );
    long i = 0;

    long Fn, Fn1, temp, Max = 6 * M;
    Fn = 1;
    Fn1 = temp = 0; 
    (*Pseq)[0] = 0;
    (*Pseq)[1] = 1;
    for ( i = 2; i <= Max; ++i) {
        temp = Fn;
        Fn = ( Fn1 + Fn ) % M ;
        Fn1 = temp;
        if ( i  == array_s) {
            array_s += 1024;
            (*Pseq) = (long*) realloc ((*Pseq), sizeof(long) * array_s );
            if( !(*Pseq) ) {
                fprintf(stderr, "Cannot allocate memory\n");
                exit(EXIT_FAILURE);
            }
        } 
        (*Pseq)[i] = (long) (Fn % M);
        if ((*Pseq)[i-1] == 0 && (*Pseq)[i] == 1) 
            break;
    } 
    (*P) = i - 1 ; //remove last mesurment becining of the next loop
    return array_s;
}

long get_fibonaccihuge(long n, long m) {

    long *Psequence = (long*) malloc(sizeof(long));
    if( !(*Psequence) ) {
        fprintf(stderr, "Cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }
    long Pinerval; 
    long out = 0;
    pisano_sequence( m, &Psequence, &Pinerval);

    out = (long) Psequence[ (n % Pinerval)  ];
    free(Psequence);
    Psequence = NULL;
    return out;
}

int main() {
    long a, b, huge;
    scanf("%ld %ld", &a, &b);
    if ( b == 1) {
        printf("0\n");
        return 0;
    }
    huge = (long) get_fibonaccihuge(a, b);
    printf("%ld\n",huge );
    return 0;
}
