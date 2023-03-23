#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

#define MAX 100

typedef struct student // 학생 1명에 대한 학번, 이름, 성적 저장
{
    int id; //학번
    char name[40]; //이름
    int score; //성적
}student;

//배열 교환
void EXCHANGE(student* arr, int a, int b)
{
    student temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

//(정렬할 배열, 하한, 상한, 1(학번) or 2(성적)
void QuickSort(student* arr, int m, int n, int num)
{
    int i = m; //상한
    int j = n; //하한

    int pivot = m; //key값 index

    if (m < n) { //상한이 하한보다 낮은 경우

        while (1) {
            while (arr[i].score > arr[pivot].score)i++; //작은 수 찾기
            while (arr[j].score < arr[pivot].score)j--; //큰 수 찾기

            if (i < j) {
                EXCHANGE(arr, i, j); //두 값 교환
            }
            else { //작은 값이 큰 값보다 뒤에 있을 경우
                EXCHANGE(arr, i, pivot); //pivot과 작은 값을 교환

                break; //반복문 종료
            }

        }
        QuickSort(arr, m, j - 1, num); //pivot 왼쪽 배열 정렬
        QuickSort(arr, j + 1, n, num); //pivot 오른쪽 배열 정렬
    }
}

int main() {

    student s[MAX];
    int num;
    char ch[40];

    printf("학생 수를 입력하세요 : ");
    scanf("%d", &num);

    //학생 정보 입력
    for (int i = 0; i < num; i++)
    {
        printf("학생 정보 입력(학번, 이름, 성적) : ");
        scanf("%d", &s[i].id);
        scanf("%s", ch);
        strcpy(s[i].name, ch);
        scanf("%d", &s[i].score);
    }
    //정렬 전
    printf("\n정렬 전 학생 출력\n");
    for (int i = 0; i < num; i++) {
        printf("%d %s %d\n", s[i].id, s[i].name, s[i].score);
    }
    printf("\n");
    printf("성적 순 학생 출력\n");
    QuickSort(s, 0, num - 1, 2); //퀵 소트(학생 배열,0,num-1,2)
    for (int i = 0; i < num; i++)
        printf("%d %s %d\n", s[i].id, s[i].name, s[i].score);
    printf("\n");

    return 0;
}