
# Exercice 1

## schema de base

https://www.mocodo.net/?mcd=eNpVjsEKwjAQRO_7FXvpbQ_2mlsgqwSSWpIgeJJogwhtFG3_31Ss1OPszL6ZipvguHXas6gAvDRSOxb4in28PRPhqYtjguDkQWpjSpqwsci2Nfsje8I6o-JWusC2mB7WQuRpUOlB-T7QeequaQRQ2_JT_wOW1hL36TLBYgr8XghnxKxC6kFpp3efJQW07iPc5B8Z3g5tPxY=

## "chaque departement est dirige par _un_ de ses employes" 

https://www.mocodo.net/?mcd=eNpVjlELgjAUhd_vr7gvQsEm-bqHYOi0gTPZRtBTWI4I1KL0_zcjSx_PPfd85wSisFqUWhrBAgDDcy61YPiqmur2dARPddW7eJcpC1bzA5d57iMEC4VClfn-KAzBqMNElFxbobxpYC5YN7SJe5Du3pLzUF9dD5CkPhMtAVO1fzfuMsBkMvxeCI6IUVnXQCK1zD5LPGjeR3DT_cgAsIpluka6XayndBmh9L8lDCc2vAHHH0_f

*Dependance fonctionnelle*: force une des entites a vivre les deux associations

## "3)"

> demande a flora

# traduction E/A -> relationnel

Employe(_numSec_,)
Departement(_numDep_,#numSecDirigeant)
Projet(_nomProjet_)
Tache(_numTache_,_#nomProjet_,(#numEmploye,#numDep))
Salaire(_date_,_#numSecEmploye_)
Travaille(_#numSecEmploye_, _#numSecDepartement_): on aurait pu mettre estDirigeant, mais on aurait perdu la cardinalite
Impliques(_#numDepart_,(_#numTache_,_#nomProjet_),Pourcentage)

donc il faut recuperer la cle primaire de la relation travaille

## Contrainte d'inclusion

effet de bord si on mets le num secu de departement en cle primaire : plusieurs departements peuvent avoir le meme nom

la cardinalite minimum se traduit pas

![](./les-problemes.jpg)






