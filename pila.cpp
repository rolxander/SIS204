#include <iostream>
#include<stdlib.h>
using namespace std;
const int maxpila=5;
struct stack{
	int tope;
	int items[maxpila];
};
struct stack p;
int iniciar()
{
	p.tope=-1;
	return 0;
}
int vacia()
{
	if (p.tope==-1)
		return 1;
	else
		return 0;
}
int llena()
{
	if (p.tope==maxpila-1)
		return 1;
	else
		return 0;
}

void insertar(int x)
{
	if (llena())
	{cout<<"La pila esta llena";
	cout<<endl;
	}
	else
		{
			p.tope ++;
			p.items [p.tope]=x;
		}
}

int eliminar()
{
	if (vacia())
	{cout<<"La pila esta vacia";
	cout<<endl;
	}
	else
		{
			
			p.items[p.tope] = 0;
			p.tope--;			
			return (p.items[p.tope]);
			
		}
}

int main(int argc, char *argv[]) {
	int r;
	int e;
	
	iniciar();
	
	//Insertando elemntos
	
	do{
		system("cls"); //Limpia la pantalla con ms dos.
		cout<<"Laboratorio Nro 1 Pilas";
		cout<<endl;
		cout<<endl;
		
		cout<<"Presione 1 si decea añadir elemneto a la pila\n";
		cout<<"Presione 2 si decea eliminar elemneto de la pila\n";
		cout<<"Presione 3 si decea mostrar la pila\n";
		cout<<"Presione 0 si decea terminar el proceso\n";
		cin>>r;
		if(r==1){
			cout<<"inserte elemento en la pila\n";
			cin>>e;
			insertar(e);
			
		}
		
		if(r==2){
			eliminar();
			
		}
		
		if(r==3){
			cout<<"Elementos en la pila\n";
			//Se muestra la pila
			cout<<p.items[0];
			cout<<endl;
			cout<<p.items[1];
			cout<<endl;
			cout<<p.items[2];
			cout<<endl;
			cout<<p.items[3];
			cout<<endl;
			cout<<p.items[4];
			cout<<endl;
			
		}
		system("pause");
	}while(r!=0);
	
	cout<<endl;
	cin.get();
	cout<<endl;
	cin.get();
	
	system("pause");
	return 0;
}
