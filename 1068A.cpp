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
    int extra = 0;
    int rest = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            if(extra==0){
                rest++;
            }
            if(extra>0) extra--;
        }
        if(s[i]=='1'){
            extra=k;
        }
    }
    cout<<rest<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}