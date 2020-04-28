#include<stdio.h>
#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
FILE *fp1;
int i,j,w1,w2,overs,c,target,chase;
char ch;
char team1[10],players1[15][11],team2[10],players2[15][11];
int runs1[11],runs2[11];
int wicket_team1=0,wicket_team2=0;
int team_a();
int team_b();
void reader();
void writer();
int main()
{
	int ch ;
	printf (" Enter  1 to read the file , to write press any other number :\n");
	scanf("%d",&ch);
	if (ch==1)
	{
		reader();
	}
	else
	{
		writer();
	}
	
	return 0;
}
int team_a()
{
	int balls1[overs][6];
	fprintf(fp1,"Team %s:\n",team1);
	printf("Enter the runs scored by %s players:	\n",team1);
	for(i=0;i<11;i++)
	{
		printf("Enter runs scored by %s , if he didnt bat enter 0:\n",players1[i]);
		scanf("%d",&runs1[i]);
		fprintf(fp1,"%s:%d \n",players1[i],runs1[i]);
	}
	printf("Enter no. of wickets lost by %s\n",team1);
	scanf("%d",&w1);
	fprintf(fp1,"No. of wickets lost by %s :\n",team1);
	printf("Enter the runs scored by %s as per overs: \n",team1);
	fprintf(fp1,"%s :\n",team1);
	for (i=0;i<overs;i++)
	{
		printf("Enter runs of over - %d\n",(i+1));		
		fprintf(fp1,"OVER : %d\n",i);
		for(j=0;j<6;j++)
		{
			scanf("%d",&balls1[i][j]);
			fprintf(fp1,"%d\t",balls1[i][j]);
		}
	}
	int total=0;
	for (i=0;i<overs;i++)
	{
		for(j=0;j<6;j++)
		{
			total=total+balls1[i][j];
		}
	}
	return total;
}
int team_b()
{
	int balls2[overs][6];
	fprintf(fp1,"Team %s:\n",team2);
	printf("Enter the runs scored by %s players:	\n",team2);
	for(i=0;i<11;i++)
	{
		printf("Enter runs scored by %s , if he didnt bat enter 0:\n",players2[i]);
		scanf("%d",&runs2[i]);
		fprintf(fp1,"%s:%d \n",players2[i],runs2[i]);
	}	
	printf("Enter no. of wickets lost by %s\n",team2);
	scanf("%d",&w2);
	fprintf(fp1,"No. of wickets lost by %s :\n",team2);
	printf("Enter the runs scored by %s as per overs: \n",team2);
	fprintf(fp1,"%s :\n",team2);
	for (i=0;i<overs;i++)
	{
		printf("Enter runs of over - %d\n",(i+1));	
		fprintf(fp1,"OVER : %d\n",i);
		for(j=0;j<6;j++)
		{
			scanf("%d",&balls2[i][j]);
			fprintf(fp1,"%d\t",balls2[i][j]);
		}
	}
	int total=0;
	for (i=0;i<overs;i++)
	{
		for(j=0;j<6;j++)
		{
			total=total+balls2[i][j];
		}
	}
	return total;
}
void writer()
{
	fp1=fopen("C:/Users/Avemaria/Desktop/C/p2/scoresheet.txt","w");
	
	printf("Enter name of Team 1:	\n");
	gets(team1);
	fprintf(fp1,"Team 1:	");
	fprintf(fp1,"%s\n",team1);
	printf("Enter the 11 Team 1 players: \n");
	for(i=0;i<11;i++)
	{
		gets(players1[i]);
	}
	for(i=0;i<11;i++)
	{
		fprintf(fp1,"%s\n",players1[i]);
	}
	char team2[10],players2[15][11];
	printf("Enter name of Team 2:	\n");
	gets(team2);
	fprintf(fp1,"Team 2:	");
	fprintf(fp1,"%s\n",team2);
	printf("Enter the 11 Team 2 players: \n");
	for(i=0;i<11;i++)
	{
		gets(players2[i]);
	}
	for(i=0;i<11;i++)
	{
		fprintf(fp1,"%s\n",players2[i]);
	}
	printf("Enter no. of overs in the match: \n");
	
	scanf("%d",&overs);
	
	printf("To start entering score press 1 else enter 0: \n");
	scanf("%d",&c);
	if (c==0)
	{
		printf("END.");
	}
	else
	{
		printf("Enter 1 if Team 1 choose to bat Else enter 2: \n");
		int toss;
		scanf("%d",&toss);
		if (toss==1)
		{
			target=team_a();
			printf("TARGET:\t%d",target);
			fprintf(fp1,"TARGET:\t%d",target);
			chase=team_b();
			if(chase>target)
			{
				printf("Team %s WINS",team2);
			}
			else
			{
				printf("Team %s WINS",team1);
			}
		}
		else
		{
			target=team_b();
			printf("TARGET:\t%d",target);
			fprintf(fp1,"TARGET:\t%d",(target+1));
			chase=team_b();
			if(chase>target)
			{
				printf("Team %s WINS",team1);
				fclose(fp1);
			}
			else
			{
				printf("Team %s WINS",team2);
				fclose(fp1);
			}
		}
	}
}
void reader()
{
	fp1=fopen("C:/Users/Avemaria/Desktop/C/p2/scoresheet.txt","r");
	char r;

	if (fp1 == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    r = fgetc(fp1);
    while (ch != EOF)
    {
        printf ("%c", r);
        r = fgetc(fp1);
    }
    fclose(fp1);
}
