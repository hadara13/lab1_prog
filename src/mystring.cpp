#include "mystring.h"
#include <cstring>
#include <iostream>

MyString :: MyString(){
            length = 0 ; 
            words = new char [1];
            words[0] = '\0' ; 
}

MyString::MyString(const char*str){
                length = strlen(str); 
                words = new char  [length +1 ];
                strcpy(words , str); 
}


MyString :: ~MyString () {
    delete [] words ; 
}

char MyString ::get_letter(int i ) const {
    return words[i] ; 
}

void MyString :: change_letter(int i , char c  ){
    if (i < length && i >=0)
    words[i] = c ; 
}

void MyString :: set_new_string(const char * str){
    delete [] words ; 
    length = strlen(str) ; 
    words = new char [length + 1 ] ; 
    strcpy(words , str) ; 
} 

void MyString :: print() {
    std::cout<<words  << std::endl; 
}

void MyString::read_line(){
    char* buffer = new char[1000];
    std::cin.getline(buffer, 1000);
    set_new_string(buffer);
    delete[] buffer;
}

// copy constructor
MyString::MyString(const MyString& other)
{
    length = other.length;
    words = new char[length + 1];
    strcpy(words, other.words);
}

TextWrapper::TextWrapper(const char* t, int w)
{
    text = t;
    width = w;
    i = 0;
    line_len = 0;
}

void TextWrapper::print_wrapped(){
    while (text[i] != '\0'){

        // to pass the spaces
        while (text[i] == ' ')
            i++;
        // if we reached the end of word 
        if (text[i] == '\0')
            break;
        // now i = the index of first letter after passing the spaces
        int start = i;
        while (text[i] != ' ' && text[i] != '\0')
            i++;

        int word_len = i - start;

        // test if the new word fits with the last one on the same line
        if (line_len + word_len > width){        
            std::cout << std::endl;
            line_len = 0;
        }
        // printing 
        for (int j = 0; j < word_len; j++)
            std::cout << text[start + j];

        std::cout << ' ';
        line_len += word_len + 1;
    }

    std::cout << std::endl;
}