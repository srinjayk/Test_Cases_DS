#include <iostream>
#include <algorithm> 
#include <bits/stdc++.h> 

using namespace std;

int main() {
    // int k = rand()%3000;
    int k = 10;
    // cout<<"k = "<<k<<endl;
    cout<<k*4<<endl;
    int i;
    for(i=0; i<k; i++){
        int n = rand()%118+6;
        int j;
        // cout<<"n = "<<n<<endl;
        // cout<<n<<endl;
        int arr[n];
        int prior[n];
        
        for(j=0; j<n; j++){
            arr[j] = (j+1)*18;
            prior[j] = j+1;
        }
        int count = 0;
        do { 
            if(count>=4){
                break;
            }
            cout <<n<<endl;
            for(int l=0;l<n;l++){
                if(l==n-1){
                    cout <<arr[n-1]<<endl;
                } 
                else{
                    cout <<arr[l]<<" ";
                }
            }
            for(int l=0;l<n;l++){
                if(l==n-1){
                    cout <<prior[n-1]<<endl;
                } 
                else{
                    cout <<prior[l]<<" ";
                }
            }
            
            count++;
        }while (next_permutation(arr, arr+n)); 
        // cout<<endl;
    }
}