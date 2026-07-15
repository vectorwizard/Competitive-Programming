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
    map<char,char> mpp;
    for(char ch = 'a';ch<='z';ch++){
        mpp[ch] = ch;
    }
    for(int i=0;i<n;i++){
        char curr = mpp[s[i]];
        if(curr=='a') continue;
        char temp = curr;
        while(k>0){
            if(mpp[temp]<temp){
                temp = mpp[temp];
                if(temp == 'a') break;
                continue;
            }
            k--;
            temp = temp-1;
            if(temp=='a') break;
        }
        while(mpp[temp]<temp){
            temp = mpp[temp];
        }
        for(char ch = temp; ch <= curr; ch++){
            mpp[ch] = min(mpp[ch], temp);
        }
    }
    string ans = "";
    for(int i=0;i<n;i++){
        ans+=mpp[s[i]];
    }
    cout<<ans<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
