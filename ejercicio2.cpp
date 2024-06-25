
#include <iostream> 
#include <fstream> 
#include <sstream> 
 
using namespace std; 
 
double calcularMedia(double *datos, int n) 
{ 
    double suma = 0.0; 
    for (int i = 0; i < n; ++i) 
    { 
        suma += datos[i]; 
    } 
    return suma / n; 
} 
 
double calcularMediaRecortada(double *datos, int n, double p)
{ 
    int k = static_cast<int>(n * p / 100.0); //static_cast: Convierte una expresión al tipo de type-id, basándose únicamente en los tipos que se encuentran en la expresión.
 
    k = min(k, n / 2); 
 
    double suma = 0.0; 
    for (int i = k; i < n - k; ++i) 
    { 
        suma += datos[i]; 
    } 
    return suma / (n - 2 * k); 
} 
 
int main() 
{ 
    const int MAX_DATOS = 70; 
    double datos[MAX_DATOS]; 
    int contador = 0; 
 
    ifstream archivo("dataExamen2_2.csv"); 
    if (!archivo.is_open()) 
    { 
        cerr << "Error al abrir el archivo.\n"; 
        return 1; 
    } 
 
    string linea; 
    while (getline(archivo, linea)) 
    { 
        istringstream ss(linea); 
        string valor; 
        while (getline(ss, valor, ',')) 
        { 
            datos[contador++] = stod(valor); 
        } 
    } 
 
    archivo.close(); 
 
    double media = calcularMedia(datos, contador); 
    cout << "Media de los datos: " << media << endl; 
 
    double porcentajes[] = {5.0, 10.0, 25.0, 75.0}; 
    for (double p : porcentajes) 
    { 
        double media_recortada = calcularMediaRecortada(datos, contador, p); 
        cout << "Media recortada al " << p << "%: " << media_recortada << endl; 
    } 
 
    return 0; 
}