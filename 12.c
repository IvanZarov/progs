#include <stdio.h>
#include <float.h>

// Структура Парабола
struct Parabola {
    double a;
    double b;
    double c;
};

// Функция для поиска параболы с наибольшим минимумом
void find_max_min(struct Parabola parabolas[], int n, int* k, struct Parabola* max_min_parabola) {
    *k = 0;
    *max_min_parabola = (struct Parabola){0, 0, 0};
    double max_min = -DBL_MAX;
    
    for (int i = 0; i < n; i++) {
        double a = parabolas[i].a;
        double b = parabolas[i].b;
        
        if (a > 0) {
            double x_min = -b / (2 * a);
            double y_min = a * x_min * x_min + b * x_min + parabolas[i].c;
            
            if (y_min > max_min) {
                max_min = y_min;
                *max_min_parabola = parabolas[i];
                *k = 1;
            } else if (y_min == max_min) {
                (*k)++;
            }
        }
    }
}

int main() {
    struct Parabola parabolas[3] = {{1, 2, 3}, {-1, 0, 2}, {2, -4, 2}};
    int k;
    struct Parabola max_min_parabola;
    
    find_max_min(parabolas, 3, &k, &max_min_parabola);
    
    printf("Количество парабол с минимумом: %d\n", k);
    if (k > 0) {
        printf("Парабола с наибольшим минимумом: y = %.1fx^2 + %.1fx + %.1f\n", max_min_parabola.a, max_min_parabola.b, max_min_parabola.c);
    } else {
        printf("Нет парабол с минимумом\n");
    }
    
    return 0;
}