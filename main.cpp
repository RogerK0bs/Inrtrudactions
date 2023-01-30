#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;
//		Класс - это тип данных
//		Структура - это тип данных
//class Point // Создавая структуру  или класс мы создаем новый тип данных
//			 // Так же их называют пользовательскими или составными типами данных
//{
//private:
//	double x1;
//	double x2;
//	double y1;
//	double y2;
//public:
//	double GetX1() // Get-метод x1
//	{
//		return x1;
//	}
//	double GetX2() // Get-метод x2
//	{
//		return x2;
//	}
//	double GetY1() // Get-метод y1
//	{
//		return y1;
//	}
//	double GetY2() // Get-метод y2
//	{
//		return y2;
//	}
//	void SetX1(double number)// Set-метод x1
//	{
//		x1 = number;
//	}
//	void SetX2(double number)// Set-метод x2
//	{
//		x2 = number;
//	}
//	void SetY1(double number)// Set-метод y1
//	{
//		y1 = number;
//	}
//	void SetY2(double number)// Set-метод y2
//	{
//		y2 = number;
//	}
//	double distance_lenght(double valueX1, double valueX2, double valueY1, double valueY2) // Можно было бы напрямую брать переменные с класса.
//	{
//		return ((valueY2 - valueY1)* (valueY2 - valueY1)) + ((valueX2 - valueX1)*(valueX2 - valueX1));
//	}
//	double distance_X()//(double x1, double x2)
//	{
//		double n1 = x1;
//		double n2 = x2;
//		if (n1 < 0)n1 *= -1;
//		if (n2 < 0)n2 *= -1;
//		if (n2 < n1)return n1 - n2;
//		return n2 - n1;
//	}
//	double distance_Y()//(double y1, double y2)
//	{
//		double n1 = y1;
//		double n2 = y2;
//		if (n1 < 0)n1 *= -1;
//		if (n2 < 0)n2 *= -1;
//		if (n2 < n1)return n1 - n2;
//		return n2 - n1;
//	}
//	/*void Print_point_X1Y1()
//	{
//		cout << "\nX1= " << x1 << "\tY1= " << y1<<endl;
//	}
//	void Print_point_X2Y2()
//	{
//		cout << "\nX2= " << x2 << "\tY2= " << y2 << endl;
//	}*/
//};
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	// Constructors:
	//Point2()
	//{
	//	x = y = 0;
	//	// RAII - Resource Aqulisation - Is Initialisation
	//	//		(выделение ресурсов = значит инициализация)
	//	cout << "DefConstructor:\t" << this << endl;
	//}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgCons:\t" << this << endl;
	}
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	// Operators:
	Point& operator=(const Point& other) // По ссылке
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}
	Point& operator()(double x, double y)
	{
		set_x(x);
		set_y(y);
		return *this;
	}
	
	
	//Метод:
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance+y_distance * y_distance);
		return distance;
	}
	void print()const
	{	
		cout << "X = "<< x <<"\tY = " <<y<< endl;
	}
};
double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
}
Point operator+(const Point& Left, const Point& Right)
{
	Point res;
	res.set_x(Left.get_x() + Right.get_x());
	res.set_y(Left.get_y() + Right.get_y());

	return res;
}
//#define DISTACE_CHECK
//#define СONSTRUCTOR_CHECK
// Comparison operators:
bool operator==(const Point& left, const Point& right)
{

		return (left.get_x() == right.get_x() && left.get_y() == right.get_y());
}
bool operator!=(const Point& left, const Point& right)
{
	return !(left == right);
}
std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	return os << "X= " << obj.get_x() << "\tY= " << obj.get_y();
}
std::istream& operator>>(std::istream& is, Point& obj)
{
	double x, y;
	is >> x >> y;
	obj(x, y);
	return is;

}

void main()
{
	setlocale(LC_ALL, "");
	//	cout <<"Hellow OOP" << endl;
	//	int a;	 // Объявление переменной 'a' типа 'int'
	//	Point A; // Объявление переменной 'A' типа 'Point'
	////тип данных // Объявление объекта 'A' структуры 'Point' 
	//			 // Объявление экземпляра 'A' структуры 'Point'
	//			 // Объекты часто называют экземплярами класса или структуры.
	//	A.x = 2;
	//	A.y = 3;
	//	cout << A.x << "\t" << A.y << endl; // обращение по имени объекта '.'
	//	Point* pA = &A;
	//	cout << pA->x << "\t" << pA->y << endl; // обращение по адресу объекта '->'
		//Point a, b;
		/*Point a;
		double n=0;
		for (size_t i = 0; i < 4; i++)
		{
			system("cls");
			switch (i)
			{
			case 0:
				cout << "Введите X1= "; cin >> n;
				a.SetX1(n);
				break;
			case 1:
				cout << "Введите Y1= "; cin >> n;
				a.SetY1(n);
				break;
			case 2:
				cout << "Введите X2= "; cin >> n;
				a.SetX2(n);
				break;
			case 3:
				cout << "Введите Y2= "; cin >> n;
				a.SetY2(n);
				break;
			}
			system("cls");
		}
		cout<<"\nX1= " << a.GetX1()<<"\tY1= "<<a.GetY1() << endl;
		cout<<"\nX2= " << a.GetX2()<<"\tY2= "<<a.GetY2() << endl;
		cout <<"Расстояние от точки до точки = "<< sqrt(a.distance_lenght(a.GetX1(), a.GetX2(), a.GetY1(), a.GetY2())) << endl;
		cout << "\nРасстояние от X1 до X2 =" << a.distance_X() << endl;
		cout << "\nРасстояние от Y1 до Y2 =" << a.distance_Y() << endl;*/
		//#ifdef DISTANCE_CHECK
			//Point a;
			//a.set_x(2);
			//a.set_y(3);
			//cout << a.get_x() << "\t" << a.get_y() << endl;
			//Point b;
			//b.set_x(7);
			//b.set_y(8);
			//cout << b.get_x() << "\t" << b.get_y() << endl;
			//cout << "расстояние от точки a до точки b: " << a.distance(b) << endl;
			//cout << "расстояние от точки b до точки a: " << b.distance(a) << endl;
			//cout << "расстояние между b до точки a: " << distance(a, b) << endl;
			//cout << "расстояние между a до точки b: " << distance(b, a) << endl;
			//cout << "расстояние между a до точки a: " << distance(a, a) << endl;
			//cout << "расстояние между b до точки b: " << distance(b, b) << endl;
			//Point A(2, 3);
			//A.print();
			//Point B = A; // CopyConstructor - только в объектах или при их создании.
			//B.print();
			//Point C; // Конструктор по умолчанию
			//C = B; // Assignment operator - операто присваинвия.
			//C.print();
		//#endif // DISTANCE_CHECK
#ifdef СONSTRUCTOR_CHECK
	for (size_t i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;

}
Point2 G;
//cout << A.get_x() << "\t" << A.get_y() << endl;
G.print();
Point2 B(2, 3);
B.print();
//Point2 C ;
//C.print();
Point2 D = B;
D.print();
#endif
//cout << "Begin" << endl;
//Point (2, 3);
//cout << "End" << endl;
Point A(2, 3);
Point B(4, 5);
Point C = A + B + A + B;
C.print();
C++;
C.print();
cout << (A == B) << endl;
cout << (A != B) << endl;
system("cls");
A.print();
A.set_x(12);
A.set_y(13);
A(2, 3);
A.print();
double a, b;
cin >> a >> b;
A(a, b);
cout << endl;
cout << A << endl;
cout << "Введите координаты точек: "; cin >> A;
cout << A << endl;
}
