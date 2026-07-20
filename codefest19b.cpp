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
    ll mini = 1e9;
    unordered_map<ll,ll> mpp;
    for(ll i=0;i<n;i++) mpp[a[i]]++;
    if(mpp.size()==n){
        cout<<0<<endl;
        return;
    }
    for(ll i=0;i<n;i++){
        unordered_map<ll,ll> temp = mpp;
        for(ll j=i;j<n;j++){
            temp[a[j]]--;
            if(temp[a[j]]==0) temp.erase(a[j]);
            ll size = n-(j-i+1);
            if(size==temp.size()){
                mini = min(mini,j-i+1);
            }
        }
    }
    cout<<mini<<endl;
} 

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
