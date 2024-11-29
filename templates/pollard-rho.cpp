// 洛谷 P4718 【模板】Pollard-Rho
// Submission: https://www.luogu.com.cn/record/191450367
// Time: 2024-11-27 17:50:12
#include <bits/stdc++.h>
using namespace std;
mt19937_64 rnd(time(NULL));
int T;
long long n, ans;
const long long base[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
long long mul(long long a, long long b, long long p) {
    return (__int128_t)a * b % p;
}
long long qpow(long long a, long long b, long long p) {
    long long s = 1;
    while (b) {
        if (b % 2 == 1) s = mul(s, a, p);
        a = mul(a, a, p);
        b /= 2;
    }
    return s;
}
bool Miller_Rabin(long long n) {
    if (n % 2 == 0) return n == 2;
    int h = __builtin_ctzll(n - 1);
    long long t = (n - 1) >> h;
    for (int i = 0; i < 7; i++) {
        long long b = base[i] % n;
        if (b == 0) continue;
        long long v = qpow(b, t, n);
        if (v == 1) continue;
        bool flag = false;
        for (int j = 1; j <= h; j++) {
            if (v == n - 1) {
                flag = true;
                break;
            }
            v = mul(v, v, n);
        }
        if (!flag) return false;
    }
    return true;
}
long long f(long long x, long long c, long long p) {
    return (qpow(x, 2, p) + c) % p;
}
long long gcd(long long x, long long y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
long long Pollard_Rho(long long n) {
    long long c = rnd() % (n - 1) + 1, p = 0, q = 0;
    for (int goal = 1; ; goal *= 2, p = q) {
        long long cur = 1;
        for (int step = 0; step <= goal; step++) {
            q = f(q, c, n);
            cur = mul(cur, abs(p - q), n);
            if (step % 127 == 0) {
                long long d = gcd(cur, n);
                if (d > 1) return d;
            }
        }
    }
    return 1;
}
void solve(long long n) {
    if (n <= ans || n == 1) return;
    if (Miller_Rabin(n)) {
        ans = max(ans, n);
        return;
    }
    long long p = 1;
    while (p == 1) p = Pollard_Rho(n);
    solve(p);
    while (n % p == 0) n /= p;
    solve(n);
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        ans = 0;
        solve(n);
        if (ans == n) puts("Prime");
        else printf("%lld\n", ans);
    }
    return 0;
}