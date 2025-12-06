#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

vector<int> p10(12);
unordered_map<int, int> mpa;
unordered_map<int, int> mpb;
void init(){
    p10[0] = 1;
    rep(i, 1, 11) p10[i] = (p10[i - 1] * 10) % 11;
}
void solve(){
    init();
    int n;cin >> n;
    vll a(n), sz(n);
    
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}