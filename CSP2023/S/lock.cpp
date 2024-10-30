#include <bits/stdc++.h>
using namespace std;
int n, ans, a[5], b[5], cnt[100000];
int get_id(int a[]) {
    int x = 0;
    for (int i = 0; i < 5; i++) x = x * 10 + a[i];
    return x;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("lock.in", "r", stdin);
        freopen("lock.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) scanf("%d", &a[j]);
        for (int j = 0; j < 5; j++) {
            for (int k = 1; k <= 9; k++) {
                memcpy(b, a, sizeof(a));
                b[j] = (a[j] + k) % 10;
                cnt[get_id(b)]++;
            }
        }
        for (int j = 0; j < 4; j++) {
            for (int k = 1; k <= 9; k++) {
                memcpy(b, a, sizeof(a));
                b[j] = (a[j] + k) % 10;
                b[j+1] = (a[j+1] + k) % 10;
                cnt[get_id(b)]++;
            }
        }
    }
    for (int i = 0; i < 100000; i++) ans += cnt[i] == n;
    printf("%d", ans);
    return 0;
}