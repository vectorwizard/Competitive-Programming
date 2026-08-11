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
    int i = 0;
    int j = n-1;
    while(i<j){
        if(s[i]!=s[j]){
            i++;
            j--;
        }
        else break;
    }
    cout<<(j-i+1)<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
