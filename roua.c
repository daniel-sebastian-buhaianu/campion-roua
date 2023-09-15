#include <stdio.h>
#include <stdlib.h>

#define NMIN 3
#define NMAX 10000

void nr_roua(FILE *fin, FILE *fout, unsigned short N, unsigned short R);
void nr_rfrumoase(FILE *fin, FILE *fout, unsigned short N, unsigned short R);

int main()
{
	FILE *fin = fopen("roua.in", "r");

	if (!fin) { printf("Eroare roua.in\n"); return 1; }

	unsigned short C, N, R;

	fscanf(fin, "%hu %hu %hu", &C, &N, &R);

	if (C < 1 || C > 2) { printf("Eroare valoare C\n"); return 2; }

	if (N < NMIN || N > NMAX) { printf("Eroare valoare N\n"); return 3; }

	if (R < NMIN-1 || R >= N) { printf("Eroare valoare R\n"); return 4; }

	FILE *fout = fopen("roua.out", "w");

	if (C == 1)
		nr_roua(fin, fout, N, R);
	else
		nr_rfrumoase(fin, fout, N, R);

	fclose(fin);

	fclose(fout);

	return 0;
}

void nr_roua(FILE *fin, FILE *fout, unsigned short N, unsigned short R)
{
	unsigned short lg, suma, st, i;
	unsigned nr;
	char *s, c;

	s = (char*)calloc(N+1, sizeof(char));

	s[N] = '\0';

	do { fscanf(fin, "%c", &c); } while (c < 'a' || c > 'z');

	for (lg = 1, nr = suma = st = i = 0; i < N; i++, lg++) {
		s[i] = c;
		
		if (s[i] == 'r') suma++;

		if (lg == R) {
			if (suma == R-1) nr++; 

			lg--;
			
			if (s[st] == 'r') suma--;

			st++;
		}

		fscanf(fin, "%c", &c);
	}

	fprintf(fout, "%u", nr);

	free(s);
}

void nr_rfrumoase(FILE *fin, FILE *fout, unsigned short N, unsigned short R)
{
	//TODO

	return;
}
// scor 35
