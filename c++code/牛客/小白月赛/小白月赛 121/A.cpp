#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

map<char, int> mp;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    string tar = "Kato_Shoko";
    rep(i, 0, n - 1){
        mp[s[i]]++;
    }
    if(mp['K'] < 1 || mp['k'] < 1 || mp['a'] < 1 || mp['t'] < 1 || mp['o'] < 3 || mp['S'] < 1 || mp['h'] < 1 || mp['_'] < 1){
        cout << "NO" << endl;
    }else{
        cout << "YES ";
        cout << n - 10 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}