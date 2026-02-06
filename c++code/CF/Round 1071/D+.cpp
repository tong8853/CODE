#include<bits/stdc++.h>
using namespace std;
#define read(st,en,a) for(int II=st;II<=en;II++) cin>>a[II]
#define up(s,e,i) for(int i=s;i<=e;i++)
#define down(s,e,i) for(int i=s;i>=e;i--) 
#define all(x) x.begin(),x.end()
#define endl '\n' 
 
namespace Main
{
    int n, a[1000010];
    int pre(int x)
    {
        up(0, n, i) if (!(x & (1 << i))) return i;
        return -1;
    }
    void solve()
    {
        cin >> n;
        int k = (1 << n);
        up(0, k - 1, i) a[i] = i;
        
        sort(a, a + k, [&](int x, int y) {
            if(pre(x) != pre(y)) return pre(x) > pre(y);
            return x < y;
        });
        up(0, k - 1, i) cout << a[i] << " ";
        cout << endl;
    }
    void main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int _;cin>>_;while(_--)solve();
    }
};

int main()
{
    Main::main();
    return 0;
}