#include <iostream>

using namespace std;

void Merge(int *a, int left, int center, int right) {
    int b[5], i = left, j = center + 1,
              k{};  // 마지막 분할은 Merge() 안에서 하는 것. (2개나 3개부터)
    while (
        i <= center &&
        j <= right) {  // 배열 왼쪽 오른쪽 나눠서 왼쪽의0과 오른쪽의0 부터 비교.
        if (a[i] > a[j])
            b[k++] = a[j++];
        else
            b[k++] = a[i++];
    }
    if (i <= center)
        b[k] = a[i];  // 왼쪽 요소가 하나 더 많아서 위에서 처리 안됐을 때 b 제일
                      // 뒤에 추가
    if (j <= right) b[k] = a[j];  // 오른쪽 요소가 ..
    do {                          // copy b to a.
        a[left + k] = b[k];
    } while (k--);  // k--를 나중에 실행해야 의도한대로 작동해서 do while 사용.
    /* while (k >= 0) {    // Also OK.
        a[left + k] = b[k];
        k--
    } */
}

void MergeSort(int *a, int left, int right) {
    int center;
    if (left < right) {
        center = (left + right) / 2;
        MergeSort(a, left, center);
        MergeSort(a, center + 1, right);
        Merge(a, left, center, right);
    }
}

int main() {
    int a[5], n, left, right;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    MergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << endl;
    return 0;
}