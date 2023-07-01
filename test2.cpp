#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> aWithIndex(n);
    for (int i = 0; i < n; i++) {
        aWithIndex[i] = make_pair(a[i], i);
    }

    sort(aWithIndex.begin(), aWithIndex.end());

    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[aWithIndex[i].second] = b[i];
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}