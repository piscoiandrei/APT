#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
ifstream in("rucsac.txt");

struct Object {
    int weight;
    int profit;
};

Object arr[10000];

int main()
{
    int n, g;
    in >> n >> g;
    for(int i = 0; i < n; i++)
        in >> arr[i].weight >> arr[i].profit;

    sort(arr, arr+n, [](const Object& lhs, const Object& rhs){
         return lhs.weight < rhs.weight;
         });
    int psum = 0, wsum = 0;
    for(int i = 0; i < n; i++)
        if(wsum + arr[i].weight <= g)
            wsum+=arr[i].weight, psum+=arr[i].profit;
    cout<<psum;
}
