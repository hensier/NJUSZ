// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/567353/submission/292577247
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int n, k, ans, w[11], f[3001][3001][2];
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
    read(n), read(k);
    memset(f, ~0x3f, sizeof(f));
    f[0][0][0] = 0;
    for (int i = 1, p; i <= n; i++) {
        read(p);
        for (int j = 1; j <= p; j++) read(w[j]);
        for (int j = 0; j <= k; j++) {
            f[i][j][0] = f[i-1][j][0];
            f[i][j][1] = f[i-1][j][1];
            if (j >= p) {
                f[i][j][0] = max(f[i][j][0], f[i-1][j-p][0] + w[p]);
                f[i][j][1] = max(f[i][j][1], f[i-1][j-p][1] + w[p]);
            }
            for (int l = 1; l <= j && l < p; l++) f[i][j][1] = max(f[i][j][1], f[i-1][j-l][0] + w[l]);
        }
    }
    for (int i = 0; i <= k; i++) ans = max(ans, f[n][i][0]);
    ans = max(ans, f[n][k][1]);
    printf("%d", ans);
    return 0;
}