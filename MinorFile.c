#include<stdio.h>
#include<time.h>
#include <stdlib.h>
#include<graphics.h>
# define Infinity 999
# define Max 100
int Predd[Max], Predb[Max], Predff[Max][Max], Predf[Max];	
double runtime_Bel, runtime_Dij, runtime_Floyd;
int kk=0,w;
double D[Max], B[Max], F[Max];
void dijikstra(int G[Max][Max], int n , int startnode);
void bellman(int G[Max][Max],int n,int startnode);
void floydWarshall(int G[Max][Max],int n);

void Display(int Pred[], int startnode, int n,int f)
{	
	int x1=960, y1=50;
	int x=45, y=80;
	int r=15;
	char str[3];
	int i,j, count,X[n],Y[n],p,c=1,h,v,d, largestnegative,k=-1, a;	
	if(f==1)
	{
		outtextxy(0,0,"Dijikstra's Algorithm:");
		a=0;
	}
	else if(f==2)
	{
		outtextxy(0,0,"Bellman Algorithm:");
		if(w==0)
		{
			a=0;
		}
		else
		{
			a=1;
			outtextxy(150,150,"Negative Cycle Found!!! Can't give the result.");
		}	
	
	}
	else if(f==3)
	{
		outtextxy(0,0,"Floyd-Warshall Algorithm:");
		if(w==0)
		{
			a=0;
		}
		else
		{
			a=1;
			outtextxy(150,150,"Negative Cycle Found!!! Can't give the result.");
		}
	}	
		
	if(a==0)
	{
			//first circle
			X[startnode]=x1;
 		  	Y[startnode]=y1;
		   	setcolor(BLUE);
		   	circle(X[startnode], Y[startnode], r); 				//void circle(int x, int y, int radius)
  		 	floodfill(X[startnode],Y[startnode],BLUE);
		   	sprintf(str,"%d",startnode+1);
 		  	outtextxy(x1-3,y1-3,str);
   	
			largestnegative=startnode;
			Pred[startnode]=-1;
	
			for(i=0;i<n;i++)							//Only to check the Pred values for while Loop
			{
			   	while(Pred[i]>-1)
			   	{	
					count=0;
					for(h=0;h<n;h++)
					{	
						if((Pred[h]<0)&&(Pred[largestnegative]<Pred[h]))
						{
							largestnegative=h;	
						}
					}
					for(j=0;j<n;j++)	
					{	
						p=Pred[j];
						if((p==largestnegative)&&(j!=startnode))
						{	
							delay(100);
							c++;
						
							if(count%2==1)
							{	
								X[j]=	X[p]-(x*count);		//Setting the vertices	
 							}	
 						
 							else
							{
								X[j]=	X[p]+(x*count);
 						
 							}
 					
 							Y[j]=	Y[p]+(y);
 					
 							//line						
 							setcolor(GREEN);
   							line(X[p],(Y[p]+r),(X[j]),(Y[j]));			//void line(int x1,int y1,int x2,int y2)
	
							//circles
							setcolor(RED);
    							circle((X[j]),(Y[j]), r);  				//void circle(int x, int y, int radius)
  							floodfill(X[j],(Y[j]),RED);
  							sprintf(str,"%d",j+1);
  							outtextxy(X[j]-3,(Y[j])-3, str);
 							
 							count++;
 							k--;
 							Pred[j]=k;
 						}
 						for(h=0;h<n;h++)
						{  d=0;
						   if(Pred[h]<0)
						   {
							for(v=0;v<n;v++)
							{
								if((h==Pred[v]))
								{
									d++;
								}					
							}
							if(d==0)
							{
								Pred[h]=-999;
							}
						   }
						}
 					}
			   	}
			}
	}
	
	delay(1000);
	cleardevice(); 
}


