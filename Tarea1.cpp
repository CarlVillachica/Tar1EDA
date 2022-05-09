#include <random>
#include <map>
#include <string>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>

#define MIDDLE 10000 //Se tienen 20000 elementos

using namespace std;

int powerF(int** V,int i , int j){
	int calc = pow(V[MIDDLE][j] - V[i][j], 2);
	return calc;
}

void calcDist(int nElem, int Dim,int** V, int* d){

	int suma = 0;
	for (int i = 0; i < nElem; i++) {
		suma = 0;
		for (int j = 0; j < Dim; j++) {
			suma =  suma +powerF(V,i,j);
		}
		suma = sqrt(suma);
		d[suma] += 1;
	}

}
int main()
{
	//Dado por el profesor

	
	int Dim ;
	int numElem = 20000;
	int** Val = new int *[numElem];

	cout<<"Dimension necesitada"<<endl;
	cin>>Dim;

	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd());  //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> distrib(1, 100);


	ofstream archivotxt;
	archivotxt.open("hacergrafica"+to_string(Dim)+".txt");



	for (int i = 0; i < numElem; i++) {
		Val[i] = new int[Dim];
		for (int j = 0; j < Dim; j++) {
			Val[i][j] = distrib(gen);
		}
	}

	int* dist=new int[1000];
	for (int i = 0; i < 1000; i++) {
		dist[i] = 0;
	}

	calcDist(numElem,Dim,Val,dist);

	for (int i = 0; i < 1000; i++) {
		archivotxt << i << " \t " << dist[i]<<"\n";
	}

	archivotxt.close();   
	return 0;
}