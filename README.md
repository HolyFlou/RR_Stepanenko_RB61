Завдання № 1
<img width="210" height="95" alt="изображение" src="https://github.com/user-attachments/assets/6bd8a95c-0fd4-4aa6-b7cb-7197a9b8730b" />
[Файл task1.c](https://github.com/HolyFlou/RR_Stepanenko_RB61/blob/main/task1.c)
В цій частині коду ми оголошуємо змінні та просимо користувача ввести N(кількість ітерацій в циклі)
```
    int N;
    double S = 0.0;

    printf("Введіть N: ");
    scanf("%d", &N);
```

В цій частині коду ми виконуємо суму за формулою що дана в завданні
```
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
```
        double temp = 1.0;
        int power = n-1;
        while (power != 0) {
            temp *= -1.0;
            power--;
        }
```

В кінці просто виводу значення те що вийшло після суми
```
  printf("S = %f", S);
```
