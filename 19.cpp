#include <iostream>
#include <map>
#include <string>

using namespace std;

struct HelpEntry {
    string term;
    string description;
};

class HelpText {
private:
    map<string, string> helpMap; // Хранение терминов и их пояснений
public:
    // Метод для добавления нового термина и его пояснения
    void addEntry(const string& term, const string& description)
    {
        helpMap[term] = description;
    }

    // Метод для вывода поясняющего текста для заданного термина
    void displayDescription(const string& term)
    {
        if (helpMap.find(term) != helpMap.end()) {
            cout << "Поясняющий текст для термина '" << term << "': " << endl;
            cout << helpMap[term] << endl;
        } else {
            cout << "Термин '" << term << "' не найден." << endl;
        }
    }

    // Метод для вывода всего текста помощи
    void displayAllEntries()
    {
        cout << "Текст помощи:" << endl;
        for (const auto& entry : helpMap) {
            cout << "Термин: " << entry.first << ", Пояснение: " << entry.second
                 << endl;
        }
    }
};

int main()
{
    HelpText help;

    // Пример начального формирования текста помощи
    help.addEntry("term1", "Это пояснение для термина 1.");
    help.addEntry("term2", "Это пояснение для термина 2.");

    char choice;
    do {
        cout << "Меню:" << endl;
        cout << "1. Добавить новый термин с пояснением" << endl;
        cout << "2. Вывести поясняющий текст для заданного термина" << endl;
        cout << "3. Вывести весь текст помощи" << endl;
        cout << "4. Выйти из программы" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            string term, description;
            cout << "Введите новый термин: ";
            cin >> term;
            cout << "Введите пояснение для термина '" << term << "': ";
            cin.ignore(); // Игнорируем символ новой строки после cin
            getline(cin, description);
            help.addEntry(term, description);
            break;
        }
        case '2': {
            string term;
            cout << "Введите термин, для которого хотите увидеть поясняющий "
                    "текст: ";
            cin >> term;
            help.displayDescription(term);
            break;
        }
        case '3':
            help.displayAllEntries();
            break;
        case '4':
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != '4');

    return 0;
}
