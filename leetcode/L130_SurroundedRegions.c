/*
    url: leetcode.com/problems/surrounded-regions
    想了各种办法，还是runtime error，不知道原因
*/

#include <stdio.h>
#include <stdlib.h>

typedef int T;
typedef struct ln sln;
typedef struct ln * pln;
typedef struct ll sll;
typedef struct ll * pll;

//list node
struct ln {
    T val;
    pln nxt;
};

//linked list
struct ll {
    pln first;
    pln last;
    int size;
};

pll ll_init() {
    pll l = (pll) malloc(sizeof(sll));
    l->first = NULL;
    l->last = NULL;
    l->size = 0;
    return l;
}

void ll_add_last(pll l, T v) {
    pln t = (pln) malloc(sizeof(sln));
    t->val = v;
    t->nxt = NULL;
    if (l->size == 0) {
        l->first = t;
        l->last = t;
        l->size = 1;
        return;
    }
    l->last->nxt = t;
    l->last = t;
    l->size ++;
}

void ll_remove_first(pll l) {
    pln t = NULL;
    if (l->first == NULL) return;
    if (l->first == l->last) {
        free(l->first);
        l->first = NULL;
        l->last = NULL;
        l->size = 0;
        return;
    }
    t = l->first->nxt;
    free(l->first);
    l->first = t;
    l->size --;
}

char** bb = NULL;
int rnrn = 0;
int cncn = 0;
pll lx = NULL, ly = NULL;

void search(int i, int j) {
    int x = 0, y = 0;
    if (bb[i][j] != 'O') return;
    lx->size = 0;
    ly->size = 0;
    ll_add_last(lx, i);
    ll_add_last(ly, j);
    while (lx->size != 0) {
        x = lx->first->val;
        y = ly->first->val;
        bb[x][y] = '1';
        ll_remove_first(lx);
        ll_remove_first(ly);
        if (x > 0) search(x-1, y);
        if (x+1 < rnrn) search(x+1, y);
        if (y > 0) search(x, y-1);
        if (y+1 < cncn) search(x, y+1);
    }
}

void solve(char** b, int rn, int cn) {
    int i = 0, j = 0;
    bb = b;
    rnrn = rn;
    cncn = cn;
    lx = ll_init ();
    ly = ll_init ();
    if (rn < 3 || cn < 3) return;
    for (i = 0; i < rn; i ++) {
        search(i, 0);
        if (b[i][cn-1] == 'O') search(i, cn-1);
    }
    for (j = 0; j < cn; j ++) {
        search(0, j);
        search(rn-1, j);
    }
    for (i = 0; i < rn; i ++) {
        for (j = 0; j < cn; j ++) {
            if (b[i][j] == 'O') {
                b[i][j] = 'X';
            } else if (b[i][j] == '1') {
                b[i][j] = 'O';
            }
        }
    }
}

int main() {
    char* b[4] = {"XXXX", "XOOX", "XXOX", "XOXX"};
    int rn = 4;
    int cn = 4;
    int i = 0, j = 0;
    char** c = (char**) malloc(sizeof(char*) * rn);
    for (i = 0; i < rn; i ++) {
        c[i] = (char*) malloc(sizeof(char) * (cn+1));
        c[i][cn] = '\0';
        for (j = 0; j < cn; j ++) {
            c[i][j] = b[i][j];
        }
    }
    solve(c, rn, cn);
    for (i = 0; i < rn; i ++) {
        printf("%s\n", c[i]);
    }
    return 0;
}