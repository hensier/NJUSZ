// 洛谷 P5043 【模板】树同构（[BJOI2015]树的同构）
// Submission: https://www.luogu.com.cn/record/190258502
// Time: 2024-11-21 22:25:24
#include <bits/stdc++.h>
using namespace std;
int M, N, cnt, head[51], siz[51], cen[2];
pair<unsigned long long, unsigned long long> h;
map<pair<unsigned long long, unsigned long long>, int> mp;
const unsigned long long mask = mt19937_64(time(nullptr))();
struct node {
    int nxt, to;
} e[99];
void add_edge(int u, int v) {
    e[++cnt] = (node){head[u], v};
    head[u] = cnt;
}
unsigned long long shift(unsigned long long x) {
    x ^= mask;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= mask;
    return x;
}
void dfs1(int u, int fa) {
    siz[u] = 1;
    int w = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v != fa) {
            dfs1(v, u);
            siz[u] += siz[v];
            w = max(w, siz[v]);
        }
    }
    w = max(w, N - siz[u]);
    if (w <= N / 2) {
        if (cen[0] == 0) cen[0] = u;
        else cen[1] = u;
    }
}
unsigned long long dfs2(int u, int fa) {
    unsigned long long h = 1;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v != fa) h += shift(dfs2(v, u));
    }
    return h;
}
int main() {
    scanf("%d", &M);
    for (int id = 1; id <= M; id++) {
        scanf("%d", &N);
        cnt = 0;
        memset(head, 0, sizeof(head));
        for (int i = 1, fa; i <= N; i++) {
            scanf("%d", &fa);
            if (fa != 0) {
                add_edge(fa, i);
                add_edge(i, fa);
            }
        }
        for (int i = 0; i < 2; i++) cen[i] = 0;
        dfs1(1, 0);
        h.first = dfs2(cen[0], 0);
        if (cen[1] != 0) {
            h.second = dfs2(cen[1], 0);
            if (h.first > h.second) swap(h.first, h.second);
        }
        else h.second = h.first;
        if (mp.find(h) == mp.end()) mp[h] = id;
        printf("%d\n", mp[h]);
    }
    return 0;
}