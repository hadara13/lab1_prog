#ifndef MYSTRING_H
#define MYSTRING_H
#include<iostream>

class MyString {
    private : 
        int length ; 
        char * words ; 

    public:
        // constructors 
        MyString();
        MyString(const char*str);
        MyString(const MyString& other);
        
        // destructor
        ~MyString() ;

        // methods 
        char get_letter(int i ) const ; 
        void change_letter(int i , char c);
        void set_new_string(const char * str);
        void print() ; 
        void read_line() ;
};

class TextWrapper{
    private : 
        const char * text ;
        int width ; 
        int i ; 
        int line_len;

    public :
        TextWrapper(const char* t, int w);
        void print_wrapped();


} ;


#endif