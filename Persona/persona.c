#include "persona.h"
#include <stdio.h>
#include <stdlib.h>

void persona_destruir(void* dato) {
  Persona* persona = (Persona*) dato;
  free(persona->nombre);
  free(persona->lugarDeNacimiento);
  free(persona);
}

Persona* persona_crear(char* nombre, int edad, char* lugarDeNacimiento) {
  Persona* persona = (Persona*) malloc(sizeof(Persona));
  persona->nombre = (char*) malloc(sizeof(char)*(strlen(nombre)+1));
  strcpy(persona->nombre, nombre);
  persona->edad = edad;
  persona->lugarDeNacimiento = (char*) malloc(sizeof(char)*(strlen(lugarDeNacimiento)+1));
  strcpy(persona->lugarDeNacimiento, lugarDeNacimiento);
  return persona;
}

int persona_compara_edad(void* dato1, void* dato2) {
  Persona* persona1 = (Persona*) dato1;
  Persona* persona2 = (Persona*) dato2;
  return persona1->edad - persona2->edad;
}

int persona_compara_nombre(void* dato1, void* dato2) {
  Persona* persona1 = (Persona*) dato1;
  Persona* persona2 = (Persona*) dato2;
  return strcmp(persona1->nombre, persona2->nombre);
}

int persona_compara_lugar_nacimiento(void* dato1, void* dato2) {
  Persona* persona1 = (Persona*) dato1;
  Persona* persona2 = (Persona*) dato2;
  return strcmp(persona1->lugarDeNacimiento, persona2->lugarDeNacimiento);
}

void persona_imprimir_archivo(FILE* archivo, void* dato) {
  Persona* persona = (Persona*) dato;
  fprintf(archivo, "%s, %d, %s\n", persona->nombre, persona->edad, persona->lugarDeNacimiento);
}