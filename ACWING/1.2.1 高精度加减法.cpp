#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6 + 10;

// C = A + B;
vector<int> add(const vector<int> &A, const vector<int> &B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size())
            t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t)
        C.push_back(1);
    return C;
}


//判断是否有A>=B
bool cmp(const vector<int> &A, const vector<int> &B) {
    if (A.size() != B.size())
        return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i]) {
            return A[i] > B[i];
        }
    }
    return true;
}

// C=A-B
vector<int> sub(const vector<int> &A, const vector<int> &B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0)
            t = 1;
        else
            t = 0;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}



int main() {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');
    //auto C = add(A,B);
    //for (int i = C.size() - 1; i < C.size(); i--) cout << C[i];
    if (cmp(A, B)) {
        auto D = sub(A, B);
        for (int i = D.size() - 1; i >= 0; i--)
            cout << D[i];
    } else {
        auto D = sub(B, A);
        printf("-");
        for (int i = D.size() - 1; i >= 0; i--)
            cout << D[i];
    }
}