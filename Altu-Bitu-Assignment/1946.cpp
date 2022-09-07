#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//서류 성적과 면접 성적 중 적어도 하나가 다른 지원자보다 작지 않는 사람 선발
//서류 성적과 면접 성적 둘다 작은 사람이 탈락

//선발할 수 있는 최대 인원 수

//1. 테스트 케이스 개수
//2. 지원자 수 (테스트 케이스 별)
//3~. 각 지원자의 '서류 성적 면접 성적' 

struct score {
	int doc;
	int interv;
};

bool cmp(const score& a, const score& b) {
	return a.doc < b.doc;
}

int main() {

	int t; //테스트 케이스 수 
	cin >> t; 
	vector<score> arr;
	vector<int> people(t);

	for (int i = 0; i < t; i++) {

		int n; // 지원자 수 
		cin >> n; 

		arr.assign(n, { 0,0 });

		for (int i = 0; i < n; i++) {
			cin >> arr[i].doc >> arr[i].interv;
		}

		sort(arr.begin(), arr.end(), cmp);  //서류 성적 오름차순 정렬

		int count = 1; 
		int temp = arr[0].interv;  //면접 점수 첫 기준

		for (int i = 1; i < arr.size(); i++) {
			if (arr[i].interv < temp) {  //
				count++;  //합격
				temp = arr[i].interv;  //면접점수 기준 변경
			}
		}

		people[i] = count;

	}

	
	for (int i = 0; i < t; i++) {
		cout << people[i] << "\n";
	}

	return 0;


}