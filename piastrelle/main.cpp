#include <iostream>
#include <cassert>

using namespace std;

#define MAX_LENGTH 25
long long piastrellature[MAX_LENGTH];

long long piastrelle(int n){
    if (n <= 2){
        return n;
    }else{
        return piastrelle(n-1) + piastrelle(n-2);
    } 
}

long long piastrelleEff(long n){
    piastrellature[1] = 1;
    piastrellature[2] = 2;
    for (int i=3; i<=n; i++){
        piastrellature[i] = piastrellature[i-1] + piastrellature[i-2];
        cout << piastrellature[i] << " ";
    }
    return piastrellature[n];
}

int main(){
    long n;
    cin >> n;
    cout << piastrelleEff(n);
    return 0;
}