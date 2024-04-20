#include <stdio.h>
#include <string.h >
#define INFINITY 1000
#define MAX 25
int startnode;
void dijkstra(int Time[MAX][MAX],int n,char metrostation[24][30]);
int main()
{
	char metrostation[24][30]={"Netaji Subash Place","Inderlok","Kashmere Gate","Welcome",
						"Azadpur","Rajiv Chowk","New Delhi","Central Secretarist",
						"Delhi Haat INA","Hauz Khas","Punjabi Bagh West","Ashok Park Main",
						"Karkarduma","Yamuna Bank","Mandi House","Kirti Nagar",
						"Rajouri Garden","Janakpuri West","Dwarka","Dwarka Sector 21",
						"Lajpat Nagar","Kalkaji Mandir","Mayur Vihar I","Botanical Garden"};
	char input[30];
	int metroindex=-5;
	int Time[MAX][MAX]={{0,6,1000,1000,5,1000,1000,1000,1000,1000,6,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000},
					    {6,0,10,1000,1000,1000,1000,1000,1000,1000,1000,3,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000},
					    {1000,10,0,8,13,9,6,1000,1000,1000,1000,1000,1000,1000,10,1000,1000,1000,1000,1000,1000,1000,1000,1000},
					    {1000,1000,8,0,1000,1000,1000,1000,1000,1000,1000,1000,8,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000},
					    {5,1000,13,1000,0,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000},
					    {1000,1000,9,1000,1000,0,2,4,1000,1000,1000,1000,1000,1000,4,15,1000,1000,1000,1000,1000,1000,1000,1000},
					    {1000,1000,6,1000,1000,2,0,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,19,1000,1000,1000,1000},
					    {1000,1000,1000,1000,1000,4,1000,0,9,1000,1000,1000,1000,1000,5,1000,1000,1000,1000,1000,11,1000,1000,1000},
					    {1000,1000,1000,1000,1000,1000,1000,9,0,7,1000,1000,1000,1000,1000,1000,23,1000,1000,1000,5,1000,1000,1000},
					    {1000,1000,1000,1000,1000,1000,1000,1000,7,0,1000,1000,1000,1000,1000,1000,1000,34,1000,1000,1000,11,1000,1000},
					    {6,1000,1000,1000,1000,1000,1000,1000,1000,1000,0,4,1000,1000,1000,1000,5,1000,1000,1000,1000,1000,1000,1000},
					    {1000,3,1000,1000,1000,1000,1000,1000,1000,1000,4,0,1000,1000,1000,5,1000,1000,1000,1000,1000,1000,1000,1000},
					    {1000,1000,1000,8,1000,1000,1000,1000,1000,1000,1000,1000,0,10,1000,1000,1000,1000,1000,1000,1000,1000,21,1000},
					    {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,10,0,7,1000,1000,1000,1000,1000,1000,1000,6,1000},
					    {1000,1000,10,1000,1000,4,1000,5,1000,1000,1000,1000,1000,7,0,1000,1000,1000,1000,1000,1000,1000,1000,1000},
					    {1000,1000,1000,1000,1000,15,1000,1000,1000,1000,1000,5,1000,1000,1000,0,6,1000,1000,1000,1000,1000,1000,1000},
					    {1000,1000,1000,1000,1000,1000,1000,1000,23,1000,5,1000,1000,1000,1000,6,0,10,1000,1000,28,1000,1000,1000},
					    {1000,1000,1000,1000,1000,1000,1000,1000,1000,34,1000,1000,1000,1000,1000,1000,10,0,11,1000,1000,1000,1000,1000},
					    {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,11,0,18,1000,1000,1000,1000},
					    {1000,1000,1000,1000,1000,1000,19,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,18,0,1000,1000,1000,1000},
					    {1000,1000,1000,1000,1000,1000,1000,11,5,1000,1000,1000,1000,1000,1000,1000,28,1000,1000,1000,0,8,14,1000},
					    {1000,1000,1000,1000,1000,1000,1000,1000,1000,11,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,8,0,1000,25},
					    {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,21,6,1000,1000,1000,1000,1000,1000,14,1000,0,13},
					    {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,25,13,0}
					
};
	int n=24;
	printf("\nEnter the source metro station out of the following stations considered:\n");
	for(int i = 0; i < 24 ; i++)
	{
		printf("%s\t",metrostation[i]);
	}
	printf("\n\nYour location:");
	gets(input);
	
	for(int i=0;i<n;i++)
	{
		if(strcmp(metrostation[i],input)==0)
		{
			metroindex=i;
			break;
		}
	}
	if(metroindex== -5)
	{
		printf("Source you entered is wrong.Please enter correct source station.");
		printf("\nPlease enter the full station name in the  title format as shown below:\n ");
		printf("For example, if the name of the station is kashmere gate then enter it as 'Kashmere Gate");
	}
	startnode=metroindex;
	dijkstra(Time,n,metrostation);
	return 0;
}

void dijkstra(int Time[MAX][MAX],int n,char metrostation[24][30])					// dijkstra's algorithm in code
{
	int time[MAX],predefine[MAX],visited[MAX];
	int nextnode,count,mintime,i,j;
	for( i=0;i<n;i++)
	{
		time[i]=Time[startnode][i];
		predefine[i]=startnode;
		visited[i]=0;
	}
	visited[startnode]=1;
	count =1;											// initialise for while loop
	while(count<n-1)									// why we use count<n-1
	{
		mintime=INFINITY;
		for(i=0;i<n;i++)								// next node gives us the node at minimum distance
		{
			if(time[i]<mintime && !visited[i])
			{mintime=time[i];
			nextnode=i;
			}
		}
		visited[nextnode]=1;				// check a better path exist through next node
		for(i=0;i<n;i++)
		{
			if(!visited[i])
			{
				if(mintime+Time[nextnode][i]<time[i])
				{
					time[i]= mintime+Time[nextnode][i];
					predefine[i]=nextnode;						// for shortest path
				}
			}
		}
		count++;
	}
// Print the path and distance of each node
	for(i=0;i<n;i++)
	{
		if(i!=startnode)
		{
			printf("\n \n Time for station '%s': = %d minutes.",metrostation[i],time[i]);
			printf("\nPath of station : %s  ",metrostation[i]);
			j=i;
			do
			{
				j=predefine[j];
				printf("<-%s",metrostation[j]);
			}
			while(j!=startnode);
			printf("\n"); 
		}
	}	
	
}