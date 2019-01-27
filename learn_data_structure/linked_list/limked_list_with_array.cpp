#include <iostream>

using namespace std;

class ArrayList {
    public:
        int size;
        int *array;
        int lastIndex;

        ArrayList (int _size) {
            this->size = _size;
            array = new int[this->size];
            lastIndex = -1;
        }

        void insert(int value, int at) {
            int i;
            if (lastIndex == -1)
                at = 0;
            else if (at > lastIndex)
                array[lastIndex + 1] = value;

            for (i = lastIndex; i >= at; i--) {
                array[i + 1] = array[i];
            }

            array[at] = value;
            lastIndex++;
        }

        void append(int value) {
            this->lastIndex++;
            this->array[this->lastIndex] = value;
        }

        void remove(int value) {
            int i, j;
            for (i = 0; i < this->lastIndex + 1; i++) {
                if (this->array[i] == value) {
                    for (j = i; j < this->lastIndex; j++) {
                        this->array[j] = this->array[j + 1];
                    }
                    this->array[j] = INT_MAX;
                    this->lastIndex--;
                    i--;
                    continue;
                }
            }
        }

        void printValues() {
            int i;
            for (i = 0; i < this->lastIndex + 1; i++)
                cout << this->array[i] << "\t";
            cout << endl;
        }
};

int main() {
    ArrayList myList(100);
    int size = 10;
    int i;
    for (i = 0; i < size; i++) {
        myList.append(i);
        myList.append(4);
    }
    myList.remove(4);
    myList.insert(4, 0);

    myList.printValues();
    return 0;
}