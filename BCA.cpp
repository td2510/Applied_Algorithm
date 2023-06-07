#include <bits/stdc++.h>
#include <string>
#include <string.h>
#include <map>  
#include <stdlib.h>
#include <iostream> 
#include <stdio.h> 
using namespace std;

#define N 50
vector<int> T[N];//T[i] danh sach giao vien co the day mon i
int m,n;
bool conflict[N][N];//cac mon bi trung gio
int x[N];
int load[N];//tai cua giao vien
int res;

void input(){
    cin >> m >> n;
    for(int t = 1; t <= m; t++){//nhap danh sach cac mon cho tung giao vien
        int k; 
        cin >> k;
        for(int j=1; j <= k; j++){
            int c;
            cin >> c;
            T[c].push_back(t);//danh sach giao vien day mon c
        }
    }
    int K;
    for(int i=1; i <= n; i++)
        for(int j=1; j <= n; j++)
            conflict[i][j] = false;
    cin >> K;
    for(int k=1; k <= K; k++){
        int i,j;
        cin >> i >> j;
        conflict[i][j] = true;
        conflict[j][i] = true;
    }
}
bool check(int t, int k){ //kiem tra xem giao vien t co bi trung gio day mon k voi mon nao truoc do khong
    for(int i = 1; i <= k; i++){
        if(conflict[i][k] && x[i] == t) return false;
    } // mon i trung gio mon k va giao vien t da duoc phan day mon i truoc do
    return true;
}
void solution(){
    int maxload = 0;
    for(int t = 1; t <= m; t++){ //tim tai lon nhat cua cac thanh vien
        maxload = max(maxload, load[t]);
    }
    if(maxload < res) res = maxload;
}
void Try(int k){ //T[k]: danh sach giao vien day mon k
    for(int i = 0; i < T[k].size(); i++){
        int t = T[k][i]; //gv thu i trong so nhung nguoi day mon thu k
        if (check(t, k)){//ok, khong bi trung
            x[k] = t;// assign course k to teacher t
            load[t] += 1;
            if(k == n) solution();
            else{
                if(load[t] < res) Try (k+1);
            }
            load[t] -= 1;
        }
    }
}
int main(){
    input();
    for(int t = 1; t <= m; t++) load[t] = 0;
    res = 1e9;
    Try(1);
    cout << res;
    return 0;
}