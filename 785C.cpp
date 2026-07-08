#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const ll mod = 1e9 + 7;
vector<ll> palindromes;
int dp[505][40005];
bool ispalin(ll n){
    string s = to_string(n);
    ll siz = s.size();
    ll l = 0;
    ll r = siz-1;
    while(l<r){
        if(s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return true;
}
void palindrome(){
    for(ll i = 1; i <= 40000; i++) {
        if(ispalin(i)) {
            palindromes.push_back(i);
        }
    }
}
ll func(ll ind,ll n,ll siz){
    if(ind==siz){
        if(n==0) return 1;
        return 0;
    }
    if(dp[ind][n]!=-1) return dp[ind][n];
    ll take = 0;
    ll nottake = 0;
    if(palindromes[ind]<=n) take = func(ind,n-palindromes[ind],siz)%mod;
    nottake = func(ind+1,n,siz)%mod;
    return dp[ind][n]=(take+nottake)%mod;
}
void solve() {
    ll n;
    cin>>n;
    ll x = palindromes.size();
    ll ans = func(0,n,x)%mod;
    cout<<ans<<endl;
}

int main() {
    fastio();
    palindrome();
    sort(palindromes.begin(),palindromes.end());
    memset(dp,-1,sizeof(dp));
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
