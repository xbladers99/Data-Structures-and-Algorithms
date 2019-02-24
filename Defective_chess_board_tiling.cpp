#include <iostream>
using namespace std;
#define size 8
int board[size][size];
int tile = 0;
void rec(int tr,int tc,int x,int y,int n)
{
    //cout<<"tr ="<<tr<<" tc = "<<tc<<endl;
    if(n==2)
    {
        tile++;
        for(int i = tr; i<=tr + n/2; i++)
            for(int j=tc; j<=tc + n/2; j++)
                if(!(i==x && j==y))
                    board[i][j] = tile;
        return;
    }
    tile++;
    int quadsize = n/2;
    int q = 0;
    int dx1,dy1,dx2,dy2,dx3,dy3,dx4,dy4;
    //1st quadrant
    if(x < tr + quadsize && y < tc + quadsize)
    {
        q = 1;
    }

    if(x < tr + quadsize && y >= tc + quadsize)
       q = 2;

    if(x >= tr + quadsize && y < tc + quadsize)
        q = 3;
    if(x >= tr + quadsize && y >= tc + quadsize)
        q = 4;
    //cout<<"quadsize = "<<quadsize<<" q = "<<q<<endl;
    if(q == 1)
    {
        dx1 = x;    dy1 = y;
        dx2 = tr + quadsize - 1;    dy2 = tc + quadsize;
        dx3 = tr + quadsize;        dy3 = tc + quadsize - 1;
        dx4 = tr + quadsize;        dy4 = tc + quadsize;
        board[dx2][dy2] = tile;
        board[dx3][dy3] = tile;
        board[dx4][dy4] = tile;
        rec(tr,tc,x,y,quadsize);
        rec(tr,tc + quadsize,dx2,dy2,quadsize);
        rec(tr + quadsize,tc,dx3,dy3,quadsize);
        rec(tr + quadsize,tc + quadsize,dx4,dy4,quadsize);
    }
    else if(q==2)
    {
        dx1 = tr + quadsize - 1;    dy1 = tc + quadsize - 1;
        dx2 = x;        dy2 = y;
        dx3 = tr + quadsize;        dy3 = tc + quadsize - 1;
        dx4 = tr + quadsize;        dy4 = tc + quadsize;
        board[dx1][dy1] = tile;
        board[dx3][dy3] = tile;
        board[dx4][dy4] = tile;
        rec(tr, tc + quadsize, x, y, quadsize);
        rec(tr,tc,dx1,dy1,quadsize);
        rec(tr + quadsize,tc,dx3,dy3,quadsize);
        rec(tr + quadsize,tc + quadsize,dx4,dy4,quadsize);
    }
    else if(q==3)
    {
        dx1 = tr + quadsize - 1;    dy1 = tc + quadsize - 1;
        dx2 = tr + quadsize - 1;        dy2 = tc + quadsize;
        dx3 = x;        dy3 = y;
        dx4 = tr + quadsize;        dy4 = tc + quadsize;
        board[dx1][dy1] = tile;
        board[dx2][dy2] = tile;
        board[dx4][dy4] = tile;
        rec(tr + quadsize, tc, x, y, quadsize);
        rec(tr,tc,dx1,dy1,quadsize);
        rec(tr,tc + quadsize,dx2,dy2,quadsize);
        rec(tr + quadsize,tc + quadsize,dx4,dy4,quadsize);
    }
    else if(q==4)
    {
        dx1 = tr + quadsize - 1;    dy1 = tc + quadsize - 1;
        dx2 = tr + quadsize - 1;        dy2 = tc + quadsize;
        dx3 = tr + quadsize;        dy3 = tc + quadsize - 1;
        dx4 = x;        dy4 = y;
        board[dx1][dy1] = tile;
        board[dx2][dy2] = tile;
        board[dx3][dy3] = tile;
        rec(tr + quadsize, tc + quadsize, x, y, quadsize);
        rec(tr,tc,dx1,dy1,quadsize);
        rec(tr,tc + quadsize,dx2,dy2,quadsize);
        rec(tr + quadsize,tc,dx3,dy3,quadsize);
    }
}

int main()
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            board[i][j] = 0;
    }
    int x,y;
    //cout<<"Enter defective tile coordinates: ";
    cin>>x>>y;
    board[x][y] = 0;
    cout<<endl;
    rec(0,0,x,y,size);
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            cout<<board[i][j]<<"\t";
        cout<<endl;
    }
}
