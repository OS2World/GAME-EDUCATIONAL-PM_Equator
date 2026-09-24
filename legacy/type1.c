#include <stdio.h>
#include <stdlib.h>

#ifdef __GNUC__
#else
enum bool {true, false};
#endif

inline int lodig(int x) { return x % 10; }
inline int dig2(int x) { return (x/10) % 10; }
inline int ctod(char x) { return x-'0'; }

const int MAXNUM=999;

void printprob(FILE* f, int a[], char set[])
{
	char s[10][9], *p;
	int j, i;
	for (j=1; j<10; j++) {
		p = itoa(a[j], s[j], 10);
		while(*p) { *p = set[ctod(*p)]; p++; }
	}
	fprintf(f, "\t%5s %s%5s = %5s\n", s[1], "-", s[2], s[3]);
	fprintf(f, "\t%5s  %5s   %5s\n", "+", "x", "-");
	fprintf(f, "\t%5s %s%5s = %5s\n", s[4], "+", s[5], s[6]);
	fprintf(f, "\t%5s  %5s   %5s\n", "=", "=", "=");
	fprintf(f, "\t%5s %s%5s = %5s\n\n", s[7], "-", s[8], s[9]);
}


void rset(int count, char set[])
{
	int i, j1, j2;
	char h;
	strcpy(set,"ABCDEFGHJK");
	for (i=0; i < count+97; i++) {
		j1 = i % 10;
		j2 = (i+1) % 10;
		h = set[j1];
		set[j1] = set[j2];
		set[j2] = h;
	}
}

bool genprob(int u, int v, int w, int a[])
{
	long int n;
	int used[10], i, j;
	char tmp[99], *p;

	if ( u & 1 || v & 1 || w == 0 || v < 1 || u < 1
		|| lodig(u) == 0 || lodig(u) == 1 || lodig(u) == dig2(u)
		|| lodig(v) == 0 || lodig(v) == 1 || lodig(v) == dig2(v)
		|| lodig(w) == 0
		) 
	{

		return false;
	}
	n = w + (u*v+v+u)/2;
	if ( n >= MAXNUM || lodig(n) == 0 ) {
		return false;
	}
	a[1] = n;
	a[2] = u;
	a[5] = v;
	a[9] = w;
	a[3] = a[1] - a[2];
	if (lodig(a[3]) == 0 
   	    || ( a[2] < 100 && a[3]/100 != a[1]/100 )
	   ) 
	{
		return false;
	}
	a[6] = a[3] - a[9];
	if (lodig(a[6]) == 0
	    || (a[9] < 100 && a[6]/100 != a[3]/100 ) 
	   )
	{
		return false;
	}
	a[4] = a[6] - a[5];
	if (a[4]  < 100 || lodig(a[4])==0 
	    || (a[5] < 100 && a[4]/100 != a[6]/100 ) 
	   ) 
	{
		return false;
	}
	a[7] = a[1] + a[4];
	if (a[7] > MAXNUM) {
		return false;
	}
	a[8] = a[7] - a[9];
	if (lodig(a[8]) == 0 || a[8] < 100 ) 
	{
		return false;
	}
	for (j=0; j< 10; j++) used[j] = 0;
	for (i=1; i < 10; i++) {
		p = itoa(a[i], tmp, 10);
		while(*p) {
			used[ctod(*p++)]++;
		}
	}
	for (j=0; j < 10; j++) {
		if (used[j] < 1) {	
/*
			printf("Pattern %d%d%d%d%d%d%d%d%d%d.\n",
				used[0], used[1], used[2], used[3], used[4],
				used[5], used[6], used[7], used[8], used[9]);
 */
			return false;
		}
	}
	return true;
}

int main(int argc, char **argv)
{
	int u,v,w, a[10];
	long int count = 0;
	char set[11];

	printf(__FILE__ " compiled "__DATE__" " __TIME__ ".\n");

	if (argc == 0) {
		for (u=12; u < 100; u++)
		    for(v=12; v < 100; v++)
			for(w=100; w <= MAXNUM; w++)
		{
			if (genprob(u,v,w,a)) {
				printf("%ld.:", ++count);
				printprob(stdout, a, "0123456789");
			}			
		}
		printf("Bei MAXNUM = %d werden %ld Probleme erzeugt:\n",
			MAXNUM, count);
	} else {
		long int index = atoi(argv[1]);
		for (u=12; u < 100; u++)
		    for(v=12; v < 100; v++)
			for(w=100; w <= MAXNUM; w++)
		{
			if (genprob(u,v,w,a)) {
				++count;
				if (count == index) {
					rset(count, set);
					printprob(stdout, a, set);
					return 0;
				}
			}			
		}
		printf("Bei MAXNUM = %d werden %ld Probleme erzeugt:\n",
			MAXNUM, count);
	}
	return 0;
}
