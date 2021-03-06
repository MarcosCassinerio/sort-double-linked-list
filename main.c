#include <stdio.h>
#include <stdlib.h>
#include "./GList/glist.h"
#include "./Persona/persona.h"

int main(int argc, char *argv[]) {
  GList lista = glist_create();
  Persona *persona;
  int edad;
  char bufferNombre[MAX_NOMBRE], bufferLugarNacimiento[MAX_LUGAR_NACIMIENTO];
  FILE *personasFile;

  if (argc != 2) {
    printf("Cantidad de argumentos invalida\n");
    return 1;
  }

  personasFile = fopen(argv[1], "r");

  while (fscanf
         (personasFile, "%[^,], %d, %[^\n]", bufferNombre, &edad,
          bufferLugarNacimiento) != EOF) {
    fgetc(personasFile);
    persona = persona_crear(bufferNombre, edad, bufferLugarNacimiento);
    lista = glist_insert_last_position(lista, persona);
  }
  fclose(personasFile);

  glist_test_sort_algorithm("selection_sort_edad", lista, glist_selection_sort,
                            persona_compara_edad, persona_imprimir_archivo);
  glist_test_sort_algorithm("selection_sort_largo_nombre", lista,
                            glist_selection_sort, persona_compara_largo_nombre,
                            persona_imprimir_archivo);
  glist_test_sort_algorithm("insertion_sort_edad", lista, glist_insertion_sort,
                            persona_compara_edad, persona_imprimir_archivo);
  glist_test_sort_algorithm("insertion_sort_largo_nombre", lista,
                            glist_insertion_sort, persona_compara_largo_nombre,
                            persona_imprimir_archivo);
  glist_test_sort_algorithm("merge_sort_edad", lista, glist_merge_sort,
                            persona_compara_edad, persona_imprimir_archivo);
  glist_test_sort_algorithm("merge_sort_largo_nombre", lista, glist_merge_sort,
                            persona_compara_largo_nombre,
                            persona_imprimir_archivo);

  glist_destroy(lista, persona_destruir);

  return 0;
}
