#include <stdio.h>
int main()
{
    int r, c;
    printf("Enter the row and column :\n");
    scanf("%d%d", &r, &c);
    int arr2D[r][c];
    int cnt = 0;
    int col[c];
    int arr[r * c];
    for (int i = 0; i < c; i++)
    {
        printf("How many elemnt in colum %d : \n", i + 1);
        int s = 0;
        scanf("%d", &s);
        for (int j = 0; j < s; j++)
        {
            scanf("%d", &arr2D[j][i]);
            arr[cnt] = arr2D[j][i];
            cnt++;
        }
        col[i] = cnt;
    }
    printf("which column do you want to print :\n");
    int h;
    scanf("%d", &h);
    if (h == 1)
    {
        for (int i = 0; i < col[h - 1]; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = col[h - 2]; i < col[h - 1]; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}