#ifndef BARREL_H
#define BARREL_H
#include<iostream>

class Barrel {
    private:
        double volume ; 
        double alcohol ; // the amount of alco 
    
    public:
        Barrel() : volume(0) , alcohol(0) {} ; 
        Barrel(double volume , double consen) {
            this -> volume = volume ; 
            this -> alcohol = consen * volume  ;  // amount 
        }  

    double get_concentration() const ;

    void pour_to(Barrel &obj , double amount) ;
}
;













#endif
