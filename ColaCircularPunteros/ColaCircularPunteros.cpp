#include <iostream>
using namespace std;
int const maxcola = 5;
struct Cola
{
	int primero,ultimo;
	int elementos[maxcola];
};

void iniciar(Cola *);
bool llena(Cola *);
bool vacia(Cola *);
void insertar(Cola *,int);
void mostrar(Cola *);
void eliminar(Cola *);

int main(int argc, char *argv[]) {
	struct Cola q;
	iniciar(&q);
	int opcion;
	do{
		cout<<"\nBienvenido a nuestra aplicacion de colas con punteros \n";
		cout<<"\n Inserte una opcion \n 1) Insertar \n 2) Eliminar \n 3) salir\n";
		cin>>opcion;
		switch(opcion)
		{
		case 1: cout<<"\n inserter un valor entero \n"; int valor ; cout<<endl;cin>>valor; insertar(&q,valor);break;
		case 2: eliminar(&q);break;
		case 3: cout<<"\nGracias por usar nuestra aplicacion\n";
		default : cout<<"\n Valor no aceptado use una de nuestra opciones \n";
		}	
		system("pause");
		system("cls");
	}while(opcion !=3);
	
	
	return 0;
}
void iniciar(Cola *q)
{
	q->primero=-1;
	q->ultimo =-1;
}
bool llena(Cola *q)
{
	if((q->primero==0 && q->ultimo==maxcola-1)||(q->ultimo+1 == q->primero))return true ; else return false;
}
bool vacia(Cola *q)
{
	if(q->primero==-1 && q->ultimo==-1)
		return true;
	return false;
}
void mostrar(Cola *q)
{
	if(vacia(q))
	{
		cout<<"\n La cola esta vacía \n";
	}
	else
	{
		cout<<"\n----------------------\n";
		for(int i = q->primero ;; i++)
		{
			if(i == maxcola)
			{
				i =0;
			}
			
			cout<<"\n Elemento "<<i+1<<": "<<q->elementos[i];
			if(i == q->ultimo)
			{
				break;
			}
			
		}
		cout<<"\n----------------------\n";
	}
}
void insertar(Cola *q, int valor)
{
	if(llena(q)){cout<<"\n La cola esta llena \n";}
	else
	{
		if(q->ultimo == maxcola-1)
		{
			q->ultimo = 0;
		}
		else
		{
			q->ultimo++;
		}
		q->elementos[q->ultimo] = valor;
		if(q->primero == -1 ) {q->primero =0;}
		mostrar(q);
	}
}
void eliminar(Cola *q)
{
	if(vacia(q))
	{
		mostrar(q);
	}
	else
	{
		
		if(q->primero == q->ultimo)
		{
			q->primero = -1;
			q->ultimo = -1;
		}else if(q->primero == maxcola-1)
		{
			q->primero =0;
		}
		else
		{
			q->primero++;
		}
		mostrar(q);
	}
}
