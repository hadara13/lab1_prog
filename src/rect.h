#ifndef RECT_H
#define RECT_H
#include <iostream>

class Rect {

private:

    int x;
    int y;
    int width ;
    int height;
    
    public :
    // from exr n. 4*
    void fix() ; 


public:
    /* to solve the task 1.2 , 1.3 :
    we must create a default constructor: 
    */
   
    // default 
    Rect () : x(0) , y(0) , width(0) ,  height(0)
    {std::cout << "constructor called for" << " " << this << std::endl;} ; /* after adding the param constructor,
    compliler won't make an implicit constructor so we got the error , to solve it we must create one by hands   
    */

    // param
    Rect(int l, int r, int b, int t) {
        if (l > r) std::swap(l, r);
        if (b > t) std::swap(b, t);
        x = l;
        y = b;
        width = r - l;
        height = t - b;

std::cout <<"constructor called for"<< " " << this<<std::endl;}

    // copy 
    Rect(const Rect& obj) :  x (obj.x) , y (obj.y) ,  width(obj.width) , height (obj.height)
    {std::cout<< " constructor called for " << " " << this << std::endl;}
    
    // destructor 
    ~ Rect() {std::cout <<"destructor has been called for  "<< " " <<this <<std::endl;}

    // getters
    int get_left() const ; 
    int get_right() const ;
    int get_top() const ; 
    int get_bottom() const ; 
    int get_width() const ; // width 
    int get_height() const ; //height 
    int get_square() const ; // square 

    // setters
    void set_width(int w ); 
    void set_height(int h ); 
    void set_left(int l ) ;
    void set_right (int r) ; 
    void set_bottom(int b) ;
    void set_top(int t) ;
    void set_all(int a , int b , int c , int d) ; 

    // METHODS
    // inflate by the same value
    void inflate(int amount );
    // inflate by two different values
    void inflate( int dw , int dh) ; 
    // inflate by many values
    void inflate(int d_left, int d_right, int d_top, int d_bottom);
    // to move the rect 
    void move(int dx, int dy = 0);
    // print rect
    void print_rect(Rect &r) ; 
};

Rect bounding_rect(Rect r1 , Rect r2 );


#endif // rect_h
