#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
typedef long long ll;

const int N = 1005;
int pre[N];
int high[N];

//一般来说，一个并查集对应三个操作：
//1、初始化（ Init()函数 ）
//2、查找函数（ Find()函数 ）
//3、合并集合函数（ Join()函数 ）

void init(int n){
    rep(i, 0, N - 1){
        pre[i] = i;//每个节点的上级都是自己
        high[i] = 1;//每个节点构成的树的高度为1
    }
}
int find_1(int x){//只查找，不进行路径压缩，故递归过程中不需要完成路径压缩
    if(pre[x] == x) return x; //递归出口： x的上级是x本身，则x为根节点
    return find_1(pre[x]); //递归查找
}
int find_2(int x){ //改进查找算法：查找根节点的同时完成路径压缩
    if(pre[x] = x) return x; //x为根节点，直接返回
    return pre[x] = find_2(pre[x]); //该代码
}
bool isSame(int x, int y){ //判断两节点是否联通
    return find_1(x) == find_1(y);
}
//
bool unite(int x, int y){
    x = find_1(x); //此时的x为原来x的根节点
    y = find_1(y);
    if(x == y) return false;// 如果root节点相同，则说明二者连通，不需要合并
    if(high[x] > high[y]) pre[y] = x;//  把 y 接在 x 上
    else{
        pre[x] = y;
        if(high[x] == high[y]) high[y]++;
    }
}

void solve(){
    
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
