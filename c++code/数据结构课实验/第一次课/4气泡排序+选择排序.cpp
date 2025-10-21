#include <bits/stdc++.h>
using namespace std;

template<class T>
T BubbleSort(T r[], int n, T k){
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n - i; j++){
            if(r[j] > d[j + 1]) swap(r[j], r[j + 1]);//交换元素
        }
    }
    return r[k - 1];
}

template<class T>
T SelectSort(T r[], int n, T k){
    for(int i = 0; i < k; i++){
        index = i;
        for(int j = i + 1; j < n; j++){
            if(r[j] < r[index]) index = j;
        }
        if(index != i) swap(r[j], r[index]);//交换元素
    }
    return r[k - 1];
}

int main() {
	
}