void GG(int G[Max][Max], int n, int startnode)
{
	int g,i=n/3,d;
	if(n%3==0)
	{
		i=n;
	}
	else if(n%3==1)
	{
		i=n+2;
	}
	else if(n%3==2)
	{
		i=n+1;
	}
	d=i/3;
	for(i=0;i<n;i++)
	{
		D[i]=-1;
		B[i]=-1;
		F[i]=-1;
	}
		dijikstra(G,n,startnode);
		D[n]=runtime_Dij;	
		bellman(G,n,startnode);
		B[n]=runtime_Bel;
		floydWarshall(G,n);
		F[n]=runtime_Floyd;	
	
		printf("Dijikstra of %d: %f\n",n,D[n]);
		printf("Bellman of %d: %f\n",n,B[n]);
		printf("Floyd of %d: %f\n",n,F[n]);

	
	for(g=d;g<n;g+=d)
	{
	    	
		dijikstra(G,g,startnode);
		D[g]=runtime_Dij;
	
		bellman(G,g,startnode);
		B[g]=runtime_Bel;
		
		floydWarshall(G,g);
		F[g]=runtime_Floyd;	
		
		printf("Dijikstra of %d: %f\n",g,D[g]);
		printf("Bellman of %d: %f\n",g,B[g]);
		printf("Floyd of %d: %f\n",g,F[g]);
	}
} 

void TG(int n)
{	
	int i,j,m=0;
	float q;
	int r=9, X=1500,Y=25, y1=25,d=13,y2=15;
	int xn=450, x1=100,yd1=850,yb1=850,yf1=850;
	double c;
	int t[Max];
	char str[3];
	int gd = 1, gm ;
	initgraph(&gd, &gm," ");
	
	setcolor(WHITE);
   	line(100,25,100,850);
   	line(100,850,1450,850);
   	setcolor(WHITE);
  	outtextxy(250,900,"No. of Nodes ----------------------------------------------------------------------------------------------------------------------------------------------------------------------->");
  	setcolor(WHITE);
  	outtextxy(35,600,"Time");
  	
  	setcolor(WHITE);
  	line(50,150,50,595);
  	outtextxy(46,145,"A");
  	
  	line(100,850,100,880);
  	outtextxy(95,882,"0");
  	
  	line(1450,850,1450,880);
  	sprintf(str,"%d",n);
  	outtextxy(1445,882,str);
  	
	
	if(n<=5)
	{
		q=25;
	}
	else if(n<=10)
	{
		q=10;
	}
	else if(n<=15)
	{
		q=5;
	}
	
	else if(n<=20)
	{
		q=5;
	}
	else if(n<=36)
	{
		q=3;
	}
	else if(n<=50)
	{
		q=1;
	}
	else if(n<=75)
	{
		q=0.5;
	}
	else if(n<=100)
	{
		q=0.2;
	}
	for(j=0;j<7+1;j++)
	{
		t[j]=-1;
	}	
		for(j=0;j<n+1;j++)
		{
			if(D[j]>-1)
			{	
				D[j]=(D[j]*1000000)*(q);
				B[j]=(B[j]*1000000)*(q);
				F[j]=(F[j]*1000000)*(q);
				
				setcolor(RED);
   				line(x1,yd1,(x1+xn),(850-D[j]));
   				t[1]=1;
   				m++;
   				t[2]=2;
   				m++;
   				setcolor(YELLOW);
				
   				if((yd1==yb1)&&((850-D[j])==(850-B[j])))					//r+y
   				{
   					setcolor(CYAN);
   					t[3]=3;
   					m++;
   				}
   				line(x1,yb1,(x1+xn),(850-B[j]));
   				
   				
   				if((yd1==yb1)&&((850-D[j])==(850-B[j]))&&(yd1==yf1)&&((850-D[j])==(850-F[j])))		//r+y+b
   				{
   					setcolor(BROWN);
   					t[4]=4;
   					m++;
   				}
   				
   				else if((yf1==yb1)&&((850-F[j])==(850-B[j])))		//y+b
   				{
   					setcolor(GREEN);
   					t[5]=5;
   					m++;
   				}
   				
   				else if((yf1==yd1)&&((850-F[j])==(850-D[j])))		//r+b
   				{
   					setcolor(MAGENTA);
   					t[6]=6;
   					m++;
   				}
   				else
   				{
   					setcolor(BLUE);
   					t[7]=7;
   					m++;
   				}
   				
   				line(x1,yf1,(x1+xn),(850-F[j]));
   			
   				x1=(x1+xn);
   				yd1=(850-D[j]);
   				yb1=(850-B[j]);
   				yf1=(850-F[j]);
   				
			}
		}
		outtextxy(X,Y,"Stands for:");
		Y=Y+30;
		for(j=0;j<=7;j++)
		{
			if(t[j]==1)
			{
				setcolor(RED);
    				circle(X,Y,r);  				//void circle(int x, int y, int radius)
  				floodfill(X,Y,RED);
  				outtextxy(X+d,Y-(r-4),"Dijkstra");
  				Y+=y1;
  			}
  			else if(t[j]==2)
  			{
				setcolor(YELLOW);
    				circle(X,Y,r);   				//void circle(int x, int y, int radius)
  				floodfill(X,Y,YELLOW);
  				outtextxy(X+d,Y-(r-4),"Bellman");
  				Y+=y1;
  			}
  			else if(t[j]==7)
			{
				setcolor(BLUE);
    				circle(X,Y,r);  				//void circle(int x, int y, int radius)
  				floodfill(X,Y,BLUE);
  				outtextxy(X+d,Y-(r-4),"Floyd");
  				Y+=y1;
  			}
  			else if(t[j]==3)
			{
				setcolor(CYAN);
    				circle(X,Y,r);    				//void circle(int x, int y, int radius)
  				floodfill(X,Y,CYAN);
  				outtextxy(X+d,Y-(r-4),"Overlaping of Dijkstra and Bellman");
  				Y+=y1;
  			}
  			else if(t[j]==5)
			{
				setcolor(GREEN);
    				circle(X,Y,r);   				//void circle(int x, int y, int radius)
  				floodfill(X,Y,GREEN);
  				outtextxy(X+d,Y-(r-4),"Overlaping of Bellman and Floyd");
  				Y+=y1;
  			}
  			else if(t[j]==6)
			{
				setcolor(MAGENTA);
    				circle(X,Y,r);   				//void circle(int x, int y, int radius)
  				floodfill(X,Y,MAGENTA);
  				outtextxy(X+d,Y-(r-4),"Overlaping of Dijkstra and Floyd");
  				Y+=y1;
  			}
  			else if(t[j]==4)
			{
				setcolor(BROWN);
    				circle(X,Y,r);  				//void circle(int x, int y, int radius)
  				floodfill(X,Y,BROWN);
  				outtextxy(X+d,Y-(r-4),"Overlaping of Dijkstra's, Bellman and Floyd");
  				Y+=y1;
  			}
		}
	
	delay(30000);
	closegraph();	
}


