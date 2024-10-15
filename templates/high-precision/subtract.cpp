// 洛谷 P2142 高精度减法
// Submission: https://www.luogu.com.cn/record/182308404
// Time: 2024-10-15 19:18:50
#include <bits/stdc++.h>
using namespace std;
string a, b;
bool smaller(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}
string subtract(string a, string b) {
    bool neg = false;
    if (smaller(a, b)) {
        neg = true;
        swap(a, b);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; b[i]; i++) {
        a[i] -= b[i] - '0';
        if (!isdigit(a[i])) {
            a[i] += 10;
            a[i+1]--;
        }
    }
    for (int i = b.size(); a[i] && !isdigit(a[i]); i++) {
        a[i] += 10;
        a[i+1]--;
    }
    reverse(a.begin(), a.end());
    int pos = 0;
    while (a[pos+1] && a[pos] == '0') pos++;
    return neg ? ('-' + a.substr(pos)) : a.substr(pos);
}
int main() {
    cin >> a >> b;
    cout << subtract(a, b);
    return 0;
}