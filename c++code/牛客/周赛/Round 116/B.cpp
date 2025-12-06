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
    int l1, r1, l2, r2;cin >> l1 >> r1 >> l2 >> r2;
    if(l2 < l1 && r1 < r2 || l1 < l2 && r2 < r1) cout << "A" << endl;
    else if(r1 < l2 || l1 > r2) cout << "B" << endl;
    else cout << "C" << endl; 
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}