// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/533703/submission/283972433
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000000, N = sqrt(maxn);
int Q, L, R, cnt, p[447], s[maxn + 1];
bool flag[N + 1], invalid[maxn + 1];
void euler() {
    flag[1] = true;
    for (int i = 2; i <= N; i++) {
        if (!flag[i]) p[++cnt] = i;
        for (int j = 1; j <= cnt && i * p[j] <= N; j++) {
            flag[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
}
namespace IO {
    char buf[1 << 21], *p1 = buf, *p2 = buf, obuf[1 << 21], *p3 = obuf;
    char gc() {
        if (p1 == p2) {
            p1 = buf;
            p2 = buf + fread(buf, 1, 1 << 21, stdin);
        }
        return p1 == p2 ? EOF : *p1++;
    }
    template<typename T> void read(T &x) {
        x = 0;
        char ch = gc();
        while (!isdigit(ch)) ch = gc();
        while (isdigit(ch)) {
            x = (x << 3) + (x << 1) + (ch ^ 48);
            ch = gc();
        }
    }
    void pc(char c) {
        if (p3 - obuf < (1 << 21)) *p3++ = c;
        else {
            fwrite(obuf, p3 - obuf, 1, stdout);
            p3 = obuf;
            *p3++ = c;
        }
    }
    template<typename T> void write(T x) {
        if (x > 9) write(x / 10);
        pc(x % 10 + 48);
    }
} using namespace IO;
int main() {
    euler();
    invalid[1] = true;
    for (int i = 1; i <= cnt; i++) {
        for (int j = i; j <= cnt; j++) {
            int x = p[i] * p[j];
            if (x > maxn) break;
            for (int k = 2; k * x <= maxn; k++) invalid[k * x] = true;
        }
    }
    for (int i = 1; i <= maxn; i++) s[i] = s[i-1] + !invalid[i];
    read(Q);
    while (Q--) {
        read(L), read(R);
        write(s[R] - s[L-1]);
        pc('\n');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}