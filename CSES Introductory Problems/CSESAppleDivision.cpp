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

long long binpow(long long a, long long b)
{
    if(b == 0) return 1;
    long long res = binpow(a, b/2);
    if(b & 1)
        return (((res%mod)*(res%mod)*(a%mod))%mod);
    else
        return ((res%mod)*(res%mod)%mod);
}

void printBits(int n, int c, vector<int>& ans)
{
    repb(i, c, -1){
        if(n & 1 << i){
            ans.pb(1);
        }
        else
        {
            ans.pb(0);
        }
    }
}


//function to generate all the permutations
void solve(){
    int n;
    cin >> n;
    vector<ll> weights(n);
    vector<int> leftPart;
    vector<int> rightPart;
    vector<int> sampleOne;
    vector<int> sampleTwo;
    for(int i=0;i<n;i++)
    {
        cin >> weights[i];
    }
    int minDiff = INT_MAX;
    rep(i, 0, pow(2,n)){
        ll number = i;
        ll leftSum = 0;
        ll rightSum = 0;
        vector<int> ans;
        repb(i, n-1, -1){
            if(number & 1 << i){
                ans.pb(1);
            }
            else
            {
                ans.pb(0);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i] == 0)
            {
                leftSum += weights[i];
            }
            else
            {
                rightSum += weights[i];
            }
        }
        //cout << leftSum << "  " << rightSum << endl;
        if( minDiff > abs(leftSum-rightSum)){
            minDiff = abs(leftSum - rightSum);
        }
    }
    cout << minDiff << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}