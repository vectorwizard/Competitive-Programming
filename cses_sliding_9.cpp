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
    ll leftsum = 0;
    ll rightsum = 0;
    for(ll i=0;i<k;i++){
        if(left.size()<=right.size()){
            left.insert(a[i]);
            leftsum+=a[i];
        }
        else {
            right.insert(a[i]);
            rightsum+=a[i];
        }
        if(!right.empty() && *left.rbegin()>*right.begin()){
            ll x = *left.rbegin();
            ll y = *right.begin();
            leftsum-=x;
            leftsum+=y;
            rightsum-=y;
            rightsum+=x;
            left.erase(left.find(x));
            left.insert(y);
            right.insert(x);
            right.erase(right.find(y));
        }
    }
    ll median = *left.rbegin();
    ll cost = (median * left.size()) - leftsum;
    cost += rightsum - (right.size() * median);
    cout<<cost<<" ";
    ll l = 0;
    for(ll r=k;r<n;r++){
        if(left.size()<=right.size()){
            left.insert(a[r]);
            leftsum+=a[r];
        }
        else {
            right.insert(a[r]);
            rightsum+=a[r];
        }
        if(!right.empty() && *left.rbegin()>*right.begin()){
            ll x = *left.rbegin();
            ll y = *right.begin();
            leftsum-=x;
            leftsum+=y;
            rightsum-=y;
            rightsum+=x;
            left.erase(left.find(x));
            left.insert(y);
            right.insert(x);
            right.erase(right.find(y));
        }
        if(left.find(a[l])!=left.end()){
            left.erase(left.find(a[l]));
            leftsum-=a[l];
        }
        else{
            right.erase(right.find(a[l]));
            rightsum-=a[l];
        }
        if(left.size()>right.size()+1){
            ll x = *left.rbegin();
            left.erase(left.find(x));
            leftsum-=x;
            right.insert(x);
            rightsum+=x;
        }
        else if(right.size()>left.size()){
            ll x = *right.begin();
            right.erase(right.find(x));
            rightsum-=x;
            left.insert(x);
            leftsum+=x;
        }
        ll median = *left.rbegin();
        ll cost = (median * left.size()) - leftsum;
        cost += rightsum - (right.size() * median);
        cout<<cost<<" ";
        l++;
    }
    cout<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}