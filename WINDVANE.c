#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
int mod(int a, int b){
    int ret = a % b;
    if(ret < 0)
        ret+=b;
    return ret;
}

int main(){
    map<char, int> rev;
    rev['N'] = 0;
    rev['E'] = 1;
    rev['S'] = 2;
    rev['W'] = 3;

    char mapper[4];
    mapper[0] = 'N';
    mapper[1] = 'E';
    mapper[2] = 'S';
    mapper[3] = 'W';

    int m, n;
    scanf("%d %d\n", &m ,&n);
    int matrix[m+1][n+1];

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            char ch;
            scanf(" %c", &ch);
            matrix[i][j] = rev[ch];
        }
    }
    bool first = true;
    int query;
    scanf("%d\n", &query);
    for(int i = 0; i < query; i++){
        char command;
        scanf(" %c", &command);
  if(command == 'C'){
            int x1, y1, x2, y2, d;
            scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &d);
            for(int i = x1; i <= x2; i++){
                for(int j = y1; j <= y2; j++){
                    if(d == 0){
                        matrix[i][j]++;
                    }
                    else {
                        matrix[i][j]--;
                    }
                }
            }
        } else{
            int x, y;
            scanf("%d %d", &x, &y);
            if(first){
                printf("%c\n", mapper[mod(matrix[x][y],4)]);
                first = false;
            } else{
                printf("\n%c\n", mapper[mod(matrix[x][y],4)]);
            }
        }
    }
}

