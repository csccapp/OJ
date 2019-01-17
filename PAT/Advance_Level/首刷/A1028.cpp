/*===================================================================================
A1028 List Sorting (25)（25 分）提问
=====================================================================================
Excel can sort records according to any column. Now you are supposed to imitate
this function.
-------------------------------------------------------------------------------------
Input
Each input file contains one test case. For each case, the first line contains two
integers N (<=100000) and C, where N is the number of records and C is the column
that you are supposed to sort the records with. Then N lines follow, each contains
a record of a student. A student's record consists of his or her distinct ID (a
6-digit number), name (a string with no more than 8 characters without space), and
grade (an integer between 0 and 100, inclusive).
-------------------------------------------------------------------------------------
Output
For each test case, output the sorting result in N lines. That is, if C = 1 then
the records must be sorted in increasing order according to ID's; if C = 2 then
the records must be sorted in non-decreasing order according to names; and if C
= 3 then the records must be sorted in non-decreasing order according to grades.
If there are several students who have the same name or grade, they must be sorted
according to their ID's in increasing order.
-------------------------------------------------------------------------------------
Sample Input 1
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60

Sample Output 1
000001 Zoe 60
000007 James 85
000010 Amy 90 
---------------------
Sample Input 2
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98

Sample Output 2
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
---------------------
Sample Input 3
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90

Sample Output 3
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
===================================================================================*/

//臣妾不能用string啊，会超时啊。

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

//#define loc
const int maxn = 100010;
struct node{
	char name[10];
	int id, grade;
}a[maxn];
int n, c;

bool cmp1(node a, node b){
	return a.id < b.id;
}

bool cmp2(node a, node b){
	int s = strcmp(a.name, b.name);
	if( s != 0)
		return s < 0;
	return a.id < b.id;
}

bool cmp3(node a, node b){
	return a.grade <= b.grade;
}

int main(){
#ifdef loc
	freopen("data.txt", "r", stdin);
	while(scanf("%d", &n) != EOF){
#endif
	cin >> n;
	cin >> c;
	for(int i = 0; i < n; ++i){
		scanf("%d%s%d", &a[i].id, a[i].name, &a[i].grade);
	}
	if(c == 1)
		sort(a, a + n, cmp1);
	else if(c == 2)
		sort(a, a + n, cmp2);
	else
		sort(a, a + n, cmp3);
	for(int i = 0; i < n; ++i){
		printf("%06d %s %d\n", a[i].id, a[i].name, a[i].grade);
	}
#ifdef loc
	cout << endl;
	}
#endif
}

