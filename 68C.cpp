#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    string s,t,p;
    cin>>s>>t>>p;
    int n = s.size();
    int m = t.size();
    if(n>m){
        cout<<"NO"<<endl;
        return;
    }
    int i = 0;
    map<char,int> mpp;
    for(int i=0;i<p.size();i++){
        mpp[p[i]]++;
    }
    for(int j=0;j<m;j++){
        if(i<n && s[i]==t[j]){
            i++;
        }
        else{
            if(mpp[t[j]]<=0){
                cout<<"NO"<<endl;
                return;
            }
            mpp[t[j]]--;
        }
    }
    if(i!=n){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
