#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
bool func(ll mid,vector<ll> &a,vector<ll> &b){
    ll n = a.size();
    ll ones = 0;
    ll zeros = 0;
    ll prev = -1;
    if(a[0]>=mid && b[0]>=mid) {
        ones++;
        prev = 1;
    }
    else if(a[0]<mid && b[0]<mid) {
        zeros++;
        prev = 0;
    }
    for(ll i=1;i<n;i++){
        ll vala = 0;
        ll valb = 0;
        if(a[i]>=mid) vala = 1;
        if(b[i]>=mid) valb = 1;
        if(vala+valb==1) continue;
        if(vala+valb==0){
            if(prev==0){
                continue;
            }
            else {
                zeros++;
                prev = 0;
            }
        }
        else {
            ones++;
            prev = 1;
        }
    }
    if(ones>zeros) return true;
    return false;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    ll low = 1;
    ll maxi1 = *max_element(a.begin(),a.end());
    ll maxi2 = *max_element(b.begin(),b.end());
    ll high = max(maxi1,maxi2);
    ll ans = 1;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,a,b)){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    cout<<ans<<endl;
}
int main(){
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}