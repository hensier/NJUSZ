// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/567353/submission/292568493
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int n, q, cnt = 1, t[1500001][27], siz[1500001], ord[27];
long long rev[27][27];
char s[1000002];
void insert(char *s) {
    for (int i = 0, p = 1; s[i]; i++) {
        int c = s[i] - 'a' + 1;
        if (t[p][c] == 0) t[p][c] = ++cnt;
        for (int j = 0; j <= 26; j++) rev[j][c] += siz[t[p][j]];
        p = t[p][c];
        siz[p]++;
    }
}
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        int len = strlen(s);
        s[len] = 'a' - 1;
        s[len+1] = '\0';
        insert(s);
    }
    while (q--) {
        scanf("%s", s);
        for (int i = 0; i < 26; i++) ord[s[i]-'a'+1] = i + 1;
        long long ans = 0;
        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 26; j++) {
                if (ord[i] > ord[j]) {
                    ans += rev[i][j];
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}