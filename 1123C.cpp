#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> spf(1e6,1);
void sieve(){
    for(ll i=0;i<1e6;i++){
        spf[i] = i;
    }
    for(ll i=2;i<1e6;i++){
        if(spf[i]==i){
            for(ll j=i*i;j<1e6;j+=i){
                if(spf[j]==j) spf[j] = i;
            }
        }
    }
} 

void solve() {
    ll n,y;
    cin>>n>>y;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    map<ll,ll> mult;
    for(ll i=0;i<n;i++){
        ll x = a[i];
        set<int> st;
        while(x>1){
            if(st.count(spf[x])==0){
                mult[spf[x]]+=(a[i]/spf[x]);
                st.insert(spf[x]);
            }
            x/=spf[x];
        }
    }
    ll maxi = 0;
    set<ll> st;
    while(y>1){
        st.insert(spf[y]);
        y/=spf[y];
    }
    for(auto it:st){
        maxi = max(maxi,mult[it] * it);
    }
    cout<<maxi<<endl;
}

int main() {
    fastio();
    ll t=1;
    sieve();
    cin>>t;
    while (t--) solve();
    return 0;
}
