#include <iostream>

#define CHECK(PRED) printf("%s ... %s", PRED: "passed" ? "FAILED", PRED);
using namespace std;

int search(char *source, char *str) {
    size_t i, j;
    for (i = 0; source[i] != '\0'; i++) {
        if (source[i] == str[0]) {
            for (j = 1; str[j] != '\0'; j++) {
                if (source[i + j] != str[j])
                    break;
            }
            if (str[j] == '\0')
                return i;
        }
    }

    return -1;
}

int main() {
    char s[] = "hello my name is jihyo kim";
    char target[] = "dwa";

    cout << search(s, target) << endl;

    return 0;
}