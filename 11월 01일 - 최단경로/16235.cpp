#include <iostream>		// 입출력을 위한 헤더
#include <deque>		// 덱 자료구조를 사용하기 위한 헤더
#include <vector>		// 벡터를 사용하기 위한 헤더

using namespace std;
typedef vector<vector<int>> matrix;		// 이차원 벡터 자료형을 matrix로 별명 설정

int countTrees(int n, vector<deque<int>>& trees) {	// 살아남은 나무 수를 계산하는 함수
	int answer = 0;						// 살아남은 나무 수를 저장할 변수
	for (int i = 0; i < n; i++)			// 땅의 0~n-1행 순회
	{
		for (int j = 0; j < n; j++)		// 땅의 0~n-1열 순회
		{
			answer += trees[i * 10 + j].size();	// 각 좌표에 있는 덱의 수, 즉 각 좌표 땅에 심어진 나무의 수를 변수에 추가
		}
	}
	return answer;			// 살아남은 나무 수 반환
}

void reproduceTree(int n, int x, int y, vector<deque<int>>& trees)
{	// 나무가 번식하는 함수
	for (int i = x - 1; i <= x + 1; i++)	// 번식가능한 나무의 x좌표 양 옆 접근
	{
		for (int j = y - 1; j <= y + 1; j++)	// 번식가능한 나무의 y좌표 위아래 접근
		{	
			if ((i == x) && (j == y)) {		// 번식가능한 나무와 동일한 좌표일 땐
				continue;					// 반복문 처음으로 돌아가기 (무시)
			}
			if (i >= 0 && j >= 0 && i < n && j < n)  // 번식으로 새로 추가될 나무들의 좌표가 땅 내부일 경우
			{
				trees[i * 10 + j].push_front(1);	// 해당 좌표에 나이 1짜리 새로운 나무 추가 (나이가 어리기 때문에, 나이순 정렬에 따라 front에 push)
			}
		}
	}
}
void solution(int n, vector<deque<int>>& trees, matrix& food, matrix& a, vector<pair<int, int>>& breeding_tree)
{	// 땅 크기, 나무 정보, 땅 양분 정보, 로봇 양분 정보, 번식 나무 정보를 입력받는 solution 함수
	for (int i = 0; i < n; i++)		// 0~n-1행 순회
	{
		for (int j = 0; j < n; j++)		// 0~n-1열 순회
		{
			int leftover = 0;		// 추가 생성될 양분의 양을 저장할 변수 
			deque<int> dq;			// 임시적으로 살아남은 나무 정보를 저장할 덱 선언
			for (auto age : trees[i * 10 + j])	// 심어진 모든 나무의 나이정보 순회하기
			{
				if (food[i][j] < age) { //양분을 먹을 수 없다 (땅의 양분이 나이보다 적음)	
					leftover += age / 2;	// 나무가 죽으면서 나무 나이의 절반이 양분으로 보충됨
					continue;			// 반복문 처음으로 돌아가기
				}
				food[i][j] -= age;		// 양분을 먹을 경우, 땅에서 먹은 양(나이)만큼 양분이 감소됨
				dq.push_back(age + 1); //나이를 1 증가시킨 후, 살아남은 나무 나이를 dq덱에 추가
				if ((age + 1) % 5 == 0)// 번식 가능하다 (나이가 5의 배수일 경우)
				{
					breeding_tree.push_back({ i, j });	// 번식할 나무를 저장하는 벡터에 좌표 정보 추가
				}
			}
			trees[i * 10 + j] = dq;		// 살아남은 나무 나이정보로 기존 나무 정보 업데이트
			food[i][j] += (a[i][j] + leftover);		// 땅의 양분에 로봇이 주는 양분과 나무가 죽어서 추가로 생성된 양분을 더한다.
		}
	}
}
/**16235 나무 재테크
 * [문제 설명] - 단순 구현 문제
 * 봄: 하나의 칸마다 나이가 어린 나무부터 자신의 나이만큼 양분을 먹고, 나이가 1 증가함
 *    각 칸에 양분이 부족해 자신의 나이만큼 양분을 못 먹는 나무는 즉시 죽음
 * 여름: 봄에 죽은 나무가 양분으로 변함. 죽은 나무마다 나이를 2로 나눈 값이 양분으로 추가 (소수점 버림)
 * 가을: 나이가 5의 배수인 나무가 번식. 인접한 8개 칸에 나이가 1인 나무가 생김
 * 겨울: 로봇(S2D2)이 땅을 돌아다니면서 A[r][c]만큼 각 칸에 양분 추가
 *
 * K년이 지난 후 상도의 땅에 살아있는 나무의 개수
 *
 * [문제 풀이]
 * A : 로봇(S2D2)가 겨울에 주는 양분의 양
 * food : 땅의 양분
 * breeding_tree: 나이가 5의 배수인 트리 (번식할 트리)
 * tree: 땅에 심은 나무 나이, 행, 열 정보
 * -> deque 컨테이너를 활용해 번식한 나무를 앞에 넣어주면 입력 후에만 정렬해서 사용 가능
 *
 * 문제의 설명대로 계절별 연산을 진행
 */
int main()	// 코드 실행 시작점이 되는 메인 함수
{
	int n, m, k;	// 땅 모서리 길이 n, 처음 심은 나무 수 m, 시간 지난 년도 수 k
	//입력
	cin >> n >> m >> k;		// n, m, k를 첫째줄에서 입력 받기
	matrix a(n, vector<int>(n, 0));		// 0으로 초기화된 a라는 2차원 벡터 선언 (로봇이 주는 양분)
	matrix food(n, vector<int>(n, 5));	// 5로 초기화된 food라는 2차원 벡터 선언 (땅의 양분)
	vector<deque<int>> trees(n * 10 + n);	// 각 나무의 정보를 덱으로 저장하는 벡터 (2차원 벡터의 좌표를 1차원 벡터로 나열)

	for (int i = 0; i < n; i++)		// a 행렬의 0~n-1행 순회
	{
		for (int j = 0; j < n; j++)		// a 행렬의 0~n-1열 순회
		{
			cin >> a[i][j];			// n*n번 반복하며 a 행렬의 모든 요소 입력받기 
		}
	}
	for (int i = 0, x, y, z; i < m; i++)	// m줄 동안 나무 m개의 정보 입력 받기
	{
		cin >> x >> y >> z;		// 각 나무의 x, y, z (x좌표, y좌표, 나이) 입력받기
		x--; y--;		// trees의 인덱스가 0부터 시작하고, 각 좌표는 1부터 시작하므로 1 빼주기
		trees[x * 10 + y].push_front(z);	// x좌표와 y좌표에 맞는 일차원 벡터의 인덱스에 나무의 나이 정보 입력 
	}
	while (k--) {		// 사계절이 반복되는 햇수만큼 반복문 실행
		vector<pair<int, int>> breeding_tree;	// 번식할 트리의 각 좌표 정보를 저장할 벡터 선언
		solution(n, trees, food, a, breeding_tree);		// 땅 크기, 나무 정보, 땅 양분 정보, 로봇 양분 정보, 번식 나무 정보를 인자로 전달하며 함수 호출
		for (auto [i, j] : breeding_tree)		// 가을이 되어, 번식 가능한 나무들을 순회
		{
			reproduceTree(n, i, j, trees);		// 번식 가능한 나무의 좌표와, 땅 크기, 나무 정보를 인자로 전달하여 함수 호출
		}
	}
	cout << countTrees(n, trees);			// 살아남은 나무의 수를 반환받아 출력
	return 0;								// 메인 함수 종료
}