int main()
{
	int G[Max][Max],i,j,n=0,u=0, m=4;
	while(u==0)
	{
		
		if((n<1)||(n>50))
		{
			printf("No. you have entered is wrong. Enter value from 1 to %d\n",50);
		}
		else
		{
			u=2;
			break;
			
		}
		printf("Enter number of vertices: ");
		scanf("%d",&n);	
	}	
	{
		char ch[8],in='0';
  	int t;
    	FILE *fp ;
    	int x,i,j,k;   
    	fp = fopen("/home/bhavuk/Desktop/Input3.csv","r") ; 
    	if(fp == NULL)
    	{
     	   printf("File not found\n");
     	   exit(1);
   	} 
    
          for(i=0;i<n;i++)		
          {
           for(j=0;j<n;)
           {	
        	for(k=0; in != ','; k++)		
    		{
      		     ch[k] = in;
      		     in=fgetc(fp);
    		}
        	
        	in=fgetc(fp);
        	t=atoi(ch);
        	G[i][j] = t;
        	j++;
            	for(k=0;k<7;k++)
          	{	ch[k]=' ';
          	}
            }
            
            if(j==n)
            {
            	while(in !='\n')
            	{
            		in=fgetc(fp);
            	}
            	 in=fgetc(fp);
            }	
    	  }
    	  fclose(fp);
	}
	printf("ENTER THE ADJACENCY MATRIX\n");
	printf("(Enter 999 for all non existance of edges)\n");
	for(i=0;i<n;i++)
	{		
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
			   G[i][j]=0;
			}	
		}
	}
	printf("Enter Matrix is:-\n");
	for (i = 0; i < n; i++)
    	{
        	for (j = 0; j < n; j++)
        	{
          		printf(" ");
         	   	printf("|\t");
			printf("%d \t", G[i][j]);
			printf("|");
        	}
        	printf("\n");
    	}
    	u=n+1;
    	printf("\n\n");
	while(u>=n)
	{
		printf("Enter the Starting Node from 1 to %d (Number):\n",n);
		scanf("%d",&u);
		u--;
		if(u<n)
		{
			break;
		}
		else
		{
			printf("No. you have entered is wrong. Enter value from 1 to %d\n",n);
		}	
	}	
	printf("\n\n\n\n");
	
	printf("*** Floyd-Warshall ALGORITHM ***");
    	printf("\n\n");
	floydWarshall(G,n);
	printf("\nRuntime time of floydWarshall is: %f",runtime_Floyd);
	printf("\n\n");
	
	printf("*** DIJKSTRA ALGORITHM ***");
	printf("\n\n");
	dijikstra(G,n,u);
	printf("\nRuntime time of Dijikstra is: %f",runtime_Dij);
	printf("\n\n\n\n");
	
	printf("\n\n");
	printf("*** BELLMAN FORD ALGORITHMS ***");
	printf("\n");
	bellman(G,n,u);
	printf("\nRuntime time of Bellman is: %f",runtime_Bel);
	printf("\n\n");
	
	int gd = 1, gm ;
	initgraph(&gd, &gm," ");
    	Display(Predd,u,n,1);		//1 stands for Dijikstra
    	Display(Predb,u,n,2);		//2 stands for Bellman
    if(w==0)
    {
	
    	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			Predf[j]=Predff[i][j];
				
		}
		
		Display(Predf,i,n,3);		//3 stands for Floyd-Warshall
		
	}
    }
    else if(w=1)
    {
    		Display(Predf,i,n,3);	
    }	
	closegraph();
	
	GG(G,n,u);
	TG(n);
	return 0;
}	

