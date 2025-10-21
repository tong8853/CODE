#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
typedef vector<int> vi;

vi KMPsearchAll(const string &text, const string &pattern){
    vi pos; // 存储所有匹配的起始位置
    int n = pattern.size();
    int m = text.size();

    // step1: 构建LPS数组
    vi LPS(n);  //LPS数组要求前后缀不能是子串本身
    int j = 0; //最长相等前后缀长度
    int i = 1;  ////因为LPS[0]固定为0，所以下标从1开始
    while(i < n){
        if(pattern[i] == pattern[j]){
            j++;
            LPS[i] = j;
            i++;
        }else{
            if(j != 0) j = LPS[j - 1];
            else{
                LPS[i] = 0;
                i++;
            }
        }
    }

    // Step2 : 查找所有匹配的子串
    i = 0;
    j = 0;
    while(i < m){
        if(text[i] == pattern[j]){
            i++;
            j++;
            //完全匹配
            if(j == n){
                int start_pos = i - j;
                pos.pb(start_pos);

                //重置j, 继续查找下一个匹配
                j = LPS[j - 1];
            }
        }else{
            if(j != 0){
                j = LPS[j - 1];
            }else{
                i++;
            }
        }
    }
}

void solve(){
    string a, b;cin >> a >> b;
    vi pos = KMPsearchAll(a, b);
    if(pos.empty()) cout << -1 << endl; // 返回-1
    else{
        // 打印所有pos
        for(auto i : pos) cout << i << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T;cin >> T;
    while(T--)solve();
}