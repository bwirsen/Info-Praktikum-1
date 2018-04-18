/*
 * main.cpp
 *
 *  Created on: 18.04.2018
 *      Author: Bjarne
 */

#include <iostream>
#include <string>
using namespace std;

int matrix[8][8] = {
			{1, 2, 1, 2, 1, 2, 1, 2},
			{1, 2, 1, 2, 1, 2, 1, 2},
			{1, 2, 1, 2, 1, 2, 1, 2},
			{1, 2, 1, 2, 1, 2, 1, 2},
			{1, 2, 1, 2, 1, 2, 1, 2},
			{1, 2, 1, 2, 1, 2, 1, 2},
			{1, 2, 1, 2, 1, 2, 1, 2},
			{1, 2, 1, 2, 1, 2, 1, 2}
		};

int main(){


	 int* pointer=&matrix[7][7];
	int zahl77=*pointer;

	cout<<zahl77<<endl;

	*pointer=5;
	int zahl77_new=matrix[7][7];
	cout<<zahl77_new<<endl;

	int matrix_2[8][8]=matrix;

if(matrix==matrix_2){
	cout<<"IDENTISCH"<<endl;
}


}


