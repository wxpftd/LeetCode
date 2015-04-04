#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int> &num) {
	if (num.size() == 0)     //Do not forget the num.size() == 0 situation.
		return 0;
	if (num.size() == 1)
		return num[0];
	vector<int> a(num);     //Do not use normal array.
	a[0] = num[0];
	a[1] = (num[0]>num[1])?num[0]:num[1];
	for (int i=2; i<(int)num.size(); ++i)
	{
		int temp = a[i-2]+num[i];
		a[i] = (temp>a[i-1])?temp:a[i-1];
	}
	return a[num.size()-1];
}
int main()
{
	vector<int> num{};
	cout << rob(num) << endl;	
	return 0;
}
