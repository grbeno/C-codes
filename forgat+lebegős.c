#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

#define F 3
#define N 3 

//karakterláncot elforgat
char *forgat(char s[], int f) {
	int len = strlen(s);
	char *p = &s[len - f];
	char *res = (char*)malloc(len+1);
	strcpy(res,p);
	s[len - f] = '\0';
	strcat(res,s);
	strcpy(s, res); //átalakított legyen az eredeti helyén! <- globálisan megváltoztatja
	return res;
}
//lebegõpontos-e?
float lebegose(char s[]) {
	char *endptr;
	float f = strtod(s, &endptr);
	if ((*endptr == '\0') || isspace(*endptr) != 0)
		return f;
	else
		return 0;
}

int main() {

	setlocale(LC_ALL, "Hungarian_Hungary.1250");
	
	//karakterlánc elforgatása többször
	char s[] = "HelloWorld";
	printf("Elforgatandó szó: %s\nMennyivel: %d\nHányszor: %d\n\n", s,F,N);
	int i;
	for (i = 0; i < N; i++) {
		char *forg = forgat(s, F);
		printf("%d. Elforgatás: %s\n", i+1,forg);
		free(forg);
	}
	
	//lebegõpontos ell.
	char test[] = "2,64";
	float f = lebegose(test);
	if (f != 0)
		printf("A %.2f lebegõpontos!\n", f);
	else
		printf("A %s nem lebegõpontos!\n", test);
	


	return 0;
}