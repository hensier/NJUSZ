// 洛谷 P1303 A*B Problem
// Submission: https://www.luogu.com.cn/record/182311294
// Time: 2024-10-15 19:26:36
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
string easy_mul(string a, char b) {
    reverse(a.begin(), a.end());
    int tmp = 0;
    for (int i = 0; a[i]; i++) {
        int x = (a[i] - '0') * (b - '0') + tmp;
        a[i] = x % 10 + '0';
        tmp = x / 10;
    }
    if (tmp) a += (tmp + '0');
    reverse(a.begin(), a.end());
    return a;
}
string mul(string a, string b) {
    string ans = "0";
    for (int i = b.size() - 1; i >= 0; i--) {
        ans = add(ans, easy_mul(a, b[i]));
        a += "0";
    }
    int pos = 0;
    while (ans[pos+1] && ans[pos] == '0') pos++;
    return ans.substr(pos);
}
int main() {
    cin >> a >> b;
    cout << mul(a, b);
    return 0;
}