#include<iostream>
#include<Windows.h>
using namespace std;

class Car
{
	char* model;
	char* country;
	char* color;
	int year;
	double price;
public:
	Car()
	{
		model = nullptr;
		country = nullptr;
		color = nullptr;
		year = 0;
		price = 0;
	}
	Car(const char* Model, const char* Country, const char* Color, int Year, double Price)
	{
		model = new char[strlen(Model) + 1];
		strcpy_s(model, strlen(Model) + 1, Model);
		country = new char[strlen(Country) + 1];
		strcpy_s(country, strlen(Country) + 1, Country);
		color = new char[strlen(Color) + 1];
		strcpy_s(color, strlen(Color) + 1, Color);
		year = Year;
		price = Price;
	}
	Car(const Car& obj) //Copy constructor
	{
		model = new char[strlen(obj.model) + 1];
		strcpy_s(model, strlen(obj.model) + 1, obj.model);
		country = new char[strlen(obj.country) + 1];
		strcpy_s(country, strlen(obj.country) + 1, obj.country);
		color = new char[strlen(obj.color) + 1];
		strcpy_s(color, strlen(obj.color) + 1, obj.color);
		year = obj.year;
		price = obj.price;
		cout << "Constructor\n" << endl;;
	}
	void Output()
	{
		cout << "Model: " << model << endl
			<< "Country: " << country << endl
			<< "Color: " << color << endl
			<< "Year: " << year << endl
			<< "Price: " << price << endl << endl;
	}
	~Car()
	{
		cout << "Destruct\n";
		delete[] model;
		delete[] country;
		delete[] color;
	}
};

int main()
{
	Car a("BMW", "Germany", "black", 2017, 50000);
	a.Output();

	Car b = a;
	b.Output();

	system("pause");

}