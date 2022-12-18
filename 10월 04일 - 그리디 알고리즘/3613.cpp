#include <iostream>
#include <vector>

using namespace std;

/*
* 1. 변수명을 입력받고 어느 언어형식인지 알아내기
* 2. 언어 형식 변환 C++ <-> Java (두 언어형식 다 아닐 시 에러 발생)
* (주의, 단어 순서는 유지돼야함)
*/

/*
* 대문자가 있으면 -> Java 형식
* 언더바가 있으면 -> C++ 형식
* (주의, 둘다 없다고 에러나는거 아님! 한 단어일 경우 소문자만 있으면 C++)
* Java -> C++ : '대문자' -> '_소문자'
* C++ -> Java : '_소문자' -> '대문자'
*/

// 관건! 문제에 언급되지 않은 C++, Java 문법을 고려해야 함 (언더바나 대문자로 시작하는 등)

void convertToC(string input, vector<char>& word) {
	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') {
			// 대문자 -> _ 소문자
			// 주의! 대문자가 맨 앞에 있을 경우, 에러 처리
			if (i == 0) {
				cout << "Error!";
				return;
			}
			word.push_back('_');
			word.push_back(input[i] + 32);	// 아스키 코드 : 대문자 + 32 = 소문자
		}
		else {
			word.push_back(input[i]);
		}
	}

	// 완성된 word 출력
	for (int i = 0; i< word.size(); i++) {
		cout << word[i];
	}
}

void convertToJava(string input, vector<char>& word) {
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '_') {
		// _소문자 -> 대문자 
			// 주의!  _가 맨 뒤or 맨 앞에 있을 경우 or _가 연속으로 올 경우, 에러 처리 
			if (i == input.size() - 1 || i == 0 || input[i+1]=='_') {
				cout << "Error!";
				return;
			}
			word.push_back(input[i + 1] - 32);
			i++;	// 두 글자를 한글자로 줄이기 때문에
		}
		else {
			word.push_back(input[i]);
		}
	}

	// 완성된 word 출력
	for (int i = 0; i < word.size(); i++) {
		cout << word[i];
	}
}

string checkType(string &input) {
	// 대문자가 포함되어있거나 소문자만 이루어져있을 때 Java
	// _가 포함되어있거나 소문자만 이루어져있을 때 C++

	int big = 0, small = 0, under = 0, ex = 0;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') big++;
		else if (input[i] >= 'a' && input[i] <= 'z') small++;
		else if (input[i] == '_') under++;
		else ex++;
	}

	// 대문자 존재, 나머지 없음 or 소문자로만
	if ((big > 0 && under == 0 && ex == 0) || (big == 0 && under == 0 && ex == 0)) {
		// 소문자로만 이루어질 경우 자바, C++ 모두 되지만 편의상 자바로 분류
		return "Java";
	}
	// 언더바 존재, 나머지 없음
	else if (big == 0 && under > 0 && ex == 0) {
		return "C++";
	}
	// 소문자로만 이루어지지도 않고, 대문자 언더바 한종류 씩만 있지도 않고, 이상한 문자가 섞여있을 때
	else {
		return "err";
	}
}

int main() {
	string input;	//입력되는 단어
	vector<char> word;

	// 입력
	cin >> input;

	string type = checkType(input);
	if (type == "Java") convertToC(input, word);
	else if (type == "C++") convertToJava(input, word);
	else if (type == "err") {
		cout << "Error!";
		return 0;
	}

	return 0;
}