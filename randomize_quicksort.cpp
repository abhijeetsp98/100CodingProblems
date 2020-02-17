#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i,n) for(i=0;i<n;i++)

typedef long long ll;
typedef long double ld;
typedef vector <long long int> vi;

int a[20]={2,8,7,1,3,5,6,4,10,23,67,45,23,78,99,100,7,3,2,20};

int part(int p,int r)
{
    int x=a[r];
    int i=p-1,temp;
    for(int j=p;j<=(r-1);j++)
    {
        if(a[j]<=x)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    return i+1;
}

int randomize_partition(int p,int r)
{
    int temp,i= ((rand()%(r-p))+p);
    temp = a[r];
    a[r] = a[i];
    a[i] = temp;
    return part(p,r);
}

quicksort(int p,int r)
{
    if (p<r)
    {
        int q = randomize_partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    quicksort(0,19);
    for(int i=0;i<20;i++)
    {
        cout<<a[i]<<" ";
    }
}
