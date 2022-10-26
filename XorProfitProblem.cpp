#include<bits/stdc++.h>
using namespace std;

int main() {
    int x,y;
    cin>>x>>y;
    int num = x^y;
    int msb=0;
    while(num!=0) {
        num=num>>1;
        msb++;
    }
    int result = 1;
    while(msb--) {
        result=result<<1;
    }
    cout<<result-1;

    return 0;
}

// Alternate Way

// int main() {
//     int x, y;
//     cin >> x >> y;
//     int max = INT_MIN;
//     for(int i = x; i <= y; i++) {
//         for(int j = i; j <= y; j++) {
//             int res = i ^ j;
//             if(res >= max) {
//                 max = res;
//             }
//         }
//     }
//     cout << max << endl;
//     return 0;
// }