#include <iostream>
using namespace std;
int hammingWeight(uint32_t n) {
	int result = 0;
	int a[]{0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
	while (n > 0)
	{
		int temp = n&15;    
		result += a[temp];
		n = n >> 4;
	}
	return result;
}
int main()
{
	cout << hammingWeight(11) << endl;
	return 0;
}

