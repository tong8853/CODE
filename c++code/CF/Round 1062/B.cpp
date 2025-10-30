#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define PII pair<int, int>
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve(){
    int n;cin >> n;
    string s, t;cin >> s >> t;
    map<char, int> mp1;
    map<char, int> mp2;
    rep(i, 0, n - 1) mp1[s[i]]++; 
    rep(i, 0, n - 1) mp2[t[i]]++;
    for(auto &x : mp1){
        if(mp2[x.ff] != x.ss){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}