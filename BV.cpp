#include "BVHeader.h"

//int BoolVector::Input(char* bv, int n, int m, int i)
//{
//	bv
//}//формирование элемента массива bv
//

void BoolVector::Output(int nomer, int znachsymb)
{
	if (nomer <= m-1);
	{
		if(nomer==0)
		{
			for (int i = 0; i < znachsymb; i++)
			{
				std::cout << (*this).bv[i];
			}
		}
		else
		{
			int pr = m * 8 - n;
			int ii = nomer * 8 - pr;
			for (int i = ii; i < ii + znachsymb; i++)
			{
				std::cout << (*this).bv[i];
			}
		}
	}
}

BoolVector::BoolVector()
{
	n = 1;
	m = 1;
	(*this).bv = new UC(n);
	(*this).bv[0] = '1';
}

BoolVector::BoolVector(int n1)
{
	n = n1;
	if (n % 8 == 0)m = n / 8;
	else m = n / 8 + 1;
	(*this).bv = new UC(n);
	for (int i = 0; i < n; i++)
	{
	    (*this).bv[i] = '0';
	}
}

BoolVector::BoolVector(char* s)
{
	n = strlen(s);
	if (n % 8 == 0)m = n / 8;
	else m = n / 8 + 1;
	bv = new UC(n);
	for (int i = 0; i < n; i++)
	{
		bv[i] = s[i];
	}
}

BoolVector::BoolVector(char* s, int n1)
{
	if (strlen(s) < n1)
	{
		n = strlen(s);
		if (n % 8 == 0)m = n / 8;
		else m = n / 8 + 1;
		bv = new UC(n);
		for (int i = 0; i < n; i++)
		{
			bv[i] = s[i];
		}
	}
	n = 0;
	m = 0;
	bv = new UC(n);
	bv[0] = 0;
}

//BoolVector BoolVector::operator= (BoolVector& VX)
//{
//	if (n == VX.n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			bv[i] = VX.bv[i];
//		}
//		return *this;
//	}
//	else
//	{
//		delete[]bv;
//		bv = new UC(VX.n);
//		n = VX.n;
//		m = VX.m;
//		for (int i = 0; i < n; i++)
//		{
//			bv[i] = VX.bv[i];
//		}
//		return *this;
//	}
//}




void BoolVector::Scan(int n1)
{
	std::cout << "введите " << n1 << " элементов вектора" << std::endl;
	if (n < n1)
	{
		n = n1;
		if (n % 8 == 0)m = n / 8;
		else m = n / 8 + 1;
		delete[]bv;
		(*this).bv = new UC(n);
	}
	else return;
	for (int i = 0; i < n1; i++)
	{
		std::cin >> (*this).bv[i];
	}
}

void  BoolVector::Print()
{
	int pr = m * 8 - n;
	if (pr != 0) 
	{
		for (int i = 0; i < pr; i++) std::cout << '0';
		Output(0, 8 - pr); std::cout << " ";
		for (int i = 1; i < m; i++)
		{
			Output(i, 8); std::cout << " ";
		}
		std::cout << "$";
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			Output(i, 8); std::cout << " ";
		}
	}
}

int BoolVector::Weight()
{
	int weight = 0;
	for (int i = 0; i < n; i++)
	{
		if (bv[i] == '1') weight++;
	}
	return weight;
}




bool BoolVector::operator== (BoolVector& X)
{
	if (n == X.n)
	{
		for (int i = 0; i < n; i++)
		{
			if (bv[i] == X.bv[i]);
			else return false;
		}
		return true;
	}
	else return false;
}

bool BoolVector::operator!= (BoolVector& X)
{
	if (n == X.n)
	{
		for (int i = 0; i < n; i++)
		{
			if (bv[i] == X.bv[i]);
			else return true;
		}
		return false;
	}
	else return true;
}

bool BoolVector::operator< (BoolVector& X)
{
	if (n <= X.n)
	{
		for (int i = 0; i < n; i++)
		{
			if (bv[i] <= X.bv[i]);
			else return false;
		}
		return true;
	}
	else return false;
}

bool BoolVector::operator> (BoolVector& X)
{
	if (n <= X.n)
	{
		for (int i = 0; i < n; i++)
		{
			if (bv[i] <= X.bv[i]);
			else return true;
		}
		return false;
	}
	else return true;
}

UC BoolVector::operator[] (int i)
{
	if (i <= n) return bv[i];
}


