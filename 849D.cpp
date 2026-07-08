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
    vector<int> prefix(n,0);
    map<char,int> mpp;
    int cnt = 0;
    for(int i=0;i<n;i++){
        mpp[s[i]]++;
        if(mpp[s[i]]<=1){
            cnt++;
        }
        prefix[i] = cnt;
    }
    vector<int> suffix(n,0);
    map<char,int> mpp1;
    cnt = 0;
    for(int i=n-1;i>=0;i--){
        mpp1[s[i]]++;
        if(mpp1[s[i]]<=1){
            cnt++;
        }
        suffix[i] = cnt;
    }
    int maxi = 0;
    for(int i=1;i<n;i++){
        maxi = max(maxi,(prefix[i-1]+suffix[i]));
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
