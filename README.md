# Розрахункова робота

**Виконав:** студент групи РБ-61 Степаненко Нікіта Павлович  

## Завдання № 1

<img width="210" height="95" alt="изображение" src="https://github.com/user-attachments/assets/6bd8a95c-0fd4-4aa6-b7cb-7197a9b8730b" />

[Файл task1.c](https://github.com/HolyFlou/RR_Stepanenko_RB61/blob/main/task1.c)

В цій частині коду ми оголошуємо змінні та просимо користувача ввести N(кількість ітерацій в циклі)
```c
    int N;
    double S = 0.0;

    printf("Введіть N: ");
    scanf("%d", &N);
```

В цій частині коду ми виконуємо суму за формулою що дана в завданні
```c
    for (int n = 1; n <= N; n++) {
        double temp = 1.0;
        int power = n-1;
        while (power != 0) {
            temp *= -1.0;
            power--;
        }
        S += temp*(1.0/n);
    }
```

В цій частині я спробував без математичних функцій відтворити піднесення до степеню
```c
        double temp = 1.0;
        int power = n-1;
        while (power != 0) {
            temp *= -1.0;
            power--;
        }
```

В кінці просто виводу значення те що вийшло після суми
```c
    printf("S = %f", S);
```

## Завдання № 2

[Файл task2.c](https://github.com/HolyFlou/RR_Stepanenko_RB61/blob/main/task2.c)

В цьому завданні потрібно було створити матрицю (`double **memory_alloc(int N);`), заповнити її випадковими числами A (`double **fill_arr(double **Arr, int N, int a);`), виконати добуток чисел які знаходяться вище головної діагоналі включно з головною діагоналю (`double multiply(double **Arr, int N);`), вивести матрицю та результати обчислення в термінал (`void print(double **Arr, int N, double result);`) та очистити heap для того щоб не було витоку пам'яті (`void clear_memory(double **Arr, int N);`).

Прототипи функцій з Doxygen-коментарями:
```c
/**
 * @brief Виділяє динамічну пам'ять для квадратної матриці N x N.
 *
 * @param N Розмірність матриці (кількість рядків і стовпчиків).
 * @return double** Вказівник на масив вказівників, що описує 2D-матрицю.
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
 * @brief Звільняє динамічно виділену пам'ять для 2D-матриці.
 *
 * @param Arr Вказівник на матрицю, пам'ять якої потрібно очистити.
 * @param N   Кількість рядків матриці.
 */
void clear_memory(double **Arr, int N);
```

Головна функція `main` та виклик усіх модулів:
```c
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
```

Виділяємо пам'ять для двовимірної матриці
```c
double **memory_alloc(int N) {
    double **Arr = (double **)malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        Arr[i] = (double *)malloc(N * sizeof(double));
    }
    return Arr;
}
```

Заповнюємо матрицю випадковими дійсними числами з [-a, a]
```c
double **fill_arr(double **Arr, int N, int a) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double random_val = -a + ((double)rand() / RAND_MAX) * (2 * a);
            Arr[i][j] = random_val;
        }
    }
    return Arr;
}
```

Розрахунок добутку елементів на головній діагоналі та вище неї
```c
double multiply(double **Arr, int N) {
    double result = 1.0;

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            result *= Arr[i][j];
        }
    }
    return result;
}
```

Вивід матриці та добутку в термінал
```c
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
```

Звільнення пам'яті
```c
void clear_memory(double **Arr, int N) {
    for (int i = 0; i < N; i++) {
        free(Arr[i]);
    }
    free(Arr);
}
```
