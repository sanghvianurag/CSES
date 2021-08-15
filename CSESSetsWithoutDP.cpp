#include<iostream>
#include<vector>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i=a;i<b;++i)
#define repb(i, a, b) for(int i=a;i>b;--i)
#define endl '\n'
#define mod 1000000007

void output(vector<int> sample)
{
    cout << sample.size() << endl;
    rep(i, 0, sample.size()) cout << sample[i] << " ";
    cout << endl;
}
void solve(){
    ll N;
    cin >> N;
    vector<int> leftNums;
    vector<int> rightNums;
    rightNums.pb(N);
    rep(i, 1, N) leftNums.pb(i);
    ll leftSum = N*(N-1)/2;
    ll rightSum = N;
    ll D = leftSum - rightSum;
    if(D == 0)
    {
        cout << "YES" << endl;
        output(leftNums);
        output(rightNums);
    }
    else
    {
        if(D%2!=0)
        {
            cout << "NO" << endl;
        }
        else
        {
            D >>= 1;
            ll sumToD = 0;
            for(auto r = --leftNums.end(); r>=leftNums.begin(); r--)
            {
                if(*r + sumToD < D)
                {
                    sumToD += *r;
                    rightNums.pb(*r);
                    leftNums.erase(r);
                } 
                else if(*r + sumToD == D)
                {
                    sumToD += *r;
                    rightNums.pb(*r);
                    leftNums.erase(r);
                    break;
                }
            }
            cout << "YES" << endl;
            output(leftNums);
            output(rightNums);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}