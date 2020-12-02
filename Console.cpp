#include "Console.h"

void Console::color(int code)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), code);

	return;

}

void Console::generic(std::string msg)
{

	// Cambio colore

	Console::color(15);

	// Scrivo il messaggio

	std::cout << msg << std::endl;

	return;

}

void Console::success(std::string msg)
{

	// Cambio colore

	Console::color(2);

	// Scrivo il messaggio

	std::cout << msg << std::endl;

	return;

}

void Console::warning(std::string msg)
{

	// Cambio colore

	Console::color(6);

	// Scrivo il messaggio

	std::cout << msg << std::endl;

	return;

}

void Console::error(std::string msg)
{

	// Cambio colore

	Console::color(4);

	// Scrivo il messaggio

	std::cout << msg << std::endl;

	return;

}

