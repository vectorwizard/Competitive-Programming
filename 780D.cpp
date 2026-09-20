#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> func(ll l,ll r,vector<ll> &a){
    ll n = a.size();
    ll mini = 1e9;
    ll cnt = 0;
    ll ind;
    ll x,y;
    ll neg=0;
    ll tot=0;
    for(ll i = l;i<r;i++){
        if(abs(a[i])==2) tot++;
        if(a[i]<0) neg++;
    }
    if(neg%2==0) return {tot,0,0};
    for(ll i=l;i<r;i++){
        if(abs(a[i])==2){
            cnt++;
        }
        if(a[i]<0){
            mini = min(mini,cnt);
            ind = i+1;
            x = i+1;
            y = 0;
            break;
        }
    }
    cnt = 0;
    ll mini1 = 1e9;
    for(ll i=r-1;i>=l;i--){
        if(abs(a[i])==2){
            cnt++;
        }
        if(a[i]<0){
            mini1 = min(mini1,(cnt));
            if(mini1<mini){
                return {tot-mini1,0,r-i};
            }
            else{
                return {tot-mini,x-l,0};
            }
        }
    }
    return {0,0,0};
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    ll l = 0;
    ll ansl=n,ansr=0;
    ll ans = -1;
    while(l<n && a[l]==0) l++;
    ll twos = 0;
    for(ll r=l;r<=n;r++){
        if(r==n || a[r]==0){
            if(l<=r){
                vector<ll> temp = func(l,r,a);
                if(temp[0]>ans){
                    ans = temp[0];
                    ansl = l+temp[1];
                    ansr = (n-r)+temp[2];
                }
            }
            twos = 0;
            l = r+1;
        }
    }
    cout<<ansl<<" "<<ansr<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}