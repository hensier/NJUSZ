#include <bits/stdc++.h>
using namespace std;
int n, m, ans, r[100001], R[100001];
int main() {
    #ifndef ONLINE_JUDGE
        freopen("duel.in", "r", stdin);
        freopen("duel.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
    sort(r + 1, r + n + 1);
    for (int i = 1, j = 1; i <= n; i = j) {
        for (j = i; j <= n && r[j] == r[i]; j++);
        R[++m] = j - i;
    }
    for (int i = 2, cnt = R[1]; i <= m; i++) {
        ans += min(R[i], cnt);
        cnt = max(R[i], cnt);
    }
    printf("%d", n - ans);
    return 0;
}