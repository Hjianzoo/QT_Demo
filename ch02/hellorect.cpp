#include <iostream>
#include "rect.h"
using namespace std;

int main(int argc,char **argv)
{
	Rect arect(3.0,4.0);
	cout<<"Diagonal length is " <<arect.CalcDiagonal()<<endl;
	cout<<"Area is " << arect.CalcArea()<<endl;
	return 0;
}
