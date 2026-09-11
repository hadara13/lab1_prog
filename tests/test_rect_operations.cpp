#include <cassert>
#include "../src/rect.h"



int main() {
    // move 
    Rect r1(1, 5, 2, 8);
    r1.move(3, 4);  //  (3, 4)
    assert(r1.get_left() == 4); // 1 + 3 = 4
    assert(r1.get_right() == 8);// 5 + 3 = 8
    assert(r1.get_bottom() == 6);// 2 + 4 = 6
    assert(r1.get_top() == 12);// 8 + 4 = 12

    // inflate 
    Rect r2(2, 6, 1, 5);
    r2.inflate(2, 3);  //  (2, 3)
    assert(r2.get_left() == 0); // 2 - 2 = 0
    assert(r2.get_right() == 8); // 6 + 2 = 8
    assert(r2.get_bottom() == -2);// 1 - 3 = -2
    assert(r2.get_top() == 8);// 5 + 3 = 8

    // inflate(تصغير)
    Rect r3(0, 10, 0, 10);
    r3.inflate(-2, -3);
    assert(r3.get_left()==2);// 0 - (-2) = 2
    assert(r3.get_right() ==8);// 10 + (-2) = 8
    assert(r3.get_bottom()== 3);// 0 - (-3) = 3
    assert(r3.get_top()== 7);// 10 + (-3) = 7

    std::cout << "All Rect operations tests passed!" << std::endl;
    return 0;
}



