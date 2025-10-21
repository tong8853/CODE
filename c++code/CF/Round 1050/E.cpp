#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;

void solve(){
    int n, k;cin >> n >> k;
	vi a(n), cnt(n + 1), ct(n + 1);
	rep(i, 0, n - 1){
		cin >> a[i];
		cnt[a[i]]++;
	}
	rep(i, 0, n){
		if(cnt[i] % k){
			cout << 0 << endl;
			return;
		}else{
			cnt[i] /= k;
		}
	}
	int res = 0;
	for(int l = 0, r = 0; r >= l && r < n; r++){
		ct[a[r]]++;
		while(ct[a[r]] > cnt[a[r]]){
			ct[a[l]]--;
			l++;
		}
		res += (r - l + 1);
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;cin >> T;
	while(T--) solve();
}
