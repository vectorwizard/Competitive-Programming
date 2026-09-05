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
    vector<ll> pos;
    vector<ll> neg;
    for(ll i=0;i<n;i++){
        if(a[i]>=0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }
    ll maxi = *max_element(a.begin(),a.end());
    ll mini = *min_element(a.begin(),a.end());
    if(maxi==0){
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    ll sum = 0;
    ll i = 0;
    ll j = 0;
    for(ll k=0;k<n;k++){
        if(i==pos.size()){
            cout<<neg[j]<<" ";
            sum+=neg[j];
            j++;
        }
        else if(j==neg.size()){
            cout<<pos[i]<<" ";
            sum+=pos[i];
            i++;
        }
        else if(sum>=0){
            cout<<neg[j]<<" ";
            sum+=neg[j];
            j++;
        }
        else{
            cout<<pos[i]<<" ";
            sum+=pos[i];
            i++;
        }
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
