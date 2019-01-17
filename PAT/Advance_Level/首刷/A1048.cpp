/*===================================================================================
A1048 Find Coins (25)��25 �֣�����
=====================================================================================
Eva loves to collect coins from all over the universe, including some other planets
like Mars. One day she visited a universal shopping mall which could accept all
kinds of coins as payments. However, there was a special requirement of the payment:
for each bill, she could only use exactly two coins to pay the exact amount. Since
she has as many as 10^5^ coins with her, she definitely needs your help. You are
supposed to tell her, for any given amount of money, whether or not she can find
two coins to pay for it.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains 2
positive numbers: N (<=10^5^, the total number of coins) and M(<=10^3^, the amount
of money Eva has to pay). The second line contains N face values of the coins, which
are all positive numbers no more than 500. All the numbers in a line are separated
by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in one line the two face values V~1~ and V~2~ (separated
by a space) such that V~1~ + V~2~ = M and V~1~ <= V~2~. If such a solution is not
unique, output the one with the smallest V~1~. If there is no solution, output "No
Solution" instead.
-------------------------------------------------------------------------------------
Sample Input 1:
8 15
1 2 8 7 2 4 11 15

Sample Output 1:
4 11
------------------
Sample Input 2:
7 14
1 8 7 2 4 11 15

Sample Output 2:
No Solution
===================================================================================*/

#include<iostream>
using namespace std;

typedef long long ll;
const int maxn = 1005;
ll value[maxn], n;
int m;

int main(){
	freopen("data.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for(ll i = 0; i < n; ++i){
		int temp;
		scanf("%d", &temp);
		value[temp]++;
	}
	bool flag = false;
	for(int i = 0; i < m && i <= m - i; ++i){
		if(value[i] != 0){
			--value[i];
			if(value[m - i] != 0){
				printf("%d %d", i, m - i);
				flag = true;
				break;
			}
		}
	}
	if(!flag) printf("No Solution");
	return 0;
}