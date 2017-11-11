#include "string.h"

String::String():name(NULL), length(0)
{
}

String::String(const String &obj)
{

}

String::~String()
{
    if(name)
    {
        delete [] name;
        name = NULL;
    }
}

//overloaded = for array, calls private method to allocate memory and copy
String &String::operator=(const char* obj)
{
    copy_array(obj);
    return *this;
}

//overloaded = for string, calls private method to allocate memory and copy
String &String::operator=(const String& Obj)
{
    copy_string(Obj);
    return *this;
}

//overloaded == to check for equality for string
bool String::operator==(const String& Obj) const
{
    return compare_string(Obj);
}

//overloaded == to check for equality for array
bool String::operator==(const char *obj) const
{
    return compare_array(obj);
}

//checks for opposite of equality of string
bool String::operator!=(const String& Obj) const
{
    return check_not_equal(Obj); 
}

//checks for opposite of equality of array
bool String::operator!=(const char *obj) const
{
    return check_not_equal(obj);
}

//checks less than for string obj
bool String::operator<(const String& Obj) const
{
    return check_less(Obj);
}

bool String::operator>(const String &Obj) const
{
    return check_greater(Obj);
}


int String::check_less(const String &Obj) const
{
    if(strcmp(this->name, Obj.name) < 0)
        return 0;
    else
        return 1;
}

int String::check_greater(const String &Obj) const
{
    return !(this->name < Obj.name);
}

int String::compare_array(const char *obj) const
{
    if(strcmp(obj, this->name) == 0)
        return 1;
    return 0;
}

int String::compare_string(const String& Obj) const
{
    if(this == &Obj)
        return 1;

    if(strcmp(this->name, Obj.name) == 0)
        return 1;

    return 0;
}
        
int String::copy_string(const String& Obj)
{
    if(this->name)
        delete [] this->name;
    
    if(this == &Obj)
        return 0;

    else
    {
        this->length = strlen(Obj.name);
        this->name = new char[this->length + 1];
        strcpy(this->name, Obj.name);
        return 1;
    }
}

int String::copy_array(const char *obj)
{
    if(this->name)
        delete [] this->name;

    if(this->name == obj)
        return 0;

    else
    {
        this->length = strlen(obj);
        this->name = new char[this->length + 1];
        strcpy(this->name, obj);
        return 1;
    }
}

//to display the contents of the class
ostream &operator<<(ostream &out, const String& Obj)
{
    out << Obj.name << endl;
    return out;
}

//take input into the string object
istream &operator>>(istream &in, String& Obj)
{
    char *temp;
    temp = new char[SIZE];
    in.getline(temp, SIZE);
    Obj = temp;
    if(temp)
        delete [] temp;
    return in;
}

int String::check_not_equal(const String& Obj) const
{
    return !(this->name == Obj.name);
}

int String::check_not_equal(const char *obj) const
{
    return !(this->name == obj);
}
