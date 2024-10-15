// 洛谷 P1601 A+B Problem（高精）
// Submission: https://www.luogu.com.cn/record/180309626
// Time: 2024-10-05 21:34:42
#include <bits/stdc++.h>
using namespace std;
string a, b;
string add(string a, string b) {
    if (a.size() < b.size()) swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; b[i]; i++) {
        a[i] += b[i] - '0';
        if (!isdigit(a[i])) {
            a[i] -= 10;
            if (a.size() == b.size() && i == b.size() - 1) a += '1';
            else a[i+1]++;
        }
    }
    for (int i = b.size(); a[i] && !isdigit(a[i]); i++) {
        a[i] -= 10;
        if (i == a.size() - 1) a += '1';
        else a[i+1]++;
    }
    reverse(a.begin(), a.end());
    return a;
}
int main() {
    cin >> a >> b;
    cout << add(a, b);
    return 0;
}