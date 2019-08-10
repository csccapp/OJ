#include<iostream>
using namespace std;

const int maxn = 1e5 + 10;
bool h[maxn];
int n;

int main(){
	scanf("%d", &n);
	int num;
	for(int i = 0; i < n; ++i){
		scanf("%d", &num);
		if(num >= 0 && num <= n){
			h[num] = true;
		}
	}
	for(int i = 1; i <= n + 1; ++i){
		if(!h[i]){
			printf("%d", i);
			break;
		}
	}
	return 0;
}
 