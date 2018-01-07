#include <bits/stdc++.h>
using namespace std;
void calculate(vector<int>& v, int sum, int index, int S, int& count){
	if (index == v.size()){
		if (sum == S) count ++;
	} else {
		calculate(v, sum, index + 1, S + v[index], count);
		calculate(v, sum, index + 1, S - v[index], count);
	}
}

int main(){
vector<int> v(5, 1);
int S = 3;
int count = 0;
calculate(v, S, 0, 0, count);
cout << count;
return 0;
}
