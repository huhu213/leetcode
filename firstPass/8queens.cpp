//
//  main.cpp
//  test
//
//  Created by 胡月 on 16/3/4.
//  Copyright © 2016年 胡月. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool putChess(vector<int> &board, int row){
    for(int i = 0; i < row; i ++) {
        if(board[i] == board[row]) return false;
        if(abs(board[i]-board[row]) == abs(i-row)) return false;
    }
    return true;
}


//Definition for a binary tree node.
void Eightqueens(vector<int> &board, int &sum, int row) {
    if(row == 8) {
        sum ++;
    }
    else {
        //put chess at each column in row
        for(int i = 0; i < 8; i ++) {
            board[row] = i;
            if(putChess(board, row)) Eightqueens(board, sum, row+1);
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> board(8, 0);
    int sum = 0;
    Eightqueens(board, sum, 0);
    cout << sum;
}
