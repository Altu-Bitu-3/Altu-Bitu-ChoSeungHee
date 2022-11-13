#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef map<char, int> mp;

/*
* ���� ���� : 1) ���� ������ ���� 2) ���� ���ڴ� ���� ������ŭ
* ����� �ܾ� : 1) ���� ���� 2) �� ���ڸ� ���ϰų� ���ų� ��ü�ϸ� ���� ����
*/


vector<int> mapping(string& word) {
	vector<int> word_char(26, 0);

	for (int i = 0; i < word.size(); i++) {
		word_char[word[i] - 'A']++;	// ���ĺ�index�� �ش��ϴ� �� count ����
	}

	return word_char;
}

int compare(string& first, vector<string>& vocab) {
	int count = 0;	// �ܾ� ���� ����v

	//first�� ���ĺ����� �����Ͽ� ���� 

	vector<int> first_char = mapping(first);

	// ���� ���� : �� ���ĺ��� ���� �� -> ��� ������ ���� ����
	// ����� �ܾ� :
	// �� ���ĺ��� ������ ���� �� 
	// 1�̳� -1�� �ϳ� ���� �� -> ����� �ܾ� : �ѱ��� ���ų� �����ָ� ��
	// 1�� -1�� �ϳ��� ���� �� -> ����� �ܾ� : �ѱ�¥�� ��ü�ϸ� ��

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

		if (plus == 0 && minus == 0) { count++; }	// ���� ����
		// ����� �ܾ�
		else if (plus == 1 && minus == 0 || plus == 0 && minus == -1 || plus == 1 && minus == -1) { count++; }

	}
	
	return count;
}

int main() {
	int n;
	string first;
	vector<string> vocab;

	// �Է�
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