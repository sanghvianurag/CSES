#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i=a;i<b;++i)
#define repb(i, a, b) for(int i=a;i>b;--i)
#define endl '\n'
#define mod 1000000007

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


void solve(){
    ll n;
    cin >> n;
   if (n <= 0)
        return;
 
    // 'arr' will store all generated codes
    vector<string> arr;
 
    // start with one-bit pattern
    arr.push_back("0");
    arr.push_back("1");
 
    // Every iteration of this loop generates 2*i codes from previously
    // generated i codes.
    int i, j;
    for (i = 2; i < (1<<n); i = i<<1)
    {
        // Enter the prviously generated codes again in arr[] in reverse
        // order. Nor arr[] has double number of codes.
        for (j = i-1 ; j >= 0 ; j--)
            arr.push_back(arr[j]);
 
        // append 0 to the first half
        for (j = 0 ; j < i ; j++)
            arr[j] = "0" + arr[j];
 
        // append 1 to the second half
        for (j = i ; j < 2*i ; j++)
            arr[j] = "1" + arr[j];
    }
 
    // print contents of arr[]
    for (i = 0 ; i < arr.size() ; i++ )
        cout << arr[i] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}