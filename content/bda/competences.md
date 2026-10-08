+++
title="competences"
draft=false
+++

# Schéma E/A
## les éléments du schéma E/A : entité, entité faible, association . . .
## les cardinalités des associations
## les contraintes d’inclusion
# Énoncé
## modéliser une entité dans mon schéma E/A
## modéliser une association (binaire) dans mon schéma E/A
## modéliser une association ternaire dans mon schéma E/A
## spécifier les cardinalités pertinentes des associations dans mon schéma E/A
## spécifier les contraintes d’inclusion dans mon schéma E/A
# Traduction
## une entité en relation avec la clé primaire correctement définie
## une entité faible en relation avec la clé primaire et la clé étrangère correctement définies
## une association one-to-many en clé étrangère
## une association one-to-many ou ternaire relation avec les clés primaires et étrangères correctement définies
# Identifier les contraintes 
## qui sont exprimables au niveau du modèle conceptuel
## qui sont exprimables uniquement au niveau du SGBD
## qui sont exprimables uniquement au niveau de l’application 













Thought for 37s
User wants, from competences.md and cours.pdf, the "marche à suivre" (how-to) for each competency. Need to read the PDF. No PDF reading tool directly—maybe use bash to extract text? Try pdftotext? Probably not available. Check tools for pdf extraction. Let's inspect.
The transcript is large; I have pages 1–38 partially. I need pages on translation E/A → relationnel (ch 3), and constraints levels (conceptuel/SGBD/application). Let me search the pages directory with rg.
I need also pages about "contraintes exprimables au niveau conceptuel/SGBD/application" — maybe earlier in chapter on structure et contraintes (pages ~40-50), and maybe page 53 covers. Also cardinalities interpretation pages 19-20, weak entity 21-22, inclusion 27-29. Check pages about contraintes levels.
I have enough. Now produce a guide in French: for each competency, the "marche à suivre" based on the course (cite pages). Long structured answer — could be a canvas, but chat is fine. The user asked "dis moi quelle est la marche à suivre" — a chat answer. Use rich-ui checklist? It's a list... The system says use Checklist component for lists. But this is really a substantive guide. I'll answer in chat in French, structured. Keep reasonably concise but complete.













