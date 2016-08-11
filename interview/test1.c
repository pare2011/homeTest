#include <stdio.h>
#include <stdlib.h>

typedef struct  _CityLink {
	char* CityName;
	signed char CityTemp;
	struct _CityLink* NextCity;
} *CityLink;

int main(int argc, char** argv)
{
	int a;
	CityLink beijing;
	beijing = (CityLink)malloc(sizeof(struct _CityLink));
	beijing->CityTemp = 21;
	printf("beijing temp is %d\n", beijing->CityTemp);
}
