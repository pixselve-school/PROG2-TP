#include <algorithm>
#include <deque>
#include <gtest/gtest.h>
#include <cstdlib>

// fichier qui contient l'implémentation de la classe Liste
#include "../Liste.h"

// fichier qui contient les deux fonctions chercherTri et copierTri de la partie 3
#include "../copier.h"

// fonctions utilitaires
#include "common_p1.h"
#include "common_p2.h"
#include "common_p24.h"

//------------------------------------------------------------------------
// tests des autres fonctions de la partie 3
// - recherche dans une liste triée
// - copie triée d'une liste
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// test recherche liste vide
//------------------------------------------------------------------------
TEST(TestList, q321RechercheListeVide)
{
  Liste<double> liste;
  Liste<double>::iterator found = chercherTri(liste.begin(),
					      liste.end(),
					      3.14159);
  EXPECT_EQ(
	    liste.end(),
	    found)
    << "Erreur itérateur résultat";
}

//------------------------------------------------------------------------
// test recherche dans liste de taille 1
// - élément inférieur au premier
// - élément égal au premier
// - élément supérieur au premier
//------------------------------------------------------------------------
TEST(TestList, q321RechercheListeTaille1)
{
  Liste<double> liste;
  liste.push_back(3.14159);
  // chercher un élément inférieur au premier
  Liste<double>::iterator found = chercherTri(liste.begin(),
					      liste.end(),
					      -999.);
  EXPECT_EQ(
	    liste.begin(),
	    found)
    << "Erreur itérateur résultat";
  // chercher un élément égal au premier
  found = chercherTri(liste.begin(),
		      liste.end(),
		      3.14159);
  EXPECT_EQ(
	    liste.begin(),
	    found)
    << "Erreur itérateur résultat";
  // chercher un élément supérieur au premier
  found = chercherTri(liste.begin(),
		      liste.end(),
		      999.);
  EXPECT_EQ(
	    liste.end(),
	    found)
    << "Erreur itérateur résultat";
}

// copier un tableau dans une liste
void
copier_array_list(
		  const std::deque<double> & array,
		  Liste<double> & liste
		  )
{
  std::deque<double>::const_iterator it     = array.begin();
  std::deque<double>::const_iterator it_fin = array.end();
  while (it != it_fin) {
    liste.push_back(*it);
    ++it;
  }
}



//------------------------------------------------------------------------
// test recherche dans liste de taille quelconque
// - élément inférieur au premier
// - élément égal au premier
// - élément égal au dernier
// - élément supérieur au dernier
// - élément présent à une position quelconque
// - élément quelconque
//------------------------------------------------------------------------
TEST(TestList, q321RechercheListe)
{
  // initialiser un tableau
  std::deque<double> array;
  ajouter_elts(array);
  // le trier
  std::sort(array.begin(), array.end());
  // le copier dans une liste
  Liste<double> liste;
  copier_array_list(array, liste);
  // faire les recherches (pfff !)
  double premier = array.front(), dernier = array.back();

  // élément inférieur au premier
  Liste<double>::iterator found = chercherTri(liste.begin(),
					      liste.end(),
					      premier -1000);
  ASSERT_EQ(
	    liste.begin(),
	    found)
    << "Erreur itérateur résultat";

  // élément égal au premier
  found = chercherTri(liste.begin(),
		      liste.end(),
		      premier);
  ASSERT_EQ(
	    liste.begin(),
	    found)
    << "Erreur itérateur résultat";

  // élément égal au dernier
  found = chercherTri(liste.begin(),
		      liste.end(),
		      dernier);
  ASSERT_EQ(
	    --liste.end(),
	    found)
    << "Erreur itérateur résultat";

  // élément supérieur au dernier
  found = chercherTri(liste.begin(),
		      liste.end(),
		      dernier + 1000);
  ASSERT_EQ(
	    liste.end(),
	    found)
    << "Erreur itérateur résultat";

  // élément présent à une position quelconque
  std::deque<double>::const_iterator it_array = array.begin();
  std::deque<double>::const_iterator it_fin   = array.end();
  while (it_array != it_fin) {
    found = chercherTri(liste.begin(),
			liste.end(),
			*it_array);
    ASSERT_EQ(
	      *it_array,
	      *found)
      << "Erreur recherche " << *it_array;
    ++it_array;
  }

  // élément quelconque
  for (int i = 0; i < 100 + rand() % 100; ++i) {
    double x = 5 + drand48();
    // chercher x dans le tableau
    std::deque<double>::const_iterator
      array_found = lower_bound(array.begin(), array.end(), x);
    // puis dans la liste
    found = chercherTri(liste.begin(),
			liste.end(),
			x);
    if (array_found == array.end()) {
      // élt cherché supérieur au dernier
      ASSERT_EQ(
		liste.end(),
		found)
	<< "Erreur itérateur résultat";
    }
    else {
      ASSERT_EQ(
		*array_found,
		*found)
	<< "Erreur recherche " << x;
    }
  }
}

