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
void recuperar_puntajes(string nombre_archivo, vector<t_puntajes> puntajes);
void mostrar_puntajes(vector<t_puntajes> puntajes);

int main() {
    vector<t_puntajes> valores, recuperados;

    valores.push_back({"pepe", 108, "4:16"});
    valores.push_back({"juana", 110, "5:18"});

    guardar_puntajes("puntajes.dat", valores);
    recuperar_puntajes("puntajes.dat", recuperados);
    mostrar_puntajes(recuperados);
        
        
    return 0;
}

void guardar_puntajes(string nombre_archivo, vector<t_puntajes> puntajes) {
    ofstream archivo(nombre_archivo, ios_base::binary);

    for (int i = 0; i < puntajes.size(); i++) 
        archivo.write( (char *) &puntajes[i], sizeof(t_puntajes));
    
    archivo.close();
}

void recuperar_puntajes(string nombre_archivo, vector<t_puntajes> puntajes) {
    ifstream archivo(nombre_archivo, ios_base::binary);
    string linea;
    t_puntajes p;
    int i = 0;
    
    if (archivo.is_open()) {
        archivo.read( (char *) &puntajes[i], sizeof(t_puntajes));
        while (!archivo.eof()) {
            string name = puntajes[i].nombre;
            int score = puntajes[i].puntaje;
            string time = puntajes[i].tiempo;
            i++;
            archivo.read( (char *) &puntajes[i], sizeof(t_puntajes));
        }
    }
    archivo.close();
}

void mostrar_puntajes(vector <t_puntajes> puntajes) {
    for (int i = 0; puntajes.size(); i++) 
        cout << puntajes[i].nombre << ", " << puntajes[i].puntaje << ", " << puntajes[i].tiempo << endl;
}