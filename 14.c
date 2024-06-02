#include <stdio.h>

int main() {
    FILE *file;
    char line[100];
    int start_end_count = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == 'Я' && line[strlen(line) - 2] == 'Я') {
            start_end_count++;
        }
    }

    fclose(file);

    printf("Количество строк, начинающихся и заканчивающихся буквой 'Я': %d\n", start_end_count);

    return 0;
}