//------------------------------------------------------------------------
// test copie triée d'une liste vide
//------------------------------------------------------------------------
TEST(TestList, q322CopieListeVide)
{
  Liste<double>   original;
  Liste<double> * copie(copierTri(original));
  ASSERT_FALSE(copie == NULL)
    << "Erreur pointeur résultat ne devrait pas être NULL";
  ASSERT_TRUE(copie->empty());
  ASSERT_NE(
	    &original,
	    copie);
  ASSERT_NE(
	    original.begin(),
	    copie->begin());
  // ajouter des éléments dans l'original
  original.push_front(100); original.push_back(999);
  // vérifier que la copie n'a pas changé
  ASSERT_TRUE(copie->empty());
  ASSERT_EQ(
	    copie->begin(),
	    copie->end());
  delete copie;
}

// test copie triée d'une liste non vide
// modification de la liste originale
TEST(TestList, q322CopieListe)
{
  // initialiser une liste et un tableau
  Liste<double>		original;
  std::deque<double>	array;
  ajouter_elts(original, array);

  // vérification préalable
  std::cout << "q322CopieListe : vérification préalable\n";
  list_equals_deque_forward(original, array);
  // trier le tableau
  std::sort(array.begin(), array.end());

  // faire une copie triée de la liste
  Liste<double> * copie(copierTri(original));
  ASSERT_FALSE(copie == NULL)
    << "Erreur pointeur résultat ne devrait pas être NULL";
  // vérifier la taille et le contenu
  std::cout << "q322CopieListe : vérification après tri\n";
  list_equals_deque_forward(*copie, array);

  // supprimer des éléments dans l'original
  original.pop_front(); original.pop_back();
  // vérifier que la copie n'a pas changé
  std::cout << "q322CopieListe : vérification après suppression\n";
  list_equals_deque_forward(*copie, array);

  // ajouter des éléments dans l'original
  original.push_front(100); original.push_back(999);
  // vérifier que la copie n'a pas changé
  std::cout << "q322CopieListe : vérification après ajout\n";
  list_equals_deque_forward(*copie, array);

  // modifier des éléments dans l'original
  original.front() *= 10; original.back() *= 9.9;
  // vérifier que la copie n'a pas changé
  std::cout << "q322CopieListe : vérification après modif\n";
  list_equals_deque_forward(*copie, array);

  delete copie;
}

// test copie d'une liste de taille quelconque
// modification de la copie
TEST(TestList, q322CopieListeBis)
{
  // initialiser une liste et un tableau
  Liste<double>		original;
  std::deque<double>	array;
  ajouter_elts(original, array);
  // vérification préalable
  std::cout << "q322CopieListeBis : vérification préalable\n";
  list_equals_deque_forward(original, array);

  // faire une copie du tableau et trier cette copie
  std::deque<double>	array_trie(array.size());
  std::copy(array.begin(), array.end(), array_trie.begin());
  std::sort(array_trie.begin(), array_trie.end());

  // faire une copie triée de la liste
  Liste<double> * copie(copierTri(original));
  ASSERT_FALSE(copie == NULL)
    << "Erreur pointeur résultat ne devrait pas être NULL";
  // vérifier la taille et le contenu
  std::cout << "q322CopieListeBis : vérification après tri\n";
  list_equals_deque_forward(*copie, array_trie);

  // supprimer des éléments dans la copie et le tableau trié
  copie->pop_front(); copie->pop_back();
  array_trie.pop_front(); array_trie.pop_back();
  // vérifier la copie
  list_equals_deque_forward(*copie, array_trie);
  // vérifier que l'original n'a pas changé
  list_equals_deque_forward(original, array);

  // ajouter des éléments dans la copie et le tableau trié
  copie->push_front(100); copie->push_back(999);
  array_trie.push_front(100); array_trie.push_back(999);
  // vérifier la copie
  list_equals_deque_forward(*copie, array_trie);
  // vérifier que l'original n'a pas changé
  list_equals_deque_forward(original, array);

  // modifier des éléments dans la copie et le tableau trié
  copie->front() *= 10; copie->back() *= 9.9;
  array_trie.front() *= 10; array_trie.back() *= 9.9;
  // vérifier la copie
  list_equals_deque_forward(*copie, array_trie);
  // vérifier que l'original n'a pas changé
  list_equals_deque_forward(original, array);

  delete copie;
}
