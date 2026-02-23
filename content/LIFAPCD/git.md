Git eset un systeme de gestion de version.

Avant de setaler sur les commandes de git, il faut comprendre de quoi il sagit.

Ce que git nest pas:

- 'juste' un moyen de stocker du code en ligne (google drive existe)
- github
- un truc plus chiant que discord pour travailler en equipe

un syteme de controle de version permets de sauvegarder le travail realise sur n fichier.s.

Pour lutiliser:
on dit a un dossier de se gitiser (git init)
on dit a git les fichiers sur lesquels on va travailler. on peut notamment:

- les modifier
- les supprimer
- en creer de nouveaux.
  pour les deplacer:
- on fait git mv

generalement on fait: git add

il faut faire attention a ne pas commencer a travailler sur tout les fichiers en meme temps,
c plus simple

une fois quon a bien travaille quon est content de ce quon a fait, on engage notre travail.
c important de faire ca souvent:

si on travaille en meme temps (dans la meme periode de temps), cela est tres utile

il faut distinguer ces espaces de travail:

- le dossier de travail (tout ce que vous manipulez, voyez a lecran)
- lindex (staging area) et le travail engage (.git)
- le dossier de reference (qui ne fait pas legion: il faut faire attention)

git sauvegarde lintegralite de votre structure de fichiers -> un commit = 1 photo de notre repertoire
git est manipule 80% du temps en local.
lavantage est alors quon peut sauvegarder ces etats de travail hors ligne
ensuite, rien nest supprime. c pour ca que mettre des commentaires douteux nest jamais une bonne idee

comment utiliser git ?

il faut linstaller

il faut le configurer

et configurer le repo (linit/le cloner)
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
