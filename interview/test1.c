#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "city.txt"

typedef struct  _CityLink {
	char* CityName;
	signed char CityTemp;
	struct _CityLink* NextCity;
} *CityLink;


int main(int argc, char** argv)
{
	char inputBuf[127], *retBuf;
	int a, len;
	FILE *fd_city;
	fd_city = fopen(FILE_PATH, "r");
	if(fd_city == NULL)
	{
		perror("open file");
		return -1;
	};
	
	do {	
		if((retBuf = fgets(inputBuf, 127, fd_city)) != NULL)
			printf("%s", inputBuf);
	}while( retBuf!= NULL );
	

	CityLink beijing;
	beijing = (CityLink)malloc(sizeof(struct _CityLink));
	beijing->CityTemp = 21;
	printf("beijing temp is %d\n", beijing->CityTemp);
	free(beijing);
	fclose(fd_city);
}
