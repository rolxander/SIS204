#include <iostream>
using namespace std;
struct nodoasig
{
	string codigo,nombre;
	int cantidad;
	struct nodoasig *siguiente;
	struct nodoasig *anterior;
};

nodoasig *primero,*ultimo,*aux;
bool vacia();
void iniciar();
void insertar_delante(string, string, int);
nodoasig *buscar(string);
void mostrar_Materia(string); 
void mostrar_Todas_Materias();
nodoasig *mostrar_Materia_MCH();
nodoasig *mostrar_Materia_mCH();
void insertar_detras(string, string, int);
void eliminar(string);
//////////////////////////////
int main(int argc, char *argv[]) {

	iniciar();
	insertar_delante("sis204","Estructura de datos",2);
	insertar_delante("sis107","Arquitectura de computadoras",4);
	insertar_delante("sis457","Programacion Avanzada",6);
	insertar_delante("sis251","Redes de datos I",8);
	insertar_delante("sis252","Redes de datos II",10);
	insertar_delante("sis110","Sistemas Operativos I",12);
	insertar_delante("sis111","Sistemas Operativos II",24);
	insertar_detras("sis100","ComputacionI",5);
	//mostrar_Todas_Materias();
	//mostrar_Materia_MCH();
	//mostrar_Materia_mCH();
	//cout<<endl<<ultimo->codigo;
	//mostrar_Materia("");
	int opcion = 0;
	string codigo,nombre;int cantidad;
	do{
		cout<<"\nBienvenido a nuestra aplicacion de Listas\n";
		cout<<"\n 1) Insertar delante";
		cout<<"\n 2) Insertar detras";
		cout<<"\n 3) Insertar ordenadamente";
		cout<<"\n 4) Buscar materia";
		cout<<"\n 5) Mostrar todas las materias";
		cout<<"\n 6) Mostrar materia con mas horas";
		cout<<"\n 7) Mostrar materia con menos horas";
		cout<<"\n 8) Eliminar materia";
		cout<<"\n 9) Salir\n";
		cin>>opcion;
		switch(opcion)
		{
			
		case 1:cout<<"\n Introduce codigo\n";cin>>codigo;cout<<"\n Introduce Nombre\n";cin>>nombre;cout<<"\n Introduce la cantidad de horas\n";cin>>cantidad;insertar_delante(codigo,nombre,cantidad);break;
		case 2:cout<<"\n Introduce codigo\n";cin>>codigo;cout<<"\n Introduce Nombre\n";cin>>nombre;cout<<"\n Introduce la cantidad de horas\n";cin>>cantidad;insertar_detras(codigo,nombre,cantidad);break;
		case 3:break;
		case 4:cout<<"\nIntroducsca el codigo de la materia\n";cin>>codigo;mostrar_Materia(codigo);break;
		case 5:cout<<"\nLista de Materias Registradas\n";mostrar_Todas_Materias();break;
		case 6:cout<<"\n La materia con mayor cantidad de horas registradas es :\n";aux = mostrar_Materia_MCH();mostrar_Materia(aux->codigo);break;
		case 7:cout<<"\n La materia con menor cantidad de horas registradas es :\n";aux = mostrar_Materia_mCH();mostrar_Materia(aux->codigo);break;
		case 8:cout<<"\n Introduce el codigo de la materia a eliminar\n";cin>>codigo;eliminar(codigo);break;
		case 9:break;
		default : cout<<"Introduce una opcion del menu";
		}
		cout<<endl;
		system("pause");
		system("cls");
	
		
	}while(opcion!=9);
	
	return 0;
}
bool vacia()
{
	if(primero == NULL) return true; else return false;
	//(primero == NULL) ? return true : else return false;
}
void iniciar()
{
	primero = NULL;
	ultimo = NULL;
}

void insertar_delante(string codigo, string nombre, int cantidad)
{
	nodoasig *nodo = new nodoasig;
	nodo->nombre = nombre;
	nodo->codigo = codigo;
	nodo->cantidad = cantidad;
	nodo->siguiente = NULL;
	nodo->anterior = NULL;
	if(vacia())
	{
		primero = nodo;
		ultimo = nodo;
	}else
	{
		nodo->siguiente = primero;
		primero->anterior = nodo;
		primero = nodo;
		
	}
}
nodoasig *buscar(string codigo)
{
	nodoasig *p = primero;
	while((p->codigo!=codigo) && (p->siguiente!= NULL))
	{
		p = p->siguiente;
		//cout<<endl<<p->nombre;
	}
	//cout<<"Sali del bucle";
	if(p->codigo==codigo)
	{
		//cout<<endl<<p->nombre;
		return p;
	}
	else
	{
		//cout<<endl<<"Estoy aqui";
		return NULL;
	}
	
}

void mostrar_Materia(string codigo)
{
	nodoasig *p= buscar(codigo);
	if(p!=NULL)
	{
		cout<<endl<<"---------------------------------------";
		cout<<"\nCodigo : "<<p->codigo<<"\nNombre : "<<p->nombre<<"\nCantidad de horas : "<<p->cantidad;
		cout<<endl<<"---------------------------------------";
	}else
	{
		cout<<"\nLa Materia con codigo "<<codigo<<" no esta registrada en la base de datos";
	}
}
void mostrar_Todas_Materias()
{
	nodoasig *p = primero;
	while(p != NULL)
	{
		mostrar_Materia(p->codigo);
		p= p->siguiente;
	}
}
nodoasig *mostrar_Materia_MCH()
{
	nodoasig *q = primero;
	nodoasig *p = primero;
	while(p != NULL)
	{
		//mostrar_Materia(p->codigo);
		if(p->cantidad>=q->cantidad)
		{
			q=p;
		}
		p= p->siguiente;
		
	}
	//cout<<endl<<"Materia mayor "<<q->codigo;
	return q;
}
nodoasig *mostrar_Materia_mCH()
{
	nodoasig *q = primero;
	nodoasig *p = primero;
	while(p != NULL)
	{
		//mostrar_Materia(p->codigo);
		if(p->cantidad<=q->cantidad)
		{
			q=p;
		}
		p= p->siguiente;
		
	}
	//cout<<endl<<"menor mayor "<<q->codigo;
	return q;
}
void insertar_detras(string codigo, string nombre, int cantidad)
{
	nodoasig *nodo = new nodoasig;
	nodo->codigo = codigo;
	nodo->nombre = nombre;
	nodo->cantidad = cantidad;
	nodo->siguiente = NULL;
	nodo->anterior = NULL;
	if(vacia())
	{
		primero = nodo;
		ultimo = nodo;
	}
	else
	{
		ultimo->siguiente = nodo;
		nodo->anterior = ultimo;
		ultimo = nodo;
	}
	
}
void eliminar(string codigo)
{
	nodoasig *p = buscar(codigo);
	if(p != NULL)
	{
		if(p==primero)
		{
			primero->siguiente->anterior = NULL;
			primero = primero->siguiente;
		}else if(p==ultimo)
		{
			ultimo->anterior->siguiente = NULL;
			ultimo = ultimo->anterior;
			
		}
		else
		{
			p->anterior->siguiente = p->siguiente;
			p->siguiente->anterior = p->anterior;
		}
	}

}








