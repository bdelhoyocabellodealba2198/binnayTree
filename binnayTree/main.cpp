#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo
{
	int dato;
	Nodo *der;
	Nodo *izq;
	
};
void imprimirArbol(Nodo *arbol, int count);
void menu();
Nodo *crearNodo(int);
void insertNode(Nodo *&arbol, int n);
Nodo *arbol = NULL;

int main()
{

	menu();
	return 0;
}

//función para mostrar el arbol completo
void imprimirArbol(Nodo * arbol, int count)
{
	if(arbol == NULL)
	{
		return;
	}
	else
	{
		imprimirArbol(arbol->der, count + 1);
		for(int i=0; i<count; i++)
		{
			std::cout << "   " << std::endl;
		};
		std::cout << arbol->dato << std::endl;
		imprimirArbol(arbol->izq, count + 1);
	}
}
//función del menú
void menu()
{
	int dato, option, counter;
	counter = 0;
	do
	{
		std::cout << "MENU" << std::endl;
		std::cout << "1.Insertar un nuevo nodo" << std::endl;
		std::cout << "2.Imprimir arbol" << std::endl;
		std::cout << "3.Salir" << std::endl;
		std::cin >> option;
		switch (option)
		{
		case 1:
			std::cout << "Ponga el numero a insertar en el arbol"<<std::endl;
			std::cin >> dato;
			insertNode(arbol, dato);
			system("pause");
			break;
		case 2:
			imprimirArbol(arbol, counter);
			system("pause");
			break;
		default:
			break;
		}
		system("cls");
	} while (option != 3);
}
//función para crear un nuevo nodo
Nodo * crearNodo(int n)
{
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;

	return nuevo_nodo;
}
//insertar un nodo en el arbol 
void insertNode(Nodo *&arbol, int n)
{
	if(arbol == NULL) //Si el arbol esta vacío creamos un nuevo nodo
	{
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	}else //si el aarbol tiene un nodo o mas de un nodo
	{
		int valoArbol = arbol->dato;
		if(n<valoArbol)//si el valor que queremos insertar es mas pequeño que el valor del nodo raiz insertamos en izq
		{
			insertNode(arbol->izq, n);
		}
		else //si el valor qque queremos inserta es más grande que el nodo raiz, insertamos en el lado derecho
		{
			insertNode(arbol->der, n);
		}
		
	}
}
