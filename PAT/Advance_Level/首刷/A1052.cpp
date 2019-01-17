/*===================================================================================
A1052 Linked List Sorting (25)（25 分）
=====================================================================================
A linked list consists of a series of structures, which are not necessarily adjacent
in memory. We assume that each structure contains an integer key and a Next pointer
to the next structure. Now given a linked list, you are supposed to sort the structures
according to their key values in increasing order.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line contains a
positive N (< 10^5^) and an address of the head node, where N is the total number
of nodes in memory and the address of a node is a 5-digit positive integer. NULL
is represented by -1.
Then N lines follow, each describes a node in the format:
Address Key Next
where Address is the address of the node in memory, Key is an integer in [-10^5^,
10^5^], and Next is the address of the next node. It is guaranteed that all the
keys are distinct and there is no cycle in the linked list starting from the head
node.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, the output format is the same as that of the input, where N
is the total number of nodes in the list and all the nodes must be sorted order.
-------------------------------------------------------------------------------------
Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345

Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
===================================================================================*/

/*
注意，该题输入节点里有无效节点。
*/

#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100010;
struct Node{
	int data;
	int adress, next;
	bool flag;
}node[maxn];

bool cmp(Node a, Node b){
	if(a.flag == false || b.flag == false)
		return a.flag > b.flag;
	return a.data < b.data;
}

int main(){
	int n, begin;
	cin >> n >> begin;
	for(int i = 0; i < maxn; ++i)
		node[i].flag = false;
	for(int i = 0; i < n; ++i){
		int temp;
		cin >> temp;
		node[temp].adress = temp;
		cin >> node[temp].data >> node[temp].next;
	}
	int count = 0, p = begin;
	while(p != -1){
		node[p].flag = true;
		count++;
		p = node[p].next;
	}
	if(count == 0){
		cout << "0 -1";
		return 0; 
	}
	sort(node, node + maxn, cmp);
	printf("%d %05d\n", count, node[0].adress);
	for(int i = 0; i < count; ++i){
		printf("%05d %d", node[i].adress, node[i].data);
		if(i != count - 1)
			printf(" %05d\n", node[i+1].adress);
		else
			cout << " -1";
	}
	return 0;
} 