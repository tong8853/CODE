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

// 判断是否为合法日期
bool isValidDate(int y, int m, int d) {
    if (y < 1 || m < 1 || m > 12 || d < 1) return false;

    // 每月天数（非闰年）
    vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 闰年二月多一天
    if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) {
        days[2] = 29;
    }

    return d <= days[m];
}

void solve() {
    int begin, end;
    cin >> begin >> end;
    int y1 = begin / 10000, m1 = (begin / 100) % 100, d1 = begin % 100;
    int y2 = end   / 10000, m2 = (end   / 100) % 100, d2 = end   % 100;
    int count = 0;
    rep(yy, y1, y2) {
        // 构造月份 mm：yy 的数字反转前两位 → mm = d2d1 (如 2021 → mm=12)
        int mm = (yy % 10) * 10 + (yy / 10 % 10);
        // 构造日期 dd：yy 的前两位反转 → dd = cba → 如 2021 → dd=02 → 即 20
        int dd = (yy / 100 % 10) * 10 + (yy / 1000);
        // 必须是合法日期
        if (!isValidDate(yy, mm, dd)) continue;
        // 转换为整数格式 yyyymmdd
        int date = yy * 10000 + mm * 100 + dd;
        // 必须在 [begin, end] 范围内
        if (date < begin || date > end) continue;
        count++;
    }
    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}