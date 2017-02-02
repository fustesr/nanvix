NANVIX
=====================


_Scheduling sur les priorités_

Dans un premier temps, nous avons essayé d’implémenter la méthode par priorité en changeant la condition qui permet de choisir le prochain processus à exécuter. 
Avant le choix se faisait sur les compteurs (counter), nous avons essayé de faire jouer la priorité dedans.


If (11* p->counter -p->priority > next->11 * counter- next->priority )
{
	next->counter++;
 	next = p;
 }

Cette première implémentation permet de faire intervenir les priorités tout en laissant un impact aux compteurs. C'est à dire qu'un processus A avec une priorité plus grande qu'un autre processus B pourra se faire piquer la place si le compteur du processus B est vraiment trop grand. 
PS : on règle l'impact des compteurs grâce au coefficients placés devant. Exemple ici : 11


La méthode nous avons implémenté est plus sévèrement basé sur les priorités. C'est à dire qu'un processus plus prioritaire qu'un autre sera en moyenne beaucoup plus souvent exécuté. Et si il y a égalité, le champ « nice » et compteur servira à départager.
Cependant pour éviter que les processus à plus faible priorité ne soit jamais exécutés, on utilise un coefficient de 2 ( c'est à dire qu'il faut  au moins 10 rejet à un processus pour égaler prioritairement un processus de priorité un cran au dessus).

Dans le cas ou, plusieurs processus sont égaux au niveau de la condition, c'est le premier processus traité qui sera choisi comme prioritaire.
C'est pourquoi après avoir choisi notre processus prioritaire, il y a une autre vérification qui permet de départager tout les processus étant égalité dans la condition, grâce aux « nice » ou aux compteurs.

Voir [sched.c](nanvix/src/kernel/pm/sched.c)

 

