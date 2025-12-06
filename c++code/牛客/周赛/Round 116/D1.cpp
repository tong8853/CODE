#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Point
{
    int x,y;
}s1[200010];
const int inf=2e9;
bool cmp(Point p,Point q)
{
    if(p.x<q.x)return 1;
    else if(p.x>q.x)return 0;
    else if(p.y<q.y)return 1;
    return 0;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i;
        for(i=0;i<n;i++)
        {
            cin>>s1[i].x>>s1[i].y;
        }
        sort(s1,s1+n,cmp);
        int max_x=inf,min_y=-inf;
        for(i=0;i<n;i++)
        {
            if(s1[i].x>max_x||s1[i].y<min_y)
            {
                cout<<"No\n";
                break;
            }
            max_x=min(max_x,s1[i].y);
            min_y=max(min_y,s1[i].y);
        }
        if(i==n)cout<<"Yes\n";
    }
    return 0;
}