
    
/**************
 solution to problem 6, Duke ACM Internet programming contest
 by: Owen Astrachan
 date: 10/23/90

 builds skyline as a linked list, as a new building is read, the
 skyline is updated to reflect the addition of the building.

 The algorithm assumes that buildings are processed in sorted order
 (by left x-coordinate)

**************/

#include <stdio.h>

#define MAX	30	/* maximum number of buildings */

typedef struct build{   /* a building */
    int l,h,r;      
} build;

typedef struct node{    /* an element of the skyline */
    int info;
    struct node *next;
} node;

build city[MAX];       	/* all the buildings */
node *sky;  		/* references the skyline list */
int numBuildings;   	/* number of buildings to process */
void PrintSkyline();

void
ReadCity()
/* read all buildings in data file, assumes a building triple
 * comes on a single line
 */
{
    numBuildings = 0;
    while (scanf("%d %d %d\n",
		 &city[numBuildings].l,
		 &city[numBuildings].h,
		 &city[numBuildings].r) == 3){
	numBuildings++;
    }		 
}

void
AddNode(list,n)
     node *list;
     int n;
/* add a node containing n after the node pointed to by list */     
{
    node *temp;

    temp = list->next;
    list->next = (node *) malloc(sizeof(node));
    list->next->info = n;
    list->next->next = temp;
}
     

void
MakeSkyline()
{

    int i;
    node *sky1,*sky2,*newhigh;
    node *temp,*trail;

    /* initialize skyline list to represent first building */
    
    sky = (node *) malloc(sizeof(node));
    sky->info = city[0].l;
    sky->next = (node *) NULL;
    
    AddNode(sky,city[0].h);
    AddNode(sky->next,city[0].r);
    AddNode(sky->next->next,0);

    /* now process the remaining buildings */
    
    for(i=1;i<numBuildings;i++){

	/* find where to insert new biulding */
	
	sky1 = sky;
	while (sky1->next->next != (node *) NULL &&
	       sky1->next->next->info < city[i].l)
	    sky1 = sky1->next->next;

	/* sky1 points to vertical line just before left-edge */
	/* of new building */
	
	sky2 = sky1->next;

	/* sky2 points to height (horizontal piece) of first building */
	/* that might be altered by addition of new building */

	if (sky1->next->info < city[i].h){  /* new building taller? */
	    if (sky1->info < city[i].l){
		/* new building comes "after", need L shaped section */
		AddNode(sky1,sky2->info);
		AddNode(sky1->next,city[i].l);
		AddNode(sky1->next->next,city[i].h);
		newhigh = sky1->next->next->next;
	    }
	    else{   /* new building shares left edge with skyline */
		AddNode(sky1,city[i].h);
		newhigh = sky1->next;
	    }

	    /* newhigh points to new horizontal part of skyline */
	    /* that is the highest horizontal piece in the skyline */

	    /* search to find where new building's right edge */
	    /* intersects skyline */
	    
	    temp = sky2;
	    while (temp->next != (node *) NULL &&
		   temp->next->info < city[i].r){
		temp = temp->next->next;
	    }

	    /* temp references horizontal piece which will be */
	    /* "touched" by new building's right edge */
	    
	    if (temp->next == (node *) NULL ||
		city[i].r < temp->next->info){

		/* must add new right edge (vertical section) */
		AddNode(newhigh,city[i].r);
		newhigh->next->next = temp;
	    }
	    else{ /* equal, no new vertical section needed */
		newhigh->next = temp->next;
	    }
	}
	else {   		    	/* new building is smaller */

	    temp = sky2;          
	    trail = sky2->next;   

	    /* invariant: trail references vertical skyline slice */
	    /*            that is the last vertical slice intersected */
	    /*            by new building's "roof" */

	    /* search to find where new building's right edge */
	    /* intersects skyline, update trail and temp to */
	    /* maintain invariant */
	    
	    while (temp->next != (node *) NULL &&
		   temp->next->info < city[i].r){
		if (temp->info > city[i].h)
		    trail = temp->next;
		temp = temp->next->next;
	    }
	    if (temp->info < city[i].h){
		AddNode(trail,city[i].h);
		if (temp->next == (node *) NULL ||
		    temp->next->info > city[i].r){

		    /* must add new right edge (vertical section) */
		    AddNode(trail->next,city[i].r);
		    trail->next->next->next = temp;
		}
		else{  /* equal, no vertical edge needed */
		    trail->next->next = temp->next;
		}
	    }
	}
    }
}

void
PrintSkyline(list)
     node *list;
{
    
    for(;list != (node *) NULL;list = list->next) {
	printf("%d ",list->info);
    }
    printf("\n");
}


main()
{
    ReadCity();
    MakeSkyline();
    PrintSkyline(sky);
}
