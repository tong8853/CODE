#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	set<pair<int, int>> s;
	vector<pair<int, int>> a(n);

	for (auto &[x, y] : a) {
		cin >> x >> y;
		s.insert({x, y});
	}

	ll ans = 0;

	{
		map<int, vector<int>> mp;
		for (auto [x, y] : a) {
			mp[x].push_back(y);
		}
		for (auto [x, f] : mp) {
			int cnt = 0;
			for (auto y : f) {
				if (s.contains({x - 1, y})) {
					ans += cnt;
					cnt++;
				}
			}
		}
	}

	{
		map<int, vector<int>> mp;
		for (auto [x, y] : a) {
			mp[y].push_back(x);
		}
		for (auto [y, f] : mp) {
			int cnt = 0;
			for (auto x : f) {
				if (s.contains({x, y - 1})) {
					ans += cnt;
					cnt++;
					if (s.contains({x - 1, y}) && s.contains({x - 1, y - 1})) {
						ans--;
					}
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}