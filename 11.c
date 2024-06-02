#include <math.h>
#include <stdio.h>

double series_sum(double x, double b, double epsilon, int n, double sum)
{
    double term = pow(x, n) * sin(b + n * M_PI / 2)
            / tgamma(n + 1); // Вычисляем очередной член ряда
    sum += term;             // Добавляем его к сумме
    if (fabs(term) >= epsilon) { // Если абсолютное значение члена ряда больше
                                 // или равно epsilon, продолжаем рекурсию
        return series_sum(x, b, epsilon, n + 1, sum);
    } else { // Иначе возвращаем текущую сумму
        return sum;
    }
}

int main()
{
    double x, b, epsilon;
    printf("Введите значение x (0 < x < 1): ");
    scanf("%lf", &x);
    printf("Введите значение b: ");
    scanf("%lf", &b);
    printf("Введите значение точности epsilon: ");
    scanf("%lf", &epsilon);

    double library_result
            = sin(x + b); // Вычисляем значение с помощью библиотечной функции
    double series_result
            = series_sum(x, b, epsilon, 0, 0); // Вычисляем значение суммы ряда

    printf("Значение суммы ряда: %lf\n", series_result);
    printf("Число членов ряда, вошедших в сумму: %d\n",
           (int)ceil(log(epsilon) / log(x))); // Оцениваем число членов ряда по
                                              // формуле log(epsilon) / log(x)
    printf("Значение по библиотечной функции: %lf\n", library_result);

    return 0;
}
