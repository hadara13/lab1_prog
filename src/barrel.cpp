#include"barrel.h"

double Barrel :: get_concentration() const {
    return alcohol / volume ; 

}

void Barrel :: pour_to(Barrel & obj , double amount /*percentage of alco by numbers*/ ) {
    double concentration = this -> get_concentration() ; 
    double alco_transfered = concentration * amount ;
    this -> alcohol -= alco_transfered ; 
    obj.alcohol += alco_transfered ; 

}