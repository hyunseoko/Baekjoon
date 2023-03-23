#include <stdio.h>

typedef struct record {
	int kor;
	int eng;
	int math;
	int sum;
	float average;
};
int main()
{
	record x[5];
	int i;

	printf("Input 3 scores of each of 5 students: ");
	for (i = 0; i <= 4; i++) {
		scanf_s("%d", &x[i].kor, sizeof(x[i].kor));
		scanf_s("%d", &x[i].eng, sizeof(x[i].eng));
		scanf_s("%d", &x[i].math, sizeof(x[i].math));
	}
	for (i = 0; i <= 4; i++) {
		x[i].sum = x[i].kor + x[i].eng + x[i].math;
		x[i].average = (float)x[i].sum / 3.0;
	}
	printf("\tKOR\tENG\tMATH\tSUM\tAVG\n");
	for (i = 0; i <= 4; i++) {
		printf("\t%d", x[i].kor);
		printf("\t%d", x[i].eng);
		printf("\t%d", x[i].math);

		printf("\t%d", x[i].sum);
		printf("\t%.2f\n", x[i].average);
	}
	return 0;
}