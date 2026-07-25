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
    for(ll i=0;i<n-k+1;i++){
        for(ll offset=0;offset<3;offset++){
            ll ind = 0 + offset;
            ll cnt = 0;
            for(ll j = i;j<i+k;j++){
                if(s[j]!=match[ind]) cnt++;
                ind = (ind+1)%3;
            }
            mini = min(mini,cnt);
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
