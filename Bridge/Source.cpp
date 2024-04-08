#include <iostream>
using namespace std;

/*
 Паттерн Bridge позволяет отделить абстракцию от ее реализации так,
 чтобы то и другое можно было изменять независимо.

Данный паттерн используется когда:
- нужно избежать постоянной привязки абстракции к реализации.
Так, например, бывает, когда реализацию необходимо выбирать во время выполнения программы.
- и абстракции, и реализации должны расширяться новыми подклассами.
В таком случае паттерн мост позволяет комбинировать разные абстракции и реализации и изменять их независимо;
- изменения в реализации абстракции не должны сказываться на клиентах, то есть клиентский код не должен перекомпилироваться;

Результаты:
- отделение реализации от интерфейса;
- повышение степени расширяемости;
- сокрытие деталей реализации от клиентов.
*/

/*
Implementor(ILanguage) - реализатор определяет интерфейс для классов реализации.
*/
class Device abstract
{
public:
	virtual void Print() abstract;
	
};

// Concretelmplementor (CPPLanguage)  - конкретный реализатор  содержит конкретную реализацию интерфейса класса Implementor.
class VideoCard: public Device
{
public:
	void Print() override
	{
		cout << "Video card:" << endl;
		cout << "Graphics chip-GeForce RTX 3090" << endl;
		cout << "Memory frequency-19500 MHz" << endl;
		cout << "Core frequency Overclocking mode-1755 MHz" << endl;
		cout << "Cooling system-iChill X4" << endl;
		cout << "Commitment to memory-24 GB" << endl;
		cout << "Separate housing is maximized-7680x4320" << endl;
		
	}
	
};

// Concretelmplementor (CSharpLanguage) - конкретный реализатор  содержит конкретную реализацию интерфейса класса Implementor.
class CPU: public Device
{
public:
	void Print() override
	{
		cout << "CPU:" << endl;
		cout << "Processor family-AMD Ryzen 9" << endl;
		cout << "Rose type-Socket AM4" << endl;
		cout << "Number of kernels-12" << endl;
		cout << "Number of streams-24" << endl;
		cout << "Base clock frequency-3700 MHz" << endl;
		cout << "Maximum clock frequency-4.8 GHz" << endl;
		cout << "Memory type-DDR4" << endl;
		cout << "Generation of AMD Ryzen processor-Zen 3" << endl;

	}
	
};

// Concretelmplementor (CSharpLanguage) - конкретный реализатор  содержит конкретную реализацию интерфейса класса Implementor.
class HDD : public Device
{
public:
	void Print() override
	{
		cout << "HDD:" << endl;
		cout << "Hoarder's revenge-22 TB" << endl;
		cout << "Hard drive type-Internal" << endl;
		cout << "Connection interface-SATAIII" << endl;
		cout << "Form factor-3.5" << endl;
		cout << "Spindle wrapping speed-7200 rpm" << endl;
		cout << "Busty buffer-512 MB" << endl;
		
	}

};

// Abstraction (Programmer) - определяет интерфейс абстракции и хранит ссылку на объект реализации типа Implementor
class IPrint abstract
{
protected:
	Device* ptr;//агрегируем како-то девайс
public:
	Device* GetDevice()
	{
		return ptr;
	}
	void SetDevice(Device* ptr)
	{
		this->ptr = ptr;
	}
	virtual void PrintDevice()abstract;
};

// RefinedAbstraction (FreelanceProgrammer)  - утонченная абстракция расширяет интерфейс, определенный абстракцией Abstraction
class PrintConsole: public IPrint
{
public:
	void PrintDevice() override
	{
		ptr->Print();
	}
};


void client(Device* dev, IPrint* printing)
{
	printing->SetDevice(dev);
	// Объект Abstraction (Programmer) перенаправляет своему объекту Implementor запросы клиента.
	printing->PrintDevice();
	
}

int main()
{
	Device* dev = new VideoCard();
	IPrint* printing = new PrintConsole();
	client(dev, printing);
	
	

	dev = new CPU();
	client(dev, printing);
	
	

	dev = new HDD();
	client(dev, printing);
	delete dev;
	

	system("pause");
	return 0;
}