#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> spf;
void sieve(){
    for(ll i=1;i<=1e5;i++){
        spf[i] = i;
    }
    for(ll i=2;i*i<=1e5;i++){
        if(spf[i]!=i) continue;
        for(ll j=i*2;j<=1e5;j+=i){
            if(spf[j]==j) spf[j] = i;
        }
    }
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    spf.assign(1e5+1,0);
    sieve();
    map<map<ll,ll>,ll> mpp;
    ll ans=  0;
    for(ll i=0;i<n;i++){
        ll x = a[i];
        map<ll,ll> hash;
        while(x>1){
            hash[spf[x]]++;
            x = x/spf[x];
        }
        for(auto &it:hash){
            it.second = it.second%k;
        }
        map<ll,ll> temp;
        for(auto &it:hash){
            if(it.second==0) continue;
            temp[it.first] = it.second;
        }
        mpp[temp]++;
    }
    for(ll i=0;i<n;i++){
        ll x = a[i];
        map<ll,ll> hash;
        while(x>1){
            hash[spf[x]]++;
            x = x/spf[x];
        }
        map<ll,ll> need;
        map<ll,ll> temp;
        for(auto &it:hash){
            ll rem = it.second % k;
            if(rem>0){
                ll needed = k - rem;
                temp[it.first] = rem;
                need[it.first] = needed;
            }
        }
        if(mpp.find(need)!=mpp.end()){
            ans+=mpp[need];
            if(temp==need) ans--;
        }
    }
    cout<<ans/2<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}