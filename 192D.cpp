#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(ll ind1,ll ind2,vector<vector<ll>> &hash,vector<vector<ll>> &hash1,string &a,string &b,vector<vector<ll>> &dp){
    ll n1 = a.size();
    ll n2 = b.size();
    if(ind1 == n1 && ind2==n2){
        return 0;
    }
    if(ind1==n1 || ind2==n2){
        return -1e9;
    }
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    ll ans = -1e9;
    for(ll i=0;i<10;i++){
        ll x1 = hash[ind1][i];
        ll x2 = hash1[ind2][i];
        if(x1!=-1 && x2!=-1){
            if(func(x1+1,x2+1,hash,hash1,a,b,dp)!=-1e9) ans = max(ans,1+func(x1+1,x2+1,hash,hash1,a,b,dp));
        }
    }
    return dp[ind1][ind2]=ans;
}

void solve() {
    string a,b;
    cin>>a>>b;
    ll n1 = a.size();
    ll n2 = b.size();
    vector<vector<ll>> hash(n1,vector<ll>(10,-1));
    for(ll i=0;i<n1;i++){
        ll sum =0;
        vector<bool> fl(10,false);
        for(ll j=i;j<n1;j++){
            sum+= (a[j] - '0');
            ll digit = sum%10;
            if(fl[digit]!=true){
                fl[digit]=true;
                hash[i][digit] = j;
            }
        }
    }
    vector<vector<ll>> hash1(n2, vector<ll>(10, -1));
    for(ll i = 0; i < n2; i++){
        ll sum = 0;
        vector<bool> fl(10, false);
        for(ll j = i; j < n2; j++){
            sum += (b[j] - '0'); 
            ll digit = sum % 10;
            if(!fl[digit]){
                fl[digit] = true;
                hash1[i][digit] = j;
            }
        }
    }
    vector<vector<ll>> dp(n1+1,vector<ll>(n2+1,-1));
    ll ans = func(0,0,hash,hash1,a,b,dp);
    if(ans<0) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
