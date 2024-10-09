// 洛谷 P3369 【模板】普通平衡树
// Submission: https://www.luogu.com.cn/record/181009043
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int n;
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
        T f = 1;
        char ch = gc();
        while (!isdigit(ch)) {
            if (ch == '-') f = -1;
            ch = gc();
        }
        while (isdigit(ch)) {
            x = (x << 3) + (x << 1) + (ch ^ 48);
            ch = gc();
        }
        x *= f;
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
    read(n);
    for (int i = 1, opt, x; i <= n; i++) {
        read(opt), read(x);
        switch (opt) {
            case 1: {
                v.insert(lower_bound(v.begin(), v.end(), x), x);
                break;
            }
            case 2: {
                v.erase(lower_bound(v.begin(), v.end(), x));
                break;
            }
            case 3: {
                write(lower_bound(v.begin(), v.end(), x) - v.begin() + 1);
                pc('\n');
                break;
            }
            case 4: {
                write(v[x-1]);
                pc('\n');
                break;
            }
            case 5: {
                write(*(lower_bound(v.begin(), v.end(), x) - 1));
                pc('\n');
                break;
            }
            case 6: {
                write(*upper_bound(v.begin(), v.end(), x));
                pc('\n');
                break;
            }
        }
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}