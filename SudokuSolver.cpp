//Program to solve a sudoku
#include<iostream>
#define N 9
using namespace std;
bool isSafe(int [N][N],int ,int ,int );
bool inRow(int [N][N],int,int );
bool inCol(int [N][N],int ,int );
bool inMat(int [N][N],int ,int ,int );
bool findEmpty(int [N][N],int &,int &);
bool isFull(int [N][N]);
bool SudokuSolver(int [N][N]);
void print(int [N][N]);
bool checkInvalid(int [N][N]);
bool checkSudoku(int [N][N]);


bool SudokuSolver(int Sudoku[N][N])  //It takes a partially filled sudoku as an input and solves the sudoku using backtracking and returns true if whole sudoku is solved
{
    int r,c;
    if(findEmpty(Sudoku,r,c)==false)
        return true;
    for(int i=1;i<=N;i++)
    {
        if(isSafe(Sudoku,r,c,i)==true){
            Sudoku[r][c]=i;
            if(SudokuSolver(Sudoku)==true)
                return true;
            Sudoku[r][c]=0;
        }
    }
        return false;

}
bool isSafe(int Sudoku[N][N],int r,int c,int i)           // checks if the number to be filled in the sudoku is safe
{
    return inRow(Sudoku,r,i)&&inCol(Sudoku,c,i)&&inMat(Sudoku,r-r%3,c-c%3,i);

}
bool inRow(int Sudoku[N][N],int r,int i)             // checks if the number to filled is safe by checking in that row
{
    for(int c=0;c<N;c++)
    {
        if(Sudoku[r][c]==i)
            return false;
    }
    return true;
}
bool inCol(int Sudoku[N][N],int c,int i)           // checks if the number to be filled is safe by checking in that column
{
    for(int r=0;r<N;r++)
    {
        if(Sudoku[r][c]==i)
            return false;
    }
    return true;
}
bool inMat(int Sudoku[N][N],int r,int c,int i)            // checks if the number to be filled is safe by checking in its 3*3 matrix
{
    for(int rStart=0;rStart<3;rStart++)
    {
        for(int cStart=0;cStart<3;cStart++)
    {
        if(Sudoku[rStart+r][cStart+c]==i)
            return false;
    }
    }
    return true;
}
bool findEmpty(int Sudoku[N][N],int &r,int &c)            // finds unassigned position in the sudoku
       {
           for(r=0;r<N;r++)
           {
               for(c=0;c<N;c++)
               {
                   if(Sudoku[r][c]==0)
                    return true;
               }
           }
           return false;
       }
bool isFull(int Sudoku[N][N])                              // checks if the entered sudoku is already filled or not
{

    for(int r=0;r<N;r++)
{
    for(int c=0;c<N;c++)
    {
        if(Sudoku[r][c]==0)
        {
         return false;
        }
    }
}
return true;
}
bool checkSudoku(int Sudoku[N][N])           // checks if the already filled sudoku is correctly solved or not
{
    for(int r=0;r<N;r++)
    {
        for(int c=0;c<N;c++)
        {
            int i=Sudoku[r][c];
            Sudoku[r][c]=0;
           if(!isSafe(Sudoku,r,c,i))
            {
                return false;
            }
            Sudoku[r][c]=i;
        }
    }
    return true;
}
bool checkInvalid(int Sudoku[N][N])         // checks if the partially filled input sudoku is valid or not
{
     for(int r=0;r<N;r++)
    {
        for(int c=0;c<N;c++)
        {
            if(Sudoku[r][c]!=0)
            {
             int i=Sudoku[r][c];
            Sudoku[r][c]=0;
            if(!isSafe(Sudoku,r,c,i))
            {
                return true;
            }
            Sudoku[r][c]=i;
            }

        }
    }
   return false;
}
void print(int Sudoku[N][N]){           // prints the solved sudoku
for(int i=0;i<N;i++)
         {
             cout<<"\t\t\t\t";
           for(int j=0;j<N;j++)
            {
              cout<<Sudoku[i][j]<<" ";
            }
            cout<<'\n';
         }
}
int main()
{
int Sudoku[N][N];
cout<<"\t\t\t\t\tSUDOKU SOLVER\t\t\t\t\t\t\n\n\n";
cout<<"\t\t\tEnter a 9*9 Sudoku \n \t\t\tEnter 0 for Unassigned Position \n\n";
for(int i=0;i<N;i++)
{
    cout<<"\t\t\t\t";
    for(int j=0;j<N;j++)
    {
        cin>>Sudoku[i][j];
    }
}
if(!isFull(Sudoku)){
        if(!checkInvalid(Sudoku))
        {
            if(SudokuSolver(Sudoku)==true)
    {
      cout<<"\n\t\tSOLVED SUDOKU IS:\n\n";
      print(Sudoku);
    }
    else
        cout<<"\t\tSudoku cannot be solved\n";
        }
    else
        cout<<"\t\tERROR\nSudoku Entered is invalid.\n"<<endl;
}
else
   {
       cout<<"\t\t\nSudoku Entered is already filled"<<endl;
       if(checkSudoku(Sudoku)==true)
        cout<<"and is correctly solved.\n";
       else cout<<"and is incorrectly solved.\n";

   }
}
