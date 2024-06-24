#include <iostream>
using namespace std;

bool cekDuplikat(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int arr[] = {2, 1, 3, 1};
    int length = sizeof(arr) / sizeof(arr[0]);

    if (cekDuplikat(arr, length)) {
        cout << "Array memiliki duplikat" << endl;
    } else {
        cout << "Array tidak memiliki duplikat" << endl;
    }

    return 0;
}
