#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <cmath> 
#include <iomanip> 
 
using namespace std; 
 

struct Triangulo { 
    double lado_a; 
    double lado_b; 
    double lado_c; 
}; 
 
 
bool esTriangulo(double a, double b, double c) { 
    return (a + b > c) && (a + c > b) && (b + c > a); 
} 
 

double calcularPerimetro(double a, double b, double c) { 
    return a + b + c; 
} 
 
 
string clasificarPorLados(double a, double b, double c) { 
    if (a == b && b == c) { 
        return "Equilatero"; 
    } else if (a == b || b == c || a == c) { 
        return "Isosceles"; 
    } else { 
        return "Escaleno"; 
    } 
} 
 
// Función para calcular el ángulo en radianes usando el teorema del coseno 
double calcularAnguloTeoremaCoseno(double a, double b, double c) { 
    return acos((b*b + c*c - a*a) / (2*b*c)); 
} 
 
// Función para calcular el ángulo en radianes usando la ley del seno 
double calcularAnguloLeySeno(double a, double b, double anguloB) { 
    return asin((a * sin(anguloB)) / b); 
} 
 
// Función para leer datos desde el archivo CSV 
void leerCSV(const string& nombreArchivo) { 
    ifstream archivo(nombreArchivo); 
    string linea; 
 
    while (getline(archivo, linea)) { 
        stringstream ss(linea); 
        string lado_a, lado_b, lado_c; 
 
        if (getline(ss, lado_a, ',') && 
            getline(ss, lado_b, ',') && 
            getline(ss, lado_c, ',')) { 
             
            double a, b, c; 
            istringstream(lado_a) >> a; 
            istringstream(lado_b) >> b; 
            istringstream(lado_c) >> c; 
 
             
            if (ss.fail()) { 
                cerr << "Error al convertir los datos en la linea: " << linea << endl; 
                continue; 
            } 
 
            cout << fixed << setprecision(2); 
            cout << "Lados: a = " << a << ", b = " << b << ", c = " << c << endl; 
 
            if (esTriangulo(a, b, c)) { 
                cout << "Es un triangulo valido." << endl; 
                double perimetro = calcularPerimetro(a, b, c); 
                cout << "Perimetro: " << perimetro << endl; 
 
                string clasificacion = clasificarPorLados(a, b, c); 
                cout << "Clasificacion por lados: " << clasificacion << endl; 
 
                double anguloA = calcularAnguloTeoremaCoseno(a, b, c); 
                double anguloB = calcularAnguloTeoremaCoseno(b, a, c); 
                double anguloC = calcularAnguloTeoremaCoseno(c, a, b); 
 
                cout << "Angulos en radianes: A = " << anguloA << ", B = " << anguloB << ", C = " << anguloC << endl; 
 
                double anguloC_leySeno = calcularAnguloLeySeno(c, b, anguloB); 
                cout << "Angulo C (Ley del Seno) en radianes: " << anguloC_leySeno << endl; 
            } else { 
                cout << "No es un triangulo valido." << endl; 
            } 
 
            cout << "---------------------------------" << endl; 
        } else { 
            cerr << "Error al leer la linea del archivo." << endl; 
        } 
    } 
 
    archivo.close(); 
} 
 
int main() { 
    leerCSV("dataExamen2_1.csv"); 
 
    return 0; 
}