// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/550514/submission/286878396
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int n, ans;
vector<int> v;
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
    read(n);
    for (int i = 0, a; i < n; i++) {
        read(a);
        v.push_back(a);
    }
    for (; v.size() != 1; ans++) {
        vector<int> u;
        if (v[0] > v[1]) u.push_back(v[0]);
        for (int i = 1; i < v.size() - 1; i++) {
            if (v[i] > v[i-1] && v[i] > v[i+1]) {
                u.push_back(v[i]);
            }
        }
        if (v[v.size()-1] > v[v.size()-2]) u.push_back(v[v.size()-1]);
        v = u;
    }
    printf("%d", ans);
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}