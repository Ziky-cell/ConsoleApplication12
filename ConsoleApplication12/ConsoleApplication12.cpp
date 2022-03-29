#include <iostream>

using namespace std;
#define SIZE 100

struct Stack
{
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size = SIZE);
    ~Stack();

    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();
};


Stack::Stack(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}


Stack::~Stack() {
    delete[] arr;
}


void Stack::push(int x)
{
    if (isFull())
    {
        exit(EXIT_FAILURE);
    }
    arr[++top] = x;
}

int Stack::pop()
{
    if (isEmpty())
    {
        exit(EXIT_FAILURE);
    }

    return arr[top--];
}

int Stack::peek()
{
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}


int Stack::size() {
    return top + 1;
}


bool Stack::isEmpty() {
    return top == -1;
}


bool Stack::isFull() {
    return top == capacity - 1;
}



int main()
{

    setlocale(LC_ALL, "rus");//поддержка кирилицы

    Stack  numbers, new_elements;//создание три списка типа int, первый с числами
    int size, volue;
    //заполнение стека
    cout << "количество элементов: ";
    cin >> size;// запись введеного значния в переменную
    for (int i = 0; i < size; i++) {
        cout << "введите " << i + 1 << " элемент стека: ";
        cin >> volue;
        numbers.push(volue);//добавление элемента в список
    }

    int check = 0;
    for (int i = 0; i < size; i++) {
        if (i == check) {
            new_elements.push(numbers.peek());
            check += 2;
        }
        numbers.pop();
    }

    cout << "преобразованный стек: ";
    size = new_elements.size();
    for (int i = 0; i < size; i++) {
        cout << new_elements.peek() << " ";
        new_elements.pop();
    }
    cout << endl;



    return 0;
}