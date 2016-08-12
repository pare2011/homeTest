#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "city.txt"

typedef struct  _CityLink {
	char* CityName;
	signed char CityTemp;
	struct _CityLink* NextCity;
} *CityLink;

CityLink allCityLink = NULL;
CityLink CityTxt;

int InsertLink(CityLink new)
{
	char* tmp_buf;
	CityLink tmpCity;
	
	tmp_buf = (char*)malloc(sizeof(new->CityName)+1);
	if(tmp_buf == NULL)
		perror("malloc tmp_buf");

	tmpCity = (CityLink)malloc(sizeof(struct _CityLink));
	if(tmpCity == NULL)
		perror("malloc tmpCity");
	strcpy(tmp_buf, new->CityName);
	tmpCity->CityName = tmp_buf;
	tmpCity->CityTemp = new->CityTemp;
	if(allCityLink == NULL)
		allCityLink = tmpCity;
	else
		allCityLink->NextCity = tmpCity;
	tmpCity->NextCity = NULL;
	return 0;
end1:
	free(tmp_buf);
end2:
	return -1;
}

int parseText(char* buf)
{
	//CityTxt->CityName = &strchr(buf, ' ');
	CityTxt->CityTemp = atoi(strchr(buf, ' ')+1);
	printf("temp is %d\n", CityTxt->CityTemp);

	return 0;
}

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
	
	CityTxt = (CityLink)malloc(sizeof(struct _CityLink));
	
	do {	
		if((retBuf = fgets(inputBuf, 127, fd_city)) != NULL)
		{
		
//pare			printf("%s", inputBuf);
			parseText(inputBuf);
		
		}
	}while( retBuf!= NULL );
	

	free(CityTxt);
	fclose(fd_city);
}
