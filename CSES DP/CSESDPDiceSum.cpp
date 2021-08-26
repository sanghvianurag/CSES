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

long long countWays(int sum, vector<int> ways, vector<ll>& dp)
{
    if(sum == 0)
    {
        return 1;
    }
    if( sum < 0)
    {
        return 0;
    }
    if(dp[sum]!=0)
    {
        return dp[sum] % mod;
    }
    for(int i=0;i<ways.size();i++)
    {
        dp[sum] += countWays(sum - ways[i], ways, dp);
    }
    return dp[sum] % mod;
}

void solve(){
    int n;
    cin >> n;
    vector<ll> dp(1000001, 0);
    long long  ans = countWays(n, {1,2,3,4,5,6}, dp);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}