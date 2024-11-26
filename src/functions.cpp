#include "functions.h"

bool contieneCodigo(const string &transmission, const string &mcode, size_t &pos) {
    pos = transmission.find(mcode);
    return pos != string::npos;
}

bool esPalindromo(const string &str, int left, int right) {
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

pair<pair<int, int>, string> palindromoMasLargo(const string &transmission) {
    int n = transmission.size();
    int maxLength = 1, start = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (esPalindromo(transmission, i, j) && (j - i + 1) > maxLength) {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }

    return make_pair(make_pair(start + 1, start + maxLength), transmission.substr(start, maxLength));
}

pair<pair<int, int>, string> subsecuenciaComunMasLarga(const string &transmission1, const string &transmission2) {
    int m = transmission1.size();
    int n = transmission2.size();
    int maxLength = 0, endIdx = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (transmission1[i - 1] == transmission2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIdx = i;
                }
            }
        }
    }

    return make_pair(make_pair(endIdx - maxLength + 1, endIdx), transmission1.substr(endIdx - maxLength, maxLength));
}
