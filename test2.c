/*
 * test.c
 * 
 * Copyright 2017 Maxime <chevamax@maxime-Satellite-Pro-R50-B>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	int counter[6] = {50,50,50,50,50,50};
	int priority[6] = {0,-100,20,-40,40};
	int nice[6] = {0,10,5,-15,7,-8};
	int nbFois[6] = {0,0,0,0,0,0};

	int p;
	int j;
	int next = 0;
	for(j=0; j <500; j++){
		for(p=0; p <6; p++)
		{
			if (priority[p] < priority[next])
			{
					counter[next]++;
					next = p;
			}
			else{
				counter[p]++;
			}
		}

		(0,-100,-100)
		(0,10,-10)

		for(p=0; p <6; p++)
		{
			if (priority[p] == priority[next] && nice[p] < nice[next] && compteur[p] > )
			{
					counter[next]++;
					next = p;
			}

		}



		printf("Processus choisi : %d\n", next);
		counter[next] = 0;
		nbFois[next]++;
		int i;
		for(i=0; i<6;i++){
			printf("  %d (%d)", counter[i], priority[i]);
		}
		printf("\n");
		
		// Pause / Resume
		//char s;
		//do{ s = getchar(); }while(s!='\n');
	}	
	int i;
	for(i=0; i<6;i++){
			printf(" %d", nbFois[i]);
		}
		printf("\n");
	
	
	return 0;
}

