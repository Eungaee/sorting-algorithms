#include <stdio.h>
int main() {
    int n, a[1000], t;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i=n; i>0; i--) {
        for (int j=1; j<i; j++) {
            if (a[j-1]>a[j]) {
                t = a[j-1];
                a[j-1] = a[j];
                a[j] = t;
            }
        }
    }
    for (int i=0; i<n; i++) {
        printf("%d\n", a[i]);
    }
}