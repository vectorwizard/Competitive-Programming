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
    int l = 0;
    int r = n-1;
    while(l<r){
        if(s[l]!=s[r]){
            break;
        }
        l++;
        r--;
    }
    if(l>=r){
        cout<<0<<endl;
        return;
    }
    else if((r-l)==1){
        if(s[l]!=s[r]){
            cout<<1<<endl;
            return;
        }
        else{
            cout<<0<<endl;
            return;
        } 
    }
    char ch1 = s[r];
    char ch2 = s[l];
    int ans1 = 1;
    int ans2 = 1;
    int left = l;
    int right = r-1;
    while(left<right){
        if(s[left]==s[right]){
            left++;
            right--;
        }
        else if(s[left]!=s[right]){
            if(s[left]==ch1){
                left++;
                ans1++;
            }
            else if(s[right]==ch1){
                right--;
                ans1++;
            }
            else{
                ans1 = 1e9;
                break;
            }
        }
    }
    left = l+1;
    right = r;
    while(left<right){
        if(s[left]==s[right]){
            left++;
            right--;
        }
        else if(s[left]!=s[right]){
            if(s[left]==ch2){
                left++;
                ans2++;
            }
            else if(s[right]==ch2){
                right--;
                ans2++;
            }
            else{
                ans2 = 1e9;
                break;
            }
        }
    }
    if(ans1>=1e9 && ans2>=1e9) cout<<-1<<endl;
    else{
        cout<<min(ans1,ans2)<<endl;
    }
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
