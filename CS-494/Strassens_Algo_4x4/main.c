#include<stdio.h>
#include<stdlib.h>
//strassen's matrix multiplication to multiply two 4 X 4 matrices
void multiply (int arr1[2][2],int arr2[2][2],int res[2][2]){
    int i,j,k;
    int s=0;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++){
                s = s + arr1[i][k] * arr2[k][j] ;
            }
            res[i][j] = s;
            s=0;
        }
    }
}

void add(int arr1[2][2],int arr2[2][2],int res[2][2]){
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            res[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

void subtract(int arr1[2][2], int arr2[2][2], int res[2][2]){
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            res[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
}

int main(){
    //arrays on which multiplication is to be done
    int arr1[4][4]= {{4,2,0,1} , {8,1,2,5} , {3,2,1,4} , {5,2,6,7}};
    int arr2[4][4]= {{2,1,3,2} , {5,4,2,3} , {1,4,0,2} , {3,2,4,1}};
    //sub arrays which will combine to give final array
    int c11[2][2],c12[2][2],c21[2][2],c22[2][2];
    //temporary arrays
    int t1[2][2],t2[2][2];
    //intermediate matrices
    int p[2][2],q[2][2],r[2][2],s[2][2],t[2][2],u[2][2],v[2][2];
    int a11[2][2], a12[2][2], a21[2][2], a22[2][2];
    int b11[2][2], b12[2][2], b21[2][2], b22[2][2];
    //final array
    int pro[4][4];
    int i,j;
    //extracting sub matrices from input matrices
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if (i<2 && j<2){
                a11[i][j]= arr1[i][j];
                b11[i][j]= arr2[i][j];
            }
            if (i<2 && j>=2){
                a12[i][j-2]= arr1[i][j];
                b12[i][j-2]= arr2[i][j];
            }
            if (i>=2 && j<2){
                a21[i-2][j] = arr1[i][j];
                b21[i-2][j] = arr2[i][j];
            }
            if (i>=2 && j>=2){
                a22[i-2][j-2] = arr1[i][j];
                b22[i-2][j-2] = arr2[i][j];
            }
        }
    }

    add(a11,a22,t1);
    add(b11,b22,t2);
    multiply(t1,t2,p);

    add(a21,a22,t1);
    multiply(t1,b11,q);

    subtract(b12,b22,t2);
    multiply(a11,t2,r);

    subtract(b21,b11,t1);
    multiply(a22,t1,s);

    add(a11,a12,t1);
    multiply(t1,b22,t);

    subtract(a21,a11,t1);
    add(b11,b12,t2);
    multiply(t1,t2,u);

    subtract(a12,a22,t1);
    add(b21,b22,t2);
    multiply(t1,t2,v);

    add(p,s,t1);
    subtract(v,t,t2);
    add(t1,t2,c11);

    add(r,t,c12);
    add(q,s,c21);
    add(p,r,t1);
    subtract(u,q,t2);
    add(t1,t2,c22);

    //combining all submatrices
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if (i<2 && j<2)
                pro[i][j] = c11[i][j];
            if (i>=2 && j<2)
                pro[i][j] = c21[i-2][j];
            if (i<2 && j>=2)
                pro[i][j] = c12[i][j-2];
            if (i>=2 && j>=2)
                pro[i][j] = c22[i-2][j-2];
        }
    }

    printf("\nThe resultant matrix is:\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ",pro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
