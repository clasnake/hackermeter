#include <stdio.h>

void fib(int n)
{
    if (n == 1) {
        printf("0\n");
    }
    else if (n == 2) {
        printf("0\n1\n");
    }
    else {
        printf("0\n1\n");
        long s = 0;
        long p = 1;
        int i;
        for (i = 3; i <= n; i++) {
            long q = s + p;
            printf("%ld\n", q);
            s = p;
            p = q;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        fib(n);
    }
    return 0;
}
