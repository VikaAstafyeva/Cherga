#include <windows.h>
#include <iostream>
#include <conio.h>
#include <tchar.h>
#include <clocale>

using namespace std;

/*Оголошення головної структури*/
struct Queue
{
    int Data;
    struct Queue* next; // Вказівник на наступний елемент черги 
};

Queue* head; // Вказівник на голову черги
Queue* tail; // Вказівник на хвіст черги

int kol = 0; //Кількість елементів

void Creation();                    /*Функція, що створює чергу*/
void Add_last(Queue* temp);         /*Функція, яка додає елемент до кінця*/
void Head_to_tail();                /*Зчитування елемента з "голови" та перенесення в "хвіст"*/
void show_menu();                   /*Виведення інформації для головного меню*/
void menu();                        /*Головне меню*/
void Loading(struct Queue* array);  /*Завантаження даних з черги до масиву*/
void inf();                         /*Інформація про елемент*/
void check_kol();                   /*Перевірка на порожній список*/

/*Функція, що створює чергу*/
void Creation() 
{
    head = (Queue*)malloc(sizeof(Queue));
    head->next = NULL;
    tail = head;
    kol = 0;
}

/*Перевірка на порожній список*/
void check_kol()
{
    if (kol == 0)
    {
        cout << "Список пустий!" << endl;
        system("pause");
        menu();
    }
}

/*Функція, яка додає елемент до кінця*/
void Add_last(Queue* temp)
{
    tail->Data = temp->Data;
    tail->next = (Queue*)malloc(sizeof(Queue));
    tail = tail->next;
    tail->next = NULL;  
    kol++;
}

/*Зчитування елемента з "голови" та перенесення в "хвіст"*/
void Head_to_tail()
{
    Queue* buff = head;
    tail->Data = buff->Data;
    tail->next = (Queue*)malloc(sizeof(Queue));
    tail = tail->next;
    tail->next = NULL;
    buff = head->next;
    free(head);
    head = buff;
}

/*Виведення списку*/
void Tablitsa()
{
    for (int i = 0; i < kol; i++)
    {
        printf("%d) %d\n", i + 1, head->Data);
        Head_to_tail();
    }
}

/*Виведення інформації для головного меню*/
void show_menu()
{
    system("cls");
    cout << "1 - Додати елемент" << endl;
    cout << "2 - Перегляд одного елемента" << endl;
    cout << "3 - Перегляд усіх елементів" << endl;
    cout << "4 - Вихід" << endl;
}
/*Завантаження даних з черги до масиву*/
void Loading(struct Queue* array)
{
    for (int i = 0; i < kol; i++) {
        array[i].Data = head->Data;
        Head_to_tail();
    }
}

/*Ввод елементів з клавіатури*/
void input()
{
    system("cls");
    Queue queue;
    int num;
    cout << "Введіть ID: ";
    cin >> num;
    queue.Data = num;
    Add_last(&queue);
}

/*Інформація про елемент*/
void inf()
{
    int Num;
    system("cls");
    cout << "Введіть номер елемента: ";
    cin >> Num;
    Num = Num - 1;
    Queue* array = new Queue[kol];
    Loading(array);
    cout << "Число: " << array[Num].Data << endl;
}

/*Головне меню*/
void menu()
{
    char ch;
    show_menu();
    while (1)
    {
        ch = _getch();
        if (ch == 49)
        {
            system("cls");
            input();
            system("pause");
            menu();
        }
        if (ch == 50)
        {
            system("cls");
            check_kol();
            inf();
            system("pause");
            menu();
        }
        if (ch == 51)
        {
            system("cls");
            check_kol();
            Tablitsa();
            system("pause");
            menu();
        }
        if (ch == 52)
        {
            exit(0);
        }
    }
}

/*Головна функція*/
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Creation();
    menu();
    return 0;
}