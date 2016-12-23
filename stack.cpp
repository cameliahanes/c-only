#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;
void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

std::string to_string(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

int main(){
	
	queue<int> qu;
	qu.push(1);
	qu.push(2);
	qu.push(3);
	cout<<qu.front()<<' ';
	qu.pop();
	cout<<qu.front()<<' ';
	qu.pop();
	
	unordered_set<string> ops = {"+","-","*"};
	
	vector<int> v = {1,2,3,4,5,6,7,8};
	stack<int> stiva;
	while (!v.empty()){
		stiva.push(v[0]);
		v.erase(v.begin());
	}
	while(!stiva.empty()){
		v.push_back(stiva.top());
		stiva.pop();
	}
	
	for_each(v.begin(),v.end(),[&](int elem){
		cout<<elem<<' ';
	});
	
	string fpp = "18 29 - 22 213 + *";
	vector<string> cuvinte = split(fpp,' ');
	stack<string> st;
	for_each(cuvinte.begin(),cuvinte.end(),[ops,&st](string str){
		if ( ops.find(str)!=ops.end()){
			int second = atoi(st.top().c_str());
			st.pop();
			int first = atoi(st.top().c_str());
			st.pop();
			if (str == "+"){
			st.push(to_string(first+second));
			}
			if (str == "-"){
			st.push(to_string(first-second));
			}
			if (str == "*"){
			st.push(to_string(first*second));
			}
		
			
		}else{
			st.push(str);
		}
		});
	cout<<st.top()<<' ';
	
	
	
	return 0;
	
}