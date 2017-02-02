NANVIX
=====================


_Scheduling sur les priorités_

Dans un premier temps, nous avons essayé d’implémenter la méthode par priorité en changeant la condition qui permet de choisir le prochain processus à exécuter. 
Avant le choix se faisait sur les compteurs (counter), nous avons essayé de faire jouer la priorité dedans.

```C
if (11* p->counter -p->priority > next->11 * counter- next->priority )
{
	next->counter++;
 	next = p;
 }
```

Cette première implémentation permet de faire intervenir les priorités tout en laissant un impact aux compteurs. C'est à dire qu'un processus A avec une priorité plus grande qu'un autre processus B pourra se faire piquer la place si le compteur du processus B est vraiment trop grand. 
PS : on règle l'impact des compteurs grâce au coefficients placés devant. Exemple ici : 11


La méthode que nous avons implémenté est plus sévèrement basé sur les priorités. C'est à dire qu'un processus plus prioritaire qu'un autre sera en moyenne beaucoup plus souvent exécuté. Et si il y a égalité, le champ « nice » et compteur servira à départager.
Cependant pour éviter que les processus à plus faible priorité ne soit jamais exécutés, on utilise un coefficient de 2 ( c'est à dire qu'il faut  au moins 10 rejet à un processus pour égaler prioritairement un processus de priorité un cran au dessus).

Dans le cas ou, plusieurs processus sont égaux au niveau de la condition, c'est le premier processus traité qui sera choisi comme prioritaire.
C'est pourquoi après avoir choisi notre processus prioritaire, il y a une autre vérification qui permet de départager tout les processus étant égalité dans la condition, grâce aux « nice » ou aux compteurs.

Voir [sched.c](sched/sched.c)

 
</br></br>

_Scheduling avec lottery_

Pour implémenter cette méthode, nous avons du modifier 5 fichiers: [sched.c](nanvix/src/kernel/pm/sched.c), [fork.c](nanvix/src/kernel/sys/fork.c), [die.c](nanvix/src/kernel/pm/die.c) et [pm.c](nanvix/src/kernel/pm/pm.c) / [pm.h](nanvix/include/nanvix/pm.h)

Dans le fichier **pm.h**, on définit la taille max du tableau de ticket (8 étant le nombre de ticket assignés pour la priorité maximum) :
```C
	#define SIZE_TAB_TICKET PROC_MAX*8
```
Vous trouverez dans **pm.c** les fonctions principales utilisées pour la lottery.

** *nb_ticket(int priority)* : permet de définir un nombre de ticket à assigner à un processus p selon sa priorité.

** *add_ticket(struct process* p)* : permet d'allouer un nombre de tickets à un processus. Un ticket pour un processus p est un pointeur vers ce processus p. Le tableau de ticket est, de facto, un tableau de pointeur de processus.

** *defragment()* : permet de regrouper tous les tickets au début du tableau (tab_ticket) pour pouvoir facilement faire un random dessus.

** *remove_ticket(struct process* p)* : permet de retirer les tickets correspondant à un processus.

** Dans le fichier **sched.c** :

Dans la méthode yield(), il ne s'agit plus maintenant de parcourir le tableau de processus mais de choisir un processus au hasard grace à notre fonction *next_process()* qui utilise notre fonction *rand()*. Le tirage se fait du début du tableau jusqu'à *$total_ticket* (c'est ici que sert la fonction defragment()).

Dans le fichier **fork.c** et **die.c** :

Dans ces fichiers, on utilise nos fonctions pour assigner des tickets à la création d'un processus (*add_ticket*) et les retirer à la destruction d'un processus (*remove_ticket* et *defragment*).

  