Voici la marche à suivre pour chaque compétence, appuyée sur ton cours (Conception de BD, Université Lyon 1) :
1. Interpréter un schéma E/A en langage naturel
Éléments du schéma (entité, entité faible, association)
Repérer les rectangles : ce sont les entités (des « choses » du monde réel : étudiant, diplôme…), avec leurs attributs.
Repérer l'attribut souligné : c'est l'identifiant, qui désigne chaque entité de façon unique.
Repérer les doubles rectangles/losanges : entité faible = entité qui n'existe que par rapport à une autre (ex. une Salle n'a de sens que dans son Bâtiment ; son identifiant local ne suffit pas).
Repérer les losanges : ce sont les associations (relations entre 2 entités = binaires, entre 3 ou plus = n-aires), qui peuvent porter leurs propres attributs (ex. date d'inscription).

faire un schema recapitulatif

Cardinalités
Pour chaque patte de l'association, lire le couple (participation, connectivité) :Participation : 0 = facultative, 1 = obligatoire (« un étudiant DOIT être inscrit »).
Connectivité : 1 = au plus une entité en face, N = plusieurs possibles.

Traduire en phrases : « un étudiant est inscrit dans au plus une formation », « une formation a plusieurs étudiants, éventuellement aucun ».
Contraintes d'inclusion
Repérer la flèche I entre deux associations A₁ → A₂ impliquant les mêmes entités.
Lire : « toute entité participant à A₁ participe aussi à A₂ ». (Une double flèche = égalité : inclusion dans les deux sens.)
2. Modéliser à partir d'un énoncé
Identifier une entité
Chercher les noms/nom d'objets du domaine avec des propriétés propres (« chaque employé est identifié par un n° de sécurité sociale, a un nom, un salaire »).
Choisir ses attributs (simples, atomiques ; multivalués marqués *).
Souligner un identifiant (jamais un attribut multivalué). Vérifier l'unicité.
Identifier une entité faible : si l'identifiant local ne suffit pas (deux salles n°1 dans deux bâtiments) et qu'il y a un lien existentiel — l'entité n'existe que si l'autre existe.
Association binaire
Chercher les verbes reliant deux entités (« s'inscrit dans », « travaille dans »).
Lui donner un nom, lui affecter ses attributs propres s'il y en a (ex. le prix payé par l'étudiant pour un module).
Règle de vigilance : une association n'a jamais d'attribut souligné — sinon il manque une entité.
Association ternaire (n-aire)
Se demander si les trois entités interagissent réellement ensemble dans un même fait.
Test du cours : tous les sous-ensembles d'entités peuvent-ils se répéter ? Si non, ce n'est pas une vraie n-aire : utiliser une agrégation (l'association binaire devient une pseudo-entité qu'on associe à la troisième).
Cardinalités
Pour chaque entité, poser deux questions à partir de l'énoncé : « est-elle obligée de participer ? » (participation 0/1) et « à combien d'entités en face peut-elle se lier ? » (connectivité 1/N).
Justifier chaque cardinalité par une phrase de l'énoncé ; lister ce qui n'est pas décidé.
Contraintes d'inclusion
Chercher dans l'énoncé des phrases du type « toute entité qui fait X fait aussi Y ».
Tracer la flèche I entre les deux associations concernées (et T, X, XT pour les spécialisations/participations si pertinent).
Rappel du cours : le graphe doit être connexe ; un cycle n'est pas une erreur mais mérite attention.
3. Passer du conceptuel au relationnel
Entité → relation
Créer une relation (table) du même nom.
Tous les attributs deviennent des colonnes.
L'identifiant souligné devient la clé primaire.
Entité faible → relation
Créer la relation avec ses attributs + sa clé locale.
Ajouter la clé de l'entité forte comme clé étrangère (référence vers la relation forte).
Clé primaire = clé étrangère + identifiant local (ex. NumBat + NumSalle). (Pour une entité spécialisée, c'est différent : la clé étrangère seule est la clé, et on ne répète aucun attribut hérité.)
Association one-to-many
Solution alternative recommandée : quand une entité a une connectivité de 1 vers l'association, placer directement la clé étrangère dans cette entité, qui référence la clé de l'autre.
Association many-to-many ou ternaire → relation
Créer une relation pour l'association.
Attributs = attributs de l'association + duplication des clés de chaque entité participante, chacune avec contrainte de clé étrangère.
Clé primaire : composée des clés étrangères de toutes les entités à connectivité N (règle générale : la clé étrangère de chaque entité de connectivité 1 fait partie de la clé).
Ensuite : simplifier si possible en justifiant, traduire les contraintes avancées (T, X…) quand c'est possible, et garder un diagramme E/A à jour équivalent au schéma implémenté.
4. Situer les contraintes selon le niveau
Exprimables au niveau conceptuel : cardinalités (participation/connectivité), contraintes de totalité T, exclusivité X, partition XT, inclusion I, égalité — tout ce qui se dessine sur le schéma E/A.
Exprimables au niveau du SGBD : les trois types de contraintes du modèle relationnel : clés, clés étrangères (contrainte d'existence) et contraintes de domaine (types, listes de valeurs, NULL autorisé ou non, conditions entre attributs). Les contraintes avancées qui se traduisent en clés/clés étrangères/domaines restent ici.
Uniquement au niveau de l'application (ou programmées spécifiquement sur le serveur) : toute contrainte du cahier des charges qui ne se traduit ni en clé, ni en clé étrangère, ni en contrainte de domaine — il faut alors la programmer spécifiquement et la documenter ; le schéma E/A « commenté » garde la trace de ces spécifications non modélisées.





