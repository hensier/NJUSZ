#include <bits/stdc++.h>
using namespace std;
long long n;
int k, ans;
set<long long> s;
long long power(int x, int y) {
    long long s = 1;
    while (y--) {
        s *= x;
        if (s > n) return -1;
    }
    return s;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("power.in", "r", stdin);
        freopen("power.out", "w", stdout);
    #endif
    scanf("%lld%d", &n, &k);
    if (k == 1) {
        printf("%lld", n);
        return 0;
    }
    s.insert(1);
    for (int b = max(k, 3); b <= log2(n); b++) {
        for (int a = 2; ; a++) {
            long long x = power(a, b);
            if (x != -1) s.insert(x);
            else break;
        }
    }
    ans = s.size();
    if (k == 2) {
        for (long long i: s) ans -= power(sqrtl(i), 2) == i;
        ans += sqrtl(n);
    }
    printf("%d", ans);
    return 0;
}