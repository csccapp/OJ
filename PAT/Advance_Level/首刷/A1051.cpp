/*===================================================================================
A1051 Pop Sequence (25)（25 分）
=====================================================================================
Given a stack which can keep M numbers at most. Push N numbers in the order of 1,
2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers
is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can
obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains 3
numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length
of push sequence), and K (the number of pop sequences to be checked). Then K lines
follow, each contains a pop sequence of N numbers. All the numbers in a line are
separated by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence
of the stack, or "NO" if not.
-------------------------------------------------------------------------------------
Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2

Sample Output:
YES
NO
NO
YES
NO
===================================================================================*/

#include<iostream>
#include<stack>
using namespace std;

const int maxn = 1010;
int a[maxn], b[maxn];
int M, N, K;

int main(){
	cin >> M >> N >> K;
	for(int i = 0; i < K; ++i){
		for(int j = 0; j < N; ++j)
			cin >> a[j];
		stack<int> s;
		int l = 0;
		for(int j = 1; j <= N; ++j){
			if(s.size() >= M)	break;
			s.push(j);
			while(!s.empty() && s.top() == a[l]){
				s.pop();
				++l;
			}
		}
		if(!s.empty())	b[i] = 0;
		else	b[i] = 1;
	}
	for(int i = 0; i < K; ++i)
		if(b[i] == 1)	cout << "YES" << endl;
		else	cout << "NO" << endl;
	return 0;
}