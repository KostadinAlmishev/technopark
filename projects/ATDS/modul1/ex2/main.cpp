//
// Created by k on 2.10.19 г..
//

#include <iostream>
#include <cassert>

#define OK 0
#define ERR_IO 1
#define ERR_MEM 2

using namespace std;

int create_arr(int **a, size_t n);
void input_arr(int* a, size_t n);
void process(int* a, size_t n, int* b, size_t m);
size_t search(const int* a, size_t n, int searched);

int main() {

    int rc = OK;
    int n = 0, m = 0;
    int *a = nullptr, *b = nullptr;
    cin >> n;
    cin >> m;
    if (n <= 0 || m <= 0) {
        return ERR_IO;
    }

    if ((rc = create_arr(&a, n)) == OK) {
        if ((rc = create_arr(&b, m)) == OK) {
            process(a, n, b, m);

            delete[] b;
        }

        delete[] a;
    }

    return rc;
}


int create_arr(int **a, size_t n) {
    int *_a = nullptr;

    _a = new int[n];
    if (!_a)
        return ERR_MEM;

    input_arr(_a, n);

    *a = _a;

    return OK;
}

void input_arr(int* a, size_t n) {
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void process(int* a, size_t n, int* b, size_t m) {
    assert(n);
    assert(m);

    for (size_t i = 0; i < m; i++) {
        cout << search(a, n, b[i]) << " ";
    }

    cout << endl;
}

size_t search(const int* a, size_t n, int searched) {
    bool finded = false;
    size_t res = 0;

    for (size_t i = 0; i < n; i++) {
        if (finded) {
            if (a[i] >= searched && a[i] < a[res]) {
                res = i;
            }
        } else if (a[i] >= searched) {
            finded = true;
            res = i;
        }
    }

    if (!finded) {
        return n;
    }

    return res;
}



