/*************************************************************************
	> File Name: 16.trie.cpp
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年12月30日 星期日 20时38分45秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE_CNT 26
#define BASE 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE_CNT];
} Node;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < BASE_CNT; i++) {
        p->next[i] = NULL;
    }
    p->flag = 0;
    return p;
}

void insert(Node *node, const char *str) {
    Node *p = node;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            p->next[str[i] - BASE] = getNewNode();
        }
        //p->flag += 1;
        p = p->next[str[i] - BASE];
        p->flag += 1;
    }
    //p->flag = 1;
    return ;
}

int search(Node *node, const char *str) {
    Node *p = node;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            return 0;
        }
        p = p->next[str[i] - BASE];
    }
    return p->flag;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE_CNT; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

char str[100];

int main() {
    Node *root = getNewNode();
    int op;
    while(gets(str)) {
        if (strcmp(str, "") == 0) {
            break;
        }
        insert(root, str);
    }
    while(scanf("%s", str) != EOF) {
        printf("%d\n", search(root, str));
    }
    clear(root);
    return 0;
}
