/*===================================================================================
A1094 The Largest Generation (25)（25 分）
=====================================================================================
A family hierarchy is usually presented by a pedigree tree where all the nodes on
the same level belong to the same generation. Your task is to find the generation
with the largest population.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. Each case starts with two positive integers
N (&lt100) which is the total number of family members in the tree (and hence assume
that all the members are numbered from 01 to N), and M (&ltN) which is the number
of family members who have children. Then M lines follow, each contains the information
of a family member in the following format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a family member, K (&gt0) is the number
of his/her children, followed by a sequence of two-digit ID's of his/her children.
For the sake of simplicity, let us fix the root ID to be 01. All the numbers in
a line are separated by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in one line the largest population number and the level
of the corresponding generation. It is assumed that such a generation is unique,
and the root level is defined to be 1.
-------------------------------------------------------------------------------------
Sample Input:
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18

Sample Output:
9 4
===================================================================================*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 110;
struct node{
	int layer;
	vector<int>	child;
}n[maxn];
int N, M;
int a[maxn];

void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int index = q.front();
		q.pop();
		for(int i = 0; i < n[index].child.size(); ++i){
			int temp = n[index].child[i];
			n[temp].layer = n[index].layer + 1;
			q.push(temp);
		}
	}
}

int main(){
	for(int i = 0; i < maxn; ++i)
		a[i] = 0;
	cin >> N >> M;
	for(int i = 0; i < M; ++i){
		int ID, k, temp;
		cin >> ID >> k;
		for(int j = 0; j < k; ++j){
			cin >> temp;
			n[ID].child.push_back(temp);
		}
	}
	n[1].layer = 1;
	BFS(1);
	for(int i = 1; i <= N; ++i)
		a[n[i].layer]++;
	int max = 0, layer;
	for(int i = 0; i < maxn; ++i){
		if(a[i] > max){
			max = a[i];
			layer = i;
		}
	}
	cout << max << " " << layer;
	return 0;
}