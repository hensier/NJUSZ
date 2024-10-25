#include <bits/stdc++.h>
using namespace std;
int t, cnt;
char s[1000001];
struct node {
    char c;
    int id;
    bool operator<(const node &x) const {
        return id < x.id;
    }
}; vector<node> upper, lower;
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        cnt = 0;
        upper.clear();
        lower.clear();
        for (int i = 0; s[i]; i++) {
            switch (s[i]) {
                case 'B': {
                    if (upper.size()) upper.pop_back();
                    break;
                }
                case 'b': {
                    if (lower.size()) lower.pop_back();
                    break;
                }
                default: {
                    if (isupper(s[i])) upper.push_back((node){s[i], ++cnt});
                    else lower.push_back((node){s[i], ++cnt});
                }
            }
        }
        while (lower.size()) {
            upper.push_back(lower.back());
            lower.pop_back();
        }
        sort(upper.begin(), upper.end());
        for (int i = 0; i < upper.size(); i++) putchar(upper[i].c);
        putchar('\n');
    }
    return 0;
}