#include <cassert>
#include "../src/rect.h"

int main() { 



    Rect r ; 
    assert(r.get_left()==0);
    assert(r.get_right() == 0);
    assert(r.get_bottom() == 0);
    assert(r.get_top() == 0);


     Rect r1(1, 5, 2, 8);
    assert(r1.get_left()== 1);
    assert(r1.get_right()== 5);
    assert(r1.get_bottom()== 2);
    assert(r1.get_top()== 8);


    Rect r2;
    r2.set_all(1, 2, 3, 4);
    assert(r2.get_left()==1);
    assert(r2.get_right()==2);
    assert(r2.get_bottom()==3);
    assert(r2.get_top()==4);


     Rect r3(-5, 5, -3, 3);
    assert(r3.get_left() == -5);
    assert(r3.get_right() == 5);
    assert(r3.get_bottom() == -3);
    assert(r3.get_top() == 3);

    return 0;
}