#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll total = accumulate(a.begin(),a.end(),0);
    if(total==x){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        ll y = -1;
        ll sum = 0;
        for(ll i=0;i<n;i++){
            if((sum+a[i])==x){
                y = a[i];
            }
            else{
                cout<<a[i]<<" ";
                sum+=a[i];
            }
        }
        if(y!=-1) cout<<y<<" ";
        cout<<endl;
    } 
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}