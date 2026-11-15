# Ejercicio 2: Archivo de texto
Guarda una lista de tareas pendientes en `tareas.txt` y, en otro modo, las lee y las muestra numeradas. Las tareas siguen ahi aunque se cierre el programa.

**Archivos:** `ArchivoTareas.h/.cpp` (`guardar` con `std::ofstream`, `leer` con `std::ifstream`) · `main.cpp` (menu con los dos modos)

- **Compilar:** `g++ -std=c++17 -Wall *.cpp -o programa.exe`
- **Ejecutar:** `./programa.exe`

```
1) Guardar tareas   2) Leer tareas   3) Salir
Opcion: 2
Tareas pendientes (6):
  1. Terminar el reporte de POO
  2. Estudiar para el examen de Calculo Integral
  ...
```

**Tema de la unidad:** persistencia en archivos de texto con flujos (`fstream`) y aviso con `std::runtime_error` cuando el archivo no se puede abrir.
