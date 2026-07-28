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
    vector<ll> w(n);
    for(ll i=0;i<n;i++) cin>>w[i];
    if(n%2==1){
        cout<<"NO"<<endl;
        return;
    }
    vector<ll> sorted = w;
    sort(sorted.begin(),sorted.end());
    ll diff = sorted[n/2] - sorted[n/2-1];
    if(diff<=1){
        cout<<"NO"<<endl;
        return;
    }
    map<ll,ll> mpp;
    for(ll i=0;i<n;i++) mpp[i]=1;
    ll mid = (sorted[n/2] + sorted[n/2-1])/2;
    for(ll i=0;i<n;i++){
        if(w[i]>mid){
            mpp[i]--;
            mpp[i+1]++;
        }
        else{
            mpp[i]--;
            mpp[i-1]++;
        }
    }
    for(ll i=0;i<n;i++){
        if(mpp[i]!=1){
            cout<<"NO"<<endl;
            return;
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
