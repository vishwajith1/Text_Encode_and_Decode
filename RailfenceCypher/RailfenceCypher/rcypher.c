#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#pragma warning (disable : 4996)
#define max 500
int main()
{
	int ch = 0;
	char plain[max];
	char cypher[max][max];
	char cyp[max];
	char dyp[max];
	int i = 0, j, l;
	int a = 0;
	int b = 1;
	int c = 2;
	int d = 0;
	
	FILE *ptr;
	ptr = fopen("plain.txt", "r");
	ch = fgetc(ptr);
	while (ch != EOF)
	{
		plain[i] = ch;
		i++;
		ch = fgetc(ptr);
	}

	plain[i] = '\0';
	fclose(ptr);
	l = strlen(plain);
	//---------------------------------------------------------Encyption---------------------------------------------------------------------
	for (i=0;i<3;i++)
		for (j = 0; j < l; j++)
		{
			if (i == 0 && j == a)                          // Row 1
			{   
				cypher[i][j] = plain[j];
				a = a + 4;
			}
			else if (i == 1 && j == b)                      // Row 2
			{
				cypher[i][j] = plain[j];
				b = b + 2;
			}
			else if( i == 2 && j == c )                  // Row 3
			{
				cypher[i][j] = plain[j];
				c = c + 4;
			}
		}
	printf("Plain text:\n\n");
	for (i = 0; i < l; i++)
	{
		printf("%c", plain[i]);
	}
	printf("\n\n");
	printf("cyphertext:\n\n");
	for(i=0;i<3;i++)
		for (j = 0; j < l; j++)

			if (cypher[i][j] != -52)
		{            
				cyp[d] = cypher[i][j];               // passing cypher result to one dimentional array
				d++;
				printf("%c", cypher[i][j]);
		}
	FILE *fp;                                       // writing encrypted result into file 
	fp = fopen("EncryptedResult.txt", "w");
	for (i = 0; i < l; i++)
	{
		fprintf(fp, "%c", cyp[i]);
	}
	fclose(fp);
//----------------------------------------------------Decryption------------------------------------------------------------------------

	for (i = 0; i < 3; i++)
	{ 
		a = 0;
		b = 1;
		c = 2;
		for (j = 0; j < l; j++)
		{
			if (i == 0 && j == a)                         // Row 1
			{
				dyp[j] = cypher[i][j];
				a = a + 4;
			}
			else if (i == 1 && j == b)                      // Row 2
			{
				dyp[j] = cypher[i][j];
				b = b + 2;
			}
			else if (i == 2 && j == c)                  // Row 3
			{
				dyp[j] = cypher[i][j];
				c = c + 4;
			}
		}
	}
	printf("\n\n");
	printf("Decrypted Text :\n\n");      // printing decrypted text
	for (i = 0; i < l; i++)
	{
		printf("%c", dyp[i]);
	}
	//                    Writing Decrypted text to a file 
	FILE *fdp;
	fdp = fopen("DecryptedText.txt", "w");
	for (i = 0; i < l; i++)
	{
		fprintf(fdp, "%c", dyp[i]);
	}
	fclose(fdp);
	getch();
	return 0;
}
