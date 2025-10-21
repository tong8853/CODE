#include <bits/stdc++.h>
using namespace std;

int Find(int a[], int n, int k){
    int count = 0;
    int i;
    for(i = 0; i < n; i++){
        if(++count && a[i] == k) break;
    }
    cout << "比较次数为" << count << endl;
    return i;
}

int main() {
	
}
