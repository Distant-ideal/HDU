/*************************************************************************
	> File Name: 2014.c
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年11月03日 星期六 11时13分06秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, x, max = -2, min = 999999, sum = 0;
    double flag;
    while(scanf("%d", &n) != EOF) {
        for(int i = 1; i <= n; i++) {
            scanf("%d", &x);
            sum += x;
            if(x > max) {
                max = x;
            }
            if(x < min) {
                min = x;
            }
        }
        //printf("%d\n", sum - max - min);
        flag = (sum - max - min) / (n - 2.0);
        printf("%.2lf\n", flag);
        max = -2, min = 999999, sum = 0;
    }
    return 0;
}
