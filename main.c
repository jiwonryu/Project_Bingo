#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define N 3
#define M 3 

void initiate_bingo(int[][] input) //���� ���̺��� �ʱ⿡ �������
void print_bingo(int[][] input) //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ��� 
int get_number_byMe() //���� ���� ��ȣ �Է� ���� 
int get_number_byCom() //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ���� 
int process_bingo() //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä�� 
int count_bingo() //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ
int double_checking(int[][] input, int x)

int[N][N] User = NULL;
int[N][N] Com = NULL;

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	int turn = 1;
	char[5] winner = NULL;
	initiate_bingo(User);
	initiate_bingo(Com);
	print_bingo();
	
	while(1)
	{
		printf("���ڸ� �����ϼ���: ");
		get_number_byMe();
		process_bingo(); 
		int bingo_counting = count_bingo();
		if(bingo_counting == M){
			strcpy(winner,"�����");
			break;
		}
		get_number_byCom();
		
		turn++ ;
	}
	printf("�¸��ڴ� %s �̸�, %d����ŭ�� turn�� �������ϴ�.", winner,turn);
	
}

void initiate_bingo(int[][] input) {
	
	int input_number = 1;
	
	for(int i = 0; i < N ; i++)
		for(int j = 0; j <N ; j++) {
		input_number = random%N*N + 1;
		double_checking(input,input_number);
		input[i][j] = input_number;
		}	
}

void print_bingo(int[][] input) {
	
}
