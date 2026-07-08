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
    ll ones = 0;
    ll twos = 0;
    ll threes = 0;
    vector<ll> one(n,0);
    vector<ll> two(n,0);
    vector<ll> three(n,0);
    if(a[0]==1) one[0] = 1;
    else if(a[0]==2) two[0] = 1;
    else three[0] = 1;
    if(a[0]==1) ones++;
    else if(a[0]==2) twos++;
    else threes++;
    for(ll i=1;i<n;i++){
        if(a[i]==1) ones++;
        else if(a[i]==2) twos++;
        else threes++;
        one[i] = ones;
        two[i] = twos;
        three[i] = threes;
    }
    vector<ll> val(n);
    for(ll k=0; k<n; k++) {
        val[k] = one[k] + two[k] - three[k];
    }
    vector<ll> vec(n);
    vec[n-2] = val[n-2]; 
    for(ll k=n-3; k>=0; k--) {
        vec[k] = max(val[k], vec[k+1]);
    }
    for(ll i=1;i<n-1;i++){
        if((one[i-1])>=(two[i-1]+three[i-1])){
            ll req = one[i-1]+two[i-1]-three[i-1];
            if(vec[i]>=req){
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
