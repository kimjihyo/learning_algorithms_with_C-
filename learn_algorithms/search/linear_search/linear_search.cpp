#include <iostream>
using namespace std;

bool linear_search(int *arr, int length, int value) {
    size_t i;
    for (i = 0; i < length; i++) {
        if (arr[i] == value)
            return true;
    }
    return false;
}

int main() {
    int myArray[5] = {0, 1, 2, 3, 4};
    cout << linear_search(myArray, sizeof(myArray)/sizeof(int), 5) << endl;

    return 0;
}