void dijikstra(int G[Max][Max],int n,int startnode)
{
	clock_t start,stop;
	start = clock();
	kk++;	
	int cost[Max][Max]; //Minimum distance to reach i node to j node  for every (cost[i][j]) 
	int distance[Max]; // distance to i node from starting node
	int visited[Max]; //0 if the node is not visited, 1 if the node is visited
	int mindistance; //Temp variable for calculating min distance
	int visitednode; //no. of node which is visited recently
	int i,j,count=1; // Loop variables
	for(i=0;i < n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0)
			{
				cost[i][j]=Infinity;
			}
			else
			{
				cost[i][j]=G[i][j];
	        }
	    }
	}      
	
	for(i=0;i< n;i++)
	{
		distance[i]=cost[startnode][i];
		Predd[i]=startnode;      	//it should not be an array
		visited[i]=0;     		// i node is not visited
	}
	distance[startnode]=0;
	visited[startnode]=1;       		//starting node is visited
	while(count < n-1)
	{
		mindistance=Infinity;
		for(i=0;i<n;i++)
		{
			if((distance[i] < mindistance)&&(!visited[i]))
			{
				mindistance=distance[i];
				visitednode=i;
			}
		}
		
		//check better path exists through visitednode	
		visited[visitednode]=1;
		for(i=0;i < n;i++)
		{
			if(!visited[i])             //runs only if the node is not visited
			{
				if((mindistance+cost[visitednode][i]) < distance[i])
				{
					distance[i]=mindistance+cost[visitednode][i];
					Predd[i]=visitednode;
				}
			}	
		}	
		count++;
	}
 
 	stop = clock(); 
	runtime_Dij= ((double) stop - start)/ CLOCKS_PER_SEC;
 	
 	if(kk<4)
 	{
  		//print the path and distance of each node
		for(i=0;i < n;i++)
		{
			if(i!=startnode)
			{
				printf("\nDistance of %d = %d", i+1, distance[i]);
				printf("\nPath = %d", i+1);
				j=i;
				
				do
				{
					j=Predd[j];
					printf(" <-%d", j+1);
			
				}while(j!=startnode);
			    
        		}
		} 
	}	

}


