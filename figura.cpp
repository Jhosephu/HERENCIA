#include<bits/stdc++.h>

using namespace std;

class figura{
	protected: 
		string color;
	public:
		figura(string);
};

figura::figura(string c){
	color=c;
}

class circulo:public figura{
	private: 
		float radio;
	public:
		circulo(string, float);
		void calcularArea(float);
		void calcularPerimetro(float);
};

circulo::circulo(string c, float r):figura(c){
	radio=r;
}

void circulo::calcularArea(float r){
	float area;
	area=3.14*pow(r,2)
}

void calcularPerimetro(float r){
	float perimetro;
	
}

int main(){
	
	return 0;
}