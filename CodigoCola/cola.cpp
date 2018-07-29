#include <iostream>
using namespace std;
int const maxcola = 5;
struct Cola
{
	int primero,ultimo;
	int elementos[5];
	
};
//Metodo que inicia la strutura
struct Cola q;
void iniciar();
bool llena();
bool vacia();
void mostrar();
void insertar(int);
void eliminar();
int main(int argc, char *argv[]) {
	int opcion;
	iniciar();
	do{
		
	cout<<"\n Introduce una opcion \n 1) Inserter \n 2)Eliminar \n";
	cin>>opcion;
	switch(opcion)
	{
	case 1 : cout<<"Inserte un valor \n";int valor;cin>>valor; insertar(valor);break;
	case 2 : eliminar();break;
	default : cout<<"Opcion no valida \n";
	}
	system("pause");
	system("cls");
	}while(opcion!=3);
	
	return 0;
}
void iniciar()
{
	q.primero = 0;
	q.ultimo = -1;
}
bool llena()
{
	if(q.ultimo==maxcola-1) return 1; else return 0;
}
bool vacia()
{
	if(q.ultimo == -1) return 1; else return 0;
}
void mostrar()
{
	if(vacia())
	{
		cout<<"\n La cola esta vacía \n";
	}
	else
	{
		for(int i = q.primero ; i<=q.ultimo ; i++)
		{
			cout<<"\n Elemento "<<i+1<<" :"<<q.elementos[i]<<endl;
		}
	}
}

void insertar(int valor)
{
	if(llena()){
		cout<<"\n La cola esta llena \n";
	}
	else
	{
		q.ultimo++;
		q.elementos[q.ultimo] = valor;
		
	}
	mostrar();
}
void eliminar()
{
	if(vacia())
	{
		mostrar();
	}
	else
	{
		//q.ultimo--;
		for(int i =0; i<q.ultimo;i++)
		{
			q.elementos[i] = q.elementos[i+1];
		}
		q.ultimo--;
		mostrar();
	}
}

