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
    if(n==2){
        cout<<-1<<endl;
        return;
    }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    vector<ll> ans = {1,2,3};
    ll sum = 6;
    for(ll i=3;i<n;i++){
        ans.push_back(sum);
        sum*=2;
    }
    for(auto it:ans){
        cout<<it<<" ";
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
