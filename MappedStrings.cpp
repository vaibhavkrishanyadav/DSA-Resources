#include<bits/stdc++.h>
using namespace std;

void mapped(string str, string out, int i, int j) {
    // BASE CASE
    if(i == str.length()) {
        cout << out << endl;
        return;
    }
    // RECURSIVE CASE

    //1. Store 1 dig on left side
    int dig = str[i] - '0';
    out.push_back(dig + 64);
    mapped(str, out, i + 1, j);
    out.pop_back();

    //2. Store 2 digit on left side
    if(i + 1 < str.length()) {
        int dig = (str[i] - '0')*10 + (str[i + 1] - '0');
        if(dig <= 26) {
            out.push_back(dig + 64);
            mapped(str, out, i + 2, j);
            out.pop_back();
        }
    }
}

int main() {
    string str, out;
    cin >> str;
    mapped(str, out, 0, 0);
    return 0;
}