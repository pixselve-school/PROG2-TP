#include "../vecteur.h"

// vérifier la dimension et les valeurs d'un vecteur (utilise get)
void
check_dim_values_with_get(const Vecteur & v, const unsigned int dim, float expected);

// vérifier la dimension et les valeurs d'un vecteur (utilise get)
void
check_dim_values_with_get(const Vecteur & v, const unsigned int dim, float expected[]);

// vérifier l'égalité de deux vecteurs (get)
void
check_vectors_equality(const Vecteur & v1, const Vecteur & v2);

// initialiser un tableau à une valeur initiale + incrément
void
init_array(float v[], const unsigned int dim, float valinit, float inc = 0);

// initialiser un vecteur et un tableau à une valeur initiale + incrément (set)
void
init_vector_and_array(Vecteur & v, float t[], const unsigned int dim,
		      float valinit, float inc = 0);
