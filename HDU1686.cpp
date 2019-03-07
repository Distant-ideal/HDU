/*************************************************************************
	> File Name: KMP.cpp
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2019年01月22日 星期二 10时45分46秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cnt = 0;

int KMP(char *str, char *pattern, int cnt) {
    int *next = (int *)malloc(sizeof(int) * strlen(pattern));
    next[0] = -1;
    for(int i = 1; pattern[i]; i++) {
        int j = next[i - 1];
        while(j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if(pattern[j + 1] == pattern[i]) next[i] = j + 1;
        else next[i] = -1;
    }
    int i = 0, j = -1;
    while(str[i]) {
        while(j != -1 && str[i] != pattern[j + 1]) j = next[j];
        if(str[i] == pattern[j + 1]) {
            j += 1;
        }
        i += 1;
        if(pattern[j + 1] == 0) cnt++;
    }
    return cnt;
} 

char str[1000005], pattern[1000005];

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        scanf("%s", pattern);
        scanf("%s", str);
        printf("%d\n", KMP(str, pattern, cnt));
    }
    return 0;
}
