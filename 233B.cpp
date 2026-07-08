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
    bool fl = true;
    for(int i=1;i<n-1;i++){
        if(s[i-1]==s[i+1] && s[i]!=s[i-1]) continue;
        else{
            fl = false;
            break;
        }
    }
    if(s[n-1]!=s[1] || s[0]==s[1] || s[0]==s[n-1]) fl = false;
    if(s[n-2]!=s[0] || s[n-1]==s[n-2] || s[n-1]==s[0]) fl = false;
    if(fl == true && n%2==0){
        cout<<-1<<endl;
        return;
    }
    string s1 = s+s;
    int maxi = 0;
    int curr = 0;
    for(int i=1;i<2*n-1;i++){
        if(s1[i]!=s1[i-1]){
            curr++;
            maxi = max(maxi,curr);
        }
        else{
            curr = 0;
        }
    }
    cout<<(maxi/2)+1<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
