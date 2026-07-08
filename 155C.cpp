#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const ll mod = 998244353;
vector<ll> fact; 
void func(ll maxi){
    fact.assign(maxi+1,0);
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2;i<=maxi;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
}
void solve() {
    string s;
    cin>>s;
    ll ways = 1;
    ll n = s.size();
    ll cnt = 0;
    ll cns = 1;
    for(ll i=1;i<n;i++){
        if(s[i]==s[i-1]){
            cns++;
        }
        else{
            ways = (ways*cns)%mod;
            cnt+=(cns-1);
            cns = 1;
        }
    }
    cnt+=(cns-1);
    ways=(ways*cns)%mod;
    ways = (ways*fact[cnt])%mod;
    cout<<cnt<<" "<<ways<<endl;
}

int main() {
    fastio();
    func(1e6);
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}

