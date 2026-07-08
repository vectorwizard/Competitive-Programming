#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<ll> primes; 
vector<ll> a;
void sieve(){
    for(ll i=2;i<400000;i++){
        if(primes[i]==1){
            for(ll j=i*i;j<400000;j=j+i){
                primes[j] = 0;
            }
        }
    }
    for(ll i=2;i<400000;i++){
        if(primes[i]==1) a.push_back(i);
    }
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> ans(n);
    ll pt = 1;
    for(ll i=0;i<n;i++){
        ans[i] = 1LL* a[pt] * a[pt-1];
        pt++;
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t;
    primes.assign(400000,1);
    sieve();
    cin>>t;
    while (t--) solve();
    return 0;
}