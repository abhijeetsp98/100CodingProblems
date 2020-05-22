#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i=0;i<n;i++)
typedef long long ll;
typedef long double ld;
typedef vector <long long int> vi;

vector< vector< pair<int,int> > > adj;
vector<int> p,d;
void dj(int s)
{
		int i,u,v,uw,dv;
		pair<int,int> pa;
		d[s]=0;
		priority_queue< pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > q;
		q.push({0,s});   //distance and node repectively
		while(!q.empty())
		{
			pa=q.top();
			v = pa.second;
			dv = pa.first;
			q.pop();
				
			if(dv != d[v]) // we want to skip the node which are already at their minimum distance from source
				continue;

			for(i=0;i<adj[v].size();i++)
			{
				u = adj[v][i].first;
				uw = adj[v][i].second;
				
				if(	d[u] > d[v] + uw )
				{
					d[u] = d[v] +uw;
					p[u] = v;
					q.push({d[u],u});
				}
			}
		}
}

void read(int n , int e)
{
	int a,b,c;
	adj.resize(n+1);
	p.resize(n+1,-1);
	d.resize(n+1,INT_MAX);
	for(int i=0;i<e;i++)
	{
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
}
void solve()
{
    int i,a,b,j,k,temp,v;
    cin>>a>>b;
    read(a,b);
    dj(1);
    cout<<d[a]<<" ";
    // p has parent of node and d has distance of each node
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
