//
// Created by k on 2.10.19 г..
//

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

// TODO make circle stack
template <typename T>
class Stack {
private:
    T* _buffer { nullptr };
    int _curr { 0 }; // -1 if it is empty
    size_t _size { 0 };
    const size_t _INITIAL_SIZE = 10;
    const size_t _RESIZE_UP_COEF = 2;
    const size_t _RESIZE_DOWN_COEF = 2;
    const size_t _MIN_SIZE_PERCENTAGE = 20; // 20%

    bool _triggerResizeUp() {
        return _curr + 1 == _size;
    }

    bool _triggerResizeDown() {
        if ((float)_curr / _size >= _MIN_SIZE_PERCENTAGE / 100.)
            return false;

        size_t newSize = _size * _RESIZE_UP_COEF;
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

public:
    Stack() {
        _size = _INITIAL_SIZE;
        _buffer = new T[_INITIAL_SIZE];
        _curr = -1;
    }

    Stack(size_t initialSize) {
        _buffer = new T[initialSize];
        _size = initialSize;
        _curr = -1;
    }

    virtual ~Stack() {
        delete[] _buffer;
    }

    void push(const T &data) {
        _resizeUp();

        _buffer[++_curr] = data;
    }

    T pop() {
        _resizeDown();
        if (isEmpty()) {
            // exception?
        }

        return _buffer[_curr--];
    }

    bool isEmpty() const {
        return _curr < 0;
    }
};

template <typename T>
class Queue {
private:
    Stack<T> _inStack;
    Stack<T> _outStack;

public:
    void enqueue(const T &data) {
       _inStack.push(data);
    }

    T dequeue() {
        if (isEmpty()) {
            // exception ??
        }

        if (_outStack.isEmpty()) {
            while (!_inStack.isEmpty()) {
                _outStack.push(_inStack.pop());
            }
        }

        return _outStack.pop();
    }

    bool isEmpty() {
        return _inStack.isEmpty() && _outStack.isEmpty();
    }
};

int main() {

    Queue<int> queue;
    int n = 0;
    cin >> n;

    bool flag = true;

    for (size_t i = 0; i < n; i++) {
        int cmd = 0, num = 0;

        cin >> cmd;
        cin >> num;

        if (cmd == 2) { // pop
            if (queue.isEmpty()) {
                if (num != -1) {
                    flag = false;
                    break;
                }
            } else {
                if (num != queue.dequeue()) {
                    flag = false;
                    break;
                }
            }

        } else if (cmd == 3) { // push
            queue.enqueue(num);
        } else {
            return -1;
        }
    }

    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

