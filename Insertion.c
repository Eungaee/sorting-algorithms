#include <stdio.h>
int main() {
    int n, a[1000], t, j;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i=1; i<n; i++) {
        t = a[i];
        for (j=i-1; j>=0&&a[j]>t; j--) {
            a[j+1] = a[j];
        }
        a[j+1] = t;
    }
    for (int i=0; i<n; i++) {
        printf("%d\n", a[i]);
    }
}