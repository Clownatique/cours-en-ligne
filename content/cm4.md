+++
title="processus"
draft = false
+++

## creation dun proc:

Un processus est un programme en cours d’exécution.
``
peut se faire avec

### fork split le processus

quand on fait fork, c comme si on ouvrait un autre terminal et quon executait le
meme executable

## terminaison dun processus

le processus devient zombie (occupe des ressources, attends quon le termine)

il y a plusieurs forme de processus finis:

- zombie (quand le processus decide daller se faire foutre)
- eventuellement orphelin (plus aucun processus le cala, c systemd qui le recupere)

- normalement (par un return ... dans main) : non ! ca c le pourquoi, pas le comment

lors de lexecution

- pret (en attente detre execute)
- endormi (sleep)

### waitpid

on rappellera que le c++ est imperatif, cest a dire que lexecution se fait ligne
par ligne...
donc si on fait un appel avec opt = 0, on bloque sur l'appel

### exec

permets d'appeller un programme (depuis le programme avec cet appel)
cest une famille de fonction: execl, exelp, execle...
under the hoods, exec remplace le process

les redirections de flux par exemples utilise ceci

### tout ces processus, sont geres par l'os

et c grace a lordonnancement: le systeme choisi a quels processus il accorde
son temps et son energie

## un peu de terminologie:

**Processus**: Programme qui tourne + seulement ce qui est associe
**Ordonancement**: Action de l'OS de choisir quel processus sexecute a un temps t
**PID**: Parent Identifier
**PPID**: Parent Process Identifier
**Systemd**: le processus qui appelle les processus
**Systemd**: le processus qui appelle les processus (ancienne version)
**TTY**:Entree de Terminal
