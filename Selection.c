#include <stdio.h>
int main() {
    int n, a[1000], m, t, idx;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i=0; i<n; i++) {
        m = 1000;
        for (int j=i; j<n; j++) {
            if (m>a[j]) {
                m = a[j];
                idx = j;
            }
        }
        t = a[i];
        a[i] = a[idx];
        a[idx] = t;
    }
    for (int i=0; i<n; i++) {
        printf("%d\n", a[i]);
    }
}