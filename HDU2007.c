/*************************************************************************
	> File Name: 2007.c
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年11月03日 星期六 10时19分02秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, m;
    int temp;
    long long int sum1 = 0, sum2 = 0;
    while(scanf("%d %d", &n, &m) != EOF) {
    	if(n > m) {
    	    int temp = n;
    	    n = m;
    	    m = temp;
    	}
        for(int i = n; i <= m; i++) {
            if(i % 2 == 0) {
                sum1 += i * i;
            } else {
                sum2 += i * i * i;
            }
        }
        printf("%lld %lld\n", sum1, sum2);
        sum1 = sum2 = 0;
    }
    return 0;
}
