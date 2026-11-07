#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int N;
    double S = 0.0;

    printf("Введіть N: ");
    scanf("%d", &N);

    for (int n = 1; n <= N; n++) {
        double temp = 1.0;
        int power = n-1;
        while (power != 0) {
            temp *= -1.0;
            power--;
        }
        S += temp*(1.0/n);
    }

    printf("S = %f", S);

    return 0;
}