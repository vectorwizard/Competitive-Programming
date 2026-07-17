#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    string s;
    cin>>s;
    int n = s.size();
    int zeros = 0;
    int ones = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='0') zeros++;
        else ones++;
    }
    int mini = min(ones,zeros);
    if(mini%2==0){
        cout<<"NET"<<endl;
        return;
    }
    cout<<"DA"<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
