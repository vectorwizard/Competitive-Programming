#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    multiset<ll> left;
    multiset<ll> right;
    for(ll i=0;i<k;i++){
        if(left.empty() || left.size()<=right.size()) left.insert(a[i]);
        else right.insert(a[i]);
        if(!right.empty() && *left.rbegin()>*right.begin()){
            ll x = *left.rbegin();
            ll y = *right.begin();
            left.erase(left.find(x));
            right.erase(right.find(y));
            left.insert(y);
            right.insert(x);
        }
    }
    cout<<*left.rbegin()<<" ";
    ll l = 0;
    for(ll r = k;r<n;r++){
        if(left.empty() || left.size()<=right.size()) left.insert(a[r]);
        else right.insert(a[r]);
        if(!right.empty() && *left.rbegin()>*right.begin()){
            ll x = *left.rbegin();
            ll y = *right.begin();
            left.erase(left.find(x));
            right.erase(right.find(y));
            left.insert(y);
            right.insert(x);
        }
        if(left.find(a[l])!=left.end()){
            left.erase(left.find(a[l]));
        }
        else{
            right.erase(right.find(a[l]));
        }
        if(left.size()>right.size()+1){
           ll x = *left.rbegin();
            left.erase(left.find(x));
            right.insert(x);
        }
        else if(right.size()>left.size()){
           ll x = *right.begin();
            right.erase(right.find(x));
            left.insert(x);
        }
        l++;
        cout<<*left.rbegin()<<" ";
    }
    cout<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}