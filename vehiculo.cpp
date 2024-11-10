#include<bits/stdc++.h>

using namespace std;

class vehiculo{
	protected:
		string numeroPlaca;
		string color;
		string marca;
		float velocimetro;
	public:
		vehiculo(string, string, string, float);
		void mostrarDatos();
		void cambiarVelocidad(float);
};

vehiculo::vehiculo(string n, string c, string m, float v){
	numeroPlaca=n;
	color=c;
	marca=m;
	velocimetro=v;
}

void vehiculo::mostrarDatos(){
	cout<<"placa "<<numeroPlaca<<", es de color "<<color<<", de marca "<<marca;
	cout<<" y tiene una velocidad de "<<velocimetro<<" m/s";
	cout<<endl;
}

void vehiculo::cambiarVelocidad(float v2){
	velocimetro=v2;
	cout<<"la velocidad fue cambiada a "<<velocimetro<<"m/s"<<endl;
}

class automovil:public vehiculo{
	private:
		int cantidadPuertas;
		int cantidadPasajeros;
	public:
		automovil(string, string, string, float, int, int);
		void mostrarAutomovil();
		int subirPasajeros(int);
		int bajarPasajeros(int);
};

automovil::automovil(string n, string c, string m, float v, int prts, int psj):vehiculo(n, c, m, v){
	cantidadPuertas=prts;
	cantidadPasajeros=psj;
}

void automovil::mostrarAutomovil(){
	mostrarDatos();
	cout<<"es un automovil que tiene "<<cantidadPuertas<<" puertas y "<<cantidadPasajeros<<" pasajeros"<<endl;
}

int automovil::subirPasajeros(int psj){
	cantidadPasajeros=cantidadPasajeros+psj;
	cout<<"los pasajeros actuales son: "<<cantidadPasajeros<<endl;
	return cantidadPasajeros;
}

int automovil::bajarPasajeros(int psj){
	cantidadPasajeros=cantidadPasajeros-psj;
	cout<<"los pasajeros actuales son: "<<cantidadPasajeros<<endl;
	return cantidadPasajeros;
}

class camion:public vehiculo{
	private:
		double carga;
	public:
		camion(string, string, string, float, double);
		void mostrarCamion();
		void cambiarCarga(double);
};

camion::camion(string n, string c, string m, float v, double crg):vehiculo(n, c, m, v){
	carga=crg;
}

void camion::mostrarCamion(){
	mostrarDatos();
	cout<<"es un camion con carga de: "<<carga<<"kg"<<endl;
}

void camion::cambiarCarga(double crg){
	carga=crg;
	cout<<"la carga cambio a: "<<carga<<"kg"<<endl;
}

int main(){
	string placa, color, marca;
	float velocidad;
	int puertas, pasajeros;
	double carga;
	int n, m;
	do{
		cout<<"ingrese el tipo de vehiculo: "<<endl;
		cout<<"1. vehiculo (general): "<<endl;
		cout<<"2. automovil: "<<endl;
		cout<<"3. camion: "<<endl;
		cout<<"0. salir: "<<endl;
		cin>>n;
			switch (n){
				case 1:
					cout<<"ingrese la placa del vehiculo: "; cin>>placa;
					cout<<"ingrese el color del vehiculo: "; cin>>color;
					cout<<"ingrese la marca del vehiculo: "; cin>>marca;
					cout<<"ingrese la velocidad del vehiculo: "; cin>>velocidad;
					do{
						vehiculo v(placa,color,marca,velocidad);
						cout<<"que desea hacer?: "<<endl;
						cout<<"1. mostrar datos: "<<endl;
						cout<<"2. cambiar velocidad: "<<endl;
						cout<<"0. retroceder: "<<endl;
						cin>>m;
						switch(m){
							case 1:
								v.mostrarDatos();
								break;
							case 2:
								cout<<"ingrese la nueva velocidad: ";
								cin>>velocidad;
								v.cambiarVelocidad(velocidad);
								break;
						}
					} while(m!=0);
					break;
				case 2:
					cout<<"ingrese la placa del automovil: "; cin>>placa;
					cout<<"ingrese el color del automovil: "; cin>>color;
					cout<<"ingrese la marca del automovil: "; cin>>marca;
					cout<<"ingrese la velocidad del autmovil: "; cin>>velocidad;
					cout<<"ingrese la cantidad de puertas: "; cin>>puertas;
					cout<<"ingrese la cantidad de pasajeros: "; cin>>pasajeros;
					do{
						automovil a(placa, color, marca, velocidad, puertas, pasajeros);
						cout<<"que desea hacer?: "<<endl;
						cout<<"1. mostrar datos: "<<endl;
						cout<<"2. cambiar velocidad: "<<endl;
						cout<<"3. subir pasajeros: "<<endl;
						cout<<"4. bajar pasajeros: "<<endl;
						cout<<"0. retroceder: "<<endl;
						cin>>m;
						switch(m){
							case 1:
								a.mostrarAutomovil();
								break;
							case 2:
								cout<<"ingrese la nueva velocidad: ";
								cin>>velocidad;
								a.cambiarVelocidad(velocidad);
								break;
							case 3:
								cout<<"ingrese la cantidad de pasajeros que suben: ";
								cin>>pasajeros;
								pasajeros=a.subirPasajeros(pasajeros);
								break;
							case 4:
								cout<<"ingrese la cantidad de pasajeros que bajan: ";
								cin>>pasajeros;
								pasajeros=a.bajarPasajeros(pasajeros);
								break;
						}
					} while(m!=0);
					break;
				case 3:
					cout<<"ingrese la placa del camion: "; cin>>placa;
					cout<<"ingrese el color del camion: "; cin>>color;
					cout<<"ingrese la marca del camion: "; cin>>marca;
					cout<<"ingrese la velocidad del camion: "; cin>>velocidad;
					cout<<"ingrese la carga del camion: "; cin>>carga;
					do{
						camion c(placa, color, marca, velocidad, carga);
						cout<<"que desea hacer?: "<<endl;
						cout<<"1. mostrar datos: "<<endl;
						cout<<"2. cambiar velocidad: "<<endl;
						cout<<"3. cambiar carga: "<<endl;
						cout<<"0. retroceder: "<<endl;
						cin>>m;
						switch(m){
							case 1:
								c.mostrarCamion();
								break;
							case 2:
								cout<<"ingrese la nueva velocidad: ";
								cin>>velocidad;
								c.cambiarVelocidad(velocidad);
								break;
							case 3:
								cout<<"ingrese la nueva carga: ";
								cin>>carga;
								c.cambiarCarga(carga);
						}
					} while(m!=0);
					break;
			}
	}while (n!=0);
	return 0;
}
