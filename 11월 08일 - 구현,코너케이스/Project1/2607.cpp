#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef map<char, int> mp;

/*
* 같은 구성 : 1) 같은 종류의 문자 2) 같은 문자는 같은 개수만큼
* 비슷한 단어 : 1) 같은 구성 2) 한 문자를 더하거나 빼거나 교체하면 같은 구성
*/


vector<int> mapping(string& word) {
	vector<int> word_char(26, 0);

	for (int i = 0; i < word.size(); i++) {
		word_char[word[i] - 'A']++;	// 알파벳index에 해당하는 곳 count 증가
	}

	return word_char;
}

int compare(string& first, vector<string>& vocab) {
	int count = 0;	// 단어 개수 세기v

	//first을 알파벳으로 분해하여 저장 

	vector<int> first_char = mapping(first);

	// 같은 구성 : 각 알파벳의 개수 비교 -> 모두 같으면 같은 구성
	// 비슷한 단어 :
	// 각 알파벳의 개수를 뺐을 때 
	// 1이나 -1이 하나 있을 때 -> 비슷한 단어 : 한글자 빼거나 더해주면 됨
	// 1과 -1이 하나씩 있을 때 -> 비슷한 단어 : 한글짜씩 교체하면 됨

	for (int i = 0; i < vocab.size(); i++) {
		vector<int> tmp_char = mapping(vocab[i]);
		vector<int> cmp_char(26);
		int plus = 0;
		int minus = 0;

		for (int j = 0; j < 26; j++) {
			cmp_char[j] = first_char[j] - tmp_char[j];
			if (cmp_char[j] > 0) {
				plus += cmp_char[j];
			}
			else if (cmp_char[j] < 0) {
				minus += cmp_char[j];
			}
		}

		if (plus == 0 && minus == 0) { count++; }	// 같은 구성
		// 비슷한 단어
		else if (plus == 1 && minus == 0 || plus == 0 && minus == -1 || plus == 1 && minus == -1) { count++; }

	}
	
	return count;
}

int main() {
	int n;
	string first;
	vector<string> vocab;

	// 입력
	cin >> n;

	cin >> first;
	n--;
	while (n--) {
		string tmp;
		cin >> tmp;
		vocab.push_back(tmp);
	}

	cout << compare(first, vocab);


	return 0;
}