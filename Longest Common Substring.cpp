#include <iostream>
#include <string.h>
using namespace std;

void printTable(int** table, int m, int n) {
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

void printLongestCommonSubstring(char* X, int endIndex, int maxLength) {
    cout << "Longest Common Substring: ";
    for (int i = endIndex - maxLength + 1; i <= endIndex; ++i) {
        cout << X[i];
    }
    cout << endl;
}

int LCSubStr(char* X, char* Y, int m, int n) {
 
    int** LCSuff = new int*[m + 1];
    for (int i = 0; i <= m; ++i) {
        LCSuff[i] = new int[n + 1];
    }

    int result = 0; 

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            } else
                LCSuff[i][j] = 0;
        }

        printTable(LCSuff, m, n);
    }
    printLongestCommonSubstring(X, m, result);

     for (int i = 0; i <= m; ++i) {
        delete[] LCSuff[i];
    }
    delete[] LCSuff;

    return result;
}

int main() {
    char X[] = "ABAB";
    char Y[] = "BABA";

    int m = strlen(X);
    int n = strlen(Y);

    cout << "Length of Longest Common Substring is " << LCSubStr(X, Y, m, n) << endl;

    return 0;
}