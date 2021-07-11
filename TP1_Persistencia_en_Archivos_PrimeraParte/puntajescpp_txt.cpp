#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct t_puntajes {
    string nombre;
    unsigned int puntaje;
    string tiempo;
};

void guardar_puntajes(string nombre_archivo, vector<t_puntajes> puntajes);
void recuperar_puntajes(string nombre_archivo, vector<t_puntajes> &puntajes);
void mostrar_puntajes(vector<t_puntajes> puntajes);

int main() {
    vector<t_puntajes> valores, recuperados;

    valores.push_back({"pepe", 108, "4:16"});
    valores.push_back({"juana", 110, "5:18"});

    guardar_puntajes("puntajes.txt", valores);
    recuperar_puntajes("puntajes.txt", recuperados);
    mostrar_puntajes(recuperados);
        
        
    return 0;
}

void guardar_puntajes(string nombre_archivo, vector<t_puntajes> puntajes) {
    fstream archivo;
    archivo.open(nombre_archivo, ios_base::app);

    for (int i = 0; i < puntajes.size(); i++) 
        archivo << puntajes[i].nombre << " " << puntajes[i].puntaje << " " << puntajes[i].tiempo << endl;
    
    archivo.close();
}

void recuperar_puntajes(string nombre_archivo, vector<t_puntajes> &puntajes) {
    ifstream archivo;
    string linea;
    t_puntajes p;
    int pos = 0;
    archivo.open(nombre_archivo);

    if (archivo.is_open()) {
        getline(archivo, linea);
        while (!archivo.eof()){
            pos = linea.find(" ");
            p.nombre = linea.substr(0, pos);
            linea.erase(0, pos + 1);
            pos = linea.find(" ");
            p.puntaje = stoi(linea.substr(0, pos));
            linea.erase(0, pos + 1);
            p.tiempo = linea.substr(0, linea.length());
            puntajes.push_back(p);
            getline(archivo, linea);
        }
    }
    archivo.close();
}

void mostrar_puntajes(vector <t_puntajes> puntajes) {
    for (int i = 0; puntajes.size(); i++) 
        cout << puntajes[i].nombre << ", " << puntajes[i].puntaje << ", " << puntajes[i].tiempo << endl;
}