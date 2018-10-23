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
void mostrar_estudiantes_Materia(string);
// Inicio main
int main(int argc, char *argv[]) {
	iniciar();
	insertar_Materia_delante("sis100","Computacion I",8);
	insertar_Materia_delante("sis204","Estructura de datos",8);
	insertar_Materia_delante("sis101","Metodologia de la prigramacion I",8);
	insertar_estudiante("35-3562","jose choque","sin direccion",'M',"sis100");
	insertar_estudiante("35-3562","jose choque","sin direccion",'M',"sis101");
	insertar_estudiante("111-255","gael choque","sin direccion",'M',"sis100");
	insertar_estudiante("111-255","gael choque","sin direccion",'M',"sis101");
	insertar_estudiante("35-3562","jose choque","sin direccion",'M',"sis204");
	insertar_estudiante("111-255","gael choque","sin direccion",'M',"sis204");
	int opcion = 0;
	string codigo,nombre,detalle,codigo_E,nombre_E,direccion_E;
	char sexo_E;
	int cantidad;
	do{
		cout<<endl<<"Bienvenido a Nuestra aplicacion de multilistas"<<endl;
		cout<<"Elige una opcion de nuestro menú"<<endl;
		cout<<endl<<"1 )Insertar Materia por delante"<<endl;
		cout<<"2) Busscar Materia"<<endl;
		cout<<"3) Agregar estudiante a una materia"<<endl;
		cout<<"4) Mostrar lista de estudiantes de una materia espesifica"<<endl;
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
		case 3: cout<<endl<<"Inserte la sigla de la materia"<<endl;
				cin>>codigo;
				cout<<endl<<"Inserte el nombre estudiante"<<endl;
				cin>>nombre_E;
				cout<<endl<<"Inserte direccion del estudiante"<<endl;
				cin>>direccion_E;
				cout<<endl<<"Inserte Carnet Universitario"<<endl;
				cin>>codigo_E;
				cout<<"Inserte el sexo del estudiante M o F"<<endl;
				cin>>sexo_E;insertar_estudiante(codigo_E,nombre_E,direccion_E,sexo_E,codigo);break;
		case 4: cout<<endl<<"Introduce la sigla de la asignatura"<<endl;
				cin>>codigo;
				mostrar_estudiantes_Materia(codigo);break;
				
		}
		system("pause");
		system("cls");
	}		
	while(opcion!=0);


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
		cout<<"\nCantidad Horas : "<<p->cantidad<<endl;
	}
}

void insertar_estudiante(string codigo,string nombre,string direccion,char sexo,string codigo_M)
{
	nodoasig *p = buscar_Materia(codigo_M);
	nodoestudiante *q = new nodoestudiante;
	nodoestudiante *r;
	q->codigo = codigo;
	q->nombre = nombre;
	q->direccion = direccion;
	q->sexo = sexo;
	q->siguiente= NULL;
	if(p->pestudiante == NULL)
	{
		p->pestudiante = q;
	}else
	{
		r = p->pestudiante;
		while(r->siguiente!=NULL)
		{
			r = r->siguiente;
		}
		
		if(r==NULL)
		{
			cout<<endl<<"Aqui jamas deberia entrar"<<endl;
		}else
		{
			r->siguiente=q;
		}
	}
}

void mostrar_estudiantes_Materia(string codigo)
{
	nodoasig *p = buscar_Materia(codigo);
	nodoestudiante *q = p->pestudiante;
	if(p==NULL)
	{
		cout<<endl<<"La materia no esta registrada"<<endl;
	}
	else{
		cout<<endl<<"Lista de alumnos "<<codigo<<endl;
		int contador = 1;
		if(q==NULL)
		{
			cout<<endl<<"No se registraron alumnos en la asignatura"<<endl;
		}else{
			while(q!=NULL)
			{
				cout<<contador<<") "<<q->nombre<<endl;
				q = q->siguiente;
				contador++;
			}
			cout<<"El total de alumnos registrados en la materia es : "<<contador-1<<endl; 
		}
	}	
}
