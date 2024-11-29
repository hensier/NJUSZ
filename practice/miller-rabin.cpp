#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
const long long base[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
long long mul(long long a, long long b, long long p) {
    long long s = 0;
    while (b) {
        if (b % 2 == 1) s = (s + a) % p;
        a = a * 2 % p;
        b /= 2;
    }
    return s;
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
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        puts(Miller_Rabin(n) ? "YES" : "NO");
    }
    return 0;
}