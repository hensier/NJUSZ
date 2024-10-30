#include <bits/stdc++.h>
using namespace std;
int T, M, a, b, c, delta, sqrtd;
int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
int msf(int x) {
    for (int i = sqrt(x); i >= 2; i--) {
        if (x % (i * i) == 0) {
            return i;
        }
    }
    return 1;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("uqe.in", "r", stdin);
        freopen("uqe.out", "w", stdout);
    #endif
    scanf("%d%d", &T, &M);
    while (T--) {
        scanf("%d%d%d", &a, &b, &c);
        delta = b * b - 4 * a * c;
        sqrtd = sqrt(delta);
        if (delta < 0) puts("NO");
        else if (sqrtd * sqrtd == delta) {
            int numer = -b + (a > 0 ? sqrtd : -sqrtd), denom = 2 * a;
            if ((numer < 0) ^ (denom < 0) && numer != 0) putchar('-');
            numer = abs(numer);
            denom = abs(denom);
            int g = gcd(numer, denom);
            numer /= g;
            denom /= g;
            if (denom == 1) printf("%d\n", numer);
            else printf("%d/%d\n", numer, denom);
        }
        else {
            int n1 = -b, d1 = 2 * a, n2 = msf(delta), d2 = abs(2 * a);
            if (n1 != 0) {
                if ((n1 < 0) ^ (d1 < 0)) putchar('-');
                n1 = abs(n1);
                d1 = abs(d1);
                int g1 = gcd(n1, d1);
                n1 /= g1;
                d1 /= g1;
                if (d1 == 1) printf("%d+", n1);
                else printf("%d/%d+", n1, d1);
            }
            delta /= n2 * n2;
            int g2 = gcd(n2, d2);
            n2 /= g2;
            d2 /= g2;
            if (d2 == 1) {
                if (n2 == 1) printf("sqrt(%d)\n", delta);
                else printf("%d*sqrt(%d)\n", n2, delta);
            }
            else if (n2 == 1) printf("sqrt(%d)/%d\n", delta, d2);
            else printf("%d*sqrt(%d)/%d\n", n2, delta, d2);
        }
    }
    return 0;
}