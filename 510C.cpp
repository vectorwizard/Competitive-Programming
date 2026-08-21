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
    ll neg = 0;
    ll pos = 0;
    ll zero = 0;
    for(ll i=0;i<n;i++){
        if(a[i]<0) neg++;
        else if(a[i]>0) pos++;
        else zero++;
    }
    if(zero==0){
        if(neg%2==0){
            for(ll i=0;i<n-1;i++){
                cout<<1<<" "<<i+1<<" "<<n<<endl;
            }
            return;
        }
        else{
            ll mini = 1e18;
            ll ind = -1;
            for(ll i=0;i<n;i++){
                if(a[i]<0){
                    if(abs(a[i])<mini){
                        ind = i;
                        mini = abs(a[i]);
                    }
                }
            }
            if(ind!=0){
                cout<<2<<" "<<ind+1<<endl;
                for(ll i=1;i<n;i++){
                    if(i==ind) continue;
                    cout<<1<<" "<<i+1<<" "<<1<<endl;
                }
            }
            else{
                cout<<2<<" "<<ind+1<<endl;
                for(ll i=0;i<n-1;i++){
                    if(i==ind) continue;
                    cout<<1<<" "<<i+1<<" "<<n<<endl;
                }
            }
            return;
        }
    }
    else{
        if(neg%2==0){
            vector<ll> bad;
            set<ll> bads;
            for(ll i=0;i<n;i++){
                if(a[i]==0){
                    bad.push_back(i);
                    bads.insert(i);
                }
            }
            for(ll i=1;i<bad.size();i++){
                cout<<1<<" "<<bad[i]+1<<" "<<bad[0]+1<<endl;
            }
            if(bad.size() == n) return;
            cout<<2<<" "<<bad[0]+1<<endl;
            vector<ll> good;
            for(ll i=0;i<n;i++){
                if(bads.count(i)>0) continue;
                good.push_back(i);
            }
            for(ll i=1;i<good.size();i++){
                cout<<1<<" "<<good[i]+1<<" "<<good[0]+1<<endl;
            }
        }
        else{
            ll mini = 1e18;
            ll ind = -1;
            for(ll i=0;i<n;i++){
                if(a[i]<0){
                    if(abs(a[i])<mini){
                        ind = i;
                        mini = abs(a[i]);
                    }
                }
            }
            vector<ll> bad;
            set<ll> bads;
            for(ll i=0;i<n;i++){
                if(a[i]==0){
                    bad.push_back(i);
                    bads.insert(i);
                }
            }
            bad.push_back(ind);
            bads.insert(ind);
            for(ll i=1;i<bad.size();i++){
                cout<<1<<" "<<bad[i]+1<<" "<<bad[0]+1<<endl;
            }
            if(bad.size() == n) return;
            cout<<2<<" "<<bad[0]+1<<endl;
            vector<ll> good;
            for(ll i=0;i<n;i++){
                if(bads.count(i)>0) continue;
                good.push_back(i);
            }
            for(ll i=1;i<good.size();i++){
                cout<<1<<" "<<good[i]+1<<" "<<good[0]+1<<endl;
            }
        }
    }
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}