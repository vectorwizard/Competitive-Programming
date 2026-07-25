#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

map<ll,pair<ll,ll>> mpp; //{prime, {lowest, s_lowest}}
map<ll,ll> freq;
vector<ll> spf;
void sieve(){
    for(ll i=2;i<spf.size();i++){
        if(spf[i]==i){
            for(ll j = i*2;j<spf.size();j+=i){
                if(spf[j]==j) spf[j] = i;
            }
        }
    }
}

void func(ll n){
    while(n>1){
        ll cnt = 0;
        ll spff = spf[n];
        while(n%spff==0){
            cnt++;
            n = n/spff;
        }
        freq[spff]++;
        if(mpp.find(spff)==mpp.end()){
            mpp[spff] = {cnt,1e9};
        }
        else{
            if(cnt<mpp[spff].first){
                mpp[spff].second = mpp[spff].first;
                mpp[spff].first = cnt;
            }
            else if(cnt<=mpp[spff].second){
                mpp[spff].second = cnt;
            }
        }
    }
}

ll power(ll a,ll b){
    if(b==0) return 1;
    ll x = power(a,b/2);
    x = x*x;
    if(b%2==1){
        x = x*a;
    }
    return x;
}

void solve() {  
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    spf.resize(*max_element(a.begin(),a.end())+1);
    for(ll i = 0;i<spf.size();i++){
        spf[i] = i;
    }
    sieve();
    for(ll i=0;i<n;i++){
        func(a[i]);
    }
    ll ans = 1;
    for(auto it:mpp){
        ll x = it.first;
        if(freq[x]==n){
            ans = ans * power(it.first,it.second.second);
        }
        else if(freq[x]==n-1){
            ans = ans * power(it.first,it.second.first);
        }
    }
    cout<<ans<<endl;
} 

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
