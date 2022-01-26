#include <iostream>
#include <sstream>	  // std::ostringstream
#include <string>
#include <gtest/gtest.h>
#include "test_common.h" // fonctions communes aux deux tests
#include "../vecteur.h"

//========================================================================
// les tests
//========================================================================

//------------------------------------------------------------------------
// Question 1
//------------------------------------------------------------------------

#ifndef VALGRIND
// test assertion constructeur
TEST(TestVecteur, q1_assertConstructeur)
{
  ASSERT_DEATH(Vecteur v1(0, 5.), "Assertion.*failed");
}
#endif

// test constructeur à 2 paramètres
// vérifier dimension et valeurs
// méthodes utilisées : 
// - constructeur à 2 paramètres
// - dimensions
// - get
TEST(TestVecteur, q1_Constructeur2Param)
{
  const unsigned int dim1(15);
  float val1(10);
  Vecteur v1(dim1, val1);
  check_dim_values_with_get(v1, dim1, val1);
}

// vérifier dimension et valeurs
// méthodes utilisées : 
// - constructeur à 1 paramètre
// - dimensions
// - get
TEST(TestVecteur, q1_Constructeur1Param)
{
  const unsigned int dim1(15);
  Vecteur v1(dim1);
  check_dim_values_with_get(v1, dim1, 0.);
}

TEST(TestVecteur, q1_Constructeur0Param)
{
  const unsigned int dim1(3);
  Vecteur v1;
  check_dim_values_with_get(v1, dim1, 0.);
}

#ifndef VALGRIND
// test assertion get
TEST(TestVecteur, q1_assertGet)
{
  const unsigned int dim1(15);
  float val1(10);
  Vecteur v1(dim1, val1);
  ASSERT_DEATH(v1.get(dim1), "Assertion.*failed");
}
#endif

#ifndef VALGRIND
TEST(TestVecteur, q1_assertSet)
{
  const unsigned int dim1(15);
  float val1(10);
  Vecteur v1(dim1, val1);
  ASSERT_DEATH(v1.set(dim1, -999.), "Assertion.*failed");
}
#endif

TEST(TestVecteur, q1_Set)
{
  const unsigned int dim1(15);
  float val1(10);
  Vecteur v1(dim1, val1);
  float expected[dim1];

  // modification du vecteur v1
  init_vector_and_array(v1, expected, dim1, val1, 1);
  // vérifier les valeurs
  check_dim_values_with_get(v1, dim1, expected);
}

//------------------------------------------------------------------------
// Question 2
//------------------------------------------------------------------------
/*
TEST(TestVecteur, q2_Affichervecteur)
{
  const unsigned int dim1(15);
  Vecteur v1(dim1, 1);
  float   expected[dim1];
  init_vector_and_array(v1, expected, dim1, 1, 10);

  // "afficher" le vecteur dans un ostringstream
  std::ostringstream vecteur_stream;
  afficherVecteur(& v1, vecteur_stream);

  // "afficher" le tableau dans un ostringstream
  // séparateur de valeurs : un espace
  std::ostringstream expected_stream;
  std::copy(expected, expected + dim1,
	    std::ostream_iterator<float>(expected_stream, " "));

  // comparer les deux
  ASSERT_EQ(vecteur_stream.str(), expected_stream.str());
}
*/
TEST(TestVecteur, q2_Lirevecteur)
{
  // résultat attendu
  float expected[] = {
    -7, 10, 15, 25.5, 999.99, -111.1, 222.2,
    -333.3, 444.4, -555.5, 666.6, -100, 88.88
  };
  int dim_expected = sizeof(expected)/sizeof(float);
  std::ostringstream expected_stream;
  expected_stream << dim_expected << " ";
  std::copy(expected, expected + dim_expected,
	    std::ostream_iterator<float>(expected_stream, " "));
  std::istringstream input_stream(expected_stream.str());
  Vecteur * v1 = lireVecteur(input_stream);
  check_dim_values_with_get(*v1, dim_expected, expected);
  delete v1;
}

//------------------------------------------------------------------------
// Question 4
//------------------------------------------------------------------------

// utilise le cdc
TEST(TestVecteur, q4_Add)
{
  const unsigned int dim1(15);
  Vecteur v1(dim1, 1);
  float   exp1[dim1];
  init_vector_and_array(v1, exp1, dim1, 1, 10);
  Vecteur v2(dim1);
  float   exp2[dim1];
  init_vector_and_array(v2, exp2, dim1, 100, 5);
  Vecteur v3(add(& v1, & v2));
  float   exp3[dim1];
  init_array(exp3, dim1, 101, 15);

  // vérifier si la somme est correcte et si les 2 vecteurs v1 et v2 sont inchangés
  check_dim_values_with_get(v1, dim1, exp1);
  check_dim_values_with_get(v2, dim1, exp2);
  check_dim_values_with_get(v3, dim1, exp3);
}

//------------------------------------------------------------------------
// Question 6
//------------------------------------------------------------------------

TEST(TestVecteur, q6_ConstructeurDeCopie)
{
  const unsigned int dim1(15);
  Vecteur v1(dim1, 1);
  float   expected1[dim1];
  init_vector_and_array(v1, expected1, dim1, 1, 10);
  {
    // faire une copie de m_v1
    Vecteur copie(v1);
    check_vectors_equality(v1, copie);
  }
  // vérifier si le vecteur v1 est toujours "en bon état"
  check_dim_values_with_get(v1, dim1, expected1);
}

TEST(TestVecteur, q6_ConstructeurDeCopieModif)
{
  const unsigned int dim1(15);
  float   valinit1(10);
  Vecteur v1(dim1, 1);
  float   expected1[dim1];
  init_vector_and_array(v1, expected1, dim1, 1, 10);

  {
    // faire une copie de v1
    Vecteur copie(v1);
    check_vectors_equality(v1, copie);
    // modifier la copie
    float new_expected[dim1];
    init_vector_and_array(copie, new_expected, dim1, valinit1, 7);
    // vérifier si la copie est correctement modifiée
    check_dim_values_with_get(copie, dim1, new_expected);
    // vérifier si l'original demeure inchangé
    check_dim_values_with_get(v1, dim1, expected1);
  }
  // vérifier si le vecteur v1 est toujours "en bon état"
  check_dim_values_with_get(v1, dim1, expected1);
}
