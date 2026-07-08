#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    map<int,char> mpp;
    for(int i=0;i<n;i++){
        if(s[i]=='?') continue;
        if(mpp.find(i%k)!=mpp.end()){
            if(s[i]!='?' && s[i]!=mpp[i%k]){
                cout<<"NO"<<endl;
                return;
            }
            mpp[i%k] = s[i];
        }
        else{
            if(s[i]!='?') mpp[i%k]=s[i];
        }
    }
    int ones = 0;
    int zeros = 0;
    int temp = 0;
    for(int i=0;i<k;i++){
        if(mpp[i]=='0') zeros++;
        else if(mpp[i]=='1') ones++;
        else temp++;
    }
    if(ones<=k/2 && zeros<=k/2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}