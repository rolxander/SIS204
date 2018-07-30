#include <iostream>
using namespace std;
int const maxcola =5;
struct Cola{
	int primero,ultimo;
	int elementos[maxcola];
};
void iniciar(Cola *);
bool llena(Cola *);
bool vacia(Cola *);
void insertar(Cola *,int);
void eliminar(Cola *);
void mostrar(Cola *);
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
void iniciar(Cola *q){
	q->primero = 0;
	q->ultimo = -1;
}
bool vacia(Cola *q)
{
	if(q->ultimo==-1) return 1;
	else return 0;
}
bool llena(Cola *q)
{
	if(q->ultimo == maxcola -1) return 1; else return 0;
}
void mostrar(Cola *q)
{
	if(vacia(q))
	{
		cout<<"\n La cola esta vacia \n";
	}else
	{
		for(int i =0; i<=q->ultimo; i++)
		{
			cout<<"Elemento "<<(i+1)<<": "<<q->elementos[i]<<endl;
		}
	}
}
void insertar(Cola *q, int valor)
{
	if(llena(q))
	{
		cout<<"\n La cola esta llena\n";
		mostrar(q);
		
	}
	else
	{
		q->ultimo ++;
		q->elementos[q->ultimo] = valor;
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
		for(int i =0; i<q->ultimo;i++)
		{
			q->elementos[i] = q->elementos[i+1];
		}
		q->ultimo--;
		mostrar(q);
	}
}

