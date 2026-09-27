#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;

    cout << "output:" << endl;

    for (int m = n; m >= 0; m--) {
        int spasi = (n - m) * 2;

        for (int i = 0; i < spasi; i++) {
            cout << " ";
        }

        for (int i = m; i >= 1; i--) {
            cout << i << " ";
        }

        cout << "*";

        for (int i = 1; i <= m; i++) {
            cout << " " << i;
        }

        cout << endl;
    }

    return 0;
}
