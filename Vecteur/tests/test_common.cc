#include <iostream>
#include <sstream>      // std::ostringstream
#include <string>
#include <gtest/gtest.h>
#include "../vecteur.h"
#include "test_common.h"

//------------------------------------------------------------------------
// fonctions utilitaires communes aux tests
//------------------------------------------------------------------------

// vérifier la dimension et les valeurs d'un vecteur (utilise get)
void
check_dim_values_with_get(const Vecteur & v, const unsigned int dim, float expected)
{
  ASSERT_EQ(dim, v.dimensions());
  for (unsigned int i = 0; i < dim; ++i) {
    EXPECT_EQ(expected, v.get(i));
  }
}

// vérifier la dimension et les valeurs d'un vecteur (utilise get)
void
check_dim_values_with_get(const Vecteur & v, const unsigned int dim, float expected[])
{
  ASSERT_EQ(dim, v.dimensions());
  for (unsigned int i = 0; i < dim; ++i) {
    EXPECT_EQ(expected[i], v.get(i));
  }
}

// vérifier l'égalité de deux vecteurs (get)
void
check_vectors_equality(const Vecteur & v1, const Vecteur & v2)
{
  ASSERT_EQ(v1.dimensions(), v2.dimensions());
  for (unsigned int i = 0; i < v1.dimensions(); ++i) {
    EXPECT_EQ(v1.get(i), v2.get(i));
  }
}

// initialiser un tableau à une valeur initiale + incrément
void
init_array(float v[], const unsigned int dim, float valinit, float inc)
{
  float vc = valinit;
  for (unsigned int i = 0; i < dim; ++i) {
    v[i] = vc; vc += inc;
  }
}

// initialiser un vecteur et un tableau à une valeur initiale + incrément (set)
void
init_vector_and_array(Vecteur & v, float t[], const unsigned int dim,
		      float valinit, float inc)
{
  float vc = valinit;
  for (unsigned int i = 0; i < dim; ++i) {
    v.set(i, vc); t[i] = vc; vc += inc;
  }
}
