#include<bits/stdc++.h>

using namespace std;

#define ll            long long
#define pb            push_back
#define pob           pop_back
#define mp            make_pair
#define rep(i, a, b)  for(int i=a;i<b;++i)
#define repb(i, a, b) for(int i=a;i>b;--i)
#define endl          '\n'
#define mod           1000000007

bool checkValidPosition(int x, int y, vector<vector<char>>& board)
{
    int tempX = x-1;
    int tempY = y-1;

    //checking the top left diagonal
    while(tempX >=0 && tempY >=0 && board[tempX][tempY]!='Q')
    {
        tempX -= 1;
        tempY -= 1;
    }
    if(tempX != -1 && tempY != -1)
    {
        return false;
    }

    tempX = x-1;
    tempY = y+1;
    //checking the top right diagonal
    while(tempX >=0 && tempY <8 && board[tempX][tempY]!='Q')
    {
        tempX -= 1;
        tempY += 1;
    }
    if(tempX != -1 && tempY != 8)
    {
        return false;
    }

    //checking top straight diagonal
    tempX = x-1;
    tempY = y;
    while(tempX >=0 && board[tempX][tempY]!='Q')
    {
        tempX -= 1;
    }
    if(tempX != -1)
    {
        return false;
    }
    return true;

}

int counter = 0;
void countWays(vector<vector<char>>& board, int row)
{
    if(row == board.size())
    {
        counter++;
        return;
    }
    for(int i=0;i<board.size();i++)
    {
        if(board[row][i] == '*') continue;
        if(checkValidPosition(row, i, board))
        {
            board[row][i] = 'Q';
            countWays(board, row+1);
            board[row][i] = '.';
        }
    }
}

//function to generate all the permutations
void solve(){
    vector<vector<char>> board(8, vector<char>(8, '.'));
    for(int i=0;i<8;i++)
    {
       for(int j=0;j<8;j++)
        {
            char s;
            cin >> s;
            board[i][j] = s;
        }
    }
    countWays(board, 0);
    cout << counter << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}