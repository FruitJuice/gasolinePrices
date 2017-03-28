// gasolinePrices.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstring>
#include <cstdlib>
int readFile(char *fileName);
double getAverage(int recordNum);
int getSelection();
int getHighMonth();
void getHighYear();

int nrecords = 0;
int year = 0;

typedef struct
{
	int year;
	double price[12];
	double average;
} gasoline;

gasoline records[30];

void main()
{
	char file[] = "C:\\Users\\sndri\\Documents\\Visual Studio 2015\\Projects\\gasolinePrices\\Debug\\gasoline.txt";
	char monthList[][15] = { "January", "February","March","April","May","June","July","October","November", "December" };
	int i;
	int select, month, bigYear;
	if(!readFile(file))
	{
		printf("Error the file couldn't be opened\n");
		return;
	}

	for(i = 0; i < nrecords; i++)
	{
		records[i].average = getAverage(i);
	}

	select = getSelection();
	
	while(select != 0)
	{
		switch(select)
		{
		case 1:
			month = getHighMonth();
			printf("Highest Price Month was %lf in %s of %d\n\n", records[year].price[month], monthList[month], year + 1976);
			break;

		case 2:
			getHighYear();
			printf("Highest Anual Average Price was %lf in %d\n\n", records[year].average, year + 1976);
			break;
		}
		select = getSelection();
	}
}

int readFile(char *fileName)
{
	FILE *ptr;
	char line[200];
	char delim[3] = "\t";
	ptr = fopen(fileName, "r");
	if (ptr == NULL) return 0;
	do
	{
		fgets(line, 200, ptr);
		if (strstr(line, "."))
		{
			 records[nrecords].year = atoi(strtok(line, delim));
			 records[nrecords].price[0] = atof(strtok(NULL, delim));
			 records[nrecords].price[1] = atof(strtok(NULL, delim));
			 records[nrecords].price[2] = atof(strtok(NULL, delim));
			 records[nrecords].price[3] = atof(strtok(NULL, delim));
			 records[nrecords].price[4] = atof(strtok(NULL, delim));
			 records[nrecords].price[5] = atof(strtok(NULL, delim));
			 records[nrecords].price[6] = atof(strtok(NULL, delim));
			 records[nrecords].price[7] = atof(strtok(NULL, delim));
			 records[nrecords].price[8] = atof(strtok(NULL, delim));
			 records[nrecords].price[9] = atof(strtok(NULL, delim));
			 records[nrecords].price[10] = atof(strtok(NULL, delim));
			 records[nrecords].price[11] = atof(strtok(NULL, delim));
			 nrecords++;
		}
	} while (!feof(ptr));
	return 1;
}

double getAverage(int recordNum)
{
	int i;
	double average;
	double total = 0;
	for(i = 0; i < 12; i++)
	{
		total += records[recordNum].price[i];
	}
	average = total / 12;
	return average;
}

int getSelection()
{
	char input[5];
	int selection = 0;
	puts("Enter Choice:");
	puts("0 - Quit");
	puts("1 - Find the month with highest price");
	puts("2 - Find the year with highest average price");
	gets_s(input);
	selection = atoi(input);
	return selection;
}

int getHighMonth()
{
	int i;
	int month = 0;
	double highMonth = records[nrecords].price[0];
	for(i = 0;  i < nrecords;month++, i++)
	{
		if (highMonth < records[i].price[month])
		{
			highMonth = records[i].price[month];
			year = i;
		}

		if (month > 11) month = 0;
	}
	return month;
}

void getHighYear()
{
	int i;
	year = 0;
	double highPrice = records[nrecords].average;
	for(i = 0; i < nrecords; i++)
	{
		if(highPrice < records[i].average)
		{
			highPrice = records[i].average;
			year = i;
		}
	}
}

