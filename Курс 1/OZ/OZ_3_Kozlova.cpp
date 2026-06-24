#include <iostream>
using namespace std;

struct List {
    int data;
    List* next;
};

//заранее ф-ия удаления всего списка
void DeleteAllDynamicArray(List*& head);

//создание одного узла. указатель возвращается на созданный узел
List* CreateElement (int value) {
    List* element = new List;
    element->data = value; //кладем значение
    element->next = nullptr;
    return element;
};

//проверка, что число целое и положительное
void NumberCheck (int& n) {
    while (!(cin >> n) || n <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\n" << "Ошибка! Попробуйте еще раз!" << "\n" << ">> ";
    }
    cin.ignore(10000, '\n');
};

//проверка что длина списка > 2
void LenCheck (int& n) {
    while (!(cin >> n) || n <= 2) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\n" << "Ошибка! Список должен содержать больше двух элементов!" << "\n" << ">> ";
    }
    cin.ignore(10000, '\n');
};

//создание списка из n случ.эл-тов
List* CreateDynamicArray (List*& head) {
    if (head != nullptr) {
        DeleteAllDynamicArray(head);
    }
    cout << "\nВведите количество элементов для нового динамического списка: ";
    int n;
    LenCheck(n); //проверка n>2
    srand(time(0));
    List* newhead = nullptr;
    List* p;

    for (int i = 0; i < n; i++) {
        List* element = new List;
        element->data = rand() % 101;
        element->next = nullptr;

        if (newhead == nullptr) {
            newhead = element; //первый узел становится головой
        } else {
            p = newhead;
            //идем до последнего узла
            while (p->next != nullptr) {
                p = p->next;
            }
            p->next = element; //прицепляем новый узел в конце
        }
    }
    cout << "\nСписок успешно создан!\n";
    return newhead; //возвращаем голову списка
};

//вывод списка (значение | адрес следующего узла)
void OutDynamicArray (List*& head) {
    cout << "\n";
    List* p = head;
    if (head == nullptr) {
        cout << "Список пуст! Выводить нечего!\n";
        return;
    }
    //идем от головы до конца списка
    while (p != nullptr) {
        cout << p->data << " | " << p->next << "\n";
        p = p->next; //переходим к след.узлу
    }
};

//вставка элеменета на заданную позицию
void InsertInDynamicArray (List*& head) {
    cout << "\nВведите номер позиции, на которую нужно вставить элемент: ";
    int pos;
    NumberCheck(pos);
    List* current = head;
    List* p; //указатель на узел перед позицией вставки
    //доходим до узла с номером pos
    for (int i = 0; i < pos - 1; i++) {
        if (current == nullptr) {
            cout << "\nОшибка! Этой позиции нет в списке!\n";
            return;
        }
        p = current; //запоминаем предыдущий
        current = current->next; //переходим к след.
    }

    cout << "Введите значение которое нужно вставить: ";
    int value;
    NumberCheck(value);
    List* element = CreateElement(value);

    if (pos == 1) {
        //вставка в начало
        element->next = head;
        head = element;
        cout << "\nЭлемент успешно добавлен!\n";
        return;
    }
    //вставка в середину или конец
    if (p != nullptr) {
        element->next = current;
        p->next = element;
        cout << "\nЭлемент успешно добавлен!\n";
        return;
    }
};

//вставка после заданного значения
void InsertAfterExactValue (List*& head) {
    if (head != nullptr) {
        cout << "\nВведите значение узла, после которого нужно вставить элемент: ";
        int need_value;
        NumberCheck(need_value);
        List* current = head;
        List* p; //указатель на найденный узел
        
        bool flag = true;
        //ищем узел с зад.знач
        while (flag) {
            p = current;
            current = current->next;
            if (current == nullptr && p->data != need_value) {
                cout << "\nОшибка! Элемента с таким значением нет в списке!\n";
                return;
            }
            if (p->data == need_value) {
                flag = false; //если нашли-выходим из цикла
            }
        }
        cout << "Введите значение которое нужно вставить: ";
        int insert_value;
        NumberCheck(insert_value);
        List* element = CreateElement(insert_value);
        if (p != nullptr) {
            element->next = current; //новый узел -> остаток списка
            p->next = element; //найденный узел -> новый узел
            cout << "\nЭлемент успешно добавлен!\n";
        }
        return;
    } else {
        cout << "\nЭлементов в списке нет! Невозможно ничего вставить!\n";
        return;
    }
};

