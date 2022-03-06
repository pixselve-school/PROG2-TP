#include <deque>
#include <gtest/gtest.h>
#include <cstdlib>

// fichier qui contient l'implémentation de la classe Liste
#include "../Liste.h"

// fonctions utilitaires
#include "common_p1.h"
#include "common_p2.h"
#include "common_p24.h"

//------------------------------------------------------------------------
// test find q3.1.1
//------------------------------------------------------------------------
TEST(TestList, q311Find)
{
  Liste<std::string> liste;
  std::deque<int>    longueurs;
  // mettre des chaînes de longueurs différentes dans la liste
  for (unsigned int i = 0; i <= 5; ++i) {
    liste.push_front(std::string(i+1, i + 'A'));
    liste.push_back (std::string(i+1, i + '1'));
    longueurs.push_front(i+1);
    longueurs.push_back (i+1);
    std::cout << std::string(i+1, i + 'A') << " - " << std::string(i+1, i + '1') << std::endl;
  }

  std::string x("A");
  Liste<std::string>::iterator it1(liste.begin());
  Liste<std::string>::iterator it2(liste.end());
  Liste<std::string>::iterator it3(find(it1, it2, x));//3.63));
  EXPECT_TRUE(
	      it3 != it2
	      )
    << "Les 2 itérateurs devraient être différents";
  EXPECT_FALSE(
	       it3 == it2
	       )
    << "Les 2 itérateurs devraient être différents";
  EXPECT_NE(
	    it3, it2
	    ) << "Les 2 itérateurs devraient être différents";
  EXPECT_EQ(
		   *it3, x
		   ) << "it3 devrait pointer sur " << x;
  x = "666666";
  it3=find(it1, it2, x);//6.05);
  EXPECT_NE(it3, it2) << "Les 2 itérateurs devraient être différents";
  EXPECT_EQ(*it3,x) << "it3 devrait pointer sur " << x;
  ++it1;
  ++it1;
  x="FFFFFF";
  it3=find(it1, it2, x);//2.42);
  EXPECT_EQ(it3,it2);
}

// test find dans liste vide
TEST(TestList, q311FindListeVide)
{
  Liste<double>	liste;
  Liste<double>::iterator pos = find(liste.begin(), liste.end(), 3.141519);
  EXPECT_EQ(
	    liste.end(),
	    pos
	    )
    << "Erreur recherche liste vide";
}

// test find dans liste d'un élément
TEST(TestList, q311FindListe1Element)
{
  Liste<double>	liste;
  liste.push_back(3.141519);
  // élément absent
  Liste<double>::iterator pos = find(liste.begin(), liste.end(), -10.5);
  EXPECT_EQ(
	    liste.end(),
	    pos
	    )
    << "Erreur recherche élément absent";

  // élément présent
  pos = find(liste.begin(), liste.end(), 3.141519);
  EXPECT_EQ(
	    liste.begin(),
	    pos
	    )
    << "Erreur recherche élément présent";
}

// test find dans liste de n éléments
TEST(TestList, q311FindListe)
{
  Liste<double>	liste;
  std::deque<double> array;
  ajouter_elts(liste, array);

  // chercher dans la liste tous les éléments du array
  for (unsigned int i = 0; i < array.size(); ++i) {
    // chercher un élément présent
    Liste<double>::iterator pos = find(liste.begin(), liste.end(), array[i]);
    ASSERT_NE(
	      liste.end(),
	      pos
	      )
      << "Erreur recherche élément présent à l'indice " << i << " valeur " << array[i];

    EXPECT_EQ(
	      array[i],
	      *pos
	      )
      << "Erreur valeur trouvée par la recherche";

    // chercher un élément absent (Attention : -0 = 0 !)
    pos = find(liste.begin(), liste.end(), -array[i]-1);
    EXPECT_EQ(
	      liste.end(),
	      pos
	      )
      << "Erreur recherche élément absent de valeur " << -array[i]-1;
  }
}

//------------------------------------------------------------------------
// test insert q3.1.2
//------------------------------------------------------------------------

