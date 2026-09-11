#include<cassert>
#include "../src/rect.h"

int main(){

    // get_width  and get_height    
    Rect r1(1, 5, 2, 8);
    assert(r1.get_width() == 4); // 5 - 1 = 4
    assert(r1.get_height() == 6);// 8 - 2 = 6

    // get_square
    assert(r1.get_square() == 24); // 4 * 6 = 24

    // set_width
    r1.set_width(10);
    assert(r1.get_width() == 10);
    assert(r1.get_right() == 11);  // left=1, width=10 → right=11

    // with 0 
    Rect r2;
    assert(r2.get_width() == 0);
    assert(r2.get_height() == 0);
    assert(r2.get_square() == 0);

    // negative param 
    Rect r3(-5, 5, -3, 3);
    assert(r3.get_width() == 10);   // 5 - (-5) = 10
    assert(r3.get_height() == 6);   // 3 - (-3) = 6
    assert(r3.get_square() == 60);  // 10 * 6 = 60

    std::cout << "All Rect properties tests passed!" << std::endl;
    
    return 0;

}
