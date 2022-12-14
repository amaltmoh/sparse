// Online C compiler to run C program online
#include<stdio.h>
// Declaring a structure...
struct sp
{
	int col;
	int row;
	int value;	
};

// Function declarartions...
void printMatrix(struct sp S[100]);
void readMatrix(int A[100][100],int *m,int *n);
void transpose(struct sp S[100], struct sp trans[100]);
void sparseMatrix(int A[100][100],int m,int n,struct sp S[100]);
void sumMatrix(struct sp A[100],struct sp B[100], struct sp sum[100]);

// Main function...
int main()
{
	struct sp trans[100],sum[100],p[100],q[100];
	int n1,m2,n2,m1,A[100][100],B[100][100];
	int row[30],sp[30],numc,numt;
	
	readMatrix(A,&m1,&n1);
	sparseMatrix(A,m1,n1,p);
	
	readMatrix(B,&m2,&n2);
	sparseMatrix(B,m2,n2,q);
		
	//..................................................................................
	printf("\nThe tupple form of the first matrix is: \n");
	printMatrix(p);
	printf("\nThe tupple form of the second matrix is: \n");
	printMatrix(q);
	
	//transpose of first matrix...
	transpose(p,trans);
	printf("\nThe transpose of 1st matrix is :\n");
	printMatrix(trans);

	//sum of matrices...
	printf("\nSum of the matrices is :\n");
	sumMatrix(p,q,sum);
	printMatrix(sum);
	
	return 0;
}

// Function definitions...
//Function to read a matrix...
void readMatrix(int A[100][100],int *m,int *n)
{
	int i,j;
	printf("Enter the dimensions of 1st  matrix : ");
	scanf("%d%d",m,n);
	printf("enter the elements of 1st  matrix :\n");
	for(i=0;i<*m;i++)
	{
		for(j=0;j<*n;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
}

// Function to convert a normal matrix to sparse matrix...
void sparseMatrix(int A[100][100],int m,int n,struct sp S[100])
{
	int i,j,l=1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(A[i][j]!=0)
			{
				S[l].row=i;
				S[l].col=j;
				S[l].value=A[i][j];
				l++;
				
			}
		}
	}
	S[0].row=m;
	S[0].col=n;
	S[0].value=l-1;
}

// Function to print a sparse matrix...
void printMatrix(struct sp S[100])
{
	int i,l=S[0].value;
	for(i=0;i<=l;i++)
	{
		printf("%d\t%d\t%d",S[i].row,S[i].col,S[i].value);
		printf("\n");
	}
}

// Function to find the transpose of a sparse matrix...
void transpose(struct sp S[100], struct sp trans[100])
{
	int i,j,numc,numt;
	int row[100],sp[100];
	numc = S[0].col ;
	numt = S[0].value;
	trans[0].row=numc;
	trans[0].col=S[0].row;
	trans[0].value = numt;
	if(numt>0)
	{
		for(i=0;i<numc;i++)
		{
			row[i]=0;
		}
		for(i=1;i<=numt;i++)
		{
			row[S[i].col]++;
		}
		sp[0]=1;
		for(i=1;i<numc;i++)
		{
			sp[i]=sp[i-1]+row[i-1];
		}
		for(i=1;i<=numt;i++)
		{
			j=sp[S[i].col]++;
			trans[j].row=S[i].col;
			trans[j].col=S[i].row;
			trans[j].value=S[i].value;
		}
	} 
		
}

