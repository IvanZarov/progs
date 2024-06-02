#include <stdio.h>
#include <stdlib.h>

// Структура элемента списка
struct Node {
    int selected; // Поле для указания выделенного элемента
    int data; // Информационное поле
    struct Node* next; // Ссылка на следующий элемент списка
};

// Функция для создания нового элемента списка
struct Node* createNode(int selected, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    newNode->selected = selected;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Функция для добавления элемента в конец списка
void append(struct Node** head, int selected, int data)
{
    struct Node* newNode = createNode(selected, data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Функция для вывода списка
void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("(%d, %d) -> ", temp->selected, temp->data);
        temp = temp->next;
    }
    printf("NIL\n");
}

int main()
{
    struct Node* S = NULL; // Указатель на голову списка

    int data;
    printf("Введите последовательность целых чисел (введите 0 для завершения "
           "ввода):\n");
    while (1) {
        scanf("%d", &data);
        if (data == 0) {
            break;
        }
        append(&S, 0, data); // Устанавливаем selected в 0
    }

    printf("Список, построенный по введенной последовательности:\n");
    printList(S);

    return 0;
}
