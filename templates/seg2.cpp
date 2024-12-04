// 洛谷 P3373 【模板】线段树 2
// Submission: https://www.luogu.com.cn/record/192721485
// Time: 2024-12-04 11:11:44
#include <bits/stdc++.h>
using namespace std;
int n, q, m, a[100001];
struct node {
    int l, r;
    long long sum, add, mul;
} t[400001];
void push_up(int p) {
    t[p].sum = (t[p*2].sum + t[p*2+1].sum) % m;
}
void push_down(int p) {
    t[p*2].sum = (t[p*2].sum * t[p].mul % m + (t[p*2].r - t[p*2].l + 1) * t[p].add % m) % m;
    t[p*2+1].sum = (t[p*2+1].sum * t[p].mul % m + (t[p*2+1].r - t[p*2+1].l + 1) * t[p].add % m) % m;
    t[p*2].add = (t[p*2].add * t[p].mul % m + t[p].add) % m;
    t[p*2+1].add = (t[p*2+1].add * t[p].mul % m + t[p].add) % m;
    t[p*2].mul = t[p*2].mul * t[p].mul % m;
    t[p*2+1].mul = t[p*2+1].mul * t[p].mul % m;
    t[p].add = 0;
    t[p].mul = 1;
}
void build(int p, int l, int r) {
    t[p].l = l;
    t[p].r = r;
    t[p].mul = 1;
    if (l == r) {
        t[p].sum = a[l] % m;
        return;
    }
    int mid = (l + r) >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    push_up(p);
}
void update_add(int p, int l, int r, long long k) {
    if (t[p].l >= l && t[p].r <= r) {
        t[p].sum = (t[p].sum + (t[p].r - t[p].l + 1) * k % m) % m;
        t[p].add = (t[p].add + k) % m;
        return;
    }
    push_down(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid) update_add(p * 2, l, r, k);
    if (r > mid) update_add(p * 2 + 1, l, r, k);
    push_up(p);
}
void update_mul(int p, int l, int r, long long k) {
    if (t[p].l >= l && t[p].r <= r) {
        t[p].sum = t[p].sum * k % m;
        t[p].add = t[p].add * k % m;
        t[p].mul = t[p].mul * k % m;
        return;
    }
    push_down(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid) update_mul(p * 2, l, r, k);
    if (r > mid) update_mul(p * 2 + 1, l, r, k);
    push_up(p);
}
long long query(int p, int l, int r) {
    if (t[p].l >= l && t[p].r <= r) return t[p].sum;
    push_down(p);
    int mid = (t[p].l + t[p].r) >> 1;
    long long s = 0;
    if (l <= mid) s = (s + query(p * 2, l, r)) % m;
    if (r > mid) s = (s + query(p * 2 + 1, l, r)) % m;
    return s;
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
    read(n), read(q), read(m);
    for (int i = 1; i <= n; i++) read(a[i]);
    build(1, 1, n);
    for (int i = 1, op, x, y; i <= q; i++) {
        read(op), read(x), read(y);
        switch (op) {
            case 1: {
                long long k;
                read(k);
                update_mul(1, x, y, k % m);
                break;
            }
            case 2: {
                long long k;
                read(k);
                update_add(1, x, y, k % m);
                break;
            }
            case 3: {
                write(query(1, x, y));
                pc('\n');
                break;
            }
        }
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}