

#include <iostream>
#include <chrono>
using namespace std;
bool A(int sum, int n, int a){
    a=a-1;
    int aux1=(n*(n+1))/2;
    int aux2=(a*(a+1)/2);
    if(sum!=aux1-aux2){
        return true;
    }
    return false;

}
int B(int *arr, int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]!=i+1){
            return i+1;
        }
    }
    return -1;
}
int C(int *arr, int n){
    int sum, total;
    sum=0;
    total=((n+1)*(n+2))/2;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return total-sum;
}
int main()
{

    cout<<"Analisis experimental ejercicio 10"<<endl;

    cout<<"n;Tiempo A;Tiempo B;Tiempo C"<<endl;
    for(int n=1000;n<=10000;n+=1000){
        int vec[n];
        int sum=0;
        for(int i=0;i<n;i++){
            vec[i]=i+1;
            sum+=i;
        }

        double tiempoA=0,tiempoB=0,tiempoC=0;
        double time=0;
        auto startA = chrono::high_resolution_clock::now();
        bool x=A(sum,n,0);
        auto finishA = chrono::high_resolution_clock::now();
        tiempoA=chrono::duration_cast<chrono::nanoseconds> (finishA - startA).count();

        auto startB = chrono::high_resolution_clock::now();
        int y= B(vec, n);
        auto finishB = chrono::high_resolution_clock::now();
        tiempoB=chrono::duration_cast<chrono::nanoseconds> (finishB - startB).count();

        auto startC = chrono::high_resolution_clock::now();
        int z= C(vec, n);
        auto finishC = chrono::high_resolution_clock::now();
        tiempoC=chrono::duration_cast<chrono::nanoseconds> (finishC - startC).count();
       
        cout<<n<<";"<<tiempoA<<";"<<tiempoB<<";"<<tiempoC<<endl;
      }
      
}
