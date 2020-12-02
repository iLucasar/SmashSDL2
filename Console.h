#pragma once

#include <iostream>
#include <Windows.h>

class Console
{

private:
	// Funzione per cambiare il colore del testo e del background
	static void color(int);

public:
	// Funzioni per scrivere messaggi generici, avvertimenti ed errori
	static void generic(std::string);
	static void success(std::string);
	static void warning(std::string);
	static void error(std::string);
	
};

