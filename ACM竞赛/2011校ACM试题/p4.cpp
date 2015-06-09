
    
/**************
 solution to problem 5, Duke ACM Internet programming contest
 by: Owen Astrachan
 date: 10/19/90


 Brute force will not determine arbitrage sequences for a series of
 n countries where n is large in any reasonable amount of time.

 The solution here could be cleaned up, but the algorithm will be the
 same.

 We maintain a 2-d array dtable such that after k currency exchanges
 dtable[i][j] holds the maximum profit obtained by starting in country i
 and ending in country j i.e., an arbitrage sequence of the form

       i -->  --->   ---> ... ---> j

 where there are k steps in the exchange sequence.

 Initially dtable is the table of exchange rates read from input and k=1,
 we iterate building up dtable until we find an arbitrage sequence or
 until the maximum number of exchanges is reached.

 At any step we can determine if an arbitrage sequence exists by
 calculating dtable[i][j] * table[j][i] (make the sequence a cycle)
 where table is the table of exchange rates read as input.

 We also maintain a 3-d table arbtable such that arbtable[i][j] is
 the sequence of exchanges leading to dtable[i][j]
 
**************/



#include <stdio.h>

#define MAXD	20    
#define PROFIT  1.01

float table[MAXD][MAXD];
float dtable[MAXD][MAXD];
float temptable[MAXD][MAXD];

int arbtable[MAXD][MAXD][MAXD];
int temparbtable[MAXD][MAXD][MAXD];

int dimension;	/* the number of countries */

int
ReadTable()
/* return 1 if exchange rates read, 0 otherwise */     
{
    int i,j;
    if (scanf("%d\n",&dimension) != 1)
	return 0;
    for(i=0;i<dimension;i++){
	for(j=0;j<dimension;j++){
	    if (i==j){
		table[i][j] = 1.0;
		dtable[i][j] = 1.0;
		arbtable[i][j][0] = j;
		continue;
	    }
	    scanf("%f",&(table[i][j]));
	    dtable[i][j] = table[i][j];
	    arbtable[i][j][0] = j;
	}
    }
    return 1;
}

void
Copy3Tables(t1,t2,n)
     int t1[MAXD][MAXD][MAXD], t2[MAXD][MAXD][MAXD];
     int n;
     
/* copy first n entries of paths from t2 to t1 */
{
    int i,j,k;
    for(i=0;i<dimension;i++)
	for(j=0;j<dimension;j++)
	    for(k=0;k<n;k++)
		t1[i][j][k] = t2[i][j][k];
}

void
Copy2Tables(t1,t2)
     float t1[MAXD][MAXD],t2[MAXD][MAXD];
     
/* copy t2 to t1 */     
{
    int i,j;
    for(i=0;i<dimension;i++){
	for(j=0;j<dimension;j++){
	    t1[i][j] = t2[i][j];
	}
    }
}

void
OneStep(n)
     int n;
{
    int i,j,k,maxIndex;
    float maxAmount,temp;
    

    /* take the n-th step, copy tables for use in processing the step */
    Copy2Tables(temptable,dtable);
    Copy3Tables(temparbtable,arbtable,n);
    
    for(i=0;i<dimension;i++){
	for(j=0;j<dimension;j++){
	    maxAmount = -100.0;

	    /* calculate new max for dtable[i][j] by going from
	       i to k and k to j for all k
	     */
	    
	    for(k=0;k<dimension;k++){
		if (k==j)
		    continue;
		if ((temp = (dtable[i][k]*table[k][j])) > maxAmount){
		    maxAmount = temp;
		    maxIndex = k;
		}
	    }

	    /* found a new max, update max and path to max */
	    temptable[i][j] = maxAmount;
	    for(k=0;k<n;k++)
		temparbtable[i][j][k] = arbtable[i][maxIndex][k];
	    temparbtable[i][j][n] = j;
	}
    }

    /* copy tables back */
    Copy2Tables(dtable,temptable);
    Copy3Tables(arbtable,temparbtable,n+1);
}

int
CycleExists(from,to)
     int *from, *to;
     
/* return 1 if arbitrage cycle exists and store start and end of */
/* cycle in from, to respectively, return 0 if no cycle exists */     
{
    int i,j;

    for(i=0;i<dimension;i++){
	for(j=0;j<dimension;j++){
	    if (dtable[i][j]*table[j][i] > PROFIT){
		*from =i;
		*to = j;
		return 1;
	    }
	}
    }
    return 0;
}

void
PrintCycle(start,finish,steps)
     int start,finish,steps;
/* print the sequence consisting of steps transactions from */
/* first country == start to last country == finish */
{
    int i;

    /* add one when printing for output, countries start at 1, not 0 */
    
    printf(" %d",start+1);
    for(i=0;i<steps;i++){
	printf(" %d",arbtable[start][finish][i]+1);
    }
    printf(" %d\n",start+1);
}


main()
{

    int i,found;
    int arb;
    int start,finish;
    
    while(ReadTable()){
	found = 0;
	for(i=1;i<dimension;i++){
	    if (CycleExists(&start,&finish)){
		PrintCycle(start,finish,i);
		found = 1;
		break;
	    }
	    OneStep(i);
	}
	if (!found)
	    printf("no arbitrage sequence exists\n");
    }
}


