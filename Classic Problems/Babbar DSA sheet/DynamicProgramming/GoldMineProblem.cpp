#include <bits/stdc++.h>
using namespace std;

int main(){
    int ROW, COL;
    cin >> ROW >> COL;
    int gold[ROW][COL];
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            cin >> gold[i][j];
        }
    }
    int ans = INT_MIN;
    for(int col = 1; col < COL; col++){
        for(int row = 0; row < ROW; row++){
            if(row == 0 && row == ROW - 1) gold[row][col] += gold[row][col - 1];
            else if(row == 0) gold[row][col] += max(gold[row][col - 1], gold[row + 1][col - 1]);
            else if(row == ROW - 1) gold[row][col] += max(gold[row][col - 1], gold[row - 1][col - 1]);
            else gold[row][col] += max({gold[row][col - 1], gold[row - 1][col - 1], gold[row + 1][col - 1]});
            ans = max(ans, gold[row][col]);
        }
    }
    for(int row = 0; row < ROW; row++){
        // iteration is done on last column separatly for ans inside of inside n^2 inner loop itself
        // because two start from 1st column so if input has only one column then ans wont consider then
        // first column, so thats why a separate loop is used for finding the max in the last column, 
        // which will consider the 1 st column it is the last
        ans = max(ans, gold[row][COL-1]);
    }
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            cout << gold[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Maximum amount of gold is " << ans << endl;
}


// ref - > https://ide.geeksforgeeks.org/RPzYax9tRQ
