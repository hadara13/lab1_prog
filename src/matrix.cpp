#include"matrix.h"

double Matrix :: get(int i , int j ) const {
    return arr[i][j] ; 

}

void Matrix:: set(int i , int j , double value ){
    arr[i][j] =  value ; 
}

int Matrix::get_height() const {return height; } 
int Matrix::get_width() const{return width ; }

void Matrix :: add_in_place(Matrix &other){
    if (height == other.height && width==other.width){
        for (int i = 0 ; i < height ; i ++){
            for (int j = 0 ; j < width ; j ++ ){
                arr[i][j] += other.arr[i][j] ; 
            }
        }
    }
    else throw std::invalid_argument("Invalid operation"); 
}

Matrix Matrix :: multiply(Matrix &other){
    if (width != other.width )
    throw std::invalid_argument("Invalid operation") ; 

    // creat an array of results
    Matrix multipresul(height , other.width , 0 );

    for(int i = 0 ; i < height ; i ++ ){
        for (int j = 0 ; j < other.width ; j++ ){
            for (int k = 0 ; k < width ; k++ ){
                multipresul.arr[i][j] += arr[i][k] * other.arr[k][j];
            }
        }
    }
    return multipresul;
}

int fibonacci(int n){

    if (n <= 1) return n;

    Matrix fib(2, 2, 0);
    fib.set(0, 0, 1);
    fib.set(0, 1, 1);
    fib.set(1, 0, 1);
    fib.set(1, 1, 0);

    Matrix result = fib;

    for (int i = 1; i < n; i++) {
        result = result.multiply(fib);
    }

    return result.get(0, 1);
}


