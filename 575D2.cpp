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
    string s;
    cin>>s;
    map<char,char> mpp;
    string match = "RGB";
    ll mini = n;
    vector<ll> ans(3,n);
    vector<ll> ind(3,0);
    ind[1] = 1;
    ind[2] = 2;
    ll l = 0;
    for(ll offset = 0;offset<3;offset++){
        ll cnt = 0;
        for(ll i=0;i<k;i++){
            if(s[i]!=match[ind[offset]]) cnt++;
            ind[offset] = (ind[offset]+1)%3;
        }
        ans[offset] = cnt;
        mini = min(mini,cnt);
    }
    for(ll offset = 0;offset<3;offset++){
        ll l = 0;
        for(ll r = k;r<n;r++){
            if(s[r]!=match[ind[offset]]) ans[offset]++;
            if(s[l] != match[(l+offset)%3]) ans[offset]--;
            l++;
            ind[offset] = (ind[offset]+1)%3;
            mini = min(mini,ans[offset]);
        }
    }
    cout<<mini<<endl;
} 

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
