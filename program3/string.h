#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

const int SIZE = 100;

class String
{
    public:
        String();
        String(const String &);
        ~String();
        String &operator=(const char*);
        String &operator=(const String&);
        bool operator==(const char *) const;
        bool operator==(const String&) const;
        bool operator!=(const String&) const;
        bool operator!=(const char *) const;
        bool operator<(const String&) const;
        bool operator>(const String&) const;
        friend ostream &operator<<(ostream &, const String&);
        friend istream &operator>>(istream &, String&);

    protected:
        char *name;
        int length;

    private:
        int compare_string(const String&) const;;
        int compare_array(const char *) const;
        int copy_string(const String&);
        int copy_array(const char *);
        int check_less(const String&) const;
        int check_greater(const String &) const;
        int check_not_equal(const String&) const;
        int check_not_equal(const char *) const;
};


