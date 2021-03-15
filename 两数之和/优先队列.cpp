#include<iostream>
#include <queue>
#include<vector>
using namespace std;
int main()
{
	priority_queue<int,vector<int>, greater<int>> q;
	vector<int> a = { 5,3,1,7,2,4 };
	for (int i = 0; i < a.size(); i++)
	{
		q.push(a[i]);
	}
	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	return 0;
}3