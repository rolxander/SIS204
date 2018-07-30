#include <iostream>
using namespace std;
int const maxcola = 5;
struct Cola
{
	int primero, ultimo;
	int elementos[maxcola];
};
struct Cola q;
// prototipacion de funciones
void iniciar();
bool llena();
bool vacia();
void mostrar();
void insertar(int);
void eliminar();
// inicio de programa principal

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
// declaracion de funciones
void iniciar()
{
	q.primero = -1;
	q.ultimo = -1;
}
bool vacia()
{
	if(q.ultimo == -1 && q.primero == -1) return 1; else return 0;
}
bool llena()
{
	if((q.primero==0 && q.ultimo== maxcola-1)||(q.ultimo+1 == q.primero)) return 1; else return 0;

}
void mostrar()
{
	if(vacia()){
		cout<<"\n La cola esta vacía \n";
	}
	else{
		
		cout<<"\n----------------------\n";
			for(int i = q.primero;true;i++)
			{
				if(i==maxcola)
				{
					i = 0;
				}
				cout<<" \n Elemento "<<i+1<<": "<<q.elementos[i];
				if(i == q.ultimo){ break; }
			}
			cout<<"\n----------------------\n";		
		
	}
}

void insertar(int valor)
{
	if(llena())
	{cout<<"\n La cola esta llena \n";}
	else
	{
			if(q.ultimo == maxcola-1)
			{
				q.ultimo =0;
			}
			else
			{
				q.ultimo++;
				
			}
			q.elementos[q.ultimo] = valor;
			if(q.primero==-1)
			{
				q.primero=0;
			}
			mostrar();		
	}
}
void eliminar()
{
	if(vacia()){mostrar();}
	else
	{
		if(q.primero == q.ultimo){q.primero =-1;q.ultimo=-1;}
		else if(q.primero == maxcola-1)
		{
			q.primero =0;
		}else
		{
			q.primero++;
			
		}
		mostrar();
		
	}
}
