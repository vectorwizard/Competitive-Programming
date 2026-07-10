#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    int n;
    cin>>n;
    string s;
    cin>>s;
    int maxi = 1;
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            cnt++;
            maxi = max(maxi,cnt);
        }
        else cnt = 1;
    }
    cout<<maxi+1<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
