#include <iostream>
#include <string>

#include <windows.h>
using namespace std;

/*
Фабричный метод (Factory Method) — порождающий шаблон проектирования, предоставляющий подклассам интерфейс для создания экземпляров некоторого класса.
В момент создания наследники могут определить, какой класс инстанциировать. Иными словами, фабрика делегирует создание объектов наследникам родительского класса.
Это позволяет использовать в коде программы не специфические классы, а манипулировать абстрактными объектами на более высоком уровне.
Фабричный метод  определяет интерфейс для создания объекта, но оставляет подклассам решение о том, какой класс инстанциировать.

Применимость:
-	классу заранее неизвестно, объекты каких подклассов ему нужно создавать.
-	класс спроектирован так, чтобы объекты, которые он создаёт, специфицировались подклассами.
-	класс делегирует свои обязанности одному из нескольких вспомогательных подклассов, и планируется локализовать знание о том, какой класс принимает эти обязанности на себя.

Достоинство:
Фабричные методы избавляют проектировщика от необходимости встраивать в код зависящие от приложения классы. Код имеет дело только с интерфейсом
класса Product, поэтому он может работать с любыми определенными пользователями классами конкретных продуктов.
Недостаток:
Потенциальный недостаток фабричного метода состоит в том, что клиентам, возможно, придется создавать подкласс класса Creator для создания лишь одного объекта ConcreteProduct.
*/

//продукт (PC) определяет интерфейс объектов, создаваемых фабричным методом

class Figure abstract
{
protected:
	int  array[4][4] = {};
	int color;
	string name = "";
	
public:
	virtual ~Figure() {}

	virtual void SetGeometry() = 0;
	virtual void SetColor() = 0;
	virtual void SetName() = 0;

	virtual void ShowFigure()
	{
		cout << "Name: " + name + ". Color: " + to_string(color) + ".\n";

		 HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		
			for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (array[i][j] == 1) {
					SetConsoleTextAttribute(h, color);
					cout << array[i][j] << " ";
				}
				else 
				{
					SetConsoleTextAttribute(h, 7);
					cout << array[i][j] << " ";
				}
			}
			cout << endl;
		   }
	
	

		
	}
};


// создатель объявляет фабричный метод, возвращающий объект абстрактный типа Product.
class Creator abstract
{
public:
	virtual ~Creator() {}
	virtual Figure* FactoryMethod() = 0;
};



// Конкретный продукт реализует интерфейс Product (в нашем случае, PC)
class Z : public Figure
{
public:
	~Z() {}
	void SetGeometry()
	{
		
		int values[4][4] = {
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};

	
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				array[i][j] = values[i][j];
			}
		}
	}


	void SetColor()override
	{
		
		color = 2;
	}
	void SetName()override
	{
		name = "Z";
	}
	
};


// Конкретный продукт реализует интерфейс Product (в нашем случае, PC)
class O : public Figure
{
public:
	~O() {}
	void SetGeometry()
	{

		int values[4][4] = {
			{1, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};


		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				array[i][j] = values[i][j];
			}
		}
	}


	void SetColor()override
	{

		color = 14;
	}
	void SetName()override
	{
		name = "O";
	}

};

// Конкретный продукт реализует интерфейс Product (в нашем случае, PC)
class I : public Figure
{
public:
	~I() {}
	void SetGeometry()
	{

		int values[4][4] = {
			{1, 0, 0, 0},
			{1, 0, 0, 0},
			{1, 0, 0, 0},
			{1, 0, 0, 0}
		};


		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				array[i][j] = values[i][j];
			}
		}
	}


	void SetColor()override
	{

		color = 11;
	}
	void SetName()override
	{
		name = "I";
	}

};


// Конкретный продукт реализует интерфейс Product (в нашем случае, PC)
class S : public Figure
{
public:
	~S() {}
	void SetGeometry()
	{

		int values[4][4] = {
			{0, 0, 1, 1},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};


		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				array[i][j] = values[i][j];
			}
		}
	}


	void SetColor()override
	{

		color = 4;
	}
	void SetName()override
	{
		name = "S";
	}

};



// Конкретный продукт реализует интерфейс Product (в нашем случае, PC)
class T : public Figure
{
public:
	~T() {}
	void SetGeometry()
	{

		int values[4][4] = {
			{0, 1, 1, 1},
			{0, 0, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		};


		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				array[i][j] = values[i][j];
			}
		}
	}


	void SetColor()override
	{

		color = 13;
	}
	void SetName()override
	{
		name = "T";
	}

};



