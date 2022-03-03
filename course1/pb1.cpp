#include <fstream>
std::ifstream in("in.in");
std::ofstream out("out.out");

#define BLEN 8
#define BYTE uint8_t
#define N 126

BYTE arr[N];
void putIn(unsigned val)
{
    arr[val/BLEN] |= (1u << (BLEN - val%BLEN - 1));
}

void printData()
{
    for(unsigned i = 0; i < N; i++)
        for(unsigned j = BLEN - 1, k = 0; j >= 0 && k < BLEN; j--, k++)
            if(arr[i] & (1u << j))
                out << BLEN*i + k << ' ';
}

int main()
{
    unsigned x;
    while(in >> x)
        putIn(x);
    printData();
}
