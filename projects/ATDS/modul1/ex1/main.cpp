//
// Created by k on 2.10.19 г..
//

#include <iostream>
#include <climits>
#include <cassert>

using namespace std;

struct coord_t {
    float x;
    float y;

    coord_t(): x(0), y(0) {};
    coord_t(float _x, float _y): x(_x), y(_y) {};
};

void hand_test();
void input_coords(coord_t *coords, size_t n);

bool read_unsigned(istream &i, size_t &res);
void output_coords(const coord_t *coords, size_t n);
float calc_area_gaus(const coord_t *coords, size_t n);

int main() {
    hand_test();

    return 0;
}

void hand_test() {
    int n = 0;

    cin >> n;

    if (n > 0) {
        coord_t coords[n];
        input_coords(coords, n);
        cout << calc_area_gaus(coords, n) << endl;
    } else {
        cout << 0 << endl;
    }
}

void input_coords(coord_t *coords, size_t n) {
    for (size_t i = 0; i < n; i++) {
        cin >> coords[i].x;
        cin >> coords[i].y;
    }
}

void output_coords(const coord_t *coords, size_t n) {
    for (size_t i = 0; i < n; i++) {
        cout << coords[i].x << " " << coords[i].y << endl;
    }
}

float calc_area_gaus(const coord_t *coords, size_t n) {
    assert(coords);
    assert(n > 0);
    float res = coords[n - 1].x * coords[0].y - coords[0].x * coords[n - 1].y;

    for (size_t i = 0; i < n - 1; i++) {
        res += coords[i].x * coords[i + 1].y - coords[i + 1].x * coords[i].y;
    }
    if (res < 0)
        res = -res;

    return 0.5f * res;
}
