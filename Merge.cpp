#include <iostream>

using namespace std;
// 마지막 분할은 Merge() 안에서 하는 것. (2개나 3개부터)
void Merge(int *a, int left, int mid, int right) {
    int b[1000], i = left, j = mid + 1, k{};
    // 배열 왼쪽 오른쪽 나눠서 왼쪽의0과 오른쪽의0 부터 비교.
    while (i <= mid && j <= right) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)  // 왼쪽이나 오른쪽 배열중 한쪽에 작은 수가 몰려있어서
        b[k++] = a[i++];  // 한쪽에서만 계속 들어갔을 때
    while (j <= right)  // 들어가지 않은 나머지 배열의 요소들을
        b[k++] = a[j++];                 // b 뒤에 전부 채우기
    for (int i = left; i <= right; i++)  // copy b to a
        a[i] = b[i - left];
}

void MergeSort(int *a, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(a, left, mid);
        MergeSort(a, mid + 1, right);
        Merge(a, left, mid, right);
    }
}

int main() {
    int a[1000], n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    MergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << '\n';
    return 0;
}