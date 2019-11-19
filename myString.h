#ifndef CS270_string
#define CS270_string

namespace CS270 {

class string {
   private:
 //default constructor
  string() {};

  string operator=(const string& other);

  //fields
  char *data;
  int len;

 public:
  //square brackets overload for read/write indexing
  //argument does not accept refrence because there is no need to modify the index value itself.
  //the implementation will use a copy of 'index'
  char& operator[](int index);

  //+ overload for concatenation
  //must accept refrence to avoid re-calling string constructor
  //refrence arguments should almost always be const
  string operator+(const string& input);
  
  //constructor
  //accepts pointer as paramater in order to differentiate from copy constructor
  string(const char* input);

  //copy constructor
  //accepts refrence because copy constructor is giving the class the ability to make copies
  //impossible to accept copy of paramater until copy constructor has been compiled and called
  string(const string& original);

  //return length of given string
 //no paramaters because it is called ON objects (object.len)
  int length() const;

  //destructor  
  ~string();
};
}

#endif //define CS270_string