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
    string s;
    cin>>s;
    ll m;
    cin>>m;
    vector<vector<ll>> hash(26,vector<ll>(n,0));
    hash[s[0]-'a'][0] = 1;
    for(ll i=0;i<26;i++){
        for(ll j = 0;j<n;j++){
            ll x = 0;
            char ch = 'a' + i;
            if(ch==s[j]) x = 1;
            if(j>0) hash[i][j] = hash[i][j-1] + x;
            else hash[i][j] = x;
        }
    }
    while(m--){
        string t;
        cin>>t;
        ll n1 = t.size();
        ll maxi = 0;
        vector<ll> vec(26,0);
        for(ll i=0;i<n1;i++){
            vec[t[i]-'a']++;
        }
        for(ll i=0;i<26;i++){
            ll target = vec[i];
            if(target==0) continue;
            ll ind = lower_bound(hash[i].begin(),hash[i].end(),target) - hash[i].begin();
            maxi = max(maxi,ind+1);
        }
        cout<<maxi<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
