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
    vector<pair<ll,char>> vec;
    for(char c='a'; c<='z'; c++){
        vec.push_back({0, c});
    }
    map<char,ll> mpp;
    ll ans = 1e9;
    ll target = 1;
    for(ll i=0;i<n;i++) {
        mpp[s[i]]++;
        vec[s[i]-'a'].first++;
    }
    sort(vec.rbegin(),vec.rend());
    for(ll k=1;k<=26;k++){
        if((n%k)!=0) continue;
        ll freq = n/k;
        ll unchanged = 0;
        for(ll i = 0;i<k;i++){
            unchanged+=min(vec[i].first, freq);
        }
        ll changed = n- unchanged;
        if(changed<ans){
            ans = changed;
            target = k;
        }
    }
    ll freq = n/target;
    cout<<ans<<endl;
    map<char,ll> mpp1;
    vector<ll> vis(n,0); 
    for(ll i=0;i<target;i++) mpp1[vec[i].second] = freq;
    for(ll i=0;i<n;i++){
        char ch = s[i];
        if(mpp1.find(ch)!=mpp1.end()){
            vis[i] = 1;
            mpp1[ch]--;
            if(mpp1[ch]==0) mpp1.erase(ch);
        }
    }
    for(ll i=0;i<n;i++){
        if(vis[i]==0){
            auto it = mpp1.begin();
            s[i] = it->first;
            mpp1[s[i]]--;
            if(mpp1[s[i]]==0) mpp1.erase(s[i]);
        }
    }
    cout<<s<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
