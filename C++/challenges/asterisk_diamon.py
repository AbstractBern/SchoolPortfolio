#include <iostream>
using namespace std;
int main() {
    int odds = 1;
    int numTimes;
    char astrk = '*';
    cout << "Enter depth of asterisk pyramind: ";
    cin >> numTimes;
    int reverseNumTimes = numTimes;
    while (numTimes != 0) {
        for (int left=0; left<numTimes-1; left++) {
            cout << " ";
        }
        for (int i=0; i < odds; i++) {
            cout << astrk;
        }
        for (int right=0; right<numTimes-1; right++) {
            cout << " ";
        }
        cout << endl;
        odds += 2;
        numTimes -= 1;
    }
    numTimes = 1;
    odds -= 4;
    while (numTimes != reverseNumTimes) {
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
        odds -= 2;
        numTimes+=1;
    }
    return 0;
}
