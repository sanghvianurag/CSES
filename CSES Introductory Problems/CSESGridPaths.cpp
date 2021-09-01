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

unordered_map<string, int> umap;
int counter = 0;

int countWays(vector<vector<int>>& grid, int row, int col, char dir, string path)
{
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid.size())
    {
        return 0;
    }
    if(row == grid.size()-1 && col == grid.size()-1)
    {
        cout << path << endl;
        return 1;
    }
    if(dir != '.'){
        path.push_back(dir);
    }
    //going down
    int a = countWays(grid, x+1, y, 'D');
    //going up
    int b = countWays(grid, x-1, y, 'U');
    //going left
    int c = countWays(grid, x, y-1, 'L');
    //going right
    int d = countWays(grid, x, y+1, 'R');

    path.pop_back();
    
    return a+b+c+d;
}
//function to generate all the permutations
void solve(){
    vector<vector<int>> grid(7, vector<int>(7, 0));
    cout << countWays(grid, 0, 0, '.', "");
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}