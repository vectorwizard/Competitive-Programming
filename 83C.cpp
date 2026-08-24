#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> func(ll n,ll k){
    vector<ll> ans;
    while(n>0){
        ll rem = n%k;
        n = n/k;
        ans.push_back(rem);
    }
    return ans;
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<vector<ll>> vec;
    for(ll i=0;i<n;i++){
        vector<ll> temp = func(a[i],k);
        vec.push_back(temp);
    }
    vector<ll> hash(65,0);
    for(ll i=0;i<vec.size();i++){
        vector<ll> temp = vec[i];
        for(ll j=0;j<temp.size();j++){
            if(temp[j]>1){
                cout<<"NO"<<endl;
                return;
            }
            if(temp[j]==1){
                if(hash[j]!=0){
                    cout<<"NO"<<endl;
                    return;
                }
                hash[j] = 1;
            }
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}