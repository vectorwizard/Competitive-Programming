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
    ll bad_zero = 0;
    ll bad_one = 0;
    ll good_one = 0;
    ll good_zero = 0;
    for(ll i=0;i<n;i++){
        if(a[i]!=b[i]){
            if(a[i]==0) bad_zero++;
            else bad_one++;
        }
        else{
            if(a[i]==1) good_one++;
            else good_zero++;
        }
    }
    if((bad_zero+bad_one)==0){
        cout<<0<<endl;
        return;
    }
    if(bad_zero>0 && bad_one==0){
        if(good_zero>0 && good_one>0){
            cout<<2<<endl;
        }
        else cout<<-1<<endl;
        return;
    }
    if(bad_one%2==0){
        cout<<2<<endl;
        return;
    }
    else cout<<1<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
