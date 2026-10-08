
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    ll ans = 0;
    set<ll> normal;
    set<ll> zero;
    for(ll i=0;i<n;i++){
        if(b[i]>a[i]){
            cout<<"NO"<<endl;
            return;
        }
        else{
            if(b[i]==0) zero.insert(a[i]-b[i]);
            else normal.insert(a[i]-b[i]);
        }
    }
    if(normal.size()==0){
        cout<<"YES"<<endl;
        return;
    }
    if(normal.size()>1){
        cout<<"NO"<<endl;
        return;
    }
    if(zero.size()==0){
        cout<<"YES"<<endl;
        return;
    }
    if(*zero.rbegin()>*normal.begin()){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}