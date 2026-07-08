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
    if(a[n-2]>a[n-1]){
        cout<<-1<<endl;
        return;
    }
    ll ops_cnt = 0;
    vector<vector<ll>> ops;
    for(ll i=n-3;i>=0;i--){
        if(a[i]<=a[i+1]) continue;
        if(a[n-1]<0){
            cout<<-1<<endl;
            return;
        }
        else{
            a[i] = a[i+1] - a[n-1];
            ops_cnt++;
            ops.push_back({i,i+1,n-1});
        }
    }
    cout<<ops_cnt<<endl;
    for(auto it:ops){
        for(ll i=0;i<3;i++){
            cout<<it[i]+1<<" ";
        }
        cout<<endl;
    }
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
