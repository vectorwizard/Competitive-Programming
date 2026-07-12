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
    for(ll i=0;i<n;i++) cin>>a[i];
    ll zeros = 0;
    for(auto it:a){
        if(it==0) zeros++;
    }
    if(zeros==n){
        cout<<0<<endl;
        return;
    }
    if(zeros==0){
        cout<<1<<endl;
    }
    else{
        ll patches = 0;
        ll cnt = 0;
        for(ll i=0;i<n;i++){
            if(a[i]==0){
                if(cnt>0) {
                    patches++;
                    cnt = 0;
                }
            }
            else cnt++;
        }
        if(cnt>0) patches++;
        if(patches==1){
            cout<<1<<endl;
        }
        else cout<<2<<endl;
    }
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
