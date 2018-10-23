#include <iostream>
using namespace std;
struct nodoestudiante
{
	string codigo,nombre,direccion,sexo;
	struct nodoestudiante *siguiente;
};

struct nodoasig
{
	string codigo, descripcion;
	int cantidad;
	struct nodoasig *siguiente;
	struct nodoestudiante *pestudiante;
};

nodoasig *primero,*ultimo;
// Prototipacion de funciones
void iniciar();
void insertar_Materia_delante(string,string,int);
nodoasig *buscar_Materia(string);
void mostra_Materia(string);
void insertar_estudiante(string,string,string,char,string);
// Inicio main
int main(int argc, char *argv[]) {
	iniciar();
	int opcion = 0;
	string codigo,nombre,detalle;
	int cantidad;
	do{
		cout<<endl<<"Bienvenido a Nuestra aplicacion de multilistas"<<endl;
		cout<<"Elige una opcion de nuestro menú"<<endl;
		cout<<endl<<"1 )Insertar Materia por delante"<<endl;
		cout<<"2) Busscar Materia"<<endl;
		cin>>opcion;
		switch(opcion)
		{
		case 1:	cout<<endl<<"Introdusca una sigla"<<endl;cin>>codigo;
				cout<<endl<<"Introdusca el nombre de la materia"<<endl;cin>>detalle;
				cout<<endl<<"Introduce la cantidad de Horas"<<endl;cin>>cantidad;cout<<endl;
				insertar_Materia_delante(codigo,detalle,cantidad);
				break;
		case 2 :cout<<endl<<"Introdusca la sigl de la materia  buscar"<<endl;
				cin>>codigo;
				mostra_Materia(codigo);break;
		}
	}
	while(opcion!=0);
	insertar_Materia_delante("sis100","Computacion I",8);
	insertar_Materia_delante("sis101","Metodologia de la prigramacion I",8);
	//mostra_Materia("sis100");
	//mostra_Materia("sis101");	
	return 0;
}
// Fin main
void iniciar()
{
	primero = NULL;
	ultimo = NULL;
}
bool vacia()
{
	if(primero == NULL) return true;
	else return false;
}

void insertar_Materia_delante(string codigo,string nombre,int cantidad)
{
	nodoasig *nodo = new nodoasig;
	nodo->descripcion = nombre;
	nodo->codigo = codigo;
	nodo->cantidad = cantidad;
	nodo->pestudiante =NULL;
	nodo->siguiente = NULL;
	if(vacia())
	{
		primero = nodo;
		ultimo = nodo;
	}
	else
	{
		nodo->siguiente = primero;
		primero = nodo;	
	}
}

nodoasig *buscar_Materia(string codigo)
{
	nodoasig *p = primero;
	if(vacia())
	{
		cout<<"\n La listta esta vacia\n";
		
	}
	if(primero == ultimo)
	{
		return primero;
	}
	else
	{
		while(p->codigo!=codigo && p->siguiente!= NULL)
		{
			p=p->siguiente;
		}
		if(p->codigo == codigo)
		{
			return p;
		}
		else
		{
			return NULL;
		}
	}
}
void mostra_Materia(string codigo)
{
	nodoasig *p = buscar_Materia(codigo);
	if(p == NULL)
	{
		cout<<"\n La materia con codigo : "<<codigo<<" no esta registrada\n";
	}
	else
	{   cout<<"\n_____________________________________________________________\n";
		cout<<"\nSigla : "<<p->codigo;
		cout<<"\nMateria : "<<p->descripcion;
		cout<<"\nCantidad Horas : "<<p->cantidad;
	}
}

void insertar_estudiante(string codigo,string nombre,string direccion,char sexo,string codigo_M){}
