#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 메시지 길이 : N
// 숫자의 범위 최대값 : C

// 1. 길이 n 짜리 vector을 만들어 입력 받은 후, 
// 2. 0~C 까지 각 숫자가 배열에 몇개씩 들어있는지 count
// 키 : 해당 숫자, 값 : 빈도수인 map 사용


map<int, int> order; //키 : 해당 숫자, 값 : 순서


bool cmp(pair<int,int>&  a, pair<int,int>& b) {  
	// 빈도수 같을 경우 일찍 나온 순으로
	if (a.second == b.second) return order[a.first] < order[b.first]; 
	// 빈도수 다를 경우 빈도수 큰 순으로
	return a.second > b.second; 
}


int main() {

	int n; //메시지 길이
	int c; //숫자 최대 가능 값
	cin >> n >> c;

	map<int, int> count;  //키 : 해당 숫자, 값 : 빈도수
	vector<pair<int, int>> vec; //map 정렬 용 임시 벡터

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		count[temp]++;  //temp 숫자의 빈도수 증가
		if (order[temp] == 0) order[temp] = i+1; //temp "등장"순서 저장  
	}

	for (auto iter : count) {
		vec.push_back(make_pair(iter.first, iter.second));
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].second; j++) {
			cout << vec[i].first << " ";
		}
	}


	return 0;
}