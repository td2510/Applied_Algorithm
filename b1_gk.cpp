#include <bits/stdc++.h>
#include <string>
#include <string.h>
#include <map>  
#include <stdlib.h>
#include <iostream> 
using namespace std;
const int N=1e6+1;

int n, k, m, a[N];
int cur = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < (n - k); i++){
        int temp = 0;
        for(int j = i; j <= (i + k); j++)
            temp += a[j];
        if(temp = m) cur++;
    }
    cout << cur;
    return 0;
}