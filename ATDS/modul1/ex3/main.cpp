//
// Created by k on 2.10.19 г..
//

#include <iostream>

using namespace std;

class Stack {
private:
    int* _buffer { nullptr };
    int _curr { 0 }; // -1 if it is empty
    size_t _size { 0 };
    const size_t _INITIAL_SIZE = 10;
    const size_t _RESIZE_UP_COEF = 2;
    const size_t _RESIZE_DOWN_COEF = 2;
    const size_t _MIN_SIZE_PERCENTAGE = 20; // 20%

    bool _triggerResizeUp() {
        return _curr == _size;
    }

    bool _triggerResizeDown() {
        if ((float)_curr / _size >= _MIN_SIZE_PERCENTAGE / 100f)
            return false;

        size_t newSize = _size * _RESIZE_UP_COEF;
        // Size can not be less than initial size
        if (newSize < _INITIAL_SIZE)
            return false;

        return true;
    }

    void _resizeUp() {
        if (!_triggerResizeUp())
            return;

        size_t newSize = _size * _RESIZE_UP_COEF;
        int* buff = new int[newSize];
        memcpy(buff, _buffer, _size * sizeof(int));

        delete[] _buffer;

        _buffer = buf;
        _size = newSize;
    }

    void _resizeDown() {
        if (!_triggerResizeDown())
            return;

        size_t newSize = _size / _RESIZE_DOWN_COEF;

        int* buff = new int[newSize];
        memcpy(buff, _buffer, newSize * sizeof(int));

        delete[] _buffer;

        _buffer = buf;
        _size = newSize;
    }

public:
    Stack() {
        Stack(initialSize);
    }

    Stack(size_t initialSize) {
        _buffer = new int[initialSize];
        _size = initialSize;
        _curr = -1;
    }

    virtual ~Stack() {
        delete[] _buffer;
    }





};