#ifndef VALGRIND
// insert : assertion itérateur sur liste courante...
TEST(TestList, q312InsertCurrentListAssertion)
{
  Liste<double> liste1;
  liste1.push_back(3.14159);
  Liste<double> liste2;
  liste2.push_back(-77.77); 
  ASSERT_DEATH(liste1.insert(liste2.begin(), 3.14159), "Assertion.*failed");  
}
#endif

// test insert dans liste vide
TEST(TestList, q312InsertListeVide)
{
  Liste<double>	liste;
  EXPECT_TRUE(liste.empty()) << "Liste devrait être vide";
  // insérer un élément
  Liste<double>::iterator new_elt = liste.insert(liste.begin(), 3.14159);
  // vérif taille
  EXPECT_FALSE(liste.empty()) << "Liste ne devrait PAS être vide";
  EXPECT_EQ(
	    (unsigned int) 1,
	    (unsigned int) liste.size()) << "Erreur taille liste";
  // vérif valeur élément inséré
  EXPECT_EQ(
	    3.14159,
	    *liste.begin())
    << "Erreur valeur élément de tête";
  // vérif itérateur résultat
  ASSERT_EQ(
	    liste.begin(),
	    new_elt
	    )
    << "Erreur itérateur résultat";
  // vérif valeur élt désigné par itérateur
  EXPECT_EQ(
	    3.14159,
	    *new_elt)
    << "Erreur valeur élément inséré";
}

  // ajouter des élts dans un array et une liste
  // avec insert
  // vérifier que l'insertion est correcte
  void
  inserer_elts(
	       Liste<double> & liste,
	       std::deque<double> & array,
	       Position ici = alea
	       )
  {
    const int array_size = 100 + rand() % 100;
    for (int i = 0; i < array_size; ++i)
    {
      double x = 5 + drand48();
      if (ici == front)
      {
	// insertion en tête
	array.push_front(i * x * x);
	Liste<double>::iterator new_elt = liste.insert(liste.begin(), i * x * x);
	// vérifier tailles
	EXPECT_EQ(
		  array.size(),
		  liste.size()) << "Erreur taille liste";
	// vérifier valeur élément de tête de liste
	EXPECT_EQ(
		  *array.begin(),
		  *liste.begin())
	  << "Erreur valeur élément de tête";
	// vérif itérateur résultat
	ASSERT_EQ(
		  liste.begin(),
		  new_elt
		  )
	  << "Erreur itérateur résultat";
	// vérif valeur élt désigné par itérateur
	EXPECT_EQ(
		  *array.begin(),
		  *new_elt)
	  << "Erreur valeur élément inséré";
      } // insertion en tête
      else if (ici == back)
      {
	// insertion en fin
	array.push_back(i * x + 1);
	Liste<double>::iterator new_elt = liste.insert(liste.end(), i * x + 1);
	// vérifier tailles
	EXPECT_EQ(
		  array.size(),
		  liste.size()) << "Erreur taille liste";
	// vérifier valeur dernier élément
	EXPECT_EQ(
		  *--array.end(),
		  *--liste.end())
	  << "Erreur valeur dernier élément";
	// vérif itérateur résultat
	ASSERT_EQ(
		  --liste.end(),
		  new_elt
		  )
	  << "Erreur itérateur résultat";
	// vérif valeur élt désigné par itérateur
	EXPECT_EQ(
		  *--array.end(),
		  *new_elt)
	  << "Erreur valeur élément inséré";
      } // insertion en fin
      else
      {
	// insertion à une position quelconque...
	Liste<double>::iterator	     liste_it = liste.begin();
	std::deque<double>::iterator array_it = array.begin();
	int pos = rand() % (1 + array.size());
	// positionner les itérateurs
	while (pos > 0)
	{
	  ++liste_it ; ++array_it ; --pos;
	}
	// effectuer l'insertion
	liste_it = liste.insert(liste_it, i * i * x + 1);
	array_it = array.insert(array_it, i * i * x + 1);
	// vérifier tailles
	EXPECT_EQ(
		  array.size(),
		  liste.size())
	  << "Erreur taille liste";
	// vérifier valeur
	EXPECT_EQ(
		  *array_it,
		  *liste_it)
	  << "Erreur valeur élément inséré";
      } // insertion en position quelconque
    } // for
  }

