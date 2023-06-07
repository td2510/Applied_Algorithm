#include <bits/stdc++.h>
#include <string>
#include <string.h>
#include <map>  
#include <stdlib.h>
#include <iostream> 
#include <stdio.h> 
using namespace std;

int t, n ,c ,a[100000];

bool check(int distance){ //check xem co bo C phan tu nao thoa man khoang cach distance
    int sl = 1;// bien dem so luong phan tu duoc chon vao bo
    int i = 1, j = 2;
    while (i < n){ //thu chon tung phan tu tuwf daauf dayx
        while (j <= n && (a[j]-a[i]) < distance) ++j; //tim phan tu tiep theo
        if (j <= n) sl++; //tang bien dem so luong phan tu duoc chon vao bo
        if (sl >= c) return true;// co the lay du c phan tu, distance nay ok
        i = j;
        j++;
    }
    return false;
}
int MaxDistance(){
    int l = 0, r = a[n] - a[1];
    while (l <= r){
        int mid = (l + r)/2;
        if (check(mid)) l = mid + 1; //tiep tuc thu ket qua o nua ben phai
        else r = mid - 1; //tim ket qua o nua ben trai
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL); //tang toc
    cin >> t; //nhap so luong test
    while(t--){
        cin >> n >> c;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a+1, a+n+1);
        cout << MaxDistance() << endl;
    }
}