#include <iostream>

using namespace std;
// int main(void)
// {
//     size_t lenOfArray = 5;
//     size_t i;
//     int myArray[lenOfArray];

//     for (i = 0; i < lenOfArray; i++)
//     {
//         myArray[i] = i;
//         cout << &myArray[i] << endl;
//     }

//     return 0;
// }


// int main(void)
// {
//     int *nullPointer = NULL;
//     int num = 10;
//     cout << nullPointer << endl;
//     nullPointer = &num;

//     cout << nullPointer << endl;
//     cout << nullPointer + 1 << endl;

//     cout << *nullPointer << endl;
//     cout << *(nullPointer + 1) << endl;

//     return 0;
// }

int main(void)
{
    int myArray[] = {1, 2, 3, 4, 5};
    int *myPointer = myArray;
    size_t i;

    for (i = 0; i < 5; i++)
    {
        cout << *(myPointer + i) << endl;
    }

    return 0;
}