#include <stdio.h>
#include <math.h>
using namespace std;

#define N 100
const int NIL = -1;
int lookup_table[N];

void init()
{
    for(int i=0; i<N; i++)
        lookup_table[i] = NIL;
}
int fib_mem(int n) {
    if(lookup_table[n] == NIL) {
        if(n <= 1)
            lookup_table[n] = n;
        else
            lookup_table[n] = fib_mem(n-1) + fib_mem(n-2);
    }
    return lookup_table[n];
}

double fib_golden(int n){
    return (double)fib_mem(n) / (double)fib_mem(n-1);
}

unsigned compute(int i=2)
{
    if(fabs(fib_golden(i)-fib_golden(i-1)) < 0.0000000001)
        return i;
    compute(i+1);
}

int main()
{
    init();
    printf ("phi = %.10lf\n", fib_golden(compute()));
}
