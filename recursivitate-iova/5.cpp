#include <iostream>
using namespace std;
unsigned hexa(unsigned n, unsigned p=1)
{
    if(!n)
        return 0;
    return (n%10)*p + hexa(n/10, p*16);
 }

 int main()
 {
     cout<<hexa(312);
 }
