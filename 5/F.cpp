// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/535298/submission/285153211
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000000;
int t, c, d[maxn + 1], invd[maxn + 1];
void init() {
    for (int i = 1; i * i <= maxn; i++) {
        d[i*i] += i;
        for (int j = i + 1; i * j <= maxn; j++) d[i*j] += i + j;
    }
    for (int i = 1; i <= maxn; i++) {
        if (d[i] <= maxn && !invd[d[i]]) {
            invd[d[i]] = i;
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
        if (x < 0) {
            pc('-');
            x = -x;
        }
        if (x > 9) write(x / 10);
        pc(x % 10 + 48);
    }
} using namespace IO;
int main() {
    init();
    read(t);
    while (t--) {
        read(c);
        write(invd[c] ? invd[c] : -1);
        pc('\n');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}