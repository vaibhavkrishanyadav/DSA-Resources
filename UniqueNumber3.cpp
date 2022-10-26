#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, arr[1000];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt[64] = {0};      // AS mazimum 64 bits can exist

    // Part where we calc bit sum
    for(int i = 0; i < n; i++) {
        int pos = 0;
        int no = arr[i];
        while(no > 0) {
            if((no & 1) == 1) {
                cnt[pos]++;
            }
            pos++;
            no = no >> 1;
        }
    }

    int ans = 0, p = 1;

    for(int i = 0; i < 64; i++) {
        cnt[i] = cnt[i] % 3;
        ans = ans + cnt[i]*p;
        p = p*2;
    }

    cout << ans;
    return 0;
}