#include <iostream>
using namespace std;

void count(char *p){

}


int main()
{
    int row,col;
    cin >> row>>col;
    char temp[row][col+1];
    for (size_t i = 0; i < row; i++)
    {
        cin >> temp[i];
    }
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            switch (temp[i][j])
            {
            case '*':
                cout << '*';
                break;
            case '?':
            {
                int num = 0,up = i-1,down = i+1,l = j-1,r = j+1;
                if (up < 0)
                {
                    up = i;
                }
                if (down == row)
                {
                    down = i;
                }
                if (l < 0)
                {
                    l = j;
                }
                if (r == col)
                {
                    r = j;
                }
                
                for (size_t a = up; a <= down; a++)
                {
                    for (size_t b = l; b <= r; b++)
                    {
                        if (temp[a][b] == '*')
                        {
                            num++;
                        }
                        
                    }
                    
                }
                cout <<num;
                break;
            }
            default:
                break;
            }
        }
        cout <<endl;
    }
    
}