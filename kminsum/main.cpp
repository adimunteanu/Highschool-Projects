#include <bits/stdc++.h>

using namespace std;

ifstream fin("kminsum.in");
ofstream fout("kminsum.out");
int n, m, k, a[1001], b[1001];
void kSmallestPair(int arr1[], int n1, int arr2[],int n2, int k)
{
    int index2[n1];
    memset(index2, 0, sizeof(index2));
    while (k > 0)
    {
        int min_sum = INT_MAX;
        int min_index = 0;
        for (int i1 = 0; i1 < n1; i1++)
        {
            if (index2[i1]<n2 && arr1[i1]+arr2[index2[i1]]<min_sum)
            {
                min_index = i1;
                min_sum = arr1[i1] + arr2[index2[i1]];
            }
        }
        cout<<arr1[min_index]<<" "<<arr2[index2[min_index]]<<'\n';
        index2[min_index]++;
        k--;
    }
}
int main()
{
    int i;
    fin>>n>>m>>k;
    for(i=0;i<n;i++)
        fin>>a[i];
    for(i=0;i<m;i++)
        fin>>b[i];
    kSmallestPair(a,n,b,m,k);
    return 0;
}
