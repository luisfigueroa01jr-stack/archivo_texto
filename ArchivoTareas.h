// Guarda y lee una lista de tareas en un archivo de texto (una tarea por linea)
#ifndef ARCHIVOTAREAS_H
#define ARCHIVOTAREAS_H

#include <string>
#include <vector>

class ArchivoTareas {
private:
    std::string ruta;

public:
    explicit ArchivoTareas(const std::string& ruta);

    // Sobrescribe el archivo con la lista. Lanza std::runtime_error si no se puede escribir.
    void guardar(const std::vector<std::string>& tareas) const;

    // Regresa las tareas del archivo. Lanza std::runtime_error si no se puede abrir.
    std::vector<std::string> leer() const;

    const std::string& obtenerRuta() const;
};

#endif
