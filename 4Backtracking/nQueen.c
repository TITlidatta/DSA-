#include <stdio.h>
#include <stdbool.h>

int counter[30];
int box[30][30];

bool safe(int i, int j, int n) {
    if (i < 0 || j < 0 || i >= n || j >= n) {
        return false;
    }
    for (int x = 0; x < n; x++) {
        if (box[i][x] == 1 || box[x][j] == 1 ||
            (i + x < n && j + x < n && box[i + x][j + x] == 1) ||
            (i - x >= 0 && j - x >= 0 && box[i - x][j - x] == 1) ||
            (i + x < n && j - x >= 0 && box[i + x][j - x] == 1) ||
            (i - x >= 0 && j + x < n && box[i - x][j + x] == 1)) {
            return false;
        }
    }
    return true;
}

int NQueen(int n, int col) {
    if (col >= n) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (safe(i, col, n)) {
            counter[i] = 1;
            box[i][col] = 1;
            if (NQueen(n, col + 1) == 1) {
                return 1;
            }
            counter[i] = 0;
            box[i][col] = 0;
        }
    }
    return 0;
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    int l = NQueen(n, 0);
    if (l == 0) {
        printf("Solution does not exist.\n");
    } else {
        printf("Solution found:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", box[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
