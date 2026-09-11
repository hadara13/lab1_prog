#include <cassert>
#include <iostream>
#include "../src/rect.h"

int main() {
    std::cout << "Testing bounding_rect..." << std::endl;

    //  normal
    Rect r1(0, 4, 0, 4);
    Rect r2(2, 6, 2, 6);
    Rect result = bounding_rect(r1, r2);
    assert(result.get_left() == 0);
    assert(result.get_right() == 6);
    assert(result.get_bottom() == 0);
    assert(result.get_top() == 6);

    // left > right
    Rect r3(5, 1, 0, 4);   // left=5, right=1
    Rect r4(0, 6, 0, 6);
    result = bounding_rect(r3, r4);
    assert(result.get_left() == 0);
    assert(result.get_right() == 6);
    assert(result.get_bottom() == 0);
    assert(result.get_top() == 6);

    // bottom > top
    Rect r5(0, 4, 5, 1);   // bottom=5, top=1 (مقلوبين)
    Rect r6(0, 4, -2, 3);
    result = bounding_rect(r5, r6);
    assert(result.get_left() == 0);
    assert(result.get_right() == 4);
    assert(result.get_bottom() == -2);
    assert(result.get_top() == 5);

    std::cout << " All bounding_rect tests passed!" << std::endl;
    return 0;
}