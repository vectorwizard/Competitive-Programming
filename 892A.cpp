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
    sort(a.begin(),a.end());
    vector<ll> b;
    vector<ll> c;
    b.push_back(a[0]);
    for(ll i=1;i<n;i++){
        if(a[i]==a[0]) b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    if(c.size()==0){
        cout<<-1<<endl;
        return;
    }
    cout<<b.size()<<" "<<c.size()<<endl;
    for(auto it:b){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it:c){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
