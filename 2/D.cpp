// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/525673/submission/284050136
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int N, K, ans, jd[1001];
int main() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) scanf("%d", &jd[i]);
    sort(jd + 1, jd + N + 1);
    for (int i = 1; i <= N; i++) {
        int pos = upper_bound(jd + i + 1, jd + N + 1, jd[i] + K) - jd - 1;
        ans = max(ans, pos - i + 1);
    }
    printf("%d", ans);
    return 0;
}