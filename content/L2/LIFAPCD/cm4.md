+++
title = "git"
draft = false
+++

## pourquoi git?

L'ecriture de code a plusieurs pose plusieurs problematiques:

- comment faire en sorte que chaque developpeur ait une version du code a jour?
- comment eviter de se partager des fichiers inutiles/sensibles
- comment gerer les conflits lorsque 2 developpeurs ont travaille sur le meme code ?
- comment conserver un historique d'edition

=> on va utiliser un gestionnaire de version de code

Et git parce que (c la norme en vrai)

## avant de commencer

ATTENTION: c tres personnel

Je pense quil important de comprendre git en le pratiquant.
Je pense aussi que toutes les tentatives d'explication de ce que c'est ne vaut
pas le livre [Pro Git, en francais](https://git-scm.com/book/fr/v2)

d'autres ressources classiques [ici](https://git-scm.com/learn)

d'autres ressources **interactives** et **innovantes** existent:

- [une reference visuelle de git](https://marklodato.github.io/visual-git-guide/index-fr.html)

- [un jeu git a installer (sur itch.io)](https://blinry.itch.io/oh-my-git)

- [un playground pour voir nos action (web)](https://onlywei.github.io/explain-git-with-d3/)

- [pour apprendre le branching quand on a bien compris les basiques](https://learngitbranching.js.org/)

au risque de me repeter: IL EST MIEUX DE SUIVRE SES RESSOURCES QUE CELLES DU PROF
(ou ma vulgaire reecriture)

### definitions importantes

#### repository/depot central

mandataire du code, sur un sesrveur

il aide a securiser au moins une version du code

#### depot local version du depot en local

se trouve dans .git

represente le travail commitee et le travail engage (.git)

#### lindex (staging area)

represente tous les changements qui sont faits dans notre copie locale du travail
on peut le voir avec git ls
le manipuler avec git rm, git mv

#### copie de travail

ce qu'on manipule reelement

#### forge: site qui heberge des depots

forge =/ github =/ gitlab =/ codeberg
(mais ils utilisent tous git)

#### remarques importantes

git sauvegarde lintegralite de notre structure de fichiers -> un commit = 1 photo de notre repertoire
git est manipule 80% du temps en local.
lavantage est alors quon peut sauvegarder ces etats de travail hors ligne
ensuite, rien nest supprime. c pour ca que mettre des commentaires douteux nest jamais une bonne idee

### commandes "de base"

une image vaut mille mots.

voici un recap des commandes en lien avec les definitions vues precedemments.

un syteme de controle de version permets de sauvegarder le travail realise sur n fichier.s.

on dit a git les fichiers sur lesquels on va travailler. on peut notamment:

- les modifier
- les supprimer
- en creer de nouveaux.
  pour les deplacer:
- on fait git mv

generalement on fait: git add (pour les ajouter a notre staging area)

il faut faire attention a ne pas commencer a travailler sur tout les fichiers en meme temps,
c plus simple

une fois quon a bien travaille quon est content de ce quon a fait, on engage notre travail.
c important de faire ca souvent:

si on travaille en meme temps (dans la meme periode de temps), cela est tres utile

git sauvegarde lintegralite de notre structure de fichiers -> un commit = 1 photo de notre repertoire
git est manipule 80% du temps en local.
lavantage est alors quon peut sauvegarder ces etats de travail hors ligne
ensuite, rien nest supprime. c pour ca que mettre des commentaires douteux nest jamais une bonne idee

### comment concretement utiliser git ?

il faut linstaller

il faut le configurer

et configurer le repo (linit/le cloner)
Pour lutiliser:
on dit a un dossier de se gitiser (git init)
toute ces etapes sont bien integres a vscode
ce diagramme montre tout ce quil est possible de faire entre le moment ou on travaille, et avant de commit

pour faire un recap de tout ce qui a ete fait (et non commit, on regarde dans git status)
si on veut voir les contributions realises (meme pas tracke)

on fait git diff

et si on veut les voir on fait

git staged

pour reparer un commit (oubli simple)
git commit 00ammed

pour ne pas enregistrer les modifications dun commit, on fait git restore --staged <file> pour enlever les modifs de lindex

pour revenir au fichier dun dernier commit: on fait git restore <file>

pour ne pas tenir compte de notre travail en gros

pour recuperer le travail fait ailleurs: git fetch

pour appliquer le travail fait ailleurs: git pull
