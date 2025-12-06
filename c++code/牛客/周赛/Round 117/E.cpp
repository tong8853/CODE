#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define PII pair<int, int>
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, m, k;

void solve(){
    cin >> n >> m >> k;
    int x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    vector<PII> ans(k);
    int tep = 0;//最少需要的步数
    while(dx >= 2 && dy >= 1 || dx >= 1 && dy >= 2){
        if(dx >= dy) dx -= 2, dy -= 1;
        else dy -= 2, dx -= 1;
        tep++;
    }
    if(dx + dy == 1) tep += 3;
    if(dx + dy == 2) tep += 2;
    if(tep > k){
        cout << "No" << endl;
        return;
    }
    if((k - tep) % 2){
        cout << "No" << endl;
        return;
    }
    



}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;//cin >> T;
    while(T--)solve();
}