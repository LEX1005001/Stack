#include <iostream>
using namespace std;

struct Node { //Реализация стека с помощью связанного списка
	int Data; //целочисленные данные
	Node* next;//Указатель типа Node на следующий элемент
};

void push(Node** top, int object) { //функция типа void которая принимает указатль на вершину стека и переменную которая будет записываться в ячейку
	Node* q; //Создаем новый указатель q типа структуры Node. По сути это и есть наш новый элемент
	q = new Node(); //выделяем память для нового элемента
	q->Data = object; //Записываем необходимое число в Data элемента

	if (top == NULL) { //Если вершины нет, то есть стек пустой
		*top = q; //вершиной стека будет новый элемент
	}
	else //если стек не пустой
	{
		q->next = *top; //Проводим связь от нового элемента, к вершине. Тоесть кладем книжку на вершину стопки.
		*top = q; //Обозначаем, что вершиной теперь является новый элемент
	}
}

bool isEmpty(struct Node* top) {//функция для проверки, пуст stack или нет
	return top == NULL;
}

int peek(struct Node* top)
{
	// проверка на пустой stack
	if (!isEmpty(top)) {
		return top->Data;
	}
	else {
		printf("The stack is empty \n");
		exit(EXIT_FAILURE);
	}
}


// Метод для удаления вершины стека
int pop(struct Node** top)
{
	struct Node* node;

	// проверка на пустой stack
	if (*top == NULL)
	{
		printf("The stack is empty\n");
		exit(EXIT_FAILURE);
	}

	// принять к сведению данные верхнего узла
	int object = peek(*top);


	node = *top;

	// обновляем верхний указатель, чтобы он указывал на следующий узел
	*top = (*top)->next;


	// освободить выделенную память
	free(node);

	return object;
}

void s_print(Node* top) { //принимает указатель на вершину стека		
	Node* q = top; //устанавливаем q на вершину
	while (q) { //пока q не пустой (while(q) эквивалентно while(q != NULL))
		cout<<q->Data<<" ";//выводим на экран данные ячейки стека
		q = q->next;//после того как вывели передвигаем q на следующий элемент(ячейку)
	}
}

int s_size(Node*top)
{
	int size = 0;
	Node* q = top; //устанавливаем q на вершину
	while (q) { //пока q не пустой (while(q) эквивалентно while(q != NULL))
		size++;//увеличиваем size
		q = q->next;//после того как вывели передвигаем q на следующий элемент(ячейку)
	}
		return size;
}

int main()
{
	struct Node* top = NULL;
	push(&top, 2);
	push(&top, 5);
	cout << isEmpty(top);
	cout << endl;
	s_print(top);
	cout<<s_size(top);
	

}

