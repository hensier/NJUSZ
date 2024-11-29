// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/550514/submission/287598749
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int k;
int main() {
    scanf("%d", &k);
    printf("%d\n", k * 2);
    for (int i = 1; i <= k * 2; i++) printf("%d %d\n", i, i);
    return 0;
}