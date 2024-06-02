#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для хранения информации о человеке
struct Person {
    char name[50];
    char phone[20];
    int birthday[3]; // День рождения: [день, месяц, год]
};

// Функция для сравнения двух записей (для qsort)
int compare(const void* a, const void* b)
{
    return strcmp(((struct Person*)a)->name, ((struct Person*)b)->name);
}

// Функция для чтения записи из файла
void readRecord(FILE* file, struct Person* person)
{
    fread(person, sizeof(struct Person), 1, file);
}

// Функция для записи записи в файл
void writeRecord(FILE* file, struct Person* person)
{
    fwrite(person, sizeof(struct Person), 1, file);
}

// Функция для добавления записи в файл
void addRecord(FILE* file)
{
    struct Person person;

    // Ввод ФИО
    printf("Введите ФИО: ");
    scanf("%s", person.name);

    // Ввод номера телефона
    printf("Введите номер телефона: ");
    scanf("%s", person.phone);

    // Ввод даты рождения
    printf("Введите день рождения (день месяц год): ");
    scanf("%d %d %d",
          &person.birthday[0],
          &person.birthday[1],
          &person.birthday[2]);

    // Очистка буфера ввода
    while (getchar() != '\n')
        ;

    // Запись данных в файл
    fwrite(&person, sizeof(struct Person), 1, file);
}

int main()
{
    FILE *inputFile, *outputFile;
    struct Person person;
    char choice;

    // Открытие файла для записи
    inputFile = fopen("F1.dat", "wb");
    if (inputFile == NULL) {
        printf("Ошибка при открытии файла F1.dat!\n");
        exit(1);
    }

    // Добавление записей в файл F1.dat
    do {
        addRecord(inputFile);
        printf("Желаете добавить еще одну запись? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    fclose(inputFile);

    // Открытие файла для чтения
    inputFile = fopen("F1.dat", "rb");
    if (inputFile == NULL) {
        printf("Ошибка при открытии файла F1.dat!\n");
        exit(1);
    }

    // Получение количества записей в файле
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    rewind(inputFile);
    int numRecords = fileSize / sizeof(struct Person);

    // Выделение памяти под все записи
    struct Person* records
            = (struct Person*)malloc(numRecords * sizeof(struct Person));
    if (records == NULL) {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }

    // Считывание всех записей из файла
    for (int i = 0; i < numRecords; ++i) {
        readRecord(inputFile, &records[i]);
    }

    fclose(inputFile);

    // Сортировка записей по ФИО
    qsort(records, numRecords, sizeof(struct Person), compare);

    // Открытие файла для записи
    outputFile = fopen("F2.dat", "wb");
    if (outputFile == NULL) {
        printf("Ошибка при открытии файла F2.dat!\n");
        exit(1);
    }

    // Запись отсортированных записей в файл
    for (int i = 0; i < numRecords; ++i) {
        writeRecord(outputFile, &records[i]);
    }

    fclose(outputFile);

    free(records);

    printf("Файл успешно обработан и записан в файл F2.dat!\n");

    return 0;
}
