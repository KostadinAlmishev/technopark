//
// Created by k on 2.10.19 г..
//

#include <iostream>
#include <cassert>
#include <climits>

using namespace std;
void countingSortByByte(int64_t *arr, unsigned radix, unsigned exponent, int64_t min) {
    size_t bucketIndex;
    int64_t *buckets = new int64_t[radix];

}

void radixSort(int64_t *arr, size_t n, size_t radix, void (*sort)(void *, void *, size_t, size_t, void*, bool (*cmp)(void*, void*))) {
    if (!n) return;
    assert(arr);

    int min = arr[0];
    int max = min;
    for (size_t i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }

    int exponent = 1;
    while ((max - min) / exponent >= 1) {

    }
}

int main() {
    const size_t radix = UINT8_MAX + 1;

    int n;
    cin >> n;
    if (n <= 0)
        return -1;

    auto *arr = new int64_t[n];




    delete[] arr;

    return 0;
}