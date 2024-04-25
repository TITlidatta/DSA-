#include <stdio.h>
#include <stdbool.h>

bool flag = false;

void binary_search(int* pts, int x, int y, int t) {
    int high, low, mid;
    low = x;
    high = y;
    mid = (x + y) / 2;
    
    if (high < low || low > high) {
        return;
    }
    
    if (low == high) {
        if (*(pts + low) == t) {
            if (flag) {
                return;
            } else {
                flag = true;
            }
        }
        return;
    }
    
    if (t > *(pts + mid)) {
        binary_search(pts, mid + 1, high, t);
        return;
    } else if (t <= *(pts + mid)) {
        if (t == *(pts + mid) && !flag) {
            flag = true;
            return;
        } else {
            binary_search(pts, low, mid - 1, t);
            return;
        }
    }
}

int main() {
    int i, j, n, m, trg;

    printf("enter the no of rows\n");
    scanf("%d", &n);

    printf("enter the no of columns\n");
    scanf("%d", &m);

    int arr[n][m];

    printf("enter the array\n");
    
    for (i = 0; i < n; i++) {
        printf("Enter for %d row\n", i+1);
        
        for (j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("enter the target ");
    scanf("%d", &trg);
     for(i=0;i<n;i++)
     {
         binary_search(arr[i],0,m-1,trg);
     }
     if(flag)
     {
         printf("found\n");
     }
     else
     { 
         printf("not found\n");
     }
   return 0;
}
