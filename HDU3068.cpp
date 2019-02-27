/*************************************************************************
	> File Name: manacher2.cpp
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2019年01月16日 星期三 19时45分47秒
 ************************************************************************/


#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int N = 110005;
char s[N], a[N * 2];
int p[N * 2];
int len;

void manacher(char *s) {
	int l = 0;
	a[l++] = '$';
	a[l++] = '#';
	for(int i = 0; i < len; i++) {
		a[l++] = s[i];
		a[l++] = '#';
	}
	a[l] = 0;
	int id = 0, ml = 0;
	for(int i = 0; i < 2 * len + 2; i++) {
		if(p[id] + id > i) {
			p[i] = min(p[2 * id - i], p[id] + id - i);
        } else {
			p[i] = 1;
        }
		while(a[i+p[i]] == a[i-p[i]]) {
			p[i]++;
        }
        if(id+p[id] < i+p[i]) {
			id = i;
        }
		if(ml < p[i]) {
			ml = p[i];
        }
    }
	printf("%d\n", ml - 1);
} 
 
int main() {
	while(scanf("%s", s) != EOF) {
		len = strlen(s);
		manacher(s);
	}
	return 0;
}
