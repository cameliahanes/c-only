#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> qsort(vector<int> v){
	
	if (v.empty()){
		vector<int> v;
		return v;
	}
	
	vector<int> lesser;
	vector<int> greater;
	
	for_each(v.begin(),v.end()-1,[&](int el){
		if (el < v.back()){
			lesser.push_back(el);
			}
		});

	for_each(v.begin(),v.end()-1,[&](int el){
		if (el >= v.back()){
			greater.push_back(el);
			}
		});
	
	vector<int> less = qsort(lesser);
	vector<int> great = qsort(greater);
	
	less.push_back(v.back());
	less.insert(less.end(),great.begin(),great.end());
	
	return less;
}

int main(){
vector<int> v = {1,3,2,12,22,100,17,25,9,18};
	vector<int> sorted = qsort(v);
	for (auto a : sorted){
		cout<<a<<' ';
	}
	
}