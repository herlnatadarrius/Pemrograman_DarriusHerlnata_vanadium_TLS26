#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Total Astronauts: ";
    cin >> N;
    int K;
    cout << "Elimination Value: ";
    cin >> K;

    int* astronauts = new int[N];
    for (int label = 0; label < N; label++) astronauts[label] = label + 1;

    int left = N;
    int elim = 0;

    cout << "Elimination Order: ";
    while (left > 1) {
        elim = (elim + K - 1) % left;
        int eliminated = astronauts[elim];
        cout << eliminated << " ";

        if (eliminated % 2 == 0) K += 2;
        else K -= 1;
        if (K < 2) K = 2;

        for (int label = elim; label < left - 1; label++)
            astronauts[label] = astronauts[label + 1];
        left--;

        if (elim == left) elim = 0;
    }
    cout << endl;

    cout << "Last Astronaut: Astronaut #" << astronauts[0] << endl;

    delete[] astronauts;
    return 0;
}