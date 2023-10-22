#pragma once
#include <iostream>

typedef unsigned char UC;
class BoolVector
{
	UC* bv;
	int n, m;
	// n -����� ������ �������,
	// m - ���������� ��������� (������) � ������� bv
	// ����� n � m: m=n/8 ���� n%8=0;
	// m=n/8+1, ���� n%8!=0
	int Input(char*, int, int, int); //������������ �������� ������� bv
	void Output(int, int); //����� �������� �������;
	//��������:
	// ����� ��������,
	//���������� ��������� (��������) ����� � ��-��
public:

	//�����������, ����������
	BoolVector(); //n=0, m=1, bv[0]=0
	BoolVector(int n1);

	//n1 - ����� ������ ������� (� �����)
	BoolVector(char* s); //s � ������ �������� �0� � �1�
	BoolVector(char* s, int n1); //n1!=strlen(s)
	BoolVector(BoolVector&); //bv ��������� ��������� �������-�����.
	~BoolVector() { delete[]bv; }

	//���� � ����������, �����, ���
	void Scan(int); // ����������� ������ ��������� �������
	void Print(); // ������������ ������� Output
	int Weight();

	//����������,���������, ���������� i-� ���������� (����)
	BoolVector operator= (BoolVector&); //������ ����� ��������!
	bool operator== (BoolVector&);
	bool operator!= (BoolVector&);
	bool operator< (BoolVector&); //x<y ���� x[i]<=y[i]
	bool operator> (BoolVector&);
	UC operator[] (int i); //������� "0" ��� "1". ��������� ����� ����� ������� !

	//��������� �������� � ����������� ������ �������
	BoolVector operator &(BoolVector& x);
	BoolVector operator |(BoolVector& x);
	BoolVector operator ^(BoolVector& x);
	BoolVector operator ~();
	BoolVector operator <<(int);
	BoolVector operator >>(int);

	//��������� �������� � ���������� ������� this
	BoolVector operator &=(BoolVector& x);
	BoolVector operator |=(BoolVector& x);
	BoolVector operator ^=(BoolVector& x);
	BoolVector operator <<=(int);
	BoolVector operator >>=(int);

	//��������� ����� ���������� �������
	BoolVector SetUp1(int);
	BoolVector SetUp0(int);
	BoolVector Invert(int);

	//��������� ������ ����������� �������
	BoolVector SetUp1(int kol, int p); //���������� � 1 kol ���������,
	BoolVector SetUp0(int kol, int p); //�������� (��������) kol //���������,
	BoolVector Invert(int kol, int p); //������������� kol ���������,

	friend std::ostream& operator << (std::ostream& r, BoolVector& x);
	friend std::istream& operator >> (std::istream& r, BoolVector& x);
};