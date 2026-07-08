#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,c;
    cin>>n>>c;
    vector<ll> u(n);
    vector<ll> p(n);
    vector<ll> d(n);
    for(ll i=0;i<n;i++){
        cin>>u[i]>>p[i]>>d[i];
    }
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(2,vector<ll>(c+1,-1)));
    vector<vector<vector<ll>>> choice(n+1,vector<vector<ll>>(2,vector<ll>(c+1,-1)));
    for(ll i = 0;i<=c;i++){
        dp[n][0][i] = 0;
        dp[n][1][i] = 0;
    }
    for(ll ind = n-1;ind>=0;ind--){
        for(ll taken = 0;taken<2;taken++){
            for(ll hours = 0;hours<=c;hours++){
                ll take = 0,nottake = 0;
                nottake = dp[ind+1][0][hours];
                if(taken==0 && d[ind]<=hours){
                    ll x = (u[ind] * p[ind] * 2) + (u[ind]*(100-p[ind]));
                    take = x + dp[ind+1][1][hours-d[ind]];
                }
                if(take>nottake){
                    dp[ind][taken][hours]=take;
                    choice[ind][taken][hours]=1;
                }
                else{
                    dp[ind][taken][hours]=nottake;
                    choice[ind][taken][hours]=0;
                }
            }
        }
    }
    ll ans = dp[0][0][c];
    vector<ll> path;
    ll ind = 0,taken = 0,hours = c;
    while(ind<n){
        if(choice[ind][taken][hours]==1){
            path.push_back(ind+1);
            taken = 1;
            hours = hours-d[ind];
        }
        else{
            taken = 0;
        }
        ind++;
    }
    cout<<path.size()<<endl;
    for(auto it:path) cout<<it<<" ";
    cout<<endl;
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
