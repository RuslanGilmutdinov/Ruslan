#pragma once
class Stack
{
public:
	typedef float value_type; // Elements type

	Stack();//�����������
	~Stack();//����������
	bool push(value_type value);//���������� ������� � ���� � ��������� ������ ����� �� 1 �����
	value_type pop();//���������� ������� ������� � ������ ������ ����� �� 1 ����
	size_t capacity();//������
	void dump(); //������� ����
	bool ok();//��������� �� ������������
	value_type GetLast();// ���������� ������� ������� ��� ��������� ������ �����

private:
	static const size_t CAPACITY = 10; 
	value_type data[CAPACITY];
	size_t	size;
};
