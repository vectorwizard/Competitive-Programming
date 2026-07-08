#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    char c;
    cin>>n;
    cin>>c;
    string s;
    cin>>s;
    s = s + s;
    int maxi = 0;
    vector<int> cs;
    vector<int> gs;
    for(int i=0;i<2*n;i++){
        if(s[i]==c) cs.push_back(i);
        else if(s[i]=='g') gs.push_back(i);
    }
    for(auto it:cs){
        int ind = lower_bound(gs.begin(),gs.end(),it) - gs.begin();
        if(ind==gs.size()) continue;
        else maxi = max(maxi,(gs[ind]-it));
    }
    cout<<maxi<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
