#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 100010;
struct Node {
	int pos;
	int next;
	int data;
	int flag;
	int index;
};
Node node[maxn];
int beg, n, k;
bool cmp(Node a, Node b) {
	if (a.flag != b.flag) return a.flag > b.flag;
	else {
		return a.index < b.index;
	}
}
int main()
{
	cin >> beg >> n >> k;
	for (int i = 0; i < n; i++) {
		int add, dat, nex;
		cin >> add >> dat >> nex;
		node[add].pos = add;
		node[add].data = dat;
		node[add].next = nex;
		if (dat < 0) {
			node[add].flag = 3;
		}
		else if (dat >= 0 && dat <= k) {
			node[add].flag = 2;
		}
		else {
			node[add].flag = 1;
		}
	}
	int t = beg;
	int math = 1;
	while (1) {
		node[t].index = math;
		t = node[t].next;
		math++;
		if (t == -1) {
			break;
		}
	}
	sort(node, node + maxn, cmp);
	//for (int i = 0; i < n; i++) {
	//	if (i != n - 1) {
	//		node[i].next = node[i + 1].pos;
	//	}
	//}
	//node[n - 1].next = -1;
	//for (int i = 0; i < n; i++) {
	//	if (i != n - 1)
	//		printf("%05d %d %05d\n", node[i].pos, node[i].data, node[i].next);
	//	else
	//		printf("%05d %d -1\n", node[i].pos, node[i].data);
	//}
	for (int i = 0; i < n; i++) {
		if (i != n - 1) {
			printf("%05d %d %05d\n", node[i].pos, node[i].data, node[i + 1].pos);
		}
		else
			printf("%05d %d -1\n", node[i].pos, node[i].data);
	}
    return 0;
}
