#include <iostream>
#include<stdlib.h>
using namespace std;
int const maxpila = 5;
struct Pila
{
	int elemento ,tope ;
	int elementos[maxpila];
};

struct Pila p;
void iniciar();
void mostrar();
bool llena();
bool vacia();
void mostrar();
void insertar(int);
void eliminar();


int main(int argc, char *argv[]) {

	iniciar();
	int opcion;
	do{
		cout<<"\n Eliga una opcion\n";
		cout<<" 1) Insertar \n 2) Eliminar\n";
		cin>>opcion;
		
		switch(opcion)
		{
		case 1: int valorin;cout<<"Insertar el valor a insertar \n"; cin>> valorin ;insertar(valorin); break;
		case 2: eliminar();break;
		default : cout<<"\n tome la opcion correcta \n";break;
		}
		cout<<"\n";
		system("pause");
		system("cls");		
	}while(opcion != 4);
	
	
	return 0;
}
void iniciar()
{
	p.tope =-1;
}



bool llena()
{
	if( p.tope == maxpila-1) return 1; else  return 0; 
}
bool vacia()
{
	if(p.tope == -1) return 1;
	else return 0;
}
void eliminar()
{
	if(vacia())
	{
		cout<<"\n La pila esta vacia \n";
	}
	else
	{
		p.tope--;
		mostrar();
	}
	
}
void mostrar()
{
	if(vacia())
	{
		cout<<"\n La pila esta vacia \n";
	}
	else
	{
		for(int i =0 ; i<=p.tope ; i++)
		{
			
			cout<<"\n |"<<p.elementos[i]<<"|";
		}
	}
}
void insertar(int valor)
{
	if(llena())
	{
		cout<<"\n La pila esta llena \n";
		
	}
	else
	{
		p.tope++;
		p.elementos[p.tope] = valor; 
	}
	mostrar();
}
