#include <bits/stdc++.h>
#include <string>
#include <string.h>
#include <map>  
#include <stdlib.h>
#include <iostream> 
#include <stdio.h> 
#define MAXN 100005
using namespace std;
int n;
pair<int, int> a[MAXN]; //mang cac doan
// sort the segments by second element of pairs
bool cmp (pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
} 
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++)
    cin >> a[i].first >> a[i].second;
}
void solve() {
    int res = 0; //result
    int last = -1; // the end point of last chosen segment
    sort(a+1, a+n+1, cmp);
    for(int i = 1; i <= n;i++)
        if (a[i].first > last){ //not overlap
            res++;
            last = a[i].second; //chon a[i] vao loi giai hien tai
        }
    cout << res << endl;
}
int main(){
    input();
    solve();
    return 0;
}