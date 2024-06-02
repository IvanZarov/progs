#include <algorithm> // Для сортировки
#include <iostream>
#include <vector>

using namespace std;

class MyClass {
private:
    int attribute1;
    char attribute2;

public:
    MyClass() : attribute1(0), attribute2(' ')
    {
    }

    MyClass(int a, char b) : attribute1(a), attribute2(b)
    {
    }

    void display() const
    {
        cout << "Attribute1: " << attribute1 << ", Attribute2: " << attribute2
             << endl;
    }

    int getAttribute1() const
    {
        return attribute1;
    }

    void setAttribute1(int a)
    {
        attribute1 = a;
    }
};

bool compareByAttribute1(const MyClass& a, const MyClass& b)
{
    return a.getAttribute1() < b.getAttribute1();
}

int main()
{
    int size;
    cout << "Введите размер исходного вектора: ";
    cin >> size;

    vector<MyClass> originalVector(size);

    for (int i = 0; i < size; ++i) {
        int a;
        char b;
        cout << "Введите значение для объекта " << i + 1 << ": ";
        cin >> a >> b;
        originalVector[i] = MyClass(a, b);
    }

    vector<MyClass> newVector;
    for (int i = 0; i < size; i += 2) {
        newVector.push_back(originalVector[i]);
    }

    if (!newVector.empty()) {
        sort(newVector.begin(), newVector.end(), compareByAttribute1);

        cout << "Отсортированный новый вектор:" << endl;
        for (const auto& obj : newVector) {
            obj.display();
        }
    } else {
        cout << "Новый вектор пуст!" << endl;
    }

    return 0;
}
