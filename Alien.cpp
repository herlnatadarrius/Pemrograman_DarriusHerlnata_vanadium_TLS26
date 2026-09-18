#include <iostream>
using namespace std;

int main() {
    char msg[1000];
    cout << "Enter message: ";
    cin.getline(msg, 1000);

    int len = 0;
    while (msg[len] != '\0') len++;

    char encrypted[1000];
    int prevVal = 0;

    for (int i = 0; i < len; i++) {
        char c = msg[i];

        if (c >= 'A' && c <= 'Z') {
            int val = c - 'A' + 1;         
            int shift = (i == 0) ? 0 : prevVal;
            int newVal = ((val - 1 + shift) % 26) + 1;
            encrypted[i] = 'A' + (newVal - 1);
            prevVal = val;                  
        } else {
            encrypted[i] = c;              
        }
    }
    encrypted[len] = '\0';

    cout << "Encrypted message: " << encrypted << endl;
    return 0;
}