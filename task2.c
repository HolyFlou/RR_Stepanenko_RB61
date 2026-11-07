#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

/**
 * @brief Виділяє динамічну пам'ять для квадратної матриці N x N.
 *
 * @param N Розмірність матриці (кількість рядків і стовпчиків).
 * @return double** Вказівник на масив вказівників, що описує двовимірну матрицю.
 */
double **memory_alloc(int N);

/**
 * @brief Заповнює матрицю випадковими дійсними числами у діапазоні [-a, a].
 *
 * @param Arr Вказівник на виділену матрицю.
 * @param N   Розмірність матриці.
 * @param a   Верхня межа діапазону генерації значень.
 * @return double** Вказівник на заповнену матрицю.
 */
double **fill_arr(double **Arr, int N, int a);

/**
 * @brief Обчислює добуток елементів, розташованих на головній діагоналі та вище неї.
 *
 * @param Arr Вказівник на матрицю з даними.
 * @param N   Розмірність матриці.
 * @return double Результат множення вибраних елементів.
 */
double multiply(double **Arr, int N);

/**
 * @brief Виводить матрицю у консоль із форматуванням та відображає підсумковий результат.
 *
 * @param Arr    Вказівник на матрицю.
 * @param N      Розмірність матриці.
 * @param result Обчислений добуток елементів.
 */
void print(double **Arr, int N, double result);

/**
 * @brief Звільняє динамічно виділену пам'ять для двовимірної матриці.
 *
 * @param Arr Вказівник на матрицю, пам'ять якої потрібно очистити.
 * @param N   Кількість рядків матриці.
 */
void clear_memory(double **Arr, int N);

int main() {
    SetConsoleOutputCP(CP_UTF8);

    // Ініціалізація генератора випадкових чисел
    srand((unsigned int)time(NULL));

    int N;
    printf("Введіть розмір матриці N: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Некоректний розмір матриці.\n");
        return 1;
    }

    // Генерація випадкового числа 'a' з діапазону [4, 8]
    int a = 4 + rand() % (8 - 4 + 1);
    printf("a = %d (діапазон елементів: [-%d, %d])\n\n", a, a, a);

    double **Arr = memory_alloc(N);
    Arr = fill_arr(Arr, N, a);

    double result = multiply(Arr, N);

    print(Arr, N, result);

    clear_memory(Arr, N);

    return 0;
}

// Виділяємо пам'ять для двовимірної матриці
double **memory_alloc(int N) {
    double **Arr = (double **)malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        Arr[i] = (double *)malloc(N * sizeof(double));
    }
    return Arr;
}

// Заповнюємо матрицю випадковими дійсними числами з [-a, a]
double **fill_arr(double **Arr, int N, int a) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double random_val = -a + ((double)rand() / RAND_MAX) * (2 * a);
            Arr[i][j] = random_val;
        }
    }
    return Arr;
}

// Розрахунок добутку
double multiply(double **Arr, int N) {
    double result = 1.0;

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            result *= Arr[i][j];
        }
    }
    return result;
}

// Вивід матриці та добутку
void print(double **Arr, int N, double result) {
    printf("Матриця A (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%7.2f ", Arr[i][j]);
        }
        printf("\n");
    }

    printf("\nРозраховане значення: %f\n", result);
}

// Звільнення пам'яті
void clear_memory(double **Arr, int N) {
    for (int i = 0; i < N; i++) {
        free(Arr[i]);
    }
    free(Arr);
}