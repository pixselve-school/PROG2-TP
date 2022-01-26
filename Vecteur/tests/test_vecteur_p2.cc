#include <iostream>
#include <sstream>      // std::ostringstream
#include <string>
#include <gtest/gtest.h>
#include "test_common.h" // fonctions cummunes aux deux tests
#include "../vecteur.h"

//------------------------------------------------------------------------
// fonctions utilitaires définies en fin de fichier
//------------------------------------------------------------------------

// vérifier la dimension et les valeurs d'un vecteur (utilise operator [])
void
check_dim_values_with_opr(const Vecteur & v, const unsigned int dim, float expected);

// vérifier la dimension et les valeurs d'un vecteur (utilise operator [])
void
check_dim_values_with_opr(const Vecteur & v, const unsigned int dim, float expected[]);


//========================================================================
// les tests
//========================================================================

// la taille du vecteur modifié diminue
TEST(TestVecteur, q7_OperateurAffectationTailleDiminue)
{
  const unsigned int dim1(15);
  Vecteur v1(dim1);
  float   expected_1[dim1];
  init_vector_and_array(v1, expected_1, dim1, 1, 10);

  const unsigned int dim2(7);
  Vecteur v2(dim2);
  float   expected_2[dim2];
  init_vector_and_array(v2, expected_2, dim2, 100, 5);

  v1 = v2;

  // vérifier v1 et v2
  check_dim_values_with_get(v1, dim2, expected_2);
  check_dim_values_with_get(v2, dim2, expected_2);

  // modifier v1
  float mod1[dim2];
  init_vector_and_array(v1, mod1, dim2, -10, -10);
  check_dim_values_with_get(v1, dim2, mod1);
  check_dim_values_with_get(v2, dim2, expected_2);

  // modifier v2
  float mod2[dim2];
  init_vector_and_array(v2, mod2, dim2, 55, 11);
  check_dim_values_with_get(v1, dim2, mod1);
  check_dim_values_with_get(v2, dim2, mod2);
}

// la taille du vecteur modifié augmente
TEST(TestVecteur, q7_OperateurAffectationTailleAugmente)
{
  const unsigned int dim1(15);
  Vecteur v1(dim1);
  float   expected_1[dim1];
  init_vector_and_array(v1, expected_1, dim1, 1, 10);

  const unsigned int dim2(7);
  Vecteur v2(dim2);
  float   expected_2[dim2];
  init_vector_and_array(v2, expected_2, dim2, 100, 5);

  v2 = v1;

  // vérifier v1 et v2
  check_dim_values_with_get(v1, dim1, expected_1);
  check_dim_values_with_get(v2, dim1, expected_1);

  // modifier v1
  float mod1[dim1];
  init_vector_and_array(v1, mod1, dim1, -10, -10);
  check_dim_values_with_get(v1, dim1, mod1);
  check_dim_values_with_get(v2, dim1, expected_1);

  // modifier v2
  float mod2[dim1];
  init_vector_and_array(v2, mod2, dim1, 55, 11);
  check_dim_values_with_get(v1, dim1, mod1);
  check_dim_values_with_get(v2, dim1, mod2);
}

TEST(TestVecteur, q8_OperateurAdd2vecteurs)
{
  const unsigned int dim1(15);
  Vecteur v1(dim1);
  float   expected_1[dim1];
  init_vector_and_array(v1, expected_1, dim1, 1, 10);

  Vecteur v2(dim1);
  float   expected_2[dim1];
  init_vector_and_array(v2, expected_2, dim1, -5, -5);

  Vecteur v3(v1 + v2);
  float   expected_3[dim1];
  init_array(expected_3, dim1, -4, 5);

  // vérifier si la somme est correcte et si les 2 vecteurs v1 et v2 sont inchangés
  check_dim_values_with_get(v1, dim1, expected_1);
  check_dim_values_with_get(v2, dim1, expected_2);
  check_dim_values_with_get(v3, dim1, expected_3);
}

