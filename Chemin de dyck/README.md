# TP1: Chemins de Dyck"

## Description

Ce travail pratique consiste à écrire un programme en langage C appelé "motdedyck.c" qui prend en entrée des mots de Dyck et dessine le chemin correspondant. Le programme lit l'entrée sur l'entrée standard (stdin) et affiche le résultat sur la sortie standard (stdout). L'objectif principal du projet est de familiariser les étudiants avec le langage C, Git, la compilation à l'aide d'un Makefile et la décomposition d'un programme en petites fonctions.

Un mot de Dyck est un mot sur un alphabet binaire qui satisfait deux propriétés : il y a autant de lettres 'a' que de lettres 'b' et pour tout préfixe du mot, il y a au moins autant de lettres 'a' que de lettres 'b'. Le programme doit valider si le mot donné en entrée est un mot de Dyck sur l'alphabet donné. Si ce n'est pas le cas, il affiche un message d'erreur approprié. Si le mot est un mot de Dyck, le programme affiche un dessin ASCII du chemin de Dyck correspondant au mot.

Le programme accepte également des arguments optionnels pour calculer la hauteur du chemin ou l'aire sous le chemin, en remplacement de l'affichage ASCII.

Le fichier "motdedyck.c" doit être complété en implémentant les fonctionnalités décrites ci-dessus. Le projet utilise également un fichier "Makefile" pour faciliter la compilation et l'exécution du programme.

Le fichier README.md contient des instructions supplémentaires pour cloner le dépôt, organiser le code, et exécuter le programme avec différents exemples d'entrées et de sorties attendues.

Lien vers le projet [https://gitlab.info.uqam.ca/aplogan.ronald_seth_sena/e23-inf3135-tp1.git](Chemin de Dyck).

## Auteur

Seth R. APLOGAN (APLR91110107)

## Fonctionnement

Pour faire fonctionner le projet il vous suffit 
* Ouvrir un terminal sur votre ordinateur
* Entrer dans le repertoire ou vous avez telecharger le dossier
* Utiliser la commande `./motdedyck.c`. l'usage vous expliquera les differentes parametre pour utiliser le programme

## Tests

Pour lancer les tests il faut faire la commande
`make test`, le  programme lancera une suite de tests
 tout les test passent soit 10 tests

## Dépendances
Les dependances du fichiers sont 
* GCC
* Bats
* Pandoc


Vous devez installez chacune d'elles pour faire fonctionner le dossier sans aucune difficultes
## Références

Mes references sont:

* stackoverflow
* geekforgeeks
* chatGpt
* l'aide de mes camarades en classe

## État du projet

Indiquez toutes les tâches qui ont été complétés en insérant un `X` entre les
crochets. Si une tâche n'a pas été complétée, expliquez pourquoi (lors de la
remise, vous pouvez supprimer ce paragraphe).

* [X] Le nom du dépôt GitLab est exactement `e23-inf3135-tp1` (Pénalité de
  **50%**).
* [X] L'URL du dépôt GitLab est exactement (remplacer `utilisateur` par votre
  nom identifiant GitLab) `https://gitlab.info.uqam.ca/utilisateur/e23-inf3135-tp1`
  (Pénalité de **50%**).
* [X] L'utilisateur `dogny_g` a accès au projet en mode *Developer*
  (Pénalité de **50%**).
* [ ] Les correcteurs ont accès au projet en mode *Developer* (`id`à venir)
* [X] Le dépôt GitLab est un *fork* de [ce
  dépôt](https://gitlab.info.uqam.ca/inf3135-sdo/motdedyck)
  (Pénalité de **50%**).
* [X] Le dépôt GitLab est privé (Pénalité de **50%**).
* [X] Le dépôt contient au moins un fichier `.gitignore`.
* [X] Le fichier `Makefile` permet de compiler le projet lorsqu'on entre
  `make`. Il supporte les cibles `html`, `test` et `clean`.
* [X] Le nombre de tests qui réussissent/échouent avec la `make test` est
  indiqué quelque part dans le fichier `README.md`.
* [X] Les sections incomplètes de ce fichier (`README.md`) ont été complétées.
* [X] L'en-tête du fichier est documentée.
* [X] L'en-tête des déclarations des fonctions est documentée (*docstring*).
* [X] Le programme ne contient pas de valeurs magiques.
