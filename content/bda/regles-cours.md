+++
title='regles-cours'
draft=false
+++

# 📐 BDA — Règles d'or

## 1. Modélisation E/A (TD2)


| Élément                | Règle d'or                                                                                                | Représentation          |
| ---------------------- | --------------------------------------------------------------------------------------------------------- | ----------------------- |
| **Entité**             | Une « chose » du monde réel avec des attributs ; identifiant **souligné** (jamais un attribut multivalué) | Rectangle               |
| **Entité faible**      | N'existe que via son entité forte ; identifiant local insuffisant                                         | Double rectangle        |
| **Association**        | Jamais d'attribut souligné — sinon il manque une entité                                                   | Losange                 |
| **Association n-aire** | Valable **seulement** si toutes les combinaisons d'entités peuvent exister ensemble ; sinon → agrégation  | Losange à n pattes      |
| **Cardinalités**       | Participation (0/1 : « doit » participer ?) × connectivité (1/N : combien en face ?)                      | (min, max) sur la patte |
| **Inclusion I**        | Tout participant à A₁ participe aussi à A₂ ; double flèche = égalité (inclusion dans les 2 sens)          | Flèche I de A₁ vers A₂  |


{{&lt; tabs &gt;}}  
{{% tab "Exemple cardinalités" %}}

> « Un étudiant DOIT être inscrit dans AU PLUS une formation. Une formation peut avoir PLUSIEURS étudiants, éventuellement aucun. »

- Côté Étudiant → Formation : participation **1** (obligatoire), connectivité **1** (au plus une).
- Côté Formation → Étudiant : participation **0** (optionnelle), connectivité **N**.  
{{% /tab %}}  
{{% tab "Exemple entité faible" %}}  
Deux salles n°1 existent dans deux bâtiments différents : `NumSalle` seul ne suffit pas.
- `Salle` est une **entité faible** de `Bâtiment`.
- Identifiant complet = `NumBat` + `NumSalle`.  
{{% /tab %}}  
{{% tab "Exemple inclusion" %}}

> « Chaque tâche a un coordonnateur employé, qui agit pour un département **impliqué dans cette tâche**. »

Si `Coordonner` (Employé, Tâche, Département) et `Impliquer` (Département, Tâche) : flèche d'inclusion de `Coordonner` vers `Impliquer`.  
{{% /tab %}}  
{{&lt; /tabs &gt;}}

## 2. Traduction E/A → Relationnel (TD2)


| Construction E/A                     | Traduction relationnelle                                                        | Clé primaire                                                 |
| ------------------------------------ | ------------------------------------------------------------------------------- | ------------------------------------------------------------ |
| Entité                               | Relation de même nom, mêmes attributs                                           | Identifiant souligné                                         |
| Entité faible                        | Relation + clé étrangère vers l'entité forte                                    | **Clé étrangère + identifiant local**                        |
| Association one-to-many              | Clé étrangère placée côté « 1 » (référence vers le côté « N »)                  | Celle de l'entité porteuse                                   |
| Association many-to-many ou ternaire | Relation dédiée : attributs de l'association + clés étrangères des participants | **Toutes les clés étrangères des entités de connectivité N** |
| Entité spécialisée                   | Clé étrangère = clé primaire ; **aucun attribut hérité répété**                 | Clé étrangère (seule)                                        |


