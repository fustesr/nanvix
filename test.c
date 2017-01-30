
#define PROC_READY 1 
#define PROC_NOT_REDY 0

#define NB_PROC 5


struct proc
{
	int state = PROC_READY;
	int counter = 0;
	int nice = 0;
	int priority = 0;
};

void initProc(struct proc p){
	int Tpriority[NB_PROC] = {-100, -40, -20, 20, -40};
	int i;
	for(i=0; i<NB_PROC; i++){
		p[i]->priority = Tpriority[i];
	}

}

int main(){
	
	*struct p = malloc(NB_PROC*sizeof(struct proc))

	initProc(p);


	next = IDLE;
	for (p = p[0]; p <= p[NB_PROC]; p++)
	{

		/* Skip non-ready process. */
		if (p->state != PROC_READY)
			continue;
		
		/*
		 * Process with higher
		 * waiting time found.
		 */
		if (p->counter -p->priority - p->nice > next->counter- next->priority - next->nice)
		{
			next->counter++;
			next = p;
		}
			
		/*
		 * Increment waiting
		 * time of process.
		 */
		else
			p->counter++;
	}
}