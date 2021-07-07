#include <bits/stdc++.h>
using namespace std;

vector<int> getLps(string s) {
    int i = 1, j = 0, len = s.length();

    vector<int> lps(len, 0);
    lps[0] = 0;

    while (i < len) {
        if (s[i] == s[j]) {
            lps[i] = j + 1;
            ++i;
            ++j;
        } else {
            // s[i] != s[j]
            if (j != 0) {
                j = lps[j - 1];
            } else {
                // j == 0
                lps[i] = 0;
                ++i;
            }
        }
    }
    return lps;
}

vector<int> kmp(string n, string m) {
    // to find m in n

    vector<int> ans;

    vector<int> lps = getLps(m);
    int i = 0, j = 0, nLen = n.length(), mLen = m.length();

    while (i < nLen) {
        if (n[i] == m[j]) {
            ++i;
            ++j;

            if (j == mLen)
                ans.push_back(i - mLen);

        } else {
            if (j != 0)
                j = lps[j - 1];
            else
                ++i;
        }
    }

    return ans;
}

int main() {
    cout << "Knuth–Morris–Pratt algorithm\n";

    string n;
    cout << "Enter a string : ";
    cin >> n;

    string m;
    cout << "Enter a substring to search for string : ";
    cin >> m;

    // fund occurrences of m in n
    vector<int> occurrences = kmp(n, m);

    if (occurrences.size() != 0) {
        for (int i = 0; i < occurrences.size(); i++) {
            cout << occurrences[i] << " - " << occurrences[i] + m.length() << "\n";
        }
    } else {
        cout << "There is no \"" << m << "\" in " << n << "\n";
    }

    return 0;
}
