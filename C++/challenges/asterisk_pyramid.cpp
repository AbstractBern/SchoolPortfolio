#include <iostream>
using namespace std;
int main() {
    int odds = 1;
    int numTimes;
    char astrk = '*';
    cout << "Enter depth of asterisk pyramind: ";
    cin >> numTimes;
    while (numTimes != 0) {
        for (int left=0; left<numTimes; left++) {
            cout << " ";
        }
        for (int i=0; i < odds; i++) {
            cout << astrk;
        }
        for (int right=0; right<numTimes; right++) {
            cout << " ";
        }
        cout << endl;
        odds += 2;
        numTimes -= 1;
    }
    return 0;
}
