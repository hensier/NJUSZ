// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/547994/submission/288448247
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int t, n, cnt, fa[100001], head[100001];
bool vis[100001], leaf[100001];
char s[100001];
struct node {
    int nxt, to;
} e[199999];
void add_edge(int u, int v) {
    e[++cnt] = (node){head[u], v};
    head[u] = cnt;
}
void dfs(int u) {
    vis[u] = true;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (!vis[v]) {
            fa[v] = u;
            dfs(v);
        }
    }
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        cnt = 0;
        memset(fa, 0, sizeof(fa));
        memset(vis, false, sizeof(vis));
        memset(head, 0, sizeof(head));
        memset(leaf, true, sizeof(leaf));
        for (int i = 1, u, v; i < n; i++) {
            scanf("%d%d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        dfs(1);
        for (int i = 1; i <= n; i++) leaf[fa[i]] = false;
        scanf("%s", s + 1);
        int leaves = 0, ans = 0, cnt1[2] = {}, cnt2 = 0;
        for (int i = 2; i <= n; i++) {
            if (leaf[i]) {
                leaves++;
                if (s[i] != '?') cnt1[s[i]-'0']++;
            }
            else if (s[i] == '?') cnt2++;
        }
        if (s[1] != '?') ans = cnt1[(s[1]-'0')^1] + (leaves - cnt1[0] - cnt1[1] + 1) / 2;
        else if (cnt1[0] != cnt1[1]) ans = max(cnt1[0], cnt1[1]) + (leaves - cnt1[0] - cnt1[1]) / 2;
        else ans = cnt1[0] + (leaves - cnt1[0] - cnt1[1] + cnt2 % 2) / 2;
        printf("%d\n", ans);
    }
    return 0;
}