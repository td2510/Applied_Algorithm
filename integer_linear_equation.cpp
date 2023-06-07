#include <bits/stdc++.h>
#include <string>
#include <string.h>
#include <map>  
#include <stdlib.h>
#include <iostream> 
#include <stdio.h> 
using namespace std;

int n, M, a[20], t[20], x[20], f=0, c=0;
void initT(){
    t[0] = a[0];
    for(int i = 1; i < n; i++){
        t[i] = t[i-1] + a[i];
    }
}
void solution(){
    if(f==M) c++;
}
void Try(int k){
    int v;
    int Max_v = (M - f - (t[n]-t[k]))/a[k];
    for(v = 1; v <= Max_v; v++){
        x[k] = v;
        f += a[k]*x[k];
        if(k == (n-1)){ 
            solution();
        }else{
            Try(k+1);
        }
        f-=a[k]*x[k];
    }
}
int main(){
    cin >> n >> M;
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    initT();
    Try(0);
    cout << c;
}