void bellman(int G[Max][Max],int n,int startnode)
{
    	clock_t start,stop;
    	start = clock();
    	kk++;
    	int distance[Max];      // distance to i node from starting node
    	int i,j,k;
	w=0;
	//we initialize all distance to infinity except source.
	for(i=0;i<n;i++)
	{
		distance[i]=Infinity;
		Predb[i]=-1;
	}
		//mark the source vertex
	distance[startnode]=0;
	//relax edges |V|-1 times
	for(k=0;k<n-1;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(G[i][j]!=0 && (distance[j]>distance[i]+G[i][j]))    
				{
					distance[j]=distance[i]+G[i][j];
					Predb[j]=i;
				}
			}
		}
	}
    	//detect negative cycle
    	//if value changes then we have a negative cycle in the graph
    	//and we cannot find the shortest distances
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(G[i][j]!=0 && distance[j]>distance[i]+G[i][j])
			{
				distance[j]=distance[i]+G[i][j];
				w++;
			}
		}
	}
	
	
	stop = clock();
	runtime_Bel= ((double) stop - start)/ CLOCKS_PER_SEC;
	
	if(kk<4)
	{
		if(w!=0)
		{
			puts("Negative Cycle Found");
		}
		else
		{   	
			for(i=0;i < n;i++)
			{
				if(i!=startnode)
				{
					printf("\nDistance of %d = %d", i+1, distance[i]);
					printf("\nPath = %d", i+1);
					j=i;
			
					do
					{
						j=Predb[j];
						printf(" <-%d", j+1);
			
					}while(j!=startnode);
				}

			}
		}	
	}		
}

// Implementing floyd-warshall algorithm
void floydWarshall(int G[Max][Max],int n) 
 {
    	clock_t start,stop;
   	start = clock();
	
	int matrix[Max][Max], i, j, k;
    	kk++;
    	for (i = 0; i < n; i++)
    	{   	for (j = 0; j < n; j++)
        	{
            		matrix[i][j] = G[i][j];
             		Predff[i][j] = i;
        	}
    	}
    	    
    	// Adding vertices individually
    	for (k = 0; k < n; k++) 
    	{
        	for (i = 0; i < n; i++) 
        	{
            		for (j = 0; j < n; j++) 
            		{
                		if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                		{    
                    			matrix[i][j] = matrix[i][k] + matrix[k][j];
                    			Predff[i][j]=Predff[k][j];
                		}
            		} 
        	}
    	}
   	
   	
   	w=0;
   	for(i=0;i<n;i++)
   	{
   		for(j=0;j<n;j++)
   		{
   			if(i==j)
   			{
   				if(matrix[i][j]<0)
   				{
   					w=1;
   				}
   			}
   		}
   	}
   	
   	
   	stop = clock();
	runtime_Floyd= ((double) stop - start)/ CLOCKS_PER_SEC;
   	
   	if(kk<4)
   	{
		if(w!=0)
		{
			puts("Negative Cycle Found");
		}
		else
		{   
    			for (int i = 0; i < n; i++) 
    			{
        			for (int j = 0; j < n; j++) 
        			{
        				printf("%d ",Predff[i][j]);
        			}
        			printf("\n");
        		}	
    			for (int i = 0; i < n; i++) 
    			{
        			for (int j = 0; j < n; j++) 
        			{
            				if (matrix[i][j] == Infinity)
            				{
               	 			printf("%4s", "INF");
            				}
            				else
            				{    
               	 			printf("%4d", matrix[i][j]);
            				}
        			}
        			printf("\n");
    			}
    			for(k=0;k<n;k++)	
			{
				printf("\nFor starting node= %d:",k+1);
				for(i=0;i < n;i++)
				{
					if(i!=k)
					{
						printf("\nDistance of %d = %d", i+1, matrix[k][i]);
						printf("\nPath = %d", i+1);
						j=i;
				
						do
						{
							j=Predff[k][j];
							printf("-> %d", j+1);
			
						}while(j!=k);
        				}
				}
				printf("\n");
			}
		}	
	}
    	
}

