/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;
int solution(vector<int> &A) {
    // Implement your solution here

    int n=A.size();
    if(n==2)
    return 0;
    int m=INT_MAX;
    for(int i=0;i<n-2;i+=2){
    
        int prev=A[i],count=0;
        for(int k=i-2;k>=0;k-=2){
            if(A[k+1]==prev){
                prev=A[k];
                continue;
            }
            count++;
        }
        int curr=A[i+1];
        for(int j=i+2;j<n;j+=2){
            if(A[j]==curr){
                curr=A[j+1];
                continue;
            }
            count++;
        }
       
        m=min(m,count);
    }
    return m;
}
int main()
{
    //vector<int> A={2,4,1,3,4,6,2,4,1,6};
    vector<int> A={3,4};
    int ans=solution(A);
    cout<<ans;
    return 0;
}