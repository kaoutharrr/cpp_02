#include <iostream>
#include <cstring>

class MyString {
private:
    char* str;

public:
    // Constructor to initialize with a string
    MyString(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // User-defined copy constructor for deep copy
    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Destructor to release dynamically allocated memory
    ~MyString() {
        delete[] str;
    }

    // Display the string
    void display() const {
        std::cout << str << std::endl;
    }
};

int main() {
    MyString original("Hello, World!");
    MyString copied = original; // Copy using the user-defined copy constructor

    original.display();
    copied.display();

    return 0;
}