//
//BoolVector BoolVector::operator &(BoolVector& X)
//{
//	BoolVector C(n);
//	if (n == X.n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if ((bv[i] == '1') && (X.bv[i] == '1')) C.bv[i] == '1';
//			else C.bv[i] == '0';
//		}
//		return C;
//	}
//	else return C;
//}
//
//BoolVector BoolVector::operator |(BoolVector& X)
//{
//	BoolVector C(n);
//	if (n == X.n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if ((bv[i] == '0') && (X.bv[i] == '0')) C.bv[i] == '0';
//			else C.bv[i] == '1';
//		}
//		return C;
//	}
//	else return C;
//}
//
//BoolVector BoolVector::operator ^(BoolVector& X)
//{
//	BoolVector C(n);
//	if (n == X.n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (bv[i] == X.bv[i]) C.bv[i] == '0';
//			else C.bv[i] == '1';
//		}
//		return C;
//	}
//	else return C;
//}
//
//BoolVector BoolVector::operator ~()
//{
//	BoolVector C(n);
//	for (int i = 0; i < n; i++)
//	{
//		if (bv[i] == '1') C.bv[i] == '0';
//		else C.bv[i] == '1';
//	}
//	return C;
//}
//
//BoolVector BoolVector::operator <<(int bits)
//{
//	BoolVector C(n);
//	if (bits <= n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if ((i + bits) <= (n - 1)) C.bv[i] = bv[i + bits];
//			else C.bv[i] = bv[i - bits];
//		}
//	}
//	else return C;
//}
//
//BoolVector BoolVector::operator >>(int bits)
//{
//	BoolVector C(n);
//	if (bits <= n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if ((i + n - bits) < n) C.bv[i] = bv[i + n - 1 - bits];
//			else C.bv[i] = bv[i - bits];
//		}
//	}
//	else return C;
//}
//
//
//
//BoolVector BoolVector::operator &=(BoolVector& X)
//{
//	if (n == X.n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if ((bv[i] == '1') && (X.bv[i] == '1')) bv[i] == '1';
//			else bv[i] == '0';
//		}
//		return *this;
//	}
//	else return *this;
//}
//
//BoolVector BoolVector::operator |=(BoolVector& X)
//{
//	if (n == X.n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if ((bv[i] == '0') && (X.bv[i] == '0')) bv[i] == '0';
//			else bv[i] == '1';
//		}
//		return *this;
//	}
//	else return *this;
//}
//
//BoolVector BoolVector::operator ^=(BoolVector& X)
//{
//	if (n == X.n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (bv[i] == X.bv[i]) bv[i] == '0';
//			else bv[i] == '1';
//		}
//		return *this;
//	}
//	else return *this;
//}
//
//BoolVector BoolVector::operator <<=(int bits)
//{
//	BoolVector C(*this);
//	;	if (bits <= n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if ((i + bits) <= (n - 1)) C.bv[i] = bv[i + bits];
//			else C.bv[i] = bv[i - bits];
//		}
//		for (int i = 0; i < n; i++)
//		{
//			bv[i] = C.bv[i];
//		}
//	}
//	else return *this;
//}
//
//BoolVector BoolVector::operator >>=(int bits)
//{
//	BoolVector C(*this);
//	;	if (bits <= n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if ((i + n - bits) < n) C.bv[i] = bv[i + n - 1 - bits];
//			else C.bv[i] = bv[i - bits];
//		}
//		for (int i = 0; i < n; i++)
//		{
//			bv[i] = C.bv[i];
//		}
//	}
//	else return *this;
//}
//

//
//BoolVector BoolVector::SetUp1(int key)
//{
//	if (key <= n)
//	{
//		bv[key] = '1';
//	}
//	return *this;
//}
//
//BoolVector BoolVector::SetUp0(int key)
//{
//	if (key <= n)
//	{
//		bv[key] = '0';
//	}
//	return *this;
//}
//
//BoolVector BoolVector::Invert(int key)
//{
//	if (key <= n)
//	{
//		bv[key] = (bv[key] == '0') ? '1' : '0';
//	}
//	return *this;
//}
//
//
//
//
//BoolVector BoolVector::SetUp1(int kol, int p)
//{
//	for (int i = p; i < n; i++)
//	{
//		SetUp1(i);
//	}
//	return *this;
//}
//
//BoolVector BoolVector::SetUp0(int kol, int p)
//{
//	for (int i = p; i < n; i++)
//	{
//		SetUp0(i);
//	}
//	return *this;
//}
//
//BoolVector BoolVector::Invert(int kol, int p)
//{
//	for (int i = p; i < n; i++)
//	{
//		Invert(i);
//	}
//	return *this;
//}

std::ostream& operator << (std::ostream& r, BoolVector& X)
{
	r << "Bool Vector of " << X.n << " elements:" << std::endl;
	int pr = X.m * 8 - X.n;
	if (pr != 0)
	{
		for (int i = 0; i < 8 - pr; i++) r << '0';

		for (int i = 1; i < X.m; i++)
		{
			int ii = X.m * 8;
			for (int i = ii; i < (X.m * 8 + 8); i++)
			{
				r << X.bv[i];
			}
			 r << " ";
		}
	}
	else
	{
		for (int i = 1; i < X.m; i++)
		{
			int ii = X.m * 8;
			for (int i = ii; i < (X.m * 8 + 8); i++)
			{
				r << X.bv[i];
			}
			r << " ";
		}
	}
	return r;
}

std::istream& operator >> (std::istream& r, BoolVector& X)
{
	std::cout << "enter the number of elements: ";
	int m;    std::cin >> m;
	if (X.n != m)
	{
		delete[]X.bv;
		X.bv = new UC[m];  X.n = m; 
		if (X.n % 8 == 0) X.m = X.n / 8;
		else X.m = X.n / 8 + 1;
	}
	std::cout << "enter " << m << " elements of bool vector: ";
	for (int i = 0; i < X.n; i++) r >> X.bv[i];
	return r;

}