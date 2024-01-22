#include <stdio.h>
void qcksort(int *a, int start, int end) {
    if (end<=start)
        return;
    int pivot=start, l=pivot+1, r=end, t;
    while (l<r) {
        while (l<=end && a[l]<a[pivot]) {
            l++;
        }
        while (r>start && a[r]>a[pivot]) {
            r--;
        }
        if (l>r) {
            t = a[pivot];
            a[pivot] = a[r];
            a[r] = t;
        } else {
            t = a[l];
            a[l] = a[r];
            a[r] = t;
        }
    }
    qcksort(a, start, r-1);
    qcksort(a, r+1, end);
}
int main() {
    int n, a[1000], t, j;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    qcksort(a, 0, n-1);
    for (int i=0; i<n; i++) {
        printf("%d\n", a[i]);
    }
}