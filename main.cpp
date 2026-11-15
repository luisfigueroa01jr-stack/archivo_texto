// Ejercicio 2: Archivo de texto
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "ArchivoTareas.h"

// Modo 1: guarda las tareas base mas las que escriba el usuario
void modoGuardar(const ArchivoTareas& archivo) {
    std::vector<std::string> tareas = {
        "Terminar el reporte de POO",
        "Estudiar para el examen de Calculo Integral",
        "Subir los ejercicios a GitHub",
        "Repasar consultas SQL",
        "Entregar la practica de Redes II"
    };

    std::cout << "Ya hay " << tareas.size() << " tareas base. Escribe tareas extra (linea vacia para terminar):" << std::endl;
    std::string linea;
    while (true) {
        std::cout << "  > ";
        if (!std::getline(std::cin, linea) || linea.empty()) {
            break;
        }
        tareas.push_back(linea);
    }

    archivo.guardar(tareas);
    std::cout << "Se guardaron " << tareas.size() << " tareas en " << archivo.obtenerRuta() << std::endl;
}

// Modo 2: lee el archivo y muestra las tareas numeradas
void modoLeer(const ArchivoTareas& archivo) {
    std::vector<std::string> tareas = archivo.leer();
    if (tareas.empty()) {
        std::cout << "El archivo existe pero no tiene tareas." << std::endl;
        return;
    }
    std::cout << "Tareas pendientes (" << tareas.size() << "):" << std::endl;
    for (std::size_t i = 0; i < tareas.size(); i++) {
        std::cout << "  " << (i + 1) << ". " << tareas[i] << std::endl;
    }
}

int main() {
    std::cout << "=== 2. Archivo de texto ===" << std::endl;
    ArchivoTareas archivo("tareas.txt");

    std::string opcion;
    while (true) {
        std::cout << "\n1) Guardar tareas   2) Leer tareas   3) Salir" << std::endl;
        std::cout << "Opcion: ";
        if (!std::getline(std::cin, opcion) || opcion == "3") {
            break;
        }
        try {
            if (opcion == "1") {
                modoGuardar(archivo);
            } else if (opcion == "2") {
                modoLeer(archivo);
            } else {
                std::cout << "Opcion no valida." << std::endl;
            }
        } catch (const std::runtime_error& e) {
            std::cout << "Error con el archivo: " << e.what() << std::endl;
        }
    }

    std::cout << "Hasta luego." << std::endl;
    return 0;
}
