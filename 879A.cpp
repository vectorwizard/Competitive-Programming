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
    ll sum = accumulate(a.begin(),a.end(),0);
    ll mul = 1;
    ll neg = 0;
    for(ll i=0;i<n;i++){
        if(a[i]==-1) neg++;
        mul*=a[i];
    }
    if(sum<0){
        ll cnt = (abs(sum)+1)/2;
        if((neg-cnt)%2==0){
            cout<<cnt<<endl;
            return;
        }
        else{
            cout<<cnt+1<<endl;
            return;
        }
    }
    else{
        if(mul==-1){
            cout<<1<<endl;
            return;
        }
        else {
            cout<<0<<endl;
            return;
        }
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
