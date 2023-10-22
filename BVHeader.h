#pragma once
#include <iostream>

typedef unsigned char UC;
class BoolVector
{
	UC* bv;
	int n, m;
	// n -длина булева вектора,
	// m - количество элементов (байтов) в массиве bv
	// св€зь n и m: m=n/8 если n%8=0;
	// m=n/8+1, если n%8!=0
	int Input(char*, int, int, int); //формирование элемента массива bv
	void Output(int, int); //вывод элемента массива;
	//задаютс€:
	// номер элемента,
	//количество выводимых (значащих) битов в эл-те
public:

	//конструктры, деструктор
	BoolVector(); //n=0, m=1, bv[0]=0
	BoolVector(int n1);

	//n1 - длина булева вектора (в битах)
	BoolVector(char* s); //s Ц строка символов С0Т и С1Т
	BoolVector(char* s, int n1); //n1!=strlen(s)
	BoolVector(BoolVector&); //bv полностью идентичен вектору-аргум.
	~BoolVector() { delete[]bv; }

	//ввод с клавиатуры, вывод, вес
	void Scan(int); // указываетс€ размер вводимого вектора
	void Print(); // используетс€ функци€ Output
	int Weight();

	//присвоение,сравнение, нахождение i-й компоненты (бита)
	BoolVector operator= (BoolVector&); //”честь длины векторов!
	bool operator== (BoolVector&);
	bool operator!= (BoolVector&);
	bool operator< (BoolVector&); //x<y если x[i]<=y[i]
	bool operator> (BoolVector&);
	UC operator[] (int i); //возврат "0" или "1". Ќумераци€ битов слева направо !

	//побитовые операции с построением нового вектора
	BoolVector operator &(BoolVector& x);
	BoolVector operator |(BoolVector& x);
	BoolVector operator ^(BoolVector& x);
	BoolVector operator ~();
	BoolVector operator <<(int);
	BoolVector operator >>(int);

	//побитовые операции с изменением вектора this
	BoolVector operator &=(BoolVector& x);
	BoolVector operator |=(BoolVector& x);
	BoolVector operator ^=(BoolVector& x);
	BoolVector operator <<=(int);
	BoolVector operator >>=(int);

	//»зменение одной компоненты вектора
	BoolVector SetUp1(int);
	BoolVector SetUp0(int);
	BoolVector Invert(int);

	//»зменение группы компонентов вектора
	BoolVector SetUp1(int kol, int p); //установить в 1 kol компонент,
	BoolVector SetUp0(int kol, int p); //сбросить (обнулить) kol //компонент,
	BoolVector Invert(int kol, int p); //инвертировать kol компонент,

	friend std::ostream& operator << (std::ostream& r, BoolVector& x);
	friend std::istream& operator >> (std::istream& r, BoolVector& x);
};