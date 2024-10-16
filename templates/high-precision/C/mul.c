// 洛谷 P1303 A*B Problem
// Submission: https://www.luogu.com.cn/record/182417896
// Time: 2024-10-16 10:09:05
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char a[2001], b[2001], ADD[4001], EMUL[4001], MUL[4001];
void reverse(char *s, int len) {
    for (char *l = s, *r = s + len - 1; l < r; l++, r--) {
        char t = *l;
        *l = *r;
        *r = t;
    }
}
void swap(char *x, char *y) {
    char t[4001];
    strcpy(t, x);
    strcpy(x, y);
    strcpy(y, t);
}
void append(char *s, int ls, char c) {
    s[ls] = c;
    s[ls+1] = '\0';
}
char *add(char *a, char *b) {
    strcpy(ADD, a);
    if (strlen(ADD) < strlen(b)) swap(ADD, b);
    int la = strlen(ADD), lb = strlen(b);
    reverse(ADD, la);
    reverse(b, lb);
    for (int i = 0; b[i]; i++) {
        ADD[i] += b[i] - '0';
        if (!isdigit(ADD[i])) {
            ADD[i] -= 10;
            if (la == lb && i == lb - 1) append(ADD, la++, '1');
            else ADD[i+1]++;
        }
    }
    for (int i = lb; ADD[i] && !isdigit(ADD[i]); i++) {
        ADD[i] -= 10;
        if (i == la - 1) append(ADD, la++, '1');
        else ADD[i+1]++;
    }
    reverse(ADD, la);
    return ADD;
}
char *easy_mul(char *a, char b) {
    strcpy(EMUL, a);
    int la = strlen(EMUL), tmp = 0;
    reverse(EMUL, la);
    for (int i = 0; EMUL[i]; i++) {
        int x = (EMUL[i] - '0') * (b - '0') + tmp;
        EMUL[i] = x % 10 + '0';
        tmp = x / 10;
    }
    if (tmp) append(EMUL, la++, tmp + '0');
    reverse(EMUL, la);
    return EMUL;
}
char *mul(char *a, char *b) {
    memset(MUL, 0, sizeof(MUL));
    MUL[0] = '0';
    char t1[4001];
    strcpy(t1, a);
    for (int i = strlen(b) - 1; i >= 0; i--) {
        char t2[4001];
        strcpy(t2, MUL);
        strcpy(MUL, add(t2, easy_mul(t1, b[i])));
        append(t1, strlen(t1), '0');
    }
    int pos = 0;
    while (MUL[pos+1] && MUL[pos] == '0') pos++;
    char t[4001];
    strncpy(t, MUL + pos, strlen(MUL) - pos);
    strcpy(MUL, t);
    return MUL;
}
int main() {
    scanf("%s%s", a, b);
    printf("%s", mul(a, b));
    return 0;
}