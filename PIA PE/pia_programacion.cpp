#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

struct alumno {
    string matriula;
    int parciales[7];
}alumnos[29];

float sacarPromedioAlumno(struct alumno alumno) {
    float promedio = 0;
    for(int j = 0; j < 7; j++) {
        promedio = promedio + alumno.parciales[j]; 
    }
    promedio = promedio / 7;
    return round(promedio);
}

int parcialesNoAprobados(struct alumno alumno) {
    int reprobados = 0;
    for(int j = 0; j < 7; j++) {
        if (alumno.parciales[j] < 70) {
            reprobados++;
        }
    }
    return reprobados;
}

int alumnosReprobadosPorParcial(alumno alumnos[], int parcial) {
    parcial = parcial - 1;
    int res = 0;
    int reprobados = 0;
    for(int j = 0; j < 29; j++) {
        res = alumnos[j].parciales[parcial];
        if (res < 70) {
            reprobados++;
        }
    }
    return reprobados;
}

float sacarPromedioPorParcial(alumno alumnos[], int parcial) {
    parcial = parcial - 1;
    float promedio = 0;
    for(int j = 0; j < 29; j++) {
        promedio = promedio + alumnos[j].parciales[parcial]; 
    }
    return round(promedio / 29);
}

float sacarPromedioGrupo(alumno alumnos[]) {
    float promedio = 0;
    int suma = 0;
    int promAux = 0;
    for(int j = 0; j < 29; j++) {
        suma = alumnos[j].parciales[0] + 
                alumnos[j].parciales[1] + 
                alumnos[j].parciales[2] + 
                alumnos[j].parciales[3] + 
                alumnos[j].parciales[4] + 
                alumnos[j].parciales[5] + 
                alumnos[j].parciales[6]; 
        promAux = suma / 7;
        promedio = promedio + promAux;
    }
    return round(promedio / 29);
}

int alumnosReprobadosEnLaMateria(alumno alumnos[]) {
    float promedio = 0;
    int reprobados = 0;
    for(int j = 0; j < 29; j++) {
        promedio = alumnos[j].parciales[0] + 
                    alumnos[j].parciales[1] + 
                    alumnos[j].parciales[2] + 
                    alumnos[j].parciales[3] + 
                    alumnos[j].parciales[4] + 
                    alumnos[j].parciales[5] + 
                    alumnos[j].parciales[6];
        promedio = promedio / 7; 
        if (round(promedio) < 70) {
            reprobados++;
        }
    }
    return reprobados;
}

int main(){

    ifstream file("calificaciones_pia_pe.csv");
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return 0;
    }

    string line;
    int i = 0;
    getline(file, line);
    while (getline(file, line))
    {
        istringstream iss(line);
        string value;
        getline(iss, value, ',');
        alumnos[i].matriula = value;
        getline(iss, value, ',');
        istringstream(value) >> alumnos[i].parciales[0];
        getline(iss, value, ',');
        istringstream(value) >> alumnos[i].parciales[1];
        getline(iss, value, ',');
        istringstream(value) >> alumnos[i].parciales[2];
        getline(iss, value, ',');
        istringstream(value) >> alumnos[i].parciales[3];
        getline(iss, value, ',');
        istringstream(value) >> alumnos[i].parciales[4];
        getline(iss, value, ',');
        istringstream(value) >> alumnos[i].parciales[5];
        getline(iss, value, ',');
        istringstream(value) >> alumnos[i].parciales[6];
        
        i++;
        cout << endl;
    }

    ofstream tabla;
    tabla.open ("tabla de calificaciones.csv");
    tabla << "Matricula,Parcial1,Parcial2,Parcial3,Parcial4,Parcial5,Parcial6,Parcial7,Promedio de calificaciones parciales,No Aprobados\n";
    for(int j = 0; j < i; j++) {
        tabla << "'" << alumnos[j].matriula.substr( alumnos[j].matriula.length() - 4 ) << "," << alumnos[j].parciales[0] << "," << alumnos[j].parciales[1] << "," << alumnos[j].parciales[2] << "," << alumnos[j].parciales[3] << "," << alumnos[j].parciales[4] << "," << alumnos[j].parciales[5] << "," << alumnos[j].parciales[6] << "," << sacarPromedioAlumno(alumnos[j]) << "," << parcialesNoAprobados(alumnos[j]);
        tabla << endl;
    }
    tabla << "Promedios" << "," << sacarPromedioPorParcial(alumnos, 1)  << "," << sacarPromedioPorParcial(alumnos, 2) << "," << sacarPromedioPorParcial(alumnos, 3) << "," << sacarPromedioPorParcial(alumnos, 4) << "," << sacarPromedioPorParcial(alumnos, 5) << "," << sacarPromedioPorParcial(alumnos, 6) << "," << sacarPromedioPorParcial(alumnos, 7) << "," << sacarPromedioGrupo(alumnos);
    tabla << endl;
    tabla << "No aprobados" << "," << alumnosReprobadosPorParcial(alumnos, 1) << "," << alumnosReprobadosPorParcial(alumnos, 2) << "," << alumnosReprobadosPorParcial(alumnos, 3) << "," << alumnosReprobadosPorParcial(alumnos, 4) << "," << alumnosReprobadosPorParcial(alumnos, 5) << "," << alumnosReprobadosPorParcial(alumnos, 6) << "," << alumnosReprobadosPorParcial(alumnos, 7) << "," << alumnosReprobadosEnLaMateria(alumnos);
    tabla.close();
    return 0;


    file.close();
}