TEST(TestVecteur, q8_OperateurAdd3vecteurs)
{
  const unsigned int dim1(15);
  Vecteur v1(dim1);
  float   expected_1[dim1];
  init_vector_and_array(v1, expected_1, dim1, 1, 10);

  Vecteur v2(dim1);
  float   expected_2[dim1];
  init_vector_and_array(v2, expected_2, dim1, -5, -5);

  Vecteur v3(dim1);
  float   expected_3[dim1];
  init_vector_and_array(v3, expected_3, dim1, -20, 7);

  Vecteur v4(v1 + v2 + v3);
  float   expected_4[dim1];
  init_array(expected_4, dim1, -24, 12);

  // vérifier si la somme est correcte et si les vecteurs vi sont inchangés
  check_dim_values_with_get(v1, dim1, expected_1);
  check_dim_values_with_get(v2, dim1, expected_2);
  check_dim_values_with_get(v3, dim1, expected_3);
  check_dim_values_with_get(v4, dim1, expected_4);
}

TEST(TestVecteur, q9_ProduitScalaire)
{
  const unsigned int dim1(15);
  Vecteur v1(dim1);
  float   expected_1[dim1];
  init_vector_and_array(v1, expected_1, dim1, 10, 10);

  Vecteur v2(dim1);
  float   expected_2[dim1];
  init_vector_and_array(v2, expected_2, dim1, -5, -5);

  float  ps = v1 * v2;
  float  expected_3 = 0;
  for (unsigned int i = 0; i < dim1; ++i) {
    expected_3 += v1.get(i) * v2.get(i);
  }
  ASSERT_EQ(expected_3, ps);
}

TEST(TestVecteur, q10_OperateurSaisie)
{
  // résultat attendu
  float expected[] = {
    -7, 10, 15, 25.5, 999.99, -111.1, 222.2,
    -333.3, 444.4, -555.5, 666.6, -100, 88.88
  };
  int dim_expected = sizeof(expected)/sizeof(float);
  std::ostringstream expected_stream;
  std::copy(expected, expected + dim_expected,
	    std::ostream_iterator<float>(expected_stream, " "));
  std::istringstream input_stream(expected_stream.str());

  Vecteur v(dim_expected);
  input_stream >> v;
  check_dim_values_with_get(v, dim_expected, expected);
}

#ifndef VALGRIND
TEST(TestVecteur, q11_AssertOperateurIndexationConst)
{
  const unsigned int dim1(15);
  float val1(10);
  Vecteur v1(dim1, val1);
  ASSERT_DEATH(v1[dim1], "Assertion.*failed");
}
#endif

#ifndef VALGRIND
TEST(TestVecteur, q11_AssertOperateurIndexation)
{
  const unsigned int dim1(15);
  float val1(10);
  Vecteur v1(dim1, val1);
  ASSERT_DEATH(v1[dim1] = 3., "Assertion.*failed");
}
#endif

TEST(TestVecteur, q11_OperateurIndexationConsultation)
{
  const unsigned int dim1(15);
  Vecteur v1(dim1);
  float   expected1[dim1];
  init_vector_and_array(v1, expected1, dim1, -555.55, 2.2);
  check_dim_values_with_get(v1, dim1, expected1);
  check_dim_values_with_opr(v1, dim1, expected1);
}

TEST(TestVecteur, q11_OperateurIndexationModification)
{
  const unsigned int dim1(15);
  Vecteur v1(dim1);
  float   expected1[dim1];
  init_vector_and_array(v1, expected1, dim1, -555.55, 2.2);
  check_dim_values_with_get(v1, dim1, expected1);

  // modification du vecteur v1
  float new_expected[dim1];
  for (unsigned int i = 0; i < dim1; ++i) {
    v1[i]	    = expected1[i]   + i;
    new_expected[i] = expected1[i]   + i;
  }
  check_dim_values_with_opr(v1, dim1, new_expected);
  // remise à l'état initial de v1
  for (unsigned int i = 0; i < dim1; ++i) {
    v1[i] = expected1[i];
  }
  check_dim_values_with_opr(v1, dim1, expected1);
}

//------------------------------------------------------------------------
// fonctions utilitaires
//------------------------------------------------------------------------

// vérifier la dimension et les valeurs d'un vecteur (utilise operator [])
void
check_dim_values_with_opr(const Vecteur & v, const unsigned int dim, float expected)
{
  ASSERT_EQ(dim, v.dimensions());
  for (unsigned int i = 0; i < dim; ++i) {
    EXPECT_EQ(expected, v[i]);
  }
}

// vérifier la dimension et les valeurs d'un vecteur (utilise operator [])
void
check_dim_values_with_opr(const Vecteur & v, const unsigned int dim, float expected[])
{
  ASSERT_EQ(dim, v.dimensions());
  for (unsigned int i = 0; i < dim; ++i) {
    EXPECT_EQ(expected[i], v[i]);
  }
}
