#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll n,k;
    cin>>n>>k;
    if(k==n-1){
        cout<<-1<<endl;
        return;
    }
    ll ones = (n+1)/2;
    ll zeros = n/2;
    ll blocks = n - k;
    string ans = "";
    for(ll i=0;i<blocks;i++){
        if(i%2==0){
            ll need = 1;
            if(i==0) need = ones - (blocks+1)/2 + 1;
            for(ll j=0;j<need;j++) ans+='1';
        }
        else{
            ll need = 1;
            if(i==1) need = zeros - (blocks/2) + 1;
            for(ll j=0;j<need;j++) ans+='0';
        }
    }
    cout<<ans<<endl;
} 

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
