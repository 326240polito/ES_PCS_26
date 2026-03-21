#include <iostream>
#include <cmath>
int main()
{static const int N = 10;
double arr[N] = {7, 12, 11, 37.2, 31.7, -13, 71, -3.12, 4.12, 8.11};
double m;
double M;
double s;
for (int i=0; i < N; i++) {
    m = std::min(arr[i], m);
    M = std::max(arr[i], M);
    s += arr[i];
}
double media = s/N;
double d;
double sum;
for (int i=0; i < N; i++){
    sum += (arr[i] - media)*(arr[i] - media);
}
double var = std::sqrt(sum/N);
std::cout << "minimo: " << m << " " << "massimo: " << M << " " << "media: " << " " << media << " " << "deviazione: " << var <<  "\n";
}

