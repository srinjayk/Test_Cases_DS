// A Dynamic programming solution for Word Wrap Problem  
#include <bits/stdc++.h> 
using namespace std; 
#define INF LLONG_MAX  
#define MOD 1000000007
  
// A utility function to print the solution  
int printSolution (string L[], long long int p[], long long int n);  
  
// l[] represents lengths of different words in input sequence.  
// For example, l[] = {3, 2, 2, 5} is for a sentence like  
// "aaa bb cc ddddd". n is size of l[] and M is line width  
// (maximum no. of characters that can fit in a line)  
void solveWordWrap (string L[], long long int l[], long long int n, long long int M)  
{  
    // For simplicity, 1 extra space is used in all below arrays  
  
    // extras[i][j] will have number of extra spaces if words from i  
    // to j are put in a single line  
    long long int extras[n+1][n+1];  
  
    // lc[i][j] will have cost of a line which has words from  
    // i to j  
    long long int lc[n+1][n+1];  
  
    // c[i] will have total cost of optimal arrangement of words  
    // from 1 to i  
    long long int c[n+1];  
  
    // p[] is used to print the solution.  
    long long int p[n+1];  
  
    long long int i, j;  
  
    // calculate extra spaces in a single line. The value extra[i][j]  
    // indicates extra spaces if words from word number i to j are  
    // placed in a single line  
    for (i = 1; i <= n; i++)  
    {  
        extras[i][i] = M - l[i-1];  
        for (j = i+1; j <= n; j++)  
            extras[i][j] = extras[i][j-1] - l[j-1] - 1;  
    }  
  
    // Calculate line cost corresponding to the above calculated extra  
    // spaces. The value lc[i][j] indicates cost of putting words from  
    // word number i to j in a single line  
    for (i = 1; i <= n; i++)  
    {  
        for (j = i; j <= n; j++)  
        {  
            if (extras[i][j] < 0)  
                lc[i][j] = INF;  
            else if (j == n && extras[i][j] >= 0)  
                lc[i][j] = 0;  
            else
                lc[i][j] = ((extras[i][j]*extras[i][j])%MOD*extras[i][j])%MOD;  
        }  
    }  
  
    // Calculate minimum cost and find minimum cost arrangement.  
    // The value c[j] indicates optimized cost to arrange words  
    // from word number 1 to j.  
    c[0] = 0;  
    for (j = 1; j <= n; j++)  
    {  
        c[j] = INF;  
        for (i = 1; i <= j; i++)  
        {  
            if (c[i-1] != INF && lc[i][j] != INF && (c[i-1]%MOD + lc[i][j]%MOD)%MOD < c[j])
            {  
                c[j] = (c[i-1] + lc[i][j])%MOD;  
                p[j] = i;  
            }  
        }  
    }  
  
    printSolution(L, p, n);  
    cout<<c[n]%MOD;
}  
  
int printSolution (string L[], long long int p[], long long int n)  
{  
    long long int k;  
    if (p[n] == 1)  
        k = 1;  
    else
        k = printSolution (L, p, p[n]-1) + 1;  
    // cout<<"Line number "<<k<<": From word no. "<<p[n]<<" to "<<n<<endl;  
    for(int i=p[n]-1; i<n-1; i++){
        cout<<L[i]<<" ";
    }
    cout<<L[n-1]<<endl;
    // cout<<"Line number "<<k<<": From word no. "<<p[n]<<" to "<<n<<endl;  
    return k;  
}  
  
// Driver program to test above functions  
int main()  
{  
    // int l[] = {3, 2, 2, 5};  
    // int n = sizeof(l)/sizeof(l[0]);  
    // int M = 6;  
    long long int n, M;
    cin>>n>>M;
    long long int l[n];
    string L[n];
    for(long long int i=0; i<n; i++){
        cin>>l[i];
        cin>>L[i];
    }
    solveWordWrap (L, l, n, M);  
    return 0;  
}  
  
  
//This is code is contributed by rathbhupendra