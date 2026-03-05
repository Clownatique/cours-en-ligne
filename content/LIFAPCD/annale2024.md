```mermaid
class datetime{
  jour
  mois
  annee
  seconde
  miliseconde
  +afficher(format)
  -convertir(format)
}

class endroit{
  float x
  float y
  string adresse
  +adresseFromGps()
}

class releve{
  date date
  signed float mesure
}


class Historique{
  vector<historique> releve
}

class usine{
  endroit coordoneeGPS
  historique debit
  historique analyse
  + donnee_temps_reel
}

class point_distrib{}
  int identifiant
  endroit emplacement
  historique debit
}

class client{
  string nom
  string prenom
  adresse
  point_distribution* point_distribution
}

class Reservoir{
    
}
class jonction{
  emplacement emplacementgps
  jointes vector<jonction*>
  historique debit_entrant
  historique debit_sortant    
}

class arbre{
  racine:usine traitement
  feuilles:point de distribution
  noeuds: chateau d'eau ou pas:est jonction
historique debit entrant/sortant
}

class affichagereseau{
  carte2D
  reservoir_focused
  nanana_focused
}

class historiqueconsommation{
  focused
}
```
