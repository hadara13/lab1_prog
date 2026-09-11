#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>

class Matrix{

    private :
        int height ;
        int width ; 
        double **arr;


    public:

        Matrix(int n) {
            height = width = n ;
            arr = new double * [n] ; 
            
            for (int i =0 ; i < n ; i++){
                arr[i] = new  double  [n] ;  
            } 
            
            for(int i = 0 ; i < n ; i ++  ){
                for (int j = 0 ; j < n ; j++){
                    if (i == j) {
                        arr[i][j] = 1 ;
                     }
                     else arr[i][j] = 0 ;   
                }
            }
        
        }

        Matrix(int m , int n , double fill_value = 0){
            height = m ; 
            width = n ;
            arr = new double * [m] ;
            
            for (int i =0 ; i < m ; i++){
                arr[i] = new  double  [n]; 

        }
            for(int i = 0 ; i < m ; i++) {
                for (int j = 0 ; j < n ; j++ ){
                    arr[i][j] = fill_value ; 
                }
            }
}
        Matrix(const Matrix& other){
        height = other.height;
        width = other.width;

        arr = new double*[height];
        for (int i = 0; i < height; i++) {
            arr[i] = new double[width];
            for (int j = 0; j < width; j++) {
            arr[i][j] = other.arr[i][j];
        }
    }
}
        ~Matrix(){

        for (int i = 0; i < height; i++) {
        delete[] arr[i];
    }
        delete[] arr;
}

//methods 
double  get(int i , int j ) const ;
void  set(int i , int j , double value ) ;

// size
int get_height() const ; 
int get_width() const;

// sum of two arrays
void add_in_place(Matrix &other) ;

// multiplication 
Matrix multiply(Matrix &other) ;




};

int fibonacci(int n) ; 


#endif