//удаление элемента по номеру
void DeleteElementForNumberDynamicArray (List*& head) {
    if (head != nullptr) {
        List* current = head;
        List* p; //указатель на узел перед удаляемым
        cout << "Введите номер элемента, который хотите удалить: ";
        int pos;
        NumberCheck(pos);
        if (pos == 1) {
            //удаление головы
            p = current;
            p = p->next;
            head = p; //голова сдвигается на 2 эл-т
            delete current; 
            cout << "\nЭлемент успешно удален!\n";
            return;
        }
        //доходим до узла перед удаляемым
        for (int i = 0; i < pos - 1; i++) {
            p = current;
            current = current->next;
            if (current == nullptr) {
                cout << "\nТакого элемента не существует!\n";
                return;
            }
        }
        //перецепляем указатели и удаляем
        p->next = current->next;
        delete current;
        cout << "\nЭлемент успешно удален!\n";
        return;
    } else {
        cout << "\nУдалять нечего!\n";
        return;
    }
};

//удаление по значению
void DeleteElementForDataDynamicArray (List*& head) {
    if (head != nullptr) {
        cout << "Введите значение элемента, который хотите удалить: ";
        int value;
        NumberCheck(value);
        List* current = head;
        List* p; //указатель на узел перед удаляемым
        // Если удаляемое значение в голове списка
        if (current->data == value) {
            p = current;
            p = p->next;
            head = p; //сдвигаем голову
            delete current;
            cout << "\nЭлемент успешно удален!\n";
            return;
        }
        // ищем узел с заданным значением
        while (current->data != value) {
            p = current;
            current = current->next;
            if ((current == nullptr) && (p->data != value)) {
                cout << "\nЭлемента с таким значением нет!\n";
                return;
            }
        }
        // перецепляем указатели и удаляем
        p->next = current->next;
        delete current;
        cout << "\nЭлемент успешно удален!\n";
        return;
    } else {
        cout << "\nЭлементов в списке нет! Невозможно ничего удалить!\n";
        return;
    }
};

//удаление всего списка и очистка памяти
void DeleteAllDynamicArray (List*& head) {
    if (head != nullptr) {
        List* p = head;
        //проходим по всем узлам и удаляем
        while (p != nullptr) {
            List* next = p->next; //запоминаем след до удаления
            delete p;
            p = next; //к следующему
        }

        head = nullptr; //обнуляем голову

        cout << "\nСписок успешно удален!\n";

    } else {
        cout << "\nУдалять нечего!\n";
        return;
    }
};

//вывод меню
bool Menu (List*& head) {
    int choice;
    cout << "\nМеню:\n" <<
    "\"1\" - создание списка\n" <<
    "\"2\" - вывод списка на экран\n" <<
    "\"3\" - вставка на определенное место\n" <<
    "\"4\" - вставка после узла с определенным значением\n" <<
    "\"5\" - удаление узла по номеру\n" <<
    "\"6\" - удаление узла с заданным значением\n" <<
    "\"7\" - удаление всего списка\n" <<
    "\"8\" - выход" <<
    "\n>> ";
    NumberCheck(choice);
    if (choice == 1) {
        head = CreateDynamicArray(head);
        return true;
    } else if (choice == 2) {
        OutDynamicArray(head);
        return true;
    } else if (choice == 3) {
        InsertInDynamicArray(head);
        return true;
    } else if (choice == 4) {
        InsertAfterExactValue(head);
        return true;
    } else if (choice == 5) {
        DeleteElementForNumberDynamicArray(head);
        return true;
    } else if (choice == 6) {
        DeleteElementForDataDynamicArray(head);
        return true;
    } else if (choice == 7) {
        DeleteAllDynamicArray(head);
        return true;
    } else if (choice == 8) {
        return false; //выход из программы
    } else {
        cout << "\nНеизвестная команда! Попробуйте еще раз!\n";
        return true;
    }
};

int main () {
    List* head = nullptr;
    while (Menu(head)) {} //показываем меню, пока пользователь не выйдет
}