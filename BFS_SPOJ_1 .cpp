#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,i,j,a1,a2,b1,b2,x,y,steps,tempx,tempy;
    cin>>t;
    string str1,str2;
    while(t--)
    {
        cin>>str1>>str2;
        int movex[8]={2,1,-2,-1,2,1,-2,-1};
        int movey[8]={1,2,1,2,-1,-2,-1,-2};
        a1=str1[0]-'a'+1;
        a2=str1[1]-'0';
        b1=str2[0]-'a'+1;
        b2=str2[1]-'0';
        if(a1==b1&&a2==b2)
        {
            cout<<"0"<<endl;
        }
        else
        {
            queue<ll> qx;
            queue<ll> qy;
            bool flag;
            vector<vector<ll>> visit(8),distance(8);
            for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                {
                    visit[i].push_back(0);
                    distance[i].push_back(0);
                }
            }
            qx.push(a1);
            qy.push(a2);
            visit[a1-1][a2-1]=1;
            steps=0;
            flag=true;
            while(!qx.empty()&&flag)
            {
                tempx=qx.front();
                tempy=qy.front();
                steps++;
                qx.pop();
                qy.pop();
                for(i=0;i<8;i++)
                {
                    x=tempx+movex[i];
                    y=tempy+movey[i];
                    if(x>=9||x<=0||y>=9||y<=0)
                    {
                        continue;
                    }
                    if(x==b1&&y==b2&&visit[x-1][y-1]==0)
                    {
                        distance[x-1][y-1]=distance[tempx-1][tempy-1]+1;
                        cout<<distance[x-1][y-1]<<endl;
                        flag=false;
                        break;
                    }
                    else{
                        visit[x-1][y-1]=1;
                        distance[x-1][y-1]=distance[tempx-1][tempy-1]+1;
                        qx.push(x);
                        qy.push(y);
                    }
                }
            }
        }
    }
}
