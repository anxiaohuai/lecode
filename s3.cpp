#include <stdio.h>
#include <stdlib.h>

int myMax(int a, int b) {
    return (a > b) ? a : b;
}

int necklace(int n, int* num, int size) {
    int mod = 1000000007;
    int j, f = 0;
    int z = 0, m = n << 1;
    int* c = (int*)malloc(sizeof(int) * (m + 1));
    
    for (int i = 0; i < size; i++) {
        c[f] = num[i];
        c[f++ + n] = num[i];
    }

    int** a = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        a[i] = (int*)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }
    
    for (int l = 1; l < n; l++) {
        for (int i = 0; i + l < m; i++) {
            j = i + l;
            for (int k = i; k < j; k++) {
                a[i][j] = myMax(a[i][j],
                                (a[i][k] + a[k + 1][j] + c[i] * c[k + 1] * c[j + 1]) % mod);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        z = myMax(a[i][i + n - 1], z);
    }
    
    for (int i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);
    free(c);
    
    return z;
}

int main() {
    int n = 4;
    int num[] = {2, 3, 5,10};

    int result = necklace(n, num, sizeof(num) / sizeof(num[0]));
    
    printf("最大值: %d\n", result);
    
    return 0;
}
