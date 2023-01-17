#include <iostream>
#include <Windows.h>
using namespace std;
//		����� - ��� ��� ������
//		��������� - ��� ��� ������
class Point // �������� ���������  ��� ����� �� ������� ����� ��� ������
			 // ��� �� �� �������� ����������������� ��� ���������� ������ ������
{
private:
	double x1;
	double x2;
	double y1;
	double y2;
public:
	double GetX1() // Get-����� x1
	{
		return x1;
	}
	double GetX2() // Get-����� x2
	{
		return x2;
	}
	double GetY1() // Get-����� y1
	{
		return y1;
	}
	double GetY2() // Get-����� y2
	{
		return y2;
	}
	void SetX1(double number)// Set-����� x1
	{
		x1 = number;
	}
	void SetX2(double number)// Set-����� x2
	{
		x2 = number;
	}
	void SetY1(double number)// Set-����� y1
	{
		y1 = number;
	}
	void SetY2(double number)// Set-����� y2
	{
		y2 = number;
	}
	double distance_lenght(double valueX1, double valueX2, double valueY1, double valueY2)
	{
		return (valueY2 - valueY1) + (valueX2 - valueX1);
	}
	double distance_X()//(double x1, double x2)
	{
		double n1 = x1;
		double n2 = x2;
		if (n1 < 0)n1 *= -1;
		if (n2 < 0)n2 *= -1;
		if (n2 < n1)return n1 - n2;
		return n2 - n1;
	}
	double distance_Y()//(double y1, double y2)
	{
		double n1 = y1;
		double n2 = y2;
		if (n1 < 0)n1 *= -1;
		if (n2 < 0)n2 *= -1;
		if (n2 < n1)return n1 - n2;
		return n2 - n1;
	}
	/*void Print_point_X1Y1()
	{
		cout << "\nX1= " << x1 << "\tY1= " << y1<<endl;
	}
	void Print_point_X2Y2()
	{
		cout << "\nX2= " << x2 << "\tY2= " << y2 << endl;
	}*/
};



void main()
{
	setlocale(LC_ALL, "");
//	cout <<"Hellow OOP" << endl;
//	int a;	 // ���������� ���������� 'a' ���� 'int'
//	Point A; // ���������� ���������� 'A' ���� 'Point'
////��� ������ // ���������� ������� 'A' ��������� 'Point' 
//			 // ���������� ���������� 'A' ��������� 'Point'
//			 // ������� ����� �������� ������������ ������ ��� ���������.
//	A.x = 2;
//	A.y = 3;
//	cout << A.x << "\t" << A.y << endl; // ��������� �� ����� ������� '.'
//	Point* pA = &A;
//	cout << pA->x << "\t" << pA->y << endl; // ��������� �� ������ ������� '->'
	//Point a, b;
	Point a;
	double n=0;
	for (size_t i = 0; i < 4; i++)
	{
		system("cls");
		switch (i)
		{
		case 0:
			cout << "������� X1= "; cin >> n;
			a.SetX1(n);
			break;
		case 1:
			cout << "������� Y1= "; cin >> n;
			a.SetY1(n);
			break;
		case 2:
			cout << "������� X2= "; cin >> n;
			a.SetX2(n);
			break;
		case 3:
			cout << "������� Y2= "; cin >> n;
			a.SetY2(n);
			break;
		}
		system("cls");
	}
		
	cout<<"\nX1= " << a.GetX1()<<"\tY1= "<<a.GetY1() << endl;
	cout<<"\nX2= " << a.GetX2()<<"\tY2= "<<a.GetY2() << endl;
	cout <<"���������� �� ����� �� ����� = "<< a.distance_lenght(a.GetX1(), a.GetX2(), a.GetY1(), a.GetY2()) << endl;
	cout << "\n���������� �� X1 �� X2 =" << a.distance_X() << endl;
	cout << "\n���������� �� Y1 �� Y2 =" << a.distance_Y() << endl;
}
