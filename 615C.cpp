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
    vector<ll> ans;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
            ll x = n/i;
            bool fl = false;
            for(ll j=i+1;j*j<x;j++){
                if(x%j==0){
                    ans.push_back(j);
                    ans.push_back(x/j);
                    fl = true;
                    break;
                }
            }
            if(fl) break;
            ans.pop_back();
        }
    }
    if(ans.size()!=3) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
