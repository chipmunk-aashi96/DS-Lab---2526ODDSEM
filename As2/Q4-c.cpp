#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int i = 0, j = 0;
    while (str[i] != '\0') {
        char c = tolower(str[i]);
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';

    cout << "String without vowels: " << str << endl;
    return 0;
}
