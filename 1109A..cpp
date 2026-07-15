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
    int maxi = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='#') cnt++;
        else{
            maxi = max(maxi,cnt);
            cnt = 0;
        }
    }
    maxi = max(maxi,cnt);
    cout<<(maxi+1)/2<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