// Function to add 2 sparse matrices...
void sumMatrix(struct sp A[100],struct sp B[100], struct sp sum[100])
{
	int i,j,k=1;
	int t1 = A[0].value;
	int t2 = B[0].value;
	if(A[0].row!=B[0].row || A[0].col!=B[0].col)
	{
		printf("\nNot compatable fr addition....\n");
		return;
	}
	for(i=1,j=1;i<=t1&&j<=t2;k++)
	{
		if(A[i].row==B[j].row && A[i].col==B[j].col)
		{
			sum[k].row= A[i].row;
			sum[k].col= B[j].col;
			sum[k].value = A[i].value+B[j].value;
			i++,j++;
		}
		else if (A[i].row==B[j].col)
		{
			if(A[i].col<B[j].col)
			{
				sum[k].row = A[i].row;
				sum[k].col = A[i].col;
				sum[k].value = A[i].value;
				i++;
			}	
			else
			{
				sum[k].row = B[j].row;
				sum[k].col = B[j].col;
				sum[k].value = B[j].value;
				j++;
			}
		}
		else
		{
			if(A[i].row<B[j].row)
			{
				sum[k].row = A[i].row;
				sum[k].col = A[i].col;
				sum[k].value = A[i].value;
				i++;
			}	
			else
			{
				sum[k].row = B[j].row;
				sum[k].col = B[j].col;
				sum[k].value = B[j].value;
				j++;
			}
		}
	}
	for(;i<=t1;i++,k++)
	{
		sum[k].row = A[i].row;
		sum[k].col = A[i].col;
		sum[k].value = A[i].value;
	}
	for(;j<=t2;j++,k++)
	{
		sum[k].row = B[j].row;
		sum[k].col = B[j].col;
		sum[k].value = B[j].value;
	}
	sum[0].row = A[0].row;
	sum[0].col = A[0].col;
	sum[0].value=k-1;
}

	
 
#include<stdio.h>
 2 
 
void quicksort(int a[25],int l,int h)
 3 
 
{
 4 
 
    int i,j,pivot,temp;
 5 
 
    if(l<h)
 6 
 
    {
 7 
 
        pivot=l;
 8 
 
        i=l;
 9 
 
        j=h;
 10 
 
        while(i<j)
 11 
 
        {
 12 
 
            while(a[i]<=a[pivot] && i<h)
 13 
 
            {
 14 
 
                i++;
 15 
 
            }
 16 
 
            while(a[j]>a[pivot])
 17 
 
            {
 18 
 
                j--;
 19 
 
            }
 20 
 
            if(i<j)
 21 
 
            {
 22 
 
                temp=a[i];
 23 
 
                a[i]=a[j];
 24 
 
                a[j]=temp;
 25 
 
            }
 26 
 
        }
 27 
 
        temp=a[pivot];
 28 
 
        a[pivot]=a[j];
 29 
 
        a[j]=temp;
 30 
 
        quicksort(a,l,j-1);
 31 
 
        quicksort(a,j+1,h);
 32 
 
    }
 33 
 
}
 34 
 
int main()
 35 
 
{
 36 
 
    int i,n,a[25];
 37 
 
    printf("\nenter the number of elements of the array: ");
 38 
 
    scanf("%d",&n);
 39 
 
    printf("enter the elements: ");
 40 
 
    for(i=0;i<n;i++)
 41 
 
    {
 42 
 
        scanf("%d",&a[i]);
 43 
 
    }
 44 
 
    quicksort(a,0,n-1);
 45 
 
    printf("\nthe sorted elements are: ");
 46 
 
    for(i=0;i<n;i++)
 47 
 
    {
 48 
 
        printf("\t%d",a[i]);
 49 
 
    }
 50 
 
}
 51 
 
 
#include<stdio.h>
 2 
 
int main()
 3 
 
{
 4 
 
    int a[50],i,n,j,temp,min;
 5 
 
    printf("enter the limit of the array: ");
 6 
 
    scanf("%d",&n);
 7 
 
    printf("enter the elements: ");
 8 
 
    for(i=0;i<n;i++)
 9 
 
    {
 10 
 
        scanf("%d",&a[i]);
 11 
 
    }
 12 
 
    for(i=0;i<n-1;i++)
 13 
 
    {
 14 
 
        min=i;
 15 
 
        for(j=i+1;j<n;j++)
 16 
 
        {
 17 
 
            if(a[j]<a[min])
 18 
 
            {
 19 
 
                min=j;
 20 
 
            }
 21 
 
        }
 22 
 
        temp=a[i];
 23 
 
        a[i]=a[min];
 24 
 
        a[min]=temp;
 25 
 
    }
 26 
 
    printf("\nthe sorted array is: ");
 27 
 
    for(i=0;i<n;i++)
 28 
 
    {
 29 
 
        printf("\t%d",a[i]);
 30 
 
    }
 31 
 
}
