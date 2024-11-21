#include<iostream>
#include<string>
using namespace std;

// Clase base Persona ------------------------------
class Persona {
protected:
    string nombres;
    string DNI;
    int edad;
public:
    Persona(string, string, int);
    void mostrarDatos();
};

Persona::Persona(string n, string d, int e) {
    nombres = n;
    DNI = d;
    edad = e;
}

void Persona::mostrarDatos() {
    cout << nombres << " tiene el DNI# " << DNI << " y tiene " << edad;
    cout << " años de edad." << endl;
}

// Clase derivada Docente --------------------------
class Docente : public Persona {
private:
    int sueldo;
    string especialidad;
public:
    Docente(string, string, int, int, string);
    void mostrarDocente();
};

Docente::Docente(string n, string d, int e, int s, string es) : Persona(n, d, e) {
    sueldo = s;
    especialidad = es;
}

void Docente::mostrarDocente() {
    mostrarDatos();
    cout << "Eres un docente con un sueldo de S/ " << sueldo << endl;
    cout << " y tiene la especialidad: " << especialidad << endl;
}

// Clase derivada Estudiante -----------------------
class Estudiante : public Persona {
private:
    int notas[5];
    int nNotas;
    string codigo;
public:
    Estudiante(string, string, int, int[], int, string);
    void mostrarEstudiante();
};

Estudiante::Estudiante(string n, string d, int e, int no[], int nn, string c) : Persona(n, d, e) {
    nNotas = nn;
    for (int i = 0; i < nn; i++) {
        notas[i] = no[i];
    }
    codigo = c;
}

void Estudiante::mostrarEstudiante() {
    mostrarDatos();
    cout << "Eres un estudiante con codigo " << codigo << " y tiene " << nNotas << " notas: ";
    for (int i = 0; i < nNotas; i++) {
        cout << notas[i] << " ";
    }
    cout << endl;
}

int main() {
    string nombre, dni, especialidad, codigo;
    int edad, sueldo, nNotas;

    // Ingreso de datos para Persona
    cout << "Ingrese el nombre de la persona: ";
    getline(cin, nombre);
    cout << "Ingrese el DNI de la persona: ";
    getline(cin, dni);
    cout << "Ingrese la edad de la persona: ";
    cin >> edad;
    Persona p(nombre, dni, edad);
    p.mostrarDatos();
    cout << endl;

    // Ingreso de datos para Docente
    cin.ignore(); // Limpiar el buffer
    cout << "Ingrese el nombre del docente: ";
    getline(cin, nombre);
    cout << "Ingrese el DNI del docente: ";
    getline(cin, dni);
    cout << "Ingrese la edad del docente: ";
    cin >> edad;
    cout << "Ingrese el sueldo del docente: ";
    cin >> sueldo;
    cin.ignore();
    cout << "Ingrese la especialidad del docente: ";
    getline(cin, especialidad);
    Docente d(nombre, dni, edad, sueldo, especialidad);
    d.mostrarDocente();
    cout << endl;

    // Ingreso de datos para Estudiante
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nombre);
    cout << "Ingrese el DNI del estudiante: ";
    getline(cin, dni);
    cout << "Ingrese la edad del estudiante: ";
    cin >> edad;
    cout << "Ingrese el codigo del estudiante: ";
    cin >> codigo;
    cout << "Ingrese el numero de notas del estudiante (máximo 5): ";
    cin >> nNotas;
    int notas[5];
    for (int i = 0; i < nNotas; i++) {
        cout << "Ingrese la nota " << (i + 1) << ": ";
        cin >> notas[i];
    }
    Estudiante e(nombre, dni, edad, notas, nNotas, codigo);
    e.mostrarEstudiante();
    cout << endl;

    return 0;
}

