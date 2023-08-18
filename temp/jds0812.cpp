#include <iostream>
#include <vector>
using namespace std;


int countSquare(vector<string>& board) {
    int n = board.size();
    int m = board[0].size();

    vector<pair<int, int>> positions;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'X') {
                positions.push_back({i, j});
            }
        }
    }

    int count = 0;
    for(int k = 2;k<=board[0].size();++k){
        for(int i = 0;i<=board.size() - k;++i){
            for(int j = 0;j<=board[0].size() -k;++j){
                pair<int ,int> f1 = make_pair(i,j);
                pair<int ,int> f2 = make_pair(i,j+k-1);
                pair<int ,int> f3 = make_pair(i+k-1,j);
                pair<int ,int> f4 = make_pair(i+k-1,j+k-1);
                vector<pair<int, int>> foursome{ f1, f2, f3, f4 };
                for(auto& a:foursome){
                    for(auto& v:positions){
                        if(v.first!=a.first && v.second != a.second)
                        {
                            break;
                        }
                    }
                }
                
                count++;
                

            }
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    int result = countSquare(board);
    cout << result << endl;

    return 0;
}
