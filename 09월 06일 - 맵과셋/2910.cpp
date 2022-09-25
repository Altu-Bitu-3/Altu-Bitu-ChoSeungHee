#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// �޽��� ���� : N
// ������ ���� �ִ밪 : C

// 1. ���� n ¥�� vector�� ����� �Է� ���� ��, 
// 2. 0~C ���� �� ���ڰ� �迭�� ��� ����ִ��� count
// Ű : �ش� ����, �� : �󵵼��� map ���


map<int, int> order; //Ű : �ش� ����, �� : ����


bool cmp(pair<int,int>&  a, pair<int,int>& b) {  
	// �󵵼� ���� ��� ���� ���� ������
	if (a.second == b.second) return order[a.first] < order[b.first]; 
	// �󵵼� �ٸ� ��� �󵵼� ū ������
	return a.second > b.second; 
}


int main() {

	int n; //�޽��� ����
	int c; //���� �ִ� ���� ��
	cin >> n >> c;

	map<int, int> count;  //Ű : �ش� ����, �� : �󵵼�
	vector<pair<int, int>> vec; //map ���� �� �ӽ� ����

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		count[temp]++;  //temp ������ �󵵼� ����
		if (order[temp] == 0) order[temp] = i+1; //temp "����"���� ����  
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