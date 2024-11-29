// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/533703/submission/283971215
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int l, r, ans;
int main() {
    scanf("%d%d", &l, &r);
    ans = r - l + 1;
    if (l <= 3 && r >= 3) ans--;
    if (l <= 4 && r >= 4) ans--;
    if (l <= 6 && r >= 6) ans--;
    printf("%d", ans);
    return 0;
}