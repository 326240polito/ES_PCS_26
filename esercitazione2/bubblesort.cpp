#include <iostream>

using namespace std;
int main() {
    static const int N=10;  // dimensione dell'array
    double arr[N]={1.0, 2.0, 3.0, 27.2, 43.7, 0, 211.0, 7.12, 4.12, 9.11};
   
    bool swapped = true;
    while (swapped == true) {
        swapped = false;
        for (int i=0; i<N-1; i++){
            if  (arr[i] > arr[i+1])  {
                double p = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=p;
                swapped = true;
            }
        } 
    }   
    for (int i=0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}