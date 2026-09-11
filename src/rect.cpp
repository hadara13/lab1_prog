#include"rect.h"
// to use min , max methods
#include"algorithm"
// in this file we put all the methods of the class except the constructors and destructors 

//getters methods 
int Rect :: get_left() const {
    return x;}  

int Rect :: get_right() const {
    return x + width ; 
}  

int Rect :: get_top() const {
    return y + height ; 
}  

int Rect :: get_bottom() const {
    return y ; 
}  

// setters method
void Rect :: set_all(int l , int r , int b , int t){
    if (l > r) std::swap(l, r);
    if (b > t) std::swap(b, t);
    x = l;
    y = b;
    width = r - l;
    height = t - b;
}
// inflate by the same value

/*void Rect :: inflate(int amount ){
    left -=amount ; 
    top -=amount ; 
    right +=amount;
    bottom +=amount;
}*/

void Rect :: inflate( int dx , int dy){
    x -= dx;
    width += 2 * dx;
    y -= dy;
    height += 2 * dy;
    fix();

} 

/*void Rect :: inflate(int d_left, int d_right, int d_bottom, int d_top){
    left -= d_left;
    right += d_right; 
    bottom += d_bottom ;
    top -= d_top;
}
*/
void Rect :: move(int dx , int dy) {
    x += dx;
    y += dy;
}

void Rect ::  print_rect(Rect &r){
    std::cout << "Left: "<< r.get_left() << ", ";
    std::cout << "Right: " << r.get_right() << ", ";
    std::cout << "Top: "<< r.get_top() << ", ";
    std::cout << "Bottom: "<< r.get_bottom() << std::endl;
}
// calculate 
int Rect :: get_width() const {
    return width ; 
}

int Rect :: get_height() const {
    return height ;
}  

int Rect :: get_square() const {
    return get_width() * get_height() ; 
}

// setters
void Rect :: set_width(int w) {
     if (w < 0) w = 0;
    width = w;

}
void Rect :: set_height(int h ) {
     if (h < 0) h = 0;
    height = h; 
}
void Rect :: set_left(int l) {
    x = l ;
    fix();
}
void Rect :: set_right(int r) {
    if (x > r) {
        int temp = x;
        x = r;
        width = temp - r;
    } else {
        width = r - x;
    }
    fix();
}
void Rect :: set_bottom(int b) {
    y = b ;
    fix();
}
void Rect :: set_top(int t) {
        if (y > t) {
        int temp = y;
        y = t;
        height = temp - t;
    } else {
        height = t - y;
    }
    fix();
}

// help method 
void Rect :: fix() {
    if (width < 0) {
        x += width;
        width = -width;
    }
    if (height < 0) {
        y += height;
        height = -height;
    }
}

Rect  bounding_rect(Rect r1 , Rect r2 ) {

        r1.fix();
        r2.fix(); 
   
    int new_l =std::min(r1.get_left() , r2.get_left()) ;
    int new_r =std::max(r1.get_right() , r2.get_right()) ; 
    int new_b =std::min(r1.get_bottom() , r2.get_bottom()) ; 
    int new_t =std::max(r1.get_top() , r2.get_top()) ;
    
    return Rect(new_l, new_r , new_b , new_t ) ; 
}