#include "myString.h"
#include <cstring>

using namespace CS270;

//square brackets overload for read/write indexing
//argument does not accept refrence because there is no need to modify the index value itself.
//the implementation will use a copy of 'index'
char& string::operator[](int index) {
    return data[index];
}

//+ overload for concatenation
//must accept refrence to avoid re-calling string constructor
//refrence arguments should almost always be const
string string::operator+(const string& input){
    string result;
    result.data = new char[len];
    result.len = this->len + input.len;

    //1st round of iteration: copies over set of chars from 'this'
    for(int i = 0; i < this->len; i++){
        result.data[i] = this->data[i];
    }

    //2nd round of interation: copies over set of chars from input
    for(int i = 0; i < input.len; i++){
        result.data[this->len + i] = input.data[i]; 
    }

    return result;
}

//constructor
//accepts pointer as paramater in order to differentiate from copy constructor
string::string(const char* input){
    int x = strlen(input);
    if (input){ // check for empty input
        data = new char[x];
        len = x;
        for(int i = 0; i < len; i++){
            data[i] = input[i];
        }
    } else{
        data = new char[0];
        len = 0;
    }
}

//copy constructor
//accepts refrence because copy constructor is giving the class the ability to make copies
//impossible to accept copy of paramater until copy constructor has been compiled and called
string::string(const string& original){
    data = new char[original.len];
    len = original.length();

    for(int i = 0; i < this->len; i++){
        this->data[i] =  original.data[i];
    }
}

//return length of given string
//no paramaters because it is called ON objects (object.len)
int string::length() const{
    return len;
}

//destructor
string::~string(){
    delete[] data;
}
