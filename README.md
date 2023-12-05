<br/>
<h1 align="center">PUSH SWAP</h1>
<p align="center">
 <img tyle="display: block;-webkit-user-select: none;margin: auto;background-color: hsl(0, 0%, 90%);transition: background-color 300ms;" src="https://i.ibb.co/nD8zBHq/MAlLAGA2.gif" height=50% width=50%>
</p>

 <p align="center">
    Push_swap es un programa desarrollado en el marco del currículo de la escuela 42 que resuelve un desafiante problema de ordenamiento utilizando dos pilas y un conjunto limitado de operaciones, desafiando las habilidades de optimización y algoritmos de sus desarrolladores.
    <br/>
    <br/>
  </p>
</p>

## Contenido

* Sobre el proyecto
* Cómo usar
  * Compilación
* Uso
* Autor

## Sobre el proyecto

Push_swap es un programa diseñado para ordenar una pila de números enteros en orden ascendente utilizando dos pilas auxiliares y un conjunto limitado de operaciones. El objetivo es minimizar la cantidad de movimientos necesarios para ordenar la pila inicial. Este proyecto desafía las habilidades de optimización y el diseño de algoritmos de los desarrolladores, ya que deben encontrar la secuencia óptima de operaciones para ordenar eficientemente la pila.

### Características principales
 * Ordenamiento eficiente: Push_swap implementa algoritmos que buscan la solución óptima para ordenar la pila en el menor número de movimientos posible, utilizando un conjunto restringido de operaciones (swap, push y rotate).

 * Dos pilas: El programa trabaja con dos pilas, A y B, y emplea operaciones específicas para ordenar los números en la pila A mientras se utiliza la pila B como auxiliar.

 * Minimización de movimientos: El desafío radica en encontrar una secuencia de operaciones que minimice la cantidad de movimientos necesarios para ordenar la pila de manera eficiente.

### Gestión de recursos y optimización

 * Eficiencia en el uso de operaciones: Se busca optimizar el número de operaciones utilizadas para ordenar la pila, implementando algoritmos eficientes y estrategias de optimización.
 * Gestión de recursos: El proyecto busca una gestión eficiente de la memoria y recursos del sistema para garantizar un funcionamiento adecuado y prevenir posibles fugas de memoria.


## Cómo usar

### Compilación
Ejecuta los siguientes comandos:

* Para compilar
```bash
make
```
* Para eliminar objetos:
```bash
make clean
```
* Para eliminar objetos y archivos binarios (programa):
```bash
make fclean
```
* Para recompilar:
```bash
make re
```
Este comando generará un archivo ejecutable get_next_line, al cual pasarle un archivo de texto para comprobarlo.

## Guía de uso de Push_swap

### Instalación
1. Clona el repositorio o descarga los archivos necesarios para el proyecto.
2. Compila el programa utilizando el comando make.
### Ejecución
El ejecutable se llama `push_swap´.
### Sintaxis
```bash
./push_swap 4 67 2 8 43
```
### Ejemplo de uso
```bash
./push_swap 4 67 84 51
```
### Resultado
El programa imprimirá en la salida estándar la secuencia de operaciones necesarias para ordenar la lista de números proporcionada. Esta secuencia de operaciones es optimizada para minimizar el número de movimientos requeridos.

### Verificación del ordenamiento
Para verificar que la secuencia de operaciones generada ordena correctamente la lista, puedes usar el programa checker.
### Uso del checker
El ejecutable para verificar el ordenamiento se llama checker. La sintaxis para ejecutar checker es la siguiente:

```bash
./checker [lista de números] | ./push_swap [lista de operaciones]
```
Por ejemplo:

```bash
./checker 4 67 2 8 43 | ./push_swap 4 67 2 8 43
```
### Resultado del checker
 * Si la lista está ordenada correctamente, checker mostrará OK.
 * Si la lista no está ordenada correctamente, checker mostrará KO.
   
## Autor

* **Juan Guerrero** - *@juguerre - 42Málaga* - [Juan Guerrero](https://github.com/Folkenciyo/)

### ¿Puedes agregar más funciones a esta biblioteca? ¿Cómo?
* Haz un fork de este repositorio
* Clona tu fork del repositorio
* Contribuye
* Realiza un push
* Crea una solicitud de extracción (pull request) en este repositorio
* ¡Espera a que se fusionen los cambios!
 ¡Sé feliz! :)
---
## 🔗 Links
[![portfolio](https://img.shields.io/badge/portfolio-002?style=for-the-badge&logo=ko-fi&logoColor=white)](https://porfolio-juan-guerrero.vercel.app/)
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/juanguerrerodeveloper/)
[![twitter](https://img.shields.io/badge/twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white)](https://twitter.com/JuanAGuerreroP1)

