// Question Link: https://www.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
//  Explaination Link: https://www.geeksforgeeks.org/sudoku-backtracking-7/
bool check(int x, int y, int matrix[9][9], int val){
    for(int i=0;i<9;i++){
        if(i != x && matrix[i][y] == val)   return false;
        if(i != y && matrix[x][i] == val)   return false;
    }

    int start_x = x - (x%3);
    int start_y = y - (y%3);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(x == i + start_x && j + start_y == y)  continue;
            if(matrix[i+start_x][j+start_y] == val) return false;
        }
    }
    return true;
}

bool SolveSudoku(int x, int y, int matrix[9][9]){
    if(x == 8 && y == 9)    return true;
    if(y == 9){
        y = 0;
        x++;
    }

    if(matrix[x][y] != 0)   return generate(x,y+1,matrix);

    for(int val = 1; val<=9; val++){
        if(check(x,y,matrix,val)){
            matrix[x][y] = val;
            if(generate(x,y+1,matrix))  return true;
        }
        matrix[x][y] = 0;
    }

    return false;
}
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return SolveSudoku(0,0,matrix);
}