// Конкретный продукт реализует интерфейс Product (в нашем случае, PC)
class J : public Figure
{
public:
	~J() {}
	void SetGeometry()
	{

		int values[4][4] = {
			{0, 0, 0, 1},
			{0, 0, 0, 1},
			{0, 0, 1, 1},
			{0, 0, 0, 0}
		};


		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				array[i][j] = values[i][j];
			}
		}
	}


	void SetColor()override
	{

		color = 12;
	}
	void SetName()override
	{
		name = "J";
	}

};

// Конкретный продукт реализует интерфейс Product (в нашем случае, PC)
class L : public Figure
{
public:
	~L() {}
	void SetGeometry()
	{

		int values[4][4] = {
			{1, 0, 0, 0},
			{1, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0}
		};


		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				array[i][j] = values[i][j];
			}
		}
	}


	void SetColor()override
	{

		color = 6;
	}
	void SetName()override
	{
		name = "L";
	}

};






// конкретный создатель переопределяет фабричный метод, возвращающий объект ConcreteProduct.
class CreatorZFigure : public Creator
{
public:

	~CreatorZFigure() {}

	Figure* FactoryMethod()override
	{
		Figure* pc = new Z();
		pc->SetGeometry();
		pc->SetColor();
		pc->SetName();
	
		return pc;
	}
};

// конкретный создатель переопределяет фабричный метод, возвращающий объект ConcreteProduct.
class CreatorOFigure : public Creator
{
public:

	~CreatorOFigure() {}

	Figure* FactoryMethod()override
	{
		Figure* pc = new O();
		pc->SetGeometry();
		pc->SetColor();
		pc->SetName();

		return pc;
	}
};

// конкретный создатель переопределяет фабричный метод, возвращающий объект ConcreteProduct.
class CreatorIFigure : public Creator
{
public:

	~CreatorIFigure() {}

	Figure* FactoryMethod()override
	{
		Figure* pc = new I();
		pc->SetGeometry();
		pc->SetColor();
		pc->SetName();

		return pc;
	}
};


// конкретный создатель переопределяет фабричный метод, возвращающий объект ConcreteProduct.
class CreatorSFigure : public Creator
{
public:

	~CreatorSFigure() {}

	Figure* FactoryMethod()override
	{
		Figure* pc = new S();
		pc->SetGeometry();
		pc->SetColor();
		pc->SetName();

		return pc;
	}
};

// конкретный создатель переопределяет фабричный метод, возвращающий объект ConcreteProduct.
class CreatorTFigure : public Creator
{
public:

	~CreatorTFigure() {}

	Figure* FactoryMethod()override
	{
		Figure* pc = new T();
		pc->SetGeometry();
		pc->SetColor();
		pc->SetName();

		return pc;
	}
};



// конкретный создатель переопределяет фабричный метод, возвращающий объект ConcreteProduct.
class CreatorJFigure : public Creator
{
public:

	~CreatorJFigure() {}

	Figure* FactoryMethod()override
	{
		Figure* pc = new J();
		pc->SetGeometry();
		pc->SetColor();
		pc->SetName();

		return pc;
	}
};

// конкретный создатель переопределяет фабричный метод, возвращающий объект ConcreteProduct.
class CreatorLFigure : public Creator
{
public:

	~CreatorLFigure() {}

	Figure* FactoryMethod()override
	{
		Figure* pc = new L();
		pc->SetGeometry();
		pc->SetColor();
		pc->SetName();

		return pc;
	}
};


// Паттерн позволяет использовать в клиентском коде программы не специфические классы, а манипулировать абстрактными объектами на более высоком уровне.
void Factory(Creator** creators, int size)
{
	// Создатель «полагается» на свои подклассы в определении фабричного метода, который будет возвращать экземпляр подходящего конкретного продукта.
	for (int i = 0; i < size; i++)
	{
		Figure* pc = creators[i]->FactoryMethod();
		pc->ShowFigure();

	}
}

void main()
{

	Creator* creators[7];
	int userChoice;


	creators[0] = new CreatorZFigure();
	creators[1] = new CreatorOFigure();
	creators[2] = new CreatorIFigure();
	creators[3] = new CreatorSFigure();
	creators[4] = new CreatorTFigure();
	creators[5] = new CreatorJFigure();
	creators[6] = new CreatorLFigure();

	Factory(creators, 7);

	
	system("pause");
}