Le **command top** sur Linux fournit une vue dynamique des processus en cours d'exécution sur le système. Voici une description des colonnes principales que l'on peut trouver dans cette interface, qui peut varier légèrement selon la version de **top** :

---

| **Colonne** | **Description**                                                                                    |
| ----------- | -------------------------------------------------------------------------------------------------- |
| **PID**     | Identifiant unique du processus.                                                                   |
| **USER**    | Nom de l'utilisateur qui possède le processus.                                                     |
| **PR**      | Priorité du processus. Une valeur plus basse indique une priorité plus élevée.                     |
| **NI**      | Valeur "nice", qui influence la priorité du processus. Une valeur plus élevée diminue la priorité. |
| **VIRT**    | Mémoire virtuelle totale utilisée par le processus.                                                |
| **RES**     | Mémoire physique réelle utilisée (en mémoire RAM).                                                 |
| **SHR**     | Mémoire partagée utilisée par le processus.                                                        |
| **S**       | État du processus (R = en cours d'exécution, S = en sommeil, Z = zombie, etc.).                    |
| **%CPU**    | Pourcentage d'utilisation du CPU par le processus.                                                 |
| **%MEM**    | Pourcentage de la mémoire totale du système utilisée par le processus.                             |
| **TIME+**   | Temps CPU total utilisé par le processus.                                                          |
| **COMMAND** | Nom ou chemin du programme exécuté.                                                                |

---

### Détails supplémentaires

- **PID (Process ID)** : Chaque processus en cours d'exécution dispose d'un identifiant unique (PID) qui permet de le gérer, de le suivre ou de le terminer.

- **USER** : Indique quel utilisateur l'a lancé, ce qui est utile pour comprendre les permissions et le contexte d'exécution.

- **PR (Priority)** et **NI (Nice Value)** : Ces deux colonnes sont interconnectées. La priorité détermine combien de temps un processus peut utiliser le CPU par rapport aux autres. La valeur "nice" permet aux utilisateurs de modifier cette priorité.

- **VIRT, RES et SHR** : Ces colonnes offrent une vue de la consommation de mémoire, ce qui est crucial pour le diagnostic des problèmes de performance.

- **S (State)** : Cette colonne aide les administrateurs à comprendre le comportement des processus, par exemple, s'ils sont bloqués ou s'ils s'exécutent normalement.

- **%CPU et %MEM** : Ces indicateurs sont essentiels pour le monitoring de l'utilisation des ressources du système, permettant de repérer les processus gourmands en ressources.

Cette vue en temps réel permet d'identifier rapidement les problèmes de performance, les processus qui consomment trop de ressources, et de prendre des décisions adéquates pour optimiser le système.
