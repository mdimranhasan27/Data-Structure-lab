#include <iostream>
using namespace std;

int main()
{
    int mat[2][2] = {{5, 2}, {5, 4}};
    int arr[4];
    for (int i = 0; i <2; i++)
    {
        for (int j = 0; j <2; j++)
        {
            arr[ i +j* 2] = mat[i][j];//column major order 
            //arr[j+ i*2] = mat[i][j]; row major order .
        }
    }
    cout << arr[0] << "\n";
    cout << arr[1] << "\n";
    cout << arr[2] << "\n";
    cout << arr[3] << "\n";

    return 0;
}