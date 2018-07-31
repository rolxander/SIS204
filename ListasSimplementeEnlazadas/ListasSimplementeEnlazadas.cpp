#include <iostream>
using namespace std;
typedef struct nodo{
	char *dato;
	struct nodo *siguiente;
}nodocaracter;
nodocaracter *primero,*ultimo;
void iniciar();
bool vacia();
void insertar_delante(char *);
void insertar_detras(char *);
void mostrar();
void eliminar(char *);

//Inicio Main
int main(int argc, char *argv[]) {
	iniciar();
	char a='a',b='b',c='c',d='d',e='e';
	insertar_detras(&d);
	insertar_delante(&c);
	insertar_detras(&e);
	insertar_delante(&b);
	insertar_delante(&a);
	eliminar(&b);
	eliminar(&c);
	eliminar(&a);
	eliminar(&d);
	eliminar(&e);
	
	
	
	
	return 0;
}
//Fin Main

void iniciar()
{
	primero = NULL;
	ultimo =NULL;
}

bool vacia()
{
	if(primero==NULL) return 1; else return 0;
}
void mostrar()
{
	if(vacia()){cout<<"\n La lista esta vacía \n";}
	else
	{
		cout<<"\n _______________________\n";
		nodocaracter *p;
		p=primero;
		while(p!=NULL)
		{
			cout<<*p->dato;
			p=p->siguiente;
		}
		cout<<"\n _______________________\n";
	}
}
void insertar_delante(char *valor)
{
	nodocaracter *p;
	p = new nodocaracter;
	p->dato = valor;
	p->siguiente = NULL;
	if(vacia())
	{
		primero = p;
		ultimo =p;
	}else
	{
		p->siguiente = primero;
		primero = p;
	}
	mostrar();
}
void insertar_detras(char * valor)
{
	nodocaracter *p;
	p = new nodocaracter;
	p->siguiente = NULL;
	p->dato = valor;
	if(vacia())
	{
		primero = p;
		ultimo = p;
	}else
	{
		ultimo->siguiente = p;
		p = ultimo;
		
	}
	mostrar();
}
void eliminar(char *valor)
{
	if(vacia()) 
	{
		mostrar();
	}
	else
	{
		nodocaracter *p,*q;
		p = primero;
		q = primero;
		while(p!=NULL && *p->dato != *valor)
 		{
			q=p;
			p = p->siguiente;
		}
		
		if(p->dato == valor)
		{
			q->siguiente = p->siguiente;
				if(p==primero)
				{
					primero = p->siguiente;
				}
				if(p == ultimo)
				{
					ultimo = q;
				}
		}
		else
		{
			cout<<"\nEl elemento no existe\n";
		}
	}
	mostrar();
}


