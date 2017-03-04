#pragma once
class Stack
{
public:
	typedef float value_type; // Elements type

	Stack();//конструктор
	~Stack();//деструктор
	bool push(value_type value);//закидывает элемент в стек и переносит голову стека на 1 вверх
	value_type pop();//возвращает верхний элемент и сносит голову стека на 1 вниз
	size_t capacity();//геттер
	void dump(); //выводит дамп
	bool ok();//проверяет на переполнение
	value_type GetLast();// возвращает верхний элемент без изменения головы стека

private:
	static const size_t CAPACITY = 10; 
	value_type data[CAPACITY];
	size_t	size;
};
