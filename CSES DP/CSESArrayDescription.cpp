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
    int n, m;
    cin >> n >> m;
    vector<ll> values(n);
    for(int i=0;i<n;i++)
    {
        cin >> values[i];
    }
    vector<vector<ll>> dpGrid(n, vector<ll>(m+1, 0));
    if(values[0]!=0)
    {
        dpGrid[0][values[0]] = 1;
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            dpGrid[0][i] = 1;
        }
    }
    for(int i=1; i<n; i++)
    {
        if(values[i] == 0)
        {
            for(int j=1;j<=m;j++)
            {
                if(j - 1 >= 1)
                {
                    dpGrid[i][j] = (dpGrid[i][j]%mod + dpGrid[i-1][j-1]%mod)%mod;
                }
                dpGrid[i][j] = (dpGrid[i][j]%mod + dpGrid[i-1][j]%mod)%mod;
                if(j + 1 <= m)
                {
                    dpGrid[i][j] = (dpGrid[i][j]%mod + dpGrid[i-1][j+1]%mod)%mod;
                }
            }
        }
        else
        {
            if(values[i]-1 >= 1)
            {
                dpGrid[i][values[i]] = (dpGrid[i][values[i]]%mod + dpGrid[i-1][values[i]-1]%mod)%mod;
            }
            dpGrid[i][values[i]] = (dpGrid[i][values[i]]%mod + dpGrid[i-1][values[i]]%mod)%mod;
            if(values[i]+1 <= m)
            {
                dpGrid[i][values[i]] = (dpGrid[i][values[i]]%mod + dpGrid[i-1][values[i]+1]%mod)%mod;
            }
        }
    }
    ll totalWays = 0;
    for(int i=1;i<=m;i++)
    {
        totalWays = (totalWays + dpGrid[n-1][i])%mod;
    }
    cout << totalWays << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}