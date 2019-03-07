#include <stdio.h>
#include <ctype.h>

int main() {
	char buff[200], c;
	int i,j;
	double fp;
	char *s = "baltimore";

	c = 'l';
	i = 45;
	fp = 1.1231231l;

	j = snprintf(buff, 6, "%s\n", s);
	printf("%d : %d\n", snprintf(buff, 6, "%s\n", s), j);

	return 0;
}

