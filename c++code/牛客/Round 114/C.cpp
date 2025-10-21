#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    vi a(n + 1);
    map<int, int> mp;
    rep(i, 1, n){
        a[i] = s[i - 1] - '0';
        mp[a[i]]++;
    }
    if(mp[1] == 0 || mp[2] == 0 || mp[3] == 0){
        cout << -1 << endl;
        return;
    }else{
        int mx = 0;
        rep(i, 1, n - 3 + 1){
            set<int> st;
            rep(j, i, i + 2){
                st.insert(a[j]);
            }
            if(mx < st.size()) mx = st.size();
        }
        cout << 3 - mx << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}