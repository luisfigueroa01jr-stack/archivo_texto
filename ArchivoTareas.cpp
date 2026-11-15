#include "ArchivoTareas.h"
#include <fstream>
#include <stdexcept>

ArchivoTareas::ArchivoTareas(const std::string& ruta) : ruta(ruta) {}

void ArchivoTareas::guardar(const std::vector<std::string>& tareas) const {
    std::ofstream archivo(ruta);  // modo por defecto: reemplaza el contenido anterior
    if (!archivo.is_open()) {
        throw std::runtime_error("no se pudo abrir \"" + ruta + "\" para escribir");
    }
    for (const std::string& tarea : tareas) {
        archivo << tarea << '\n';
    }
    if (archivo.fail()) {
        throw std::runtime_error("ocurrio un error al escribir en \"" + ruta + "\"");
    }
}   // el archivo se cierra solo al salir de la funcion

std::vector<std::string> ArchivoTareas::leer() const {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        throw std::runtime_error("no se pudo abrir \"" + ruta + "\" (primero usa la opcion de guardar)");
    }
    std::vector<std::string> tareas;
    std::string linea;
    while (std::getline(archivo, linea)) {
        if (!linea.empty() && linea.back() == '\r') {
            linea.pop_back();  // por si el archivo se edito en Windows
        }
        if (!linea.empty()) {
            tareas.push_back(linea);
        }
    }
    return tareas;
}

const std::string& ArchivoTareas::obtenerRuta() const {
    return ruta;
}
