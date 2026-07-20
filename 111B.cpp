#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll n,k,m;
    cin>>n>>k>>m;
    if(k>m){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    ll cnt = 0;
    for(ll i=0;i<k-1;i++){
        cnt++;
        cout<<1<<" ";
    }
    cout<<(m-cnt)<<" ";
    for(ll i=0;i<(n-k);i++){
        cout<<1<<" ";
    }
    cout<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
