#include <string>
#include <vector>
#include <iostream>

using namespace std;
pair<int,int> changeDir(int r, int c , int dir){
    int nextR = 0, nextC = 0;

    if(dir == 0){
        nextR = r+1;
        nextC = c;
    }else if(dir == 1){
        nextR = r;
        nextC = c+1;
    }else if(dir == 2){
        nextR = r-1;
        nextC = c-1;
    }
    return {nextR,nextC};
}
vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> snail, visited;

    int count = 1, index = 1, dir = 0 , r = 0 , c = 0;

    for(int i = 0 ; i < n ; i++){
        snail.push_back(vector<int>());
        visited.push_back(vector<int>());
        for(int j = 0 ; j < i+1 ; j++){
            snail[i].push_back(j);
            visited[i].push_back(0);
            count++;
        }
    }
    int nextR = 0, nextC = 0;
    pair<int,int> nextPair;

    while(count > index){
        snail[r][c] = index++;
        visited[r][c] = 1;

        nextPair = changeDir(r,c,dir);
        nextR = nextPair.first;
        nextC = nextPair.second;

        if(nextR >= n || nextC >= n || nextR < 0 || nextC < 0 || visited[nextR][nextC] == 1)
        {
            dir++;
            if(dir == 3) dir = 0;
            nextPair = changeDir(r,c,dir);
            nextR = nextPair.first;
            nextC = nextPair.second;
        }

        r = nextR;
        c = nextC;
    }

    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < snail[i].size() ; j++)
            answer.push_back(snail[i][j]);
    }
    return answer;
}

int main(){
    
    vector<int> sol;
    cout << "Programmers - triple snail" << endl;
    
    cout << "CASE 1 : if N = 4 --------->";
    sol = {1,2,9,3,10,8,4,5,6,7};
    if(solution(4) == sol)
        cout << "CORRECT" << endl;
    else
        cout << "WRONG" << endl;
        
    cout << "CASE 2 : if N = 5 --------->";
    sol = {1,2,12,3,13,11,4,14,15,10,5,6,7,8,9};
    if(solution(5) == sol)
        cout << "CORRECT" << endl;
    else
        cout << "WRONG" << endl;
    
    cout << "CASE 3 : if N = 6 --------->";
    sol = {1,2,15,3,16,14,4,17,21,13,5,18,19,20,12,6,7,8,9,10,11};
    if(solution(6) == sol)
        cout << "CORRECT" << endl;
    else
        cout << "WRONG" << endl;
    return 0;
}