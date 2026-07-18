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
    ll neg = 0;
    ll pos = 0;
    ll zeros = 0;
    for(ll i=0;i<n;i++){
        if(a[i]<0) neg++;
        else if(a[i]>0) pos++;
        else zeros++;
    }
    if(neg>2 || pos>2){
        cout<<"NO"<<endl;
        return;
    }
    vector<ll> vec;
    for(ll i=0;i<n;i++){
        if(a[i]!=0) vec.push_back(a[i]); 
    }
    zeros = min(2LL,zeros);
    while(zeros>0){
        vec.push_back(0);
        zeros--;
    }
    ll m = vec.size();
    a = vec;
    for(ll i=0;i<m;i++){
        for(ll j=0;j<m;j++){
            for(ll k=0;k<m;k++){
                if(i==j) continue;
                if(k==j) continue;
                if(i==k) continue;
                ll sum = a[i] + a[j] + a[k];
                bool fl = false;
                for(ll l=0;l<m;l++){
                    if(sum==a[l]){
                        fl = true;
                        break;
                    }
                }
                if(!fl){
                    cout<<"NO"<<endl;
                    return;
                }
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
