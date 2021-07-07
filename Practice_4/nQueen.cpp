#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<bool>> &board, int row, int col, int N)
{
    int r,c;
    for(c= col;c>=0;c--)
    {
        if(board[row][c])
        {
            return false;
        }
    }
     for(r= row, c= col;c>=0 && r>=0;c--,r--)
    {
        if(board[r][c])
        {
            return false;
        }
    }
    for(r= row, c= col;c>=0 && r<N;c--,r++)
    {
        if(board[r][c])
        {
            return false;
        }
    }
    return true;
}
bool NQueenHelper(vector<vector<bool>> &board, int col, int N)
{
    if(col>=N){
        return true;
    }
    for(int row=0;row<N;row++)
    {
        if(isSafe(board, row, col,N) ){
            board[row][col]=true;
            if(NQueenHelper(board, col+1,N)){
                return true;
            }
            board[row][col]=false;
        }
    }
    return false;
}

vector<vector<bool>> NQueen(int N){
    vector<vector<bool>> board(N,vector<bool>(N,false));
    if(NQueenHelper(board,0,N)){
        return board;
    }
    else{
        return {};
    }
}
void printMatrix(vector<vector<bool>> board){
for(int i=0;i<board.size();i++)
{
    for(int j=0;j<board[i].size();j++)
    {
        cout<<board[i][j]<<" ";
    }
    cout<<endl;
}
}
int main()
{
    vector<vector<bool>> check;
    check= NQueen(10);
    printMatrix(check);   
}