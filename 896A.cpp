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
    if(n%2==0){
        cout<<2<<endl;
        cout<<1<<" "<<n<<endl;
        cout<<1<<" "<<n<<endl;
        return;
    }
    else{
        cout<<4<<endl;
        cout<<1<<" "<<(n-1)<<endl;
        cout<<1<<" "<<(n-1)<<endl;
        cout<<(n-1)<<" "<<n<<endl;
        cout<<(n-1)<<" "<<n<<endl;
    }
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
