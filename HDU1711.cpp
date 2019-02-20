/*************************************************************************
	> File Name: KMP.cpp
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2019年01月22日 星期二 10时45分46秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int KMP(int *str, int *pattern, int n , int m) {
    int *next = (int *)malloc(sizeof(int) * m);
    next[0] = -1;
    for(int i = 1; i < m; i++) {
        int j = next[i - 1];
        while(j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if(pattern[j + 1] == pattern[i]) next[i] = j + 1;
        else next[i] = -1;
    }
    int i = 0, j = -1;
    while(i < n) {
        while(j != -1 && str[i] != pattern[j + 1]) j = next[j];
        if(str[i] == pattern[j + 1]) {
            j += 1;
        }
        i += 1;
        if(j + 1 == m) return i - m + 1;
    }
    return -1;
} 

int str[1000005] = {0}, pattern[10005] = {0};

int main() {
    int n, k, m;
    scanf("%d", &k);
    for(int l = 0; l < k; l++) {
        scanf("%d %d", &n, &m);
        for(int j = 0; j < n; j++) {
            scanf("%d", &str[j]);
        }
        for(int j = 0; j < m; j++) {
            scanf("%d", &pattern[j]);
        }
        printf("%d\n", KMP(str, pattern, n, m));
        //printf("%d\n", Sunday(str, pattern, n, m));
        memset(str, 0, sizeof(str));
        memset(pattern, 0, sizeof(pattern));
    }
    return 0;
}
