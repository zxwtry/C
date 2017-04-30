/*
    url: leetcode.com/problems/distinct-subsequences
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _max(int a, int b, int c) {
    if (a > b) return _max(b,a,c);
    return b < c ? c : b;
}

int numDistinct(char* s, char* t) {
    int sn = s == NULL ? 0 : strlen(s);
    int tn = t == NULL ? 0 : strlen(t);
    int i = 0, j = 0, ans = 0;
    int** m = (int**) malloc(sizeof(int*) * (sn+1));
    for (i = 0; i <= sn; i ++) {
        m[i] = (int*) malloc(sizeof(int) * (tn+1));
        for (j = 0; j <= tn; j ++) m[i][j] = 0;
    }
    for (i = 0; i < sn; i ++) {
        for (j = 0; j < tn; j ++) {
            if (s[i] == t[i]) {
                m[i+1][j+1] = _max(m[i][j], m[i][j+1]+1, m[i+1][j]+1);
            } else {
                m[i+1][j+1] = _max(m[i][j], m[i][j+1], m[i+1][j]);
            }
        }
    }
    ans = m[sn][tn];
    for (i = 0; i <= sn; i ++) free(m[i]);
    free(m);
    return ans;
}

int main() {
    char* s = "rabbbit";
    char* t = "rabbit";
    printf("%d\r\n", numDistinct(s, t));
}