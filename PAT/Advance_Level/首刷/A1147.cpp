/*===================================================================================
A编程题
=====================================================================================
1147 Heaps（30 分）提问
In computer science, a heap is a specialized tree-based data structure that satisfies
the heap property: if P is a parent node of C, then the key (the value) of P is
either greater than or equal to (in a max heap) or less than or equal to (in a min
heap) the key of C. A common implementation of a heap is the binary heap, in which
the tree is a complete binary tree. (Quoted from Wikipedia at https://en.wikipedia.org/wiki/Heap_(data_structure))
Your job is to tell if a given complete binary tree is a heap.
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line gives two
positive integers: M (≤ 100), the number of trees to be tested; and N (1 < N ≤
1,000), the number of keys in each tree, respectively. Then M lines follow, each
contains N distinct integer keys (all in the range of int), which gives the level
order traversal sequence of a complete binary tree.
-------------------------------------------------------------------------------------
Output Specification:
For each given tree, print in a line Max Heap if it is a max heap, or Min Heap for
a min heap, or Not Heap if it is not a heap at all. Then in the next line print
the tree's postorder traversal sequence. All the numbers are separated by a space,
and there must no extra space at the beginning or the end of the line.
-------------------------------------------------------------------------------------
Sample Input:
3 8
98 72 86 60 65 12 23 50
8 38 25 58 52 82 70 60
10 28 15 12 34 9 8 56

Sample Output:
Max Heap
50 60 65 72 12 23 86 98
Min Heap
60 58 52 38 82 70 25 8
Not Heap
56 12 34 28 9 8 15 10
===================================================================================*/


#include<iostream>
#include<vector>
using namespace std;

const int maxn = 105;
vector<int> tree, ans;
int m, n;

int judge(){
	int index;
	if(tree[1] > tree[2] && tree[1] > tree[3])	index = 2;
	else if(tree[1] < tree[2] && tree[1] < tree[3]) index = 1;
	else return 0;
	for(int i = 2; i <= n/2; ++i){
		int _index;
		if(2 * i <= n && 2 * i + 1 <= n){
			if(tree[2*i] > tree[i] && tree[2*i+1] > tree[i])
				_index = 1;
			else if(tree[2*i] < tree[i] && tree[2*i+1] < tree[i])
				_index = 2;
			else _index = 0;
		}
		if(2 * i <= n && 2 * i + 1 > n){
			if(tree[2*i] > tree[i])
				_index = 1;
			else if(tree[2*i] < tree[i])
				_index = 2;
			else _index = 0;
		}
		if(_index != index)	return 0;
	}
	return index;
}

void postOrder(int root){
	if(2 * root <= n)
		postOrder(2*root);
	if(2 * root + 1 <= n)
		postOrder(2*root+1);
	ans.push_back(tree[root]);
}

int main(){
	freopen("data.txt", "r", stdin);
	cin >> m >> n;
	for(int i = 0; i < m; ++i){
		tree.push_back(0);
		for(int j = 0; j < n; ++j){
			int temp;
			cin >> temp;
			tree.push_back(temp);
		}
		int u = judge();
		if(u == 0)	cout << "Not Heap" << endl;
		if(u == 1)	cout << "Min Heap" << endl;
		if(u == 2)	cout << "Max Heap" << endl;
		postOrder(1);
		for(int i = 0; i < n; ++i){
			if(i != 0)	cout << " ";
			cout << ans[i];
		}
		ans.clear();
		tree.clear();
		cout << endl;
	}
	return 0;
}