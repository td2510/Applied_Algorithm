#include <bits/stdc++.h>
#include <string>
#include <string.h>
#include <map>  
#include <stdlib.h>
#include <iostream> 
using namespace std;

int n, a[20];
pair<int, bool> S0[20], S1[20];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if (a[0] % 2 == 0){
        S0[0].first = a[0];
        S0[0].second = true;
        S1[0].second = false;
    } else {
        S1[0].first = a[0];
        S1[0].second = true;
        S0[0].second = false;
    }
    for(int i = 1; i < n; i++){
        if (a[i] % 2 == 0){
            if(S0[i-1].second=true){
                if(S0[i-1].first > 0){
                S0[i].first=S0[i-1].first+a[i];
                } else S0[i].first = a[i];
                S0[i].second = true;
            } else {
                S0[i].first=a[i];
                S0[i].second = true;
            }
            if(S1[i-1].second=true){
                S1[i].first=S1[i-1].first+a[i];
                S1[i].second = true;
            } else {
                S1[i].second=false;
            }
        } else {
            if(S1[i-1].second=true){
                S0[i].first=S1[i-1].first+a[i];
                S0[i].second = true;
            } else {
                S0[i].second=false;
            }
            if(S0[i-1].second=true){
                if(S0[i-1].first > 0){
                S1[i].first=S0[i-1].first+a[i];
                } else S1[i].first = a[i];
                S1[i].second = true;
            } else {
                S1[i].first=a[i];
                S1[i].second = true;
            }
        }
    }
    long ans = -1e18;
    for(int i = 0; i < n; i++){
        if((S0[i].second = true) && (ans < S0[i].first)) ans = S0[i].first;
    }
    cout << ans << endl;
}