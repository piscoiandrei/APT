#include <iostream>
#include <string>
using namespace std;

string fibostr(string s1, string s2, int n)
{
    if(n == 0)
        return s1;
    if(n == 1)
        return s2;
    return fibostr(s1,s2,n-1) + fibostr(s1,s2,n-2);
}

int main()
{
    string s1 = "13";
    string s2 = "ab";
    cout<<fibostr(s1, s2, 20);
}
