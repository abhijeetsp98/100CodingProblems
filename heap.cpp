#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i,n) for(i=0;i<n;i++)

typedef long long ll;
typedef long double ld;
typedef vector <long long int> vi;

int hs=20,a[21]={111,9,7,6,4,90,89,67,34,12,10,9,8,7,1,102,100,98,78,55};
void heapify(int i,int heapsize)
{
    int leftchild,rightchild,largest,temp,temp2;
    leftchild = 2*i;
    rightchild = 2*i+1;
    if ( (leftchild<=heapsize) && (a[leftchild]>a[i]))
    {
        largest=leftchild;
    }
    else
    {
        largest=i;
    }
    if( (rightchild<=heapsize) && (a[rightchild]>a[largest]))
    {
        largest=rightchild;
    }
    if(largest!=i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(largest,heapsize);
    }

}
void build_heap(int heapsize)
{
    for(int i=heapsize/2;i>=1;i--)
    {
        heapify(i,heapsize);
    }
}
int extract()
{
    int ans=a[0];
    a[0]=a[hs-1];
    hs--;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i;
    build_heap(21);
    //heapsort
    for(i=0;i<20;i++)//n complexity
    {
        cout<<extract()<<" ";//logn complexity of extract
        heapify(0,hs);
    }
}
