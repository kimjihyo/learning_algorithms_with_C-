#include <iostream>
using namespace std; // Tells the compiler to use std namespace. Q. What is namespace?

int main() { // main function is where program execution begins

    cout<<"Hello world!"<<endl;
    // cout<<"" -> prints a message in the double quotations on console.
    // <<endl -> prints a new line.

    cout<< sizeof(bool) << " byte" <<endl;
    cout<< sizeof(char) << " byte" <<endl;

    return 0;
    // return 0 -> ends the main function.
}