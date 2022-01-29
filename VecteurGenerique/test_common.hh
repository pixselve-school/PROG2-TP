//------------------------------------------------------------------------
// test vecteur avec google test
//------------------------------------------------------------------------
#include <gtest/gtest.h>

//------------------------------------------------------------------------
// fonctions utilitaires
//------------------------------------------------------------------------

// vérifier la dimension et les valeurs d'un vecteur (utilise get)
template <class T>
void check_dim_values_with_get(const Vecteur<T> & v, unsigned int dim, T expected) {
  ASSERT_EQ(dim, v.dimensions());
  for (unsigned int i = 0; i < dim; ++i) {
    EXPECT_EQ(expected, v.get(i));
  }
}

// vérifier la dimension et les valeurs d'un vecteur (utilise get)
template <class T>
void check_dim_values_with_get(const Vecteur<T> & v, unsigned int dim, T expected[]) {
  ASSERT_EQ(dim, v.dimensions());
  for (unsigned int i = 0; i < dim; ++i) {
    EXPECT_EQ(expected[i], v.get(i));
  }
}

// vérifier la dimension et les valeurs d'un vecteur (utilise operator [])
template <class T>
void check_dim_values_with_opr(const Vecteur<T> & v, unsigned int dim, T expected) {
  ASSERT_EQ(dim, v.dimensions());
  for (unsigned int i = 0; i < dim; ++i) {
    EXPECT_EQ(expected, v[i]);
  }
}

// vérifier la dimension et les valeurs d'un vecteur (utilise operator [])
template <class T>
void check_dim_values_with_opr(const Vecteur<T> & v, unsigned int dim, T expected[]) {
  ASSERT_EQ(dim, v.dimensions());
  for (unsigned int i = 0; i < dim; ++i) {
    EXPECT_EQ(expected[i], v[i]);
  }
}

// vérifier l'égalité de deux vecteurs
template <class T>
void check_vectors_equality(const Vecteur<T> & v1, const Vecteur<T> & v2) {
  ASSERT_EQ(v1.dimensions(), v2.dimensions());
  for (unsigned int i = 0; i < v1.dimensions(); ++i) {
    EXPECT_EQ(v1[i], v2[i]);
  }
}

// initialiser un tableau à une valeur initiale + incrément
template <class T>
void init_array(T v[], unsigned int dim, T valinit, T inc = T())
{
  T vc = valinit;
  for (unsigned int i = 0; i < dim; ++i) {
    v[i] = vc; vc += inc;
  }
}

// initialiser un vecteur et un tableau à une valeur initiale + incrément
template <class T>
void init_vector_and_array(Vecteur<T> & v,
			   T t[],
			   unsigned int dim,
			   T valinit,
			   T inc = T())
{
  T vc = valinit;
  for (unsigned int i = 0; i < dim; ++i)
  {
    v[i] = vc; t[i] = vc; vc += inc;
  }
}
