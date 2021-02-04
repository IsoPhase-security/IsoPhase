

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

class Mat {
public:
	Mat();
	~Mat();
	int rows;
	int cols;
	int type() { return 1; };
	int channels() { return 1; };
	char* data;
	int total() { return 1; };
};

#include "cvtcolor.h"


int main()
{
	printf("xxxxxxxxx\n");
	return 1;
}


