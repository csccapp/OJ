#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll P = 1e7 + 19;
const ll MAXN = 1010;
ll powP[MAXN], H1[MAXN] = {0}, H2[MAXN] = {0};
vector<pair<int ,int>>pr1, pr2;
void init(int len){
    powP[0] = 1;
    for (int i = 1; i <= len; ++i){
        powP[i] = (powP[i - 1] * P) % MOD;
    }
} 

void calH(ll H[], string str){
    H[0] = str[0];
    for (int i = 1; i < str.length(); ++i){
        H[i] = (H[i - 1] * P + str[i]) % MOD;
    }
}

int calSingleSubH(ll H[], int i, int j){
    if(i == 0)
        return H[j];
    return ((H[j] - H[i - 1] * powP[j - i + 1]) % MOD + MOD) % MOD;
}

void calSubH(ll H[], int len, vector<pair<int, int>> &pr){
    for (int i = 0; i < len; ++i){
        for (int j = i; j < len; ++j){
            int hashValue = calSingleSubH(H, i, j);
            pr.push_back(make_pair(hashValue, j - i + 1));
        }
    }
}

int getMax(){
    int ans = 0;
    for (int i = 0; i < pr1.size(); ++i){
        for(int j = 0; j < pr2.size(); ++j){
            if(pr1[i].first == pr2[j].first)
                ans = max(ans, pr1[i].second);
        }
    }
    return ans;
}

int main(){
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    init(max(str1.length(), str2.length()));
    calH(H1, str1);
    calH(H2, str2);
    calSubH(H1, str1.length(), pr1);
    calSubH(H2, str2.length(), pr2);
    printf("ans = %d\n", getMax());
    system("pause");
    return 0;
}