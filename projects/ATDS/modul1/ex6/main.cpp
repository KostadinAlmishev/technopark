//
// Created by k on 2.10.19 г..
//

#include <iostream>
#include <ctime>

using namespace std;

#define RAND(min, max) (rand() % (max + 1 - min) + min)

int cmpUInt(const void *a, const void *b) {
    unsigned int _a = *((unsigned int*)a);
    unsigned int _b = *((unsigned int*)b);

    if (_a < _b) {
        return -1;
    } else if (_a > _b) {
        return 1;
    }

    return 0;
}

int partition(unsigned int *arr, size_t l, size_t h, int (*cmp)(const void*, const void*)) {

    swap(arr[RAND(l, h)], arr[h]);

    size_t i = l, j = l;
    while (j < h) {
        if (cmp(arr + j, arr + h) > 0) {
            j++;
        } else {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }

    swap(arr[i], arr[h]);
    return i;
}

void sort(unsigned *arr, size_t n) {
    int l = 0;
    int h = n - 1;
    int stack[n];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;

    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h, cmpUInt);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

int main() {
    srand(time(nullptr));

    int n = 0, k = 0;
    cin >> n;
    cin >> k;
    if (n <= 0 || k < 0 || k >=n)
        return -1;

    auto *arr = new unsigned int[n];

    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, n);
    cout << arr[k] << endl;

    delete[] arr;

    return 0;
}