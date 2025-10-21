#include <bits/stdc++.h>
using namespace std;

const int n = 10;
struct Person{
    char *name;
    int count;
}Leader[n];

void Election(Person Leader[], int n){
    char *name;
    cin >> name;
    while(name != "#"){
        for(int i = 0; i < n; i++){
            if(strcmp(Leader[i].name, name) == 0) Leader[i].count++;
        }
        cin >> name;
    }
    for(int i = 0; i < n; i++){
        cout << Leader[i].name << "得票数为：" << Leader[i].count << endl;
    }
}
int main() {
	
}
