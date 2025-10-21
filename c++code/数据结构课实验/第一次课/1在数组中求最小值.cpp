#include <bits/stdc++.h>
using namespace std;

int ArrayMin(int a[], int n){
    int min_num = a[0];
    for(int  i = 1; i < n; i++){
        if(a[i] < min_num) min_num = a[i]; 
    }
    return min_num;
}

int main() {
	
}
