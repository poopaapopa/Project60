#include <iostream>
using namespace std;

template <typename T>
struct Element
{
	T data;
	Element* Next = NULL;
	Element* prev = NULL;
};
template <class T>
class Array
{
	Element<T>* Head;
	Element<T>* Tail;
	Element<T>* prev;
	int count;
	int grow;
public:
	Array()
	{
		Head = Tail = NULL;
		count = 0;
		grow = 1;
	}
	Array(const Array& L)
	{
		Head = Tail = NULL;
		count = 0;
		grow = 1;
		Element<T>* temp = L.Head;
		while (temp != 0)
		{
			AddTail(temp->data);
			temp = temp->Next;
		}
	}
	~Array()
	{
		RemoveAll();
	}
	void Add(int n)
	{
		Element<T>* temp = new Element<T>;
		temp->prev = 0;
		temp->data = n;
		temp->Next = Head;
		if (Head != 0)
			Head->prev = temp;
		if (count == 0)
			Head = Tail = temp;
		else
			Head = temp;
		count++;
		if (GetAt(count) == n)
		{
			int g = grow - 1;
			while (g)
			{
				Element<T>* temp = new Element<T>;
				temp->prev = 0;
				temp->Next = Head;
				if (Head != 0)
					Head->prev = temp;
				if (count == 0)
					Head = Tail = temp;
				else
					Head = temp;
				count++;
				g--;
			}
		}
	}
	void AddHead(int n)
	{
		Element<T>* temp = new Element<T>;
		temp->prev = 0;
		temp->data = n;
		temp->Next = Head;
		if (Head != 0)
			Head->prev = temp;
		if (count == 0)
			Head = Tail = temp;
		else
			Head = temp;
		count++;
	}
	void AddTail(int n)
	{
		Element<T>* temp = new Element<T>;
		temp->prev = 0;
		temp->data = n;
		temp->prev = Tail;
		if (Tail != 0)
			Tail->Next = temp;
		if (count == 0)
			Head = Tail = temp;
		else
			Tail = temp;
		count++;
	}
	void InsertAt(int pos = 0)
	{
		if (pos == 0)
		{
			cout << "Enter the position of the ins item ";
			cin >> pos;
		}
		if (pos<1 or pos>count + 1)
		{
			cout << "Incorrect position!!!";
			return;
		}
		if (pos == count + 1)
		{
			int data;
			cout << "Enter the ins item ";
			cin >> data;
			AddTail(data);
			return;
		}
		else if (pos == 1)
		{
			int data;
			cout << "Enter the ins item ";
			cin >> data;
			AddHead(data);
			return;
		}
		int i = 1;
		Element<T>* Ins = Head;
		while (i < pos)
		{
			Ins = Ins->Next;
			i++;
		}
		Element<T>* PrevIns = Ins->prev;
		Element<T>* temp = new Element<T>;
		cout << "Enter the ins item ";
		cin >> temp->data;
		if (PrevIns != 0 and count != 1)
			PrevIns->Next = temp;
		temp->Next = Ins;
		temp->prev = PrevIns;
		Ins->prev = temp;
		count++;
	}
	int GetSize()
	{
		return count;
	}
	void SetSize(int count = -1,int grow = 1)
	{
		if (count == -1)
		{
			cout << "Enter the size  ";
			cin >> count;
		}
		if (count < 0)
		{
			cout << "Incorrect size!!!";
			return;
		}
		if (grow < 1)
		{
			cout << "Incorrect grow!!!";
			return;
		}
		if (count == 0)
		{
			RemoveAll();
			return;
		}
		if (this->count > count)
		{
			int a = 0;
			while (this->count != count)
			{
				RemoveAt(count - a);
				a++;
			}
		}
		if (this->count < count)
		{
			while (this->count != count)
				AddHead(NULL);
		}
		this->grow = grow;
	}
	bool IsEmpty()
	{
		return !count;
	}
	T GetAt(int pos)
	{
		Element<T>* temp = Head;
		if (pos<1 or pos>count)
		{
			cout << "Incorrect position!!!!!\n";
			return 0;
		}
		int i = 1;
		while (i < pos and temp != 0)
		{
			temp = temp->Next;
			i++;
		}
		if (temp == 0)
			return 0;
		else
			return temp->data;
	}
	Element <T>** GetData()
	{
		return &Tail;
	}
	void SetAt(int index = 0)
	{
		if (index == 0)
		{
			cout << "Enter the position of the ins item ";
			cin >> index;
		}
		if (index < 1 or index > count + 1)
		{
			cout << "Incorrect position!!!";
			return;
		}
		int i = 1;
		Element<T>* Ins = Head;
		while (i < index)
		{
			Ins = Ins->Next;
			i++;
		}
		Element<T>* PrevIns = Ins->prev;
		Element<T>* temp = new Element<T>;
		cout << "Enter the set item ";
		cin >> temp->data;
		if (PrevIns != 0 and count != 1)
			PrevIns->Next = temp;
		temp->Next = Ins->Next;
		temp->prev = Ins;
		Ins->prev = temp;
	}
	void RemoveAt(int pos = 0)
	{
		if (pos == 0)
		{
			cout << "Enter the position of the remove item ";
			cin >> pos;
		}
		if (pos < 1 or pos>count)
		{
			cout << "Incorrect position!!!";
			return;
		}
		int i = 1;
		Element<T>* Del = Head;
		while (i < pos)
		{
			Del = Del->Next;
			i++;
		}
		Element<T>* PrevDel = Del->prev;
		Element<T>* AfterDel = Del->Next;
		if (PrevDel != 0 and count != 1)
			PrevDel->Next = AfterDel;
		if (AfterDel != 0 and count != 1)
			AfterDel->prev = PrevDel;
		if (pos == 1)
			Head = AfterDel;
		if (pos == count)
			Tail = PrevDel;
		delete Del;
		count--;
	}
	void RemoveAll()
	{
		while (count != 0)
			RemoveAt(1);
	}
	void Print()
	{
		Element<T>* temp = Head;
		cout << "(";
		while (temp->Next != 0)
		{
			if (temp->data != -842150451)
		        cout << temp->data << " ";
			temp = temp->Next;
		}
		cout << temp->data << ")\n";
	}
	Array operator+(const Array& L)
	{
		Array Result(*this);
		Element<T>* temp = L.Head;
		while (temp != 0)
		{
			Result.AddTail(temp->data);
			temp = temp->Next;
		}
		return Result;
	}
	Array operator=(const Array& L)
	{
		if (this == &L)
			return *this;
		this->~Array();
		Element<T>* temp = L.Head;
		while (temp != 0)
		{
			AddTail(temp->data);
			temp = temp->Next;
		}
		return *this;
	}
	T operator[](int pos)
	{
		return GetAt(pos);
	}
};

int main()
{
	Array<int> A;
	const int n = 10;
	int a[n] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < n; i++)
		if (i % 2 == 0)
			A.AddHead(a[i]);
		else
			A.AddTail(a[i]);
	cout << "Array size: \n";
	cout << A.GetSize() << "\n";
	cout << "Array A: \n";
	A.Print();
	A.SetSize(5, 1);
	cout << "Array A: \n";
	A.Print();
	if (!A.IsEmpty())
		cout << "Array A is not empty\n";
	cout << "3 elem of array is:\n";
	cout << A.GetAt(3) << "\n";
	A.SetAt();
	cout << "Array A: \n";
	A.Print();
	cout <<"A[3] = "<< A[3] << "\n";
	A.Add(9);
	cout << "Array A + 9: \n";
	A.Print();
	cout << A.GetData() << "\n";
	A.InsertAt();
	cout << "Array A: \n";
	A.Print();
	A.RemoveAt();
	cout << "Array A - A[3]: \n";
	A.Print();
	Array<int> T;
	T = A;
	cout << "Array T = A: \n";
	T.Print();
	cout << "Array A+T: \n";
	Array<int> Sum = A + T;
	Sum.Print();
	return 0;
}