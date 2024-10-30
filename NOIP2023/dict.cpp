#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[3001], t[3001], T[3001];
int main() {
    #ifndef ONLINE_JUDGE
        freopen("dict.in", "r", stdin);
        freopen("dict.out", "w", stdout);
    #endif
    cin >> n >> m;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
        t[i] = s[i];
        reverse(t[i].begin(), t[i].end());
        T[i] = t[i];
    }
    sort(T + 1, T + n + 1);
    for (int i = 1; i <= n; i++) {
        if (t[i] != T[1]) cout << (s[i] < T[1]);
        else cout << (s[i] < T[2]);
    }
    return 0;
}