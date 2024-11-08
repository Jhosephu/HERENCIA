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
	cout<<" y una velocidad de "<<velocimetro<<" m/s";
	cout<<endl;
}

void vehiculo::cambiarVelocidad(float v2){
	velocimetro=v2;
	cout<<"la velocidad fue cambiada a "<<velocimetro<<"m/s";
}

class automovil:public vehiculo{
	private:
		int cantidadPuertas;
		int cantidadPasajeros;
	public:
		automovil(string, string, string, float, int, int);
		void mostrarAutomovil();
		void subirPasajeros(int);
		void bajarPasajeros(int);
};

automovil::automovil(string n, string c, string m, float v, int prts, int psj):vehiculo(n, c, m, v){
	cantidadPuertas=prts;
	cantidadPasajeros=psj;
}

void automovil::mostrarAutomovil(){
	mostrarDatos();
	cout<<"es un automovil que tiene "<<cantidadPuertas<<" puertas y "<<cantidadPasajeros<<" pasajeros"<<endl;
}

void automovil::subirPasajeros(int psj){
	cantidadPasajeros=cantidadPasajeros+psj;
	cout<<"los pasajeros actuales son: "<<cantidadPasajeros;
}

void automovil::bajarPasajeros(int psj){
	cantidadPasajeros=cantidadPasajeros-psj;
	cout<<"los pasajeros actuales son: "<<cantidadPasajeros;
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
}

int main(){
	vehiculo v("XXXXXXX", "azul", "toyota", 30);
	v.mostrarDatos();
	cout<<"automovil: "<<endl;
	automovil a("XXXXXXX", "rojo", "ferrari", 50, 4, 15);
	a.mostrarAutomovil();
	cout<<"camion: "<<endl;
	camion c("XXXXXXX", "verde", "RONCO", 40, 4.5);
	c.mostrarCamion();
	return 0;
}