// test insert en tête de liste non vide
TEST(TestList, q312InsertTeteListe)
{
  Liste<double>		liste;
  std::deque<double>	array;
  // initialiser la liste et le tableau avec push_back/front
  ajouter_elts(liste, array);

  // insertion en tête et vérification
  inserer_elts(liste, array, front);

  // encore une vérification
  list_equals_deque_forward(liste, array);
}

// test insert en fin de liste non vide
TEST(TestList, q312InsertFinListe)
{
  Liste<double>		liste;
  std::deque<double>	array;
  // initialiser la liste et le tableau avec push_back/front
  ajouter_elts(liste, array);

  // insertion en fin et vérification
  inserer_elts(liste, array, back);

  // encore une vérification
  list_equals_deque_forward(liste, array);
}

// test insert au hasard dans liste non vide
TEST(TestList, q312InsertHasardListe)
{
  Liste<double>		liste;
  std::deque<double>	array;
  // initialiser la liste et le tableau avec push_back/front
  ajouter_elts(liste, array);

  // insertion en fin et vérification
  inserer_elts(liste, array, alea);

  // encore une vérification
  list_equals_deque_forward(liste, array);
}

//------------------------------------------------------------------------
// tests erase q3.1.3
//------------------------------------------------------------------------

#ifndef VALGRIND
// erase : assertion itérateur sur liste courante...
TEST(TestList, q313EraseCurrentListAssertion)
{
  Liste<double> liste1;
  liste1.push_back(3.14159);
  Liste<double> liste2;
  liste2.push_back(-77.77); 
  ASSERT_DEATH(liste1.erase(liste2.begin()), "Assertion.*failed");  
}
#endif

#ifndef VALGRIND
// erase : assertion itérateur fin de liste
TEST(TestList, q313EraseEndListAssertion)
{
  Liste<double> liste;
  ASSERT_DEATH(liste.erase(liste.begin()), "Assertion.*failed");  
}
#endif

// erase : suppression dans liste d'un élément
TEST(TestList, q313EraseListe1Element)
{
  Liste<double> liste;
  liste.push_back(3.14159);
  Liste<double>::iterator next = liste.erase(liste.begin());
  EXPECT_TRUE(liste.empty());
  EXPECT_EQ(
	    liste.end(),
	    next
	    )
    << "Erreur itérateur résultat";
}

// erase : suppression dans liste quelconque
TEST(TestList, q313Erase)
{
  // mettre des éléments dans une liste et un tableau
  Liste<double>		liste;
  std::deque<double>	array;
  ajouter_elts(liste, array);
  // vérification préalable
  list_equals_deque_forward(liste, array);
  // supprimer des éléments de la liste et du tableau
  for (unsigned int i = 0; i < array.size(); ++i) {
    Liste<double>::iterator	 liste_it = liste.begin();
    std::deque<double>::iterator array_it = array.begin();
    int pos = rand() % array.size();
    // positionner les itérateurs
    while (pos > 0) {
      ++liste_it ; ++array_it ; --pos;
    }
    ASSERT_NE(
	      liste.end(),
	      liste_it)
      << "Erreur l'itérateur ne devrait pas être end";
    ASSERT_EQ(
	      *array_it,
	      *liste_it)
      << "Erreur : les éléments à supprimer n'ont pas même valeur !";
    // effectuer la suppression
    liste_it = liste.erase(liste_it);
    array_it = array.erase(array_it);
    // vérifier tailles
    EXPECT_EQ(
	      array.size(),
	      liste.size())
      << "Erreur taille liste";
    // vérifier l'itérateur résultat
    if (array_it == array.end()) {
      EXPECT_EQ(
		liste.end(),
		liste_it)
	<< "Erreur itérateur résultat";
    }
    else {
      // vérifier valeur
      EXPECT_EQ(
		*array_it,
		*liste_it)
	<< "Erreur valeur élément après celui supprimé";
    }
    // vérifier les conteneurs
    list_equals_deque_forward(liste, array);
  }
}
