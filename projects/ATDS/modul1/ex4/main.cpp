//
// Created by k on 2.10.19 г..
//

#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

template <typename T>
class ArrayList {
public:
    ArrayList() :
    _currSize(0)
    {
        _size = _INITIAL_SIZE;
        _buffer = new T[_size];
    }

    ~ArrayList() {
        delete[] _buffer;
    }

    void add(T el) {
        _resizeUp();

        _buffer[_currSize++] = el;
    }

    void clear() {
        _currSize = 0;
        _resizeDown();
    }

    T& operator[](size_t i) {
        assert(i < _currSize);

        return _buffer[i];
    }

    T pop() {
        T res = _buffer[--_currSize];
        _resizeUp();

        return res;
    }

    size_t size() {
        return _currSize;
    }

    bool empty() {
        return _currSize == 0;
    }

private:
    bool _triggerResizeUp() {
        return _currSize == _size;
    }

    bool _triggerResizeDown() {
        if ((float)_currSize / _size >= _MIN_SIZE_PERCENTAGE / 100.)
            return false;

        size_t newSize = _size / _RESIZE_DOWN_COEF;
        // Size can not be less than initial size
        return newSize >= _INITIAL_SIZE;
    }

    void _resizeUp() {
        if (!_triggerResizeUp())
            return;

        size_t newSize = _size * _RESIZE_UP_COEF;
        T* buff = new T[newSize];
        memcpy(buff, _buffer, _size * sizeof(T));

        delete[] _buffer;

        _buffer = buff;
        _size = newSize;
    }

    void _resizeDown() {
        if (!_triggerResizeDown())
            return;

        size_t newSize = _size / _RESIZE_DOWN_COEF;

        T* buff = new T[newSize];
        memcpy(buff, _buffer, newSize * sizeof(T));

        delete[] _buffer;

        _buffer = buff;
        _size = newSize;
    }

    T *_buffer { nullptr };
    size_t _currSize { 0 };
    size_t _size { 0 };

    const size_t _INITIAL_SIZE = 10;
    const size_t _RESIZE_UP_COEF = 2;
    const size_t _RESIZE_DOWN_COEF = 2;
    const size_t _MIN_SIZE_PERCENTAGE = 20; // 20%
};

template <typename T>
class Heap {
public:
    Heap() {

    }

    void insert(T el) {
        _arr.add(el);
        _siftUp(_arr.size() - 1);
    }

    T extractMin() {
        assert(!_arr.empty());
        int result = _arr[0];
        _arr[0] = _arr.pop();

        if (!_arr.empty()) {
            _siftDown(0);
        }

        return result;
    }

    T peekMin() {
        return _arr[0];
    }

    size_t getSize() {
        return _arr.size();
    }

    bool isEmpty() {
        return _arr.empty();
    }

private:

    void _buildHeap() {
        for (int i = (int)_arr.size() / 2 - 1; i >= 0; --i) {
            _siftDown(i);
        }
    }

    void _siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (_arr[i] >= _arr[parent])
                return;

            swap(_arr[i], _arr[parent]);
            i = parent;
        }
    }

    void _siftDown(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < _arr.size() && _arr[left] < _arr[smallest]) {
            smallest = left;
        }
        if (right < _arr.size() && _arr[right] < _arr[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            swap(_arr[i], _arr[smallest]);
            _siftDown(smallest);
        }
    }

    ArrayList<T> _arr;
};

long find_sum(Heap<long> &heap) {
    if (heap.getSize() == 1)
        return heap.extractMin();

    long sum = 0;

    while (!heap.isEmpty()) {
        long min1 = heap.extractMin();
        long min2 = heap.extractMin();
        long tmp = min1 + min2;
        sum += tmp;

        if (!heap.isEmpty()) {
            heap.insert(tmp);
        }
    }

    return sum;
}

int main() {
    int n = 0;

    cin >> n;
    if (n <= 0)
        return -1;

    Heap<long> heap;

    for (int i = 0; i < n; i++) {
        long tmp = 0;
        cin >> tmp;
        heap.insert(tmp);
    }

    cout << find_sum(heap) << endl;

    return 0;
}