#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
const int N = 1e5 + 10;
typedef pair<int, int> PII;
vector<PII> a;

int main(){
    int n, m;
    cin >> n >> m;
    int l, r;
    for(int i = 1; i <= m; i ++){
        cin >> l >> r;
        a.push_back({l, r});
    }

    sort(a.begin(), a.end());
    int ans = 0;
    int lr = a[0].second;
    for(int i = 1; i < m; i ++){

        if(a[i].first > lr){
            ans = max(ans, a[i].first - lr - 1);
        }
        lr = max(lr, a[i].second);
    }
    ans = max(ans, a[0].first - 1);
    ans = max(ans, n - lr);

    cout << ans << endl;

    return 0;
}
