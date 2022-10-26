#include<bits/stdc++.h>
using namespace std;

void DiagnolPrint(int mat[][100], int m, int n) {
    int row = 0, col = 0;
    bool up = true;
    
    while(row < m && col < n) {
        if(up) {
            while(row > 0 && col < n-1) {
                cout << mat[row][col] << ", ";
                row--;
                col++;
            }
            cout << mat[row][col] << ", ";
            if(col == n-1) {
                row++;
            }
            else {
                col++;
            }
        }
        else {
            while(col > 0 && row < m-1) {
                cout << mat[row][col] << ", ";
                row++;
                col--;
            }
            cout << mat[row][col] << ", ";
            if(row == m-1) {
                col++;
            }
            else {
                row++;
            }
        }
        up = !up;
    }
}

int main() {
    int mat[100][100], m, n;
    cin >> m >> n;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    DiagnolPrint(mat, m, n);

    return 0;
}