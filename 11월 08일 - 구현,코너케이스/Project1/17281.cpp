#include <iostream>     // 입출력을 위한 헤더  
#include <vector>       // 벡터 사용을 위한 헤더
using namespace std;        
vector<bool> visited(10, false);        // 각 주자들의 타순 지정 상태를 저장하기 위한 벡터 
vector<int> order(10); //주자 순서
/**
 * [힌트] 입력이 그렇게 크지 않네요! 모든 경우의 수를 다 해보면 될 것 같아요.
 *        3아웃이 되면 아웃 카운트와 출루한 주자들이 모두 리셋되고 새로운 이닝이 시작된다는 규칙을 잘 기억해주세요!
 */

 /* 출루한 주자들의 상태 업데이트 */
int hit(vector<bool>& state, int n) {
    int score = 0;      // 점수 변수
    for (int i = 3; i > 0; i--) {   // 출루 주자들에 대해 반복문 실행
        if (!state[i]) {        // i루에 사람이 없으면 
            continue;           // 반복문 재시작
        }
        // i루에 사람이 있으면
        state[i] = false; //주자 위치 이동 (현재 루는 사람 없음으로 교체)
        if (i + n >= 4) { //홈으로 들어오는 경우
            score++;      // 득점
        }
        else {              // 홈이 아닌 루로 이동할 경우
            state[i + n] = true;    // 현재 i루에서 n루타를 통해 이동하여 도착한 루에 사람 있음 표시
        }
    }
    //현재 타자의 위치 설정하기
    if (n == 4) { //타자가 홈런을 날렸을 경우
        return score + 1;   // 득점
    }
    //안타를 쳤을 경우
    state[n] = true;    // 홈에서부터 n루타 하여 이동한 곳에 사람 있음 표시
    return score;       // 점수 반환
}
/* 타순이 결정됐을 때 경기에서 얻는 점수 구하기 */
int getScore(vector<vector<int>>& inning, int n) {  // 타자 정보와 이닝 수를 인자로 받음
    int out = 0, score = 0, cur = 0;    //아웃 수, 점수, 현재 이닝
    vector<bool> state(4, false);       // 출루 상태 저장 벡터
    int i = 1;          // 첫번째 주자부터 시작
    while (true)        // 무한루프 while 문 (별도의 종료 조건 지정)
    {
        if (out == 3) { //3아웃일 경우 (종료 조건)
            cur++; //다음 이닝
            out = 0;    // 아웃 수 리셋
            state = vector<bool>(4, false); //출루한 주자 리셋
            continue;   // 반복문 재시작
        }
        if (cur == n) { //이닝 종료
            break;      // 반복문을 빠져나가 경기 종료하고 점수 반환
        }

        int player = order[i++]; //타석으로 나갈 주자
        i = i % 9 + 1;  // 주자는 1번부터 9번, 9번이후엔 다시 1번 -> 모듈러 연산 필요
        if (inning[cur][player] == 0) { //해당 이닝에서 해당 주자가 아웃일 경우
            out++;            // 아웃 수 추가
            continue;         // 반복문 재시작 (아웃되면 아무것도 이루어지지 않음)
        }
        score += hit(state, inning[cur][player]);   // 아웃되지 않을 경우, 현재 출루 상태와 현재 이닝의 현재 주자에 대한 득점 계산
    }
    return score;       // 경기 종료 : 취종 점수 반환
}

/* 타순 정하기 */
void game(int cnt, int n, vector<vector<int>>& inning, int& maxScore) {
    // 타순 지정 함수 : 몇번째 타자인지, 총 이닝 수, 타자들 정보, 최대 점수
    if (cnt == 4) { //4번째 타자는 1로 고정
        game(cnt + 1, n, inning, maxScore);     // 다음 타자에 대해 다시 타순 정하기 실행
    }
    else if (cnt == 10) { //9명의 타자 순서 정해진 경우
        int score = getScore(inning, n);    //정해진 타순에 대해 점수 내기
        if (score > maxScore) {     // 얻은 점수가 현재까지의 최대 점수보다 클 때, 
            maxScore = score;       // 최대 점수 update
        }
    }
    else {                          // 아직 타순을 모두 정하지 않았을 경우
        for (int i = 2; i <= 9; i++) {  // 1번 선수를 제외한 8명의 선수에 대해 반복
            if (visited[i]) {           // i번 선수가 이미 타순이 지정되었으면
                continue;               // 반복문 처음으로 돌아가기 (타순 지정 패스)
            }
            visited[i] = true;          // i번 선수의 타순을 지정 중임을 표시
            order[cnt] = i;             // i번 선수를 cnt번째 순서로 지정
            game(cnt + 1, n, inning, maxScore); // 그다음번째 타자에 대해 다시 타순 정하기 실행
            visited[i] = false;         // i번째 선수 타순 지정 중인 상태 해제
        }
    }
}
int main() {       // 코드의 실행 시작 지점인 메인 함수 
    int n; cin >> n; //이닝 횟수
    int score, maxScore = 0;    // 아인타팀이 얻을 수 있는 최대 점수
    vector<vector<int>> inning(n, vector<int>(10)); //타자들이 각 이닝에서 얻는 결과
    for (int i = 0; i < n; i++) {   // 각 이닝에 대한 입력 받기   
        for (int j = 1; j <= 9; j++) {  // 각 선수에 대한 입력 받기
            cin >> inning[i][j];        // 2차원 벡터에 타자 결과에 대한 입력받기
        }
    }
    order[4] = 1; //1번 선수는 4번 타자로 고정
    visited[1] = true;  // 1번 선수 타순 지정 완료 표시

    game(1, n, inning, maxScore);   // 1번 타자부터 시작, 몇번이닝, 타자 정보, 최대 점수를 인자로 담아 타순 지정 함수 호출
    cout << maxScore;      // 경기 결과, 최대 점수 출력  
    return 0;       // 메인 함수 종료
}