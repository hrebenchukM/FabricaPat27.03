#include <iostream>
#include <string>

#include <windows.h>
using namespace std;

/*
��������� ����� (Factory Method) � ����������� ������ ��������������, ��������������� ���������� ��������� ��� �������� ����������� ���������� ������.
� ������ �������� ���������� ����� ����������, ����� ����� ���������������. ����� �������, ������� ���������� �������� �������� ����������� ������������� ������.
��� ��������� ������������ � ���� ��������� �� ������������� ������, � �������������� ������������ ��������� �� ����� ������� ������.
��������� �����  ���������� ��������� ��� �������� �������, �� ��������� ���������� ������� � ���, ����� ����� ���������������.

������������:
-	������ ������� ����������, ������� ����� ���������� ��� ����� ���������.
-	����� ������������� ���, ����� �������, ������� �� ������, ����������������� �����������.
-	����� ���������� ���� ����������� ������ �� ���������� ��������������� ����������, � ����������� ������������ ������ � ���, ����� ����� ��������� ��� ����������� �� ����.

�����������:
��������� ������ ��������� �������������� �� ������������� ���������� � ��� ��������� �� ���������� ������. ��� ����� ���� ������ � �����������
������ Product, ������� �� ����� �������� � ������ ������������� �������������� �������� ���������� ���������.
����������:
������������� ���������� ���������� ������ ������� � ���, ��� ��������, ��������, �������� ��������� �������� ������ Creator ��� �������� ���� ������ ������� ConcreteProduct.
*/

//������� (PC) ���������� ��������� ��������, ����������� ��������� �������

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


// ��������� ��������� ��������� �����, ������������ ������ ����������� ���� Product.
class Creator abstract
{
public:
	virtual ~Creator() {}
	virtual Figure* FactoryMethod() = 0;
};



// ���������� ������� ��������� ��������� Product (� ����� ������, PC)
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


// ���������� ������� ��������� ��������� Product (� ����� ������, PC)
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

// ���������� ������� ��������� ��������� Product (� ����� ������, PC)
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


// ���������� ������� ��������� ��������� Product (� ����� ������, PC)
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



// ���������� ������� ��������� ��������� Product (� ����� ������, PC)
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



// ���������� ������� ��������� ��������� Product (� ����� ������, PC)
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

// ���������� ������� ��������� ��������� Product (� ����� ������, PC)
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






// ���������� ��������� �������������� ��������� �����, ������������ ������ ConcreteProduct.
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

// ���������� ��������� �������������� ��������� �����, ������������ ������ ConcreteProduct.
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

// ���������� ��������� �������������� ��������� �����, ������������ ������ ConcreteProduct.
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


// ���������� ��������� �������������� ��������� �����, ������������ ������ ConcreteProduct.
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

// ���������� ��������� �������������� ��������� �����, ������������ ������ ConcreteProduct.
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



// ���������� ��������� �������������� ��������� �����, ������������ ������ ConcreteProduct.
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

// ���������� ��������� �������������� ��������� �����, ������������ ������ ConcreteProduct.
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


// ������� ��������� ������������ � ���������� ���� ��������� �� ������������� ������, � �������������� ������������ ��������� �� ����� ������� ������.
void Factory(Creator** creators, int size)
{
	// ��������� ������������ �� ���� ��������� � ����������� ���������� ������, ������� ����� ���������� ��������� ����������� ����������� ��������.
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