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
#define INF           1e9

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> dpGrid(n, vector<int>(n, 0));
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> grid[i][j];
        }
    }
    for(int i=1;i<n;i++)
    {
        if(grid[i][0]!='*'){
            dpGrid[i][0] = 1;
        }
        if(grid[0][i]!='*'){
            dpGrid[0][i] = 1;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(grid[i][j] == '*')
            {
                dpGrid[i][j] = 0;
            }
            else
            {
                dpGrid[i][j] = dpGrid[i-1][j]%mod + dpGrid[i][j-1]%mod;
            }
        }
    }
    cout << dpGrid[n-1][n-1] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}