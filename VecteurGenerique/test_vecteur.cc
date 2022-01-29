#include <gtest/gtest.h>
#include "vecteur.h"
#include "test_common.hh"

//------------------------------------------------------------------------
// test du produit scalaire : commenter plus bas selon ce qu'on veut tester
//	- Q9  ou
//	- Q12 ou
//	- Q14
//------------------------------------------------------------------------

#ifndef VALGRIND
// test assertion constructeur
TEST(TestVecteur, q1_assertConstructeur)
{
  ASSERT_DEATH(Vecteur<float> v1(0, 5.), "Assertion.*failed");
}
#endif

TEST(TestVecteur, q1_Constructeur2Param)
{
  unsigned int dim1(15);
  float val1(10);
  Vecteur<float> v1(dim1, val1);
  check_dim_values_with_opr(v1, dim1, val1);
}

TEST(TestVecteur, q1_Constructeur1Param)
{
  unsigned int dim1(15);
  Vecteur<float> v1(dim1);
  check_dim_values_with_opr(v1, dim1, 0.f);
}

TEST(TestVecteur, q1_Constructeur0Param)
{
  unsigned int dim1(3);
  Vecteur<float> v1;
  check_dim_values_with_opr(v1, dim1, 0.f);
}

TEST(TestVecteur, q1_Set)
{
  unsigned int dim1(15);
  float val1(10);
  Vecteur<float> v1(dim1, val1);
  float expected[dim1];

  // modification du vecteur v1
  init_vector_and_array(v1, expected, dim1, val1, 1.F);
  // vérifier les valeurs
  check_dim_values_with_opr(v1, dim1, expected);
}

TEST(TestVecteur, q6_ConstructeurDeCopie)
{
  unsigned int dim1(15);
  Vecteur<float> v1(dim1, 1);
  float   expected1[dim1];
  init_vector_and_array(v1, expected1, dim1, 1.F, 10.F);
  {
    // faire une copie de m_v1
    Vecteur<float> copie(v1);
    check_vectors_equality(v1, copie);
  }
  // vérifier si le vecteur v1 est toujours "en bon état"
  check_dim_values_with_opr(v1, dim1, expected1);
}

TEST(TestVecteur, q6_ConstructeurDeCopieModif)
{
  unsigned int dim1(15);
  float   valinit1(10);
  Vecteur<float> v1(dim1, 1);
  float   expected1[dim1];
  init_vector_and_array(v1, expected1, dim1, 1.F, 10.F);

  {
    // faire une copie de v1
    Vecteur<float> copie(v1);
    check_vectors_equality(v1, copie);
    // modifier la copie
    float new_expected[dim1];
    init_vector_and_array(copie, new_expected, dim1, valinit1, 7.F);
    // vérifier si la copie est correctement modifiée
    check_dim_values_with_opr(copie, dim1, new_expected);
    // vérifier si l'original demeure inchangé
    check_dim_values_with_opr(v1, dim1, expected1);
  }
  // vérifier si le vecteur v1 est toujours "en bon état"
  check_dim_values_with_opr(v1, dim1, expected1);
}

  // la taille du vecteur modifié diminue
TEST(TestVecteur, q7_OperateurAffectationTailleDiminue)
{
  unsigned int dim1(15);
  Vecteur<float> v1(dim1);
  float   expected_1[dim1];
  init_vector_and_array(v1, expected_1, dim1, 1.F, 10.F);

  unsigned int dim2(7);
  Vecteur<float> v2(dim2);
  float   expected_2[dim2];
  init_vector_and_array(v2, expected_2, dim2, 100.F, 5.F);

  v1 = v2;

  // vérifier v1 et v2
  check_dim_values_with_opr(v1, dim2, expected_2);
  check_dim_values_with_opr(v2, dim2, expected_2);

  // modifier v1
  float mod1[dim2];
  init_vector_and_array(v1, mod1, dim2, -10.F, -10.F);
  check_dim_values_with_opr(v1, dim2, mod1);
  check_dim_values_with_opr(v2, dim2, expected_2);

  // modifier v2
  float mod2[dim2];
  init_vector_and_array(v2, mod2, dim2, 55.F, 11.F);
  check_dim_values_with_opr(v1, dim2, mod1);
  check_dim_values_with_opr(v2, dim2, mod2);
}

