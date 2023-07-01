#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& A, const vector<int>& B) {
    int N = A.size();
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < N; i++) {
            if (A[i] > A[i + 1] && B[i] < B[i + 1]) {
                swap(A[i], A[i + 1]);
                sorted = false;
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    bubbleSort(A, B);

    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }

    return 0;
}
