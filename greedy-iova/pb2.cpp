#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
ifstream in("rucsac.txt");

int n, g = 20;

struct Object {
    int weight;
    int profit;
};
Object arr[16], b[16];

int bkt(int n)
{
    int pmax = -1, psum, wsum;
    // try every possible subsequence of length k
   for(int k = 1; k < n; k++)
       for(int i = 0; i < n-k; i++)
        {
            psum=0;
            wsum=0;
            for(int j = i; j < i+k; j++)
                if(wsum + b[j].weight <= g)
                    wsum+=b[j].weight, psum+=b[j].profit;
            pmax = max(psum, pmax);
        }
    return pmax;
}

int greedy(int n)
{
     sort(arr, arr+n, [](const Object& lhs, const Object& rhs){
         return lhs.weight < rhs.weight;
         });

    int psum = 0, wsum = 0;
    for(int i = 0; i < n; i++)
        if(wsum + arr[i].weight <= g)
            wsum+=arr[i].weight, psum+=arr[i].profit;
    return psum;
}

int main()
{
    for(int i = 0; i < 15; i++)
    {
        in >> arr[i].weight >> arr[i].profit;
        b[i].weight = arr[i].weight;
        b[i].profit = arr[i].profit;
    }

    for(int n = 5; n <= 15; n++)
        cout << "Backtracking: " << bkt(n) << " Greedy: " << greedy(n) << '\n';
}


