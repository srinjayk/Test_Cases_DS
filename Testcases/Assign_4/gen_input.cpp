#include <iostream>
#include <algorithm> 
#include <bits/stdc++.h> 

using namespace std;

int main() {
    // int k = rand()%3000;
    int k = 10;
    int mod = 40;
    cout<<k<<" "<<mod<<endl;
    for(int i=0; i<k; i++){
        int n = (rand()+55)%(mod-1)+1;
        // cout<<n<<endl;
        int arr[n];

        for(int j=0; j<n; j++){
            arr[j] = ((j+1)*1)%26;
        }
        
        string a = "";
        
        for(int j=0;j<n;j++){
            a = a + (char)('a'+arr[j]);
        }
        
        cout <<a.size()<<" "<<a<<endl;
    }
    
    return 0;
}