// la taille du vecteur modifié augmente
TEST(TestVecteur, q7_OperateurAffectationTailleAugmente)
{
  unsigned int dim1(15);
  Vecteur<float> v1(dim1);
  float   expected_1[dim1];
  init_vector_and_array(v1, expected_1, dim1, 1.F, 10.F);

  unsigned int dim2(7);
  Vecteur<float> v2(dim2);
  float   expected_2[dim2];
  init_vector_and_array(v2, expected_2, dim2, 100.F, 5.F);

  v2 = v1;

  // vérifier v1 et v2
  check_dim_values_with_opr(v1, dim1, expected_1);
  check_dim_values_with_opr(v2, dim1, expected_1);

  // modifier v1
  float mod1[dim1];
  init_vector_and_array(v1, mod1, dim1, -10.F, -10.F);
  check_dim_values_with_opr(v1, dim1, mod1);
  check_dim_values_with_opr(v2, dim1, expected_1);

  // modifier v2
  float mod2[dim1];
  init_vector_and_array(v2, mod2, dim1, 55.F, 11.F);
  check_dim_values_with_opr(v1, dim1, mod1);
  check_dim_values_with_opr(v2, dim1, mod2);
}

TEST(TestVecteur, q8_OperateurAdd2Vecteurs)
{
  unsigned int dim1(15);
  Vecteur<float> v1(dim1);
  float   expected_1[dim1];
  init_vector_and_array(v1, expected_1, dim1, 1.F, 10.F);

  Vecteur<float> v2(dim1);
  float   expected_2[dim1];
  init_vector_and_array(v2, expected_2, dim1, -5.F, -5.F);

  Vecteur<float> v3(v1 + v2);
  float   expected_3[dim1];
  init_array(expected_3, dim1, -4.F, 5.F);

  // vérifier si la somme est correcte et si les 2 vecteurs v1 et v2 sont inchangés
  check_dim_values_with_opr(v1, dim1, expected_1);
  check_dim_values_with_opr(v2, dim1, expected_2);
  check_dim_values_with_opr(v3, dim1, expected_3);
}

TEST(TestVecteur, q8_OperateurAdd3Vecteurs)
{
  unsigned int dim1(15);
  Vecteur<float> v1(dim1);
  float   expected_1[dim1];
  init_vector_and_array(v1, expected_1, dim1, 1.F, 10.F);

  Vecteur<float> v2(dim1);
  float   expected_2[dim1];
  init_vector_and_array(v2, expected_2, dim1, -5.F, -5.F);

  Vecteur<float> v3(dim1);
  float   expected_3[dim1];
  init_vector_and_array(v3, expected_3, dim1, -20.F, 7.F);

  Vecteur<float> v4(v1 + v2 + v3);
  float   expected_4[dim1];
  init_array(expected_4, dim1, -24.F, 12.F);

  // vérifier si la somme est correcte et si les vecteurs vi sont inchangés
  check_dim_values_with_opr(v1, dim1, expected_1);
  check_dim_values_with_opr(v2, dim1, expected_2);
  check_dim_values_with_opr(v3, dim1, expected_3);
  check_dim_values_with_opr(v4, dim1, expected_4);
}

