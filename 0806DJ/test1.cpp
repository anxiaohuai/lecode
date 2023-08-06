#include <stdio.h>

int calculateMaxTotalYie(int cropField[][100], int m, int n) {
    int ans = 0;
    
    int rowMax = 0;
    int rowIndex = 0;
    for (int i = 0; i < m; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += cropField[i][j];
            ans += cropField[i][j];
        }
        if (rowMax < rowSum) {
            rowMax = rowSum;
            rowIndex = i;
        }
    }
    
    int colMax = 0;
    int colIndex = 0;
    for (int i = 0; i < n; i++) {
        int colSum = 0;
        for (int j = 0; j < m; j++) {
            colSum += cropField[j][i];
        }
        if (colMax < colSum) {
            colMax = colSum;
            colIndex = i;
        }
    }
    
    return ans + rowMax + colMax - cropField[rowIndex][colIndex];
}

int main() {
    int cropField_rows, cropField_cols;
    scanf("%d %d", &cropField_rows, &cropField_cols);
    
    int cropField[100][100];
    for (int i = 0; i < cropField_rows; i++) {
        for (int j = 0; j < cropField_cols; j++) {
            scanf("%d", &cropField[i][j]);
        }
    }
    
    int res = calculateMaxTotalYie(cropField, cropField_rows, cropField_cols);
    printf("%d\n", res);
    
    return 0;
}
