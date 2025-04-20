#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define EPS 1e-3

void nhap(double centroids[50][10], double data[100][100], int *n, int *K, int *Dim){
	printf("nhap so cum: ");
	scanf("%d",K);
	printf("nhap chieu (DIM): ");
	scanf("%d",Dim);
	printf("nhap so diem: ");
	scanf("%d",n);
	for(int i=0;i<*n;i++){
		printf("diem %d: ",i+1);
		for(int j=0;j<*Dim;j++){
			scanf("%lf",&data[i][j]);
		}
	}
}

void random_centroids(double centroids[50][10], double data[100][100], int n, int K, int Dim){
	srand(time(NULL));
    for (int i=0;i<K;i++) {
        int random_index=rand() % n;
        for (int j=0;j<Dim; j++) {
            centroids[i][j] = data[random_index][j];
        }
    }
}

double euclidean_distance(double *a, double *b, int dim) {
    double distance = 0.0;
    for (int i = 0; i < dim; i++) {
        distance += pow(a[i] - b[i], 2);
    }
    return sqrt(distance);
}

int find_nearest_cluster(double *point, double centroids[K][DIM], int dim) {
    int cluster = 0; 
    double min_distance = euclidean_distance(point, centroids[0], dim); 
    for (int i = 1; i < K; i++) 
        double distance = euclidean_distance(point, centroids[i], dim); 
        if (distance < min_distance) {
            min_distance = distance;
            cluster = i; 
        }
    }
    return cluster;
}

int main(){
	int n,K,Dim;
	double centroids[50][10],data[100][100];
	nhap(centroids,data,&n,&K,&Dim);
	random_centroids(centroids,data,n,K,Dim);
	for(int i=0;i<K;i++){
    printf("Centroid %d: ", i+1);
    for(int j=0;j<Dim;j++){
        printf("%.2lf ", centroids[i][j]);
    }
    printf("\n");
	}
	return 0;
}
