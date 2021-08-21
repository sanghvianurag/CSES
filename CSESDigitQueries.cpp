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



void solve(){
        
        ll q;
        cin >> q;
        rep(i, 0, q){
            ll k;
            cin >> k;
            ll finalK = k;
            ll divisor = 9;
            ll cumulativeSum = 0;
            ll lengthOfSeries = 0;
            ll factor = 1;
            while((divisor*factor) < k)
            {
                k -= (divisor*factor);
                //cout << k << endl;
                //cout << divisor << endl;
                cumulativeSum += divisor;
                lengthOfSeries += divisor*factor;
                divisor *= 10;
                factor++;
            }
            int countZeroes = 1;
            while(divisor >= 10)
            {
                divisor = divisor/10;
                countZeroes++;
            }
            ll result = k/countZeroes;
            ll ans = (lengthOfSeries + result*countZeroes);
            ll number = cumulativeSum + result;
            if(ans == finalK)
            {
                
                cout << (number)%10 << endl;
            }
            else
            {
                if(ans < finalK)
                {
                    //cout << "yes" << endl;
                    int diff = abs(ans - finalK);
                    diff = abs(diff - countZeroes);
                    number++;
                    while(diff)
                    {
                        number /= 10;
                        diff--;
                    }
                    cout << number % 10 << endl;
                }
                else
                {
                       while(ans!=finalK)
                       {
                            ans--;
                       }
                       cout << ans%10 << endl;
                }
            }
        }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}