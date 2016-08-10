#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	char* nameBuf = new char(255);
	cout<<"please input you name:"<<endl;
	cin>>nameBuf;
	cout<<"hello :"<<nameBuf<<endl;

	return 0;
}