> ⚠️ Toute contrainte non traduisible en clé / clé étrangère / domaine (ex. *somme des taux d'implication ≤ 100 %*) doit être **programmée** (trigger, application) et **documentée** sur le schéma E/A.

{{&lt; tabs &gt;}}  
{{% tab "Exemple one-to-many" %}}  
`Employé (1) —— travaille dans —— (N) Département`

→ `Employe(numSS, nom, tel, #numDept)` : la clé étrangère `numDept` est placée dans Employé.  
{{% /tab %}}  
{{% tab "Exemple many-to-many" %}}  
`Employé (N) —— participe —— (N) Projet`

→ `Participe(#numSS, #numProj)` : clé primaire = (`numSS`, `numProj`).  
{{% /tab %}}  
{{% tab "Exemple ternaire" %}}  
`Département (N) —— impliqué (taux) —— Tâche (N)` avec attribut `taux`

→ `Impliquer(#numDept, #numTache, taux)` : clé = (`numDept`, `numTache`).  
{{% /tab %}}  
{{&lt; /tabs &gt;}}

## 3. Algèbre relationnelle (TD3)


| Opérateur                         | Syntaxe                           | Règle d'or                                                           |
| --------------------------------- | --------------------------------- | -------------------------------------------------------------------- |
| Sélection                         | $\\sigma\_{C}(R)$                 | Filtre des **tuples** ; condition sur les valeurs                    |
| Projection                        | $\\pi\_{X}(R)$                    | Garde des **colonnes** et **élimine les doublons**                   |
| Renommage                         | $\\rho\_{\[X/Y\]}(R)$             | Indispensable avant une auto-jointure                                |
| Jointure naturelle                | $R \\bowtie S$                    | Égalité sur les attributs de même nom, colonnes en double supprimées |
| Union / Intersection / Différence | $R \\cup S$, $R \\cap S$, $R - S$ | Schémas **compatibles** (mêmes attributs)                            |
| Produit cartésien                 | $R \\times S$                     | Schémas **disjoints** ($R \\cap S = \\emptyset$)                     |
| Division                          | $R \\div S$                       | « pour **TOUS** les… »                                               |


{{&lt; tabs &gt;}}  
{{% tab "Le « pas de »" %}}  
Produits **jamais commandés** :

$$\\pi\_{pnom}(produits) - \\pi\_{pnom}(commandes)$$

Toujours : total − ceux qui vérifient.  
{{% /tab %}}  
{{% tab "Auto-jointure" %}}  
Paires de fournisseurs dans la même ville, **sans symétriques** :

$$\\pi\_{f1, f2}(\\sigma\_{f1 &lt; f2}(\\rho\_{f1/fnom}(fournisseurs) \\bowtie \\rho\_{f2/fnom}(fournisseurs)))$$

Renommer d'abord, puis éliminer les doublons avec `f1 < f2`.  
{{% /tab %}}  
{{% tab "Division : « tous les »" %}}  
Produits fournis par **tous** les fournisseurs :

$$\\pi\_{pnom, fnom}(produits) \\div \\pi\_{fnom}(fournisseurs)$$

Équivalent avec π et − : $R \\div S = \\pi\_X(R) - \\pi\_X((\\pi\_X(R) \\times S) - R)$.  
{{% /tab %}}  
{{% tab "Max / min" %}}  
Pas d'agrégat en algèbre → différence :

$$\\pi\_{pnom}(produits) - \\pi\_{pnom}(\\pi\_{pnom, prix}(produits) \\bowtie \\sigma\_{prix &lt; p.prix}(\\rho\_{p/produits}(produits)))$$

Les plus chers = tous − ceux **strictement moins chers qu'un autre**.  
{{% /tab %}}  
{{&lt; /tabs &gt;}}

## 4. Dépendances fonctionnelles et de jointure (TD4)


| Concept                               | Règle d'or                                                                                                                                             |
| ------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **DF** $X \\to Y$                     | La valeur de $X$ détermine **une seule** valeur de $Y$                                                                                                 |
| Réflexivité                           | $Y \\subseteq X \\Rightarrow X \\to Y$ (toujours vraie)                                                                                                |
| Transitivité                          | $X \\to Y,\\ Y \\to Z \\Rightarrow X \\to Z$                                                                                                           |
| Clé composée                          | Si une donnée varie selon plusieurs identifiants (ex. prix selon agence **et** type **et** année), la partie gauche contient **tous** ces identifiants |
| **DJ** $\\bowtie\[X\_1,\\dots,X\_n\]$ | La relation se **recompose sans perte** par jointure de ses projections ; traduit une association n-aire **non décomposable** en binaires              |


**Propagation des DF** :


| Opération                 | La DF $X \\to Y$ est-elle préservée ?      |
| ------------------------- | ------------------------------------------ |
| Sélection $\\sigma\_C(r)$ | ✅ Toujours                                 |
| Différence $r - s$        | ✅ Toujours                                 |
| Projection $\\pi\_W(r)$   | ❌ Pas forcément                            |
| Jointure $r \\bowtie s$   | ❌ Pas forcément (un contre-exemple suffit) |
| Union $r \\cup s$         | ❌ Pas forcément                            |
| Produit $r \\times s$     | ✅ Oui (si $R \\cap S = \\emptyset$)        |


{{&lt; tabs &gt;}}  
{{% tab "Exemple DF" %}}

> « Chaque agence est basée dans une ville. »

$$A \\to ville$$

> « Les agences proposent des types de véhicules, chacune à un prix qui varie selon les années. »

$$A, T, annee \\to prix$$  
{{% /tab %}}  
{{% tab "Contre-exemple DJ" %}}  
Si les commerciaux sont affectés à des agences **et** habilités sur des types, **indépendamment** → deux associations binaires séparées.

Une relation unique $R(A, T, C)$ est alors **fausse** : elle force des combinaisons inexistantes (redondance). $R(A,T,C)$ n'est une bonne représentation que si l'affectation lie **réellement les trois ensemble** (DJ valide).  
{{% /tab %}}  
{{&lt; /tabs &gt;}}

## 5. Clés minimales et formes normales (TD5–TD6)

**Calcul des clés minimales** :

1. Partir des attributs **absents de toute partie droite** de DF.
2. Si cet ensemble ferme tout $R$ → **unique clé minimale**.
3. Sinon, explorer les sur-ensembles.
4. **Cycles** dans les DF ($A \\to B$, $B \\to A$) ⟹ **plusieurs clés minimales**.


| Forme normale | Condition (pour toute contrainte)                                          |
| ------------- | -------------------------------------------------------------------------- |
| **1FN**       | Valeurs atomiques                                                          |
| **3FN**       | DF $X \\to A$ : $X$ superclé **ou** $A$ **premier** (appartient à une clé) |
| **FNBC**      | DF $X \\to A$ : $X$ superclé — point final                                 |
| **4FN**       | DM (DJ binaire non triviale) $X \\twoheadrightarrow Y$ : $X$ superclé      |
| **5FN**       | DJ non triviale : le fragment commun contient une superclé                 |


> 📏 Enchaînement : 1FN ⊂ 3FN ⊂ FNBC ⊂ 4FN ⊂ 5FN. La « meilleure FN » = la plus haute vérifiée par **toutes** les contraintes ; **une seule violation rétrograde**.

{{&lt; tabs &gt;}}  
{{% tab "Exemple clé minimale" %}}  
$R = ABCDE$, $\\Sigma = {A \\to E;\\ B \\to D;\\ D \\to C;\\ D \\to A}$

- Attributs jamais à droite : $A, B$.
- $AB^+ = ABDEC = R$ → **AB est clé**.
- $A^+ = AE \\ne R$ ; $B^+ = BDCAE = R$ → **B est aussi clé** (cycle $B \\to D \\to A \\to E$) ⟹ plusieurs clés, dont des attributs premiers ($A$, $B$, $D$…).  
{{% /tab %}}  
{{% tab "Exemple 3FN vs FNBC" %}}  
$R(A,B',B,C,D,E)$ avec DF $B' \\to B$ où $B'$ (directeur) n'est pas superclé et $B$ est premier (dans la clé) :
- 3FN ✅ (la partie droite $B$ est un attribut premier)
- FNBC ❌ ($B'$ n'est pas superclé)  
{{% /tab %}}  
{{% tab "Détection redondances" %}}  
Table `Films(NumFilm, Titre, Année, NumOriginal, AnnéeOriginal, Similarité)` :
- Doublons de `Dracula / 1931` dans plusieurs lignes ⟹ DF probables : `NumFilm → Titre, Année` et `NumFilm → NumOriginal`.
- `AnnéeOriginal` répété ⟹ DF `NumOriginal → AnnéeOriginal` + dépendance d'inclusion `NumFilm → NumOriginal`.
- Conclusion : relation **non normalisée** → décomposer selon le schéma E/A retrouvé.  
{{% /tab %}}  
{{&lt; /tabs &gt;}}

## 6. Inférence, fermeture, poursuite (TD7)

**Règles d'inférence** :


| Type  | Règle                    | Énoncé                                                                                         |
| ----- | ------------------------ | ---------------------------------------------------------------------------------------------- |
| DF    | Réflexivité              | $Y \\subseteq X \\Rightarrow X \\to Y$                                                         |
| DF    | Augmentation             | $X \\to Y \\Rightarrow WX \\to WY$                                                             |
| DF    | Transitivité             | $X \\to Y,\\ Y \\to Z \\Rightarrow X \\to Z$                                                   |
| DJ    | Conversion               | $X \\to Y \\Rightarrow \\bowtie\[XY, X-\]$                                                     |
| DJ    | Quasi-transitivité mixte | $\\bowtie\[XY, X-\]$ et $XY \\to Z$ $\\Rightarrow X \\to Z - Y$                                |
| DI    | Transitivité             | $R\[X\] \\subseteq S\[Y\]$, $S\[Y\] \\subseteq T\[Z\]$ $\\Rightarrow R\[X\] \\subseteq T\[Z\]$ |
| DF/DI | Pullback                 | $R\[XY\] \\subseteq S\[TU\]$ et $S : T \\to U$ $\\Rightarrow R : X \\to Y$                     |


**Fermeture** $X^+ = {A \\in R \\mid \\Sigma \\models X \\to A}$ :


| Propriété   | Énoncé                                           |
| ----------- | ------------------------------------------------ |
| Extensive   | $X \\subseteq X^+$                               |
| Croissante  | $X \\subseteq Y \\Rightarrow X^+ \\subseteq Y^+$ |
| Idempotente | $(X^+)^+ = X^+$                                  |


> 🔑 $X \\to Y$ est inférée par $\\Sigma$ **si et seulement si** $Y \\subseteq X^+$.

**Poursuite (chase)** : construire le tableau des projections avec des NULL, appliquer les contraintes pour compléter ; si on obtient le tuple cible, $\\Sigma \\models \\sigma$.

> 💡 **Piège** : toujours faire l'inférence **avant** de conclure sur la forme normale. Ex. $\\Sigma = {AB \\to C,\\ \\bowtie\[AB, AC\]}$ *semble* en FNBC, mais $\\Sigma \\equiv {A \\to C}$, et $A$ n'étant pas superclé, la relation n'est même pas en 3FN… si $A$ n'est pas clé.

{{&lt; tabs &gt;}}  
{{% tab "Calcul de fermeture" %}}  
$\\Sigma = {BC \\to A,\\ AC \\to B,\\ AE \\to C,\\ D \\to BE,\\ B \\to DE,\\ C \\to E}$

$D^+$ : $D \\to BE$ donne $BDE$ ; $B \\to DE$ (rien de neuf) ; il manque $A, C$ → $D$ n'est pas clé.

$(AD)^+$ : $A, D$ → $D \\to BE$ → $ABDE$ → $B \\to DE$, $AE \\to C$ → $ABCDE$ = R → **AD est clé**.

En explorant les fermés par taille croissante : **dès qu'on trouve une clé, ne pas explorer ses sur-ensembles** (tous fermés sur $R$).  
{{% /tab %}}  
{{% tab "Preuve par règles" %}}  
$\\Sigma = {ABC \\to E;\\ BE \\to D;\\ BD \\to C}$, montrer $\\Sigma \\models BE \\to C$ :

1. $BE \\to D$ (donnée)
2. $BDE \\to BD$ (réflexivité) ; $BD \\to C$ (donnée) → $BDE \\to C$ (augmentation/transitivité)
3. $BE \\to BDE$ (réflexivité), puis transitivité avec 2 → $BE \\to C$ ∎  
{{% /tab %}}  
{{&lt; /tabs &gt;}}

## 7. Couvertures minimales (TD8)

**Algorithme** :

1. **Normaliser** : parties droites en singletons ; fermer les parties gauches ($X \\to X^+$).
2. **Réduire** : élaguer les attributs inutiles à gauche (si $(X \\setminus {A})^+ \\supseteq Y$, retirer $A$) et à droite.
3. **Éliminer les DF redondantes** : si $\\Sigma' - {X \\to Y} \\vdash X \\to Y$ (recalculer $X^+$ **sans** elle), la supprimer.


| Notion                                     | Définition                                                                                                       |
| ------------------------------------------ | ---------------------------------------------------------------------------------------------------------------- |
| **Équivalence** $\\Sigma \\equiv \\Sigma'$ | Chaque DF de l'un est inférée par l'autre, **et réciproquement** (via les fermetures)                            |
| **Couverture minimale**                    | Plus petit ensemble de DF **équivalent** à $\\Sigma$                                                             |
| **Réduite**                                | Attributs gauches/droites minimaux                                                                               |
| ⚠️                                         | Minimale ≠ optimum/minimum ; l'ordre de traitement peut donner des couvertures **différentes mais équivalentes** |


{{&lt; tabs &gt;}}  
{{% tab "DF redondante ?" %}}  
$\\Sigma = {A \\to B;\\ A \\to C;\\ D \\to E;\\ C \\to D;\\ B \\to C;\\ BC \\to A}$

Test de $A \\to C$ : calculer $A^+$ sur $\\Sigma - {A \\to C}$ : $A \\to B$ → $AB$ → $B \\to C$ → $ABC$ → $BC \\to A$… $C \\subseteq A^+$ → **$A \\to C$ est redondante**, on la supprime.  
{{% /tab %}}  
{{% tab "Exemple complet" %}}  
$\\Sigma\_1 = {A \\to C,\\ AC \\to D,\\ E \\to AD,\\ E \\to F}$

- Équivalence avec $\\Sigma\_2 = {A \\to CD,\\ E \\to AF}$ ?
  - $E^+$ dans $\\Sigma\_1$ : $E \\to A, D$ → $A \\to C$ → $E \\to AFCD$ ⟹ $E \\to AF$ ✅
  - $A^+$ : $ACD$ ⟹ $A \\to CD$ ✅ → $\\Sigma\_1 \\vdash \\Sigma\_2$
  - Réciproquement $\\Sigma\_2 \\vdash A \\to C$ (décomposition de $A \\to CD$) et $AC \\to D$ (réflexivité) ✅ → **équivalents**.
- Réduction : $AC \\to D$ se réduit à $A \\to D$ (car $A \\to C$) → couverture minimale ${A \\to CD,\\ E \\to AF} = \\Sigma\_2$.  
{{% /tab %}}  
{{% tab "Non-redondance" %}}  
$\\Sigma = {ABC \\to D,\\ B \\to A,\\ E \\to B,\\ CE \\to D}$ sur $R = ABCDE$ :
- Retirer $CE \\to D$ : $(CE)^+$ sur le reste = $CEB A$… via $E \\to B$ puis $B \\to A$ → $ABCE$ → $ABC \\to D$ → $D$ ⊆ $(CE)^+$ → **redondante**.
- Retirer $ABC \\to D$ : $(ABC)^+$ sans elle = $ABC$ seul → pas $D$ → non redondante… d'où : **tester chaque DF une par une**, la réponse dépend de l'ordre (ici $\\Sigma$ n'est pas minimale).  
{{% /tab %}}  
{{&lt; /tabs &gt;}}
