#include <bits/stdc++.h>
#include <string>
#include <string.h>
#include <map>  
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <functional> 
using namespace std;
const int N=1e6+1;

int n, a[N], num;
priority_queue<int> b;
std::string type;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b.push(a[i]);
    }
    do{
        cin >> type;
        if(type == "insert"){
            cin >> num;
            b.push(num);
        } else if(type == "delete-max"){
            if(!b.empty()){
                cout << b.top() << endl;
                b.pop();
            } else cout << "none" << endl;
        }
    }while(type != "*");
    return 0;
}