// produit scalaire "simple" : deux vecteurs de même type
TEST(TestVecteur, q9_ProduitScalaire)
{
  unsigned int dim1(15);
  Vecteur<float> v1(dim1);
  float   expected_1[dim1];
  init_vector_and_array(v1, expected_1, dim1, 10.F, 10.F);

  Vecteur<float> v2(dim1);
  float   expected_2[dim1];
  init_vector_and_array(v2, expected_2, dim1, -5.F, -5.F);

  float  ps = v1 * v2;
  float  expected_3 = 0;
  for (unsigned int i = 0; i < dim1; ++i) {
    expected_3 += v1[i] * v2[i];
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

  Vecteur<float> v(dim_expected);
  input_stream >> v;
  check_dim_values_with_opr(v, dim_expected, expected);
}

#ifndef VALGRIND
TEST(TestVecteur, q11_AssertOperateurIndexationConst)
{
  unsigned int dim1(15);
  float val1(10);
  Vecteur<float> v1(dim1, val1);
  ASSERT_DEATH(v1[dim1], "Assertion.*failed");
}
#endif

#ifndef VALGRIND
TEST(TestVecteur, q11_AssertOperateurIndexation)
{
  unsigned int dim1(15);
  float val1(10);
  Vecteur<float> v1(dim1, val1);
  ASSERT_DEATH(v1[dim1] = 3., "Assertion.*failed");
}
#endif

TEST(TestVecteur, q11_OperateurIndexationConsultation)
{
  unsigned int dim1(15);
  Vecteur<float> v1(dim1);
  float expected1[dim1];
  init_vector_and_array(v1, expected1, dim1, -555.55F, 2.2F);
  check_dim_values_with_opr(v1, dim1, expected1);
}

TEST(TestVecteur, q11_OperateurIndexationModification)
{
  unsigned int dim1(15);
  Vecteur<float> v1(dim1);
  float   expected1[dim1];
  init_vector_and_array(v1, expected1, dim1, -555.55F, 2.2F);
  check_dim_values_with_opr(v1, dim1, expected1);

  // modification du vecteur v1
  float new_expected[dim1];
  for (unsigned int i = 0; i < dim1; ++i) {
    v1[i]           = expected1[i] + i;
    new_expected[i] = expected1[i] + i;
  }
  check_dim_values_with_opr(v1, dim1, new_expected);
  // remise à l'état initial de v1
  for (unsigned int i = 0; i < dim1; ++i) {
    v1[i] = expected1[i];
  }
  check_dim_values_with_opr(v1, dim1, expected1);
}

/* ========================================================================
   pour tester q9  : Commenter cette fonction et les suivantes
   pour tester q12 : DÉcommenter cette fonction ; commentez les suivantes
   pour tester q14 : Commenter cette fonction ; DÉcommenter les suivantes
   ========================================================================*/

/*
TEST(TestVecteur, q12_ProduitScalaire)
{
  unsigned int dim1(15);
  Vecteur<float> v1(dim1);
  float   expected_1[dim1];
  init_vector_and_array(v1, expected_1, dim1, 10.F, 10.F);

  Vecteur<int> v2(dim1);
  int   expected_2[dim1];
  init_vector_and_array(v2, expected_2, dim1, -5, -5);

  // produit scalaire des deux vecteurs
  float  ps = v1 * v2;			// à deux paramètres

  // produit scalaire des deux tableaux
  float  expected_3 = 0;
  for (unsigned int i = 0; i < dim1; ++i)
  {
    expected_3 += v1[i] * v2[i];
  }
  ASSERT_EQ(expected_3, ps);

  // idem dans l'autre sens
  int psint = v2 * v1;			// à deux paramètres
  int expected_4 = 0;
  for (unsigned int i = 0; i < dim1; ++i)
  {
    expected_4 += v2[i] * v1[i];
  }
  ASSERT_EQ(expected_4, psint);
}
*/
/*
TEST(TestVecteur, q14_ProduitScalaire)
{
  unsigned int dim1(15);
  Vecteur<float> v1(dim1);
  float   expected_1[dim1];
  init_vector_and_array(v1, expected_1, dim1, 10.F, 10.F);

  Vecteur<int> v2(dim1);
  int   expected_2[dim1];
  init_vector_and_array(v2, expected_2, dim1, -5, -5);

  // produit scalaire des deux vecteurs
  float  ps = v1 * Vecteur<float>(v2);	// avec constructeur doublement générique

  // produit scalaire des deux tableaux
  float  expected_3 = 0;
  for (unsigned int i = 0; i < dim1; ++i)
  {
    expected_3 += v1[i] * v2[i];
  }
  ASSERT_EQ(expected_3, ps);

  // idem dans l'autre sens
  int psint = v2 * Vecteur<int>(v1);	// avec constructeur doublement générique
  int expected_4 = 0;
  for (unsigned int i = 0; i < dim1; ++i)
  {
    expected_4 += v2[i] * v1[i];
  }
  ASSERT_EQ(expected_4, psint);
}

TEST(TestVecteur, q14_addition)
{
  unsigned int dim1(15);
  Vecteur<float> v1(dim1);
  float   expected_1[dim1];
  init_vector_and_array(v1, expected_1, dim1, 10.5F, 2.F);

  Vecteur<int> v2(dim1);
  int   expected_2[dim1];
  init_vector_and_array(v2, expected_2, dim1, 5, 5);

  // Vecteur<float> + Vecteur<int> => Vecteur<float>
  Vecteur<float> addf12(v1 + v2);
  float   expected_3[dim1];
  init_array(expected_3, dim1, 15.5F, 7.F);
  check_dim_values_with_opr(addf12, dim1, expected_3);

  // Vecteur<int> + Vecteur<float> => Vecteur<float>
  Vecteur<float> addf21(v2 + v1);
  float   expected_4[dim1];
  init_array(expected_4, dim1, 15.F, 7.F);
  check_dim_values_with_opr(addf21, dim1, expected_4);
}

// vérifier la dimension et les valeurs d'un vecteur (utilise operator [])
template <class T, class U>
void check_dim_values_with_opr(const Vecteur<T> & v, unsigned int dim, U expected[]) {
  ASSERT_EQ(dim, v.dimensions());
  for (unsigned int i = 0; i < dim; ++i) {
    EXPECT_EQ(expected[i], v[i]);
  }
}

TEST(TestVecteur, q14_affectation)
{
  unsigned int dim1(15);
  Vecteur<float> v1(dim1);
  float   expected_1[dim1];
  init_vector_and_array(v1, expected_1, dim1, 10.5F, 10.F);

  unsigned int dim2(7);
  Vecteur<int> v2(dim2);
  int   expected_2[dim2];
  init_vector_and_array(v2, expected_2, dim2, 100, 5);

  v1 = v2;
  check_dim_values_with_opr(v1, dim2, expected_2);
}
*/

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  return RUN_ALL_TESTS();
}
