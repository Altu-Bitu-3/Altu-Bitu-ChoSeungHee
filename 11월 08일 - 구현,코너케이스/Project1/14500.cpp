#include <iostream>     // 입출력을 위한 헤더
#include <vector>       // 벡터 사용을 위한 헤더

using namespace std;
const int MAX = 1000;       // 입력으로 주어지는 수의 최대값 

int n, m;                   // 종이의 세로 가로 크기
vector<vector<int>> board;  // 종이 위치에 대한 2차원 벡터
int ans;                    // 합의 최댓값을 저장하는 변수

/**
 * 1. 보라색 블럭을 제외하고는 모두 한붓 그리기로 그릴 수 있음
 *    -> 일반적인 백트래킹으로 모양을 만들 수 있음
 * 2. 보라색 블럭은 3개의 블럭이 결정된 이후에, 가운데에서 탐색을 해야 만들 수 있음
 *    -> 3번째 블럭을 결정하면서 현재 좌표를 갱신하지 않고, 직전 좌표에서 다시 한번 백트래킹을 진행하여 얻을 수 있음
 * 3. 각 블럭에 대해 깊이가 4인 백트래킹 함수를 수행하며 최댓값 갱신
 *
 * 방문처리 -> board를 활용해서 0을 저장하는 것으로
 * 가지치기 -> 현재 탐색이 남은 칸을 모두 MAX라 해도 ans이 더 큰 경우
 */

void backtracking(int x, int y, int cnt, int sum) {
    // x, y : 종이의 좌표, cnt : 몇번째 탐색 중인 블럭인지, sum : 칸에 적힌 수의 합
    int dx[4] = { -1, 1, 0, 0 };    // 확인할 블록의 x좌표 차 (현재 탐색중인 블록의 좌/우/0)
    int dy[4] = { 0, 0, -1, 1 };    // 확인할 블록의 y좌표 차 (현재 탐색중인 블록의 상/하/0)

    if (cnt == 4) { //기저조건: 4개의 블럭을 탐색함
        ans = max(ans, sum);    // 계산한 합 중 최댓값 도출
        return;     // 함수 종료
    }

    if (ans >= MAX * (4 - cnt) + sum) {     // 남은 블록이 모두 최댓값일 경우의 합보다 현재까지 계산한 합이 더 크거나 같을 때 (-> 결국 구해지는 최대 값일 경우)
        return;     // 함수 종료
    }

    for (int i = 0; i < 4; i++) {           // 상하좌우를 살펴보기 위한 반복문
        int nx = x + dx[i];     // 확인할 블럭의 x좌표 
        int ny = y + dy[i];     // 확인할 블럭의 y좌표

        if (nx < 0 || nx >= n || ny < 0 || ny >= m || !board[nx][ny]) {
            // 범위를 벗어나거나, 이미 방문했다면
            continue;   // 반복문 재시작 (다른 방향의 블록을 살펴보기)
        }
        if (cnt == 2) {     // 두번째 블록을 탐색하고 있을 경우
            int temp = board[nx][ny];      // 확인할 블럭에 적힌 수를 임시 저장
            board[nx][ny] = 0;              // 확인할 블록에 적힌 수 0으로 임시 처리
            backtracking(x, y, cnt + 1, sum + temp);    // 세번째 블록 탐색을 위한 재귀 호출 (확인할 블록의 수까지의 합 전달)
            board[nx][ny] = temp;       // 확인한 블록에 적힌 수 원상 복귀
        }
        int temp = board[nx][ny];       // 확인할 블록에 적힌 수 임시 저장   
        board[nx][ny] = 0;              // 확인할 블록에 적힌 수 0으로 임시 처리 
        backtracking(nx, ny, cnt + 1, sum + temp);  // 현재 확인할 블록에 대해 새로이 탐색을 하기 위한 재귀 호출
        board[nx][ny] = temp;           // 확인 후 해당 블록에 적힌 수 원상 복귀
    }
}

int main() {        // 코드 실행의 시작점인 메인 함수

    //입력
    cin >> n >> m;  // 종이의 세로 가로 크기 입력 받기

    board.assign(n, vector<int>(m, 0)); // 종이 좌표를 나타내는 2차원 벡터를 nxm으로 지정, 0으로 초기화한다
    for (int i = 0; i < n; i++) {       // 각 n행에 따라 반복
        for (int j = 0; j < m; j++) {   // 각 m열에 따라 반복
            cin >> board[i][j];         // 각 (i,j)칸에 대해 종이에 쓰여있는 수 입력받기
        }
    }

    //연산
    for (int i = 0; i < n; i++) {        // 각 n행에 따라 반복
        for (int j = 0; j < m; j++) {    // 각 m열에 따라 반복
            int temp = board[i][j];     // 각 (i,j)칸에 대해 종이에 쓰여있는 수를 temp에 임시저장
            board[i][j] = 0;            // 해당 (i,j)칸 0으로 임시 처리
            backtracking(i, j, 1, temp); //모양처리
            board[i][j] = temp;         // 모양 처리 후 다시 원래 값으로 (i,j)칸 채워넣기
        }
    }

    //출력
    cout << ans;    // 합의 최댓값 출력

    return 0;       // 메인 함수 종료
}