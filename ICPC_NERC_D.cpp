#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    string s,t;
    cin>>s>>t;
    int n1 = s.size();
    int n2 = t.size();
    int i = n1-1;
    int j = n2-1;
    set<char> deletions;
    while(i>=0 && j>=0){
        if(s[i]==t[j]){
            if(deletions.count(s[i])){
                cout<<"NO"<<endl;
                return;
            }
            else j--;
        }
        else{
            deletions.insert(s[i]);
        }
        i--;
    }
    if(j<0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
