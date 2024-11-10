#include<bits/stdc++.h>

using namespace std;

class figura{
	protected: 
		string color;
	public:
		figura(string);
		void mostrarDatos();
};

figura::figura(string c){
	color=c;
}

void figura::mostrarDatos(){
	cout<<"color: "<<color<<endl;
}

class circulo:public figura{
	private: 
		float radio;
	public:
		circulo(string, float);
		void mostrarCirculo();
		float calcularArea();
		float calcularPerimetro();
};

circulo::circulo(string c, float r):figura(c){
	radio=r;
}

void circulo::mostrarCirculo(){
	mostrarDatos();
	cout<<"el circulo tiene un radio de "<<radio<<"m"<<endl;
}

float circulo::calcularArea(){
	float area;
	area=3.14*pow(radio,2);

	return area;
}

float circulo::calcularPerimetro(){
	float perimetro;
	perimetro=2*3.14*radio;
	
	return perimetro;
}

class rectangulo:public figura{
	private:
		float base;
		float altura;
	public:
		rectangulo(string, float, float);
		void mostrarRectangulo();
		float calcularArea();
};

rectangulo::rectangulo(string c, float b, float h):figura(c){
	base=b;
	altura=h;
}

void rectangulo::mostrarRectangulo(){
	mostrarDatos();
	cout<<"base del rectangulo: "<<base<<"m"<<endl;
	cout<<"altura del rectangulo: "<<altura<<"m"<<endl;
}

float rectangulo::calcularArea(){
	float area;
	area=base*altura;
	return area;
}

class triangulo:public figura{
	private:
		float base;
		float altura;
		string tipo;
	public:
		triangulo(string, float, float, string);
		void mostrarTriangulo();
		float calcularArea();
};

triangulo::triangulo(string c, float b, float h, string t):figura(c){
	base=b;
	altura=h;
	tipo=t;
}

void triangulo::mostrarTriangulo(){
	mostrarDatos();
	cout<<"base del triangulo: "<<base<<"m"<<endl;
	cout<<"altura del triangulo: "<<altura<<"m"<<endl;
	cout<<"tipo del triangulo: "<<tipo<<endl;
}

float triangulo::calcularArea(){
	float area;
	area=(base*altura)/2.;
	return area;
}

int main(){
	string color;
	float radio, base, altura;
	string tipo;
	float area, perimetro;
	int n, m;
	do{
		cout<<"escoja entre los siguientes: "<<endl;
		cout<<"1. figura (general) "<<endl;
		cout<<"2. circulo "<<endl;
		cout<<"3. rectangulo "<<endl;
		cout<<"4. triangulo "<<endl;
		cout<<"0. salir: ";
		cin>>n;
		switch(n){
			case 1:
				cout<<"ingrese el color de la figura: "; cin>>color;
				do{
				figura f(color);
				f.mostrarDatos();
				}while (0);
				break;
			case 2:
				cout<<"ingrese el color del circulo: "; cin>>color;
				cout<<"ingrese el radio del circulo: "; cin>>radio;
				do{
					circulo c(color, radio);
					cout<<"que desea hacer?: "<<endl;
					cout<<"1. mostrar datos "<<endl;
					cout<<"2. calcular area "<<endl;
					cout<<"3. calcular perimetro "<<endl;
					cout<<"0. retroceder "<<endl;
					cin>>m;
					switch (m){
						case 1:
							c.mostrarCirculo();
							break;
						case 2:
							area=c.calcularArea();
							cout<<"el area del circulo es: "<<area<<endl;
							break;
						case 3:
							perimetro=c.calcularPerimetro();
							cout<<"el perimetro del circulo es: "<<perimetro<<endl;
							break;
					}
				} while(m!=0);
				break;
			case 3:
				cout<<"ingrese el color del rectangulo: "; cin>>color;
				cout<<"ingrese la base del rectangulo: "; cin>>base;
				cout<<"ingrese la altura del rectangulo: "; cin>>altura;
				do{
					rectangulo r(color, base, altura);
					cout<<"que desea hacer?: "<<endl;
					cout<<"1. mostrar datos "<<endl;
					cout<<"2. calcular area "<<endl;
					cout<<"0. retroceder "<<endl;
					cin>>m;
					switch (m){
						case 1:
							r.mostrarRectangulo();
							break;
						case 2:
							area=r.calcularArea();
							cout<<"el area del rectangulo es: "<<area<<endl;
							break;
					}
				}while (m!=0);
				break;
			case 4:
				cout<<"ingrese el color del triangulo: "; cin>>color;
				cout<<"ingrese la base del triangulo: "; cin>>base;
				cout<<"ingrese la altura del triangulo: "; cin>>altura;
				cout<<"ingrese el tipo de triangulo: "; cin>>tipo;
				do{
					triangulo t(color, base, altura, tipo);
					cout<<"que desea hacer?: "<<endl;
					cout<<"1. mostrar datos "<<endl;
					cout<<"2. calcular area "<<endl;
					cout<<"0. retroceder "<<endl;
					cin>>m;
					switch (m){
						case 1:
							t.mostrarTriangulo();
							break;
						case 2:
							area=t.calcularArea();
							cout<<"el area del triangulo es: "<<area<<endl;
							break;
					}
				}while (m!=0);
				break;
		}
	}while (n!=0);
	return 0;
}
