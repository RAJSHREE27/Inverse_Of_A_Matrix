// name- RAJSHREE GAVEL , roll no. - 16115064
// this program to is calculate the inverse of a given matrix and to check its correctness.

#include <iostream>
using namespace std;                
int determinant(int **mat,int n);                               //function definitions
int cofactor(int **mat, int n, int i, int j);
int minor(int **mat, int n, int i, int j);

int main()
{
    int **mat,**cof;
    float **inverse,**identity;
    int i,j,n,det,k;
    cout<<"\n enter the size of matrix :";                      //entering size of original matrix
    cin>>n;
    mat=new int*[n];
    cof=new int*[n];
    inverse=new float*[n];
    identity=new float*[n];
    
    for(i=0; i<n; i++)
    {   mat[i]=new int[n];
        cof[i]=new int[n];
        inverse[i]=new float[n];
        identity[i]=new float[n];                               //declaring various matrices to be used in the program
    }
    cout<<"\n enter the matrix :";
    for(i=0; i<n ; i++)                                         // entering the matrix
    {
        for(j=0; j<n; j++)
        {
            cin>>mat[i][j];
        }
    }
    for(i=0; i<n ; i++)                                            //initialising identity matrix with 0         
     {
        for(j=0; j<n; j++)
        {
            identity[i][j]=0;
        }
     }
    
    det = determinant(mat ,n);                                  //calculating the determinant                                   
    if(det==0)
    {   cout<<"\n the matrix is singular!! so no inverse could be found!!";
    }
    else
    {   cout<<"\n now calculating the adjoint!!"<<"\n";                     // when the entered matrix is non-singular, then matrix inversion is possible
        for(i=0; i<n ; i++)                                  
        {
            for(j=0; j<n ; j++)
            {
                cof[j][i]= cofactor(mat, n, i, j);                          //finding the cofactors of the elements           
            }
        }                              
        for(i=0; i<n; i++)
        {
           for(j=0; j<n; j++)
            {
                inverse[i][j]=(float)cof[i][j]/(float)det;                  //finding the inverse matrix
            }
        }
            cout<<"\n the required inverse of a matrix is : ";              // printing the inverse of the matrix
            for(i=0; i<n; i++)
            {
                for(j=0; j<n ; j++)
                {
                    cout<<inverse[i][j]<<" ";
                }
                cout<<"\n";
            }
        
        cout<<"\n checking the value is correct or not!";
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                for(k=0; k<n; k++)
                {
                    identity[i][j] += mat[i][k]*inverse[k][j];              // checking it to get the identity matrix
                }
            }
        }
        cout<<"\n the value is:"<<"\n";
          for(i=0; i<n; i++)
            {
                for(j=0; j<n ; j++)
                {
                    cout<<identity[i][j]<<" ";
                }
                cout<<"\n";
            }
        }

        return 0;
        
 }

 int determinant(int **mat, int n)                                       // function to find the determinant of the given matrix
 {  
    int x=0;
    int i;
    if(n==1)
    {  
         return mat[0][0];
     }  
    for(i=0; i<n; i++)
    {  
          x += mat[0][i]*cofactor(mat,n,0,i);
    } 
    return x;  
 }      

 int cofactor(int **mat, int n, int i, int j)                       //function to find the cofactor
 {  
     if((i+j)%2==0)
     {
        return minor(mat, n, i, j);
     }
     else
     {  return -1*minor(mat, n, i, j);
     }
 }

 int minor(int **mat, int n, int i, int j)                          //function to find the minor
 {   
    int **min_mat;
    int k, m, r, p=0, q=0 ;
    min_mat=new int*[n-1];
    for(k=0; k<n-1; k++)
    {
        min_mat[k]=new int[n-1];
    }
 
    for(m=0; m<n; m++)
    {  
            for(r=0; r<n; r++)
            {
                if(m!=i && r!=j)
                {
                    min_mat[p][q]=mat[m][r];
                    q++;
                    if (q==n-1)
                    {
                        q=0;
                        p++;
                    }
                }
            }
            
        
    }
   return determinant(min_mat , n-1);
 }