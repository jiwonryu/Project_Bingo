#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define N 4
#define M 3
void initiate_bingo(int input[N][N]);
//���� ���̺��� �ʱ⿡ �������
void print_bingo(int input[N][N]);
//���� ���̺� ���� ��Ȳ�� ȭ�鿡 ��� 
int get_number_byMe();
//���� ���� ��ȣ �Է� ���� 
int get_number_byCom(int Com_bingo[N][N]);
//��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ���� 
int process_bingo(int input[N][N], int x);
//���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä�� 
int count_bingo(int input[N][N]);
//���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ
int double_checking(int input[N][N], int x);
//���� �ǿ� ���� ���ڰ� �ִ��� Ȯ�� 
int User[N][N]={0};
int Com[N][N]={0};

void main(int argc, char *argv[]) {
   srand(time(NULL));
   int turn = 1;
   int get_integer = 0;
   int user_win = 0;
   int com_win = 0;

   initiate_bingo(User);
   initiate_bingo(Com);
   while (1) {
      printf("<User's bingo>\n");
      print_bingo(User);
      int bingo_counting = 0;
      get_integer = get_number_byMe();
      process_bingo(User, get_integer);
      process_bingo(Com, get_integer);

      bingo_counting = count_bingo(User);
      if (bingo_counting == M)
         user_win = 1;

      bingo_counting = count_bingo(Com);
      if (bingo_counting == M)
         com_win = 1;

      if (user_win ==1 || com_win == 1)
         break;

      get_integer = get_number_byCom(Com);
      process_bingo(User, get_integer);
      process_bingo(Com, get_integer);
   
      bingo_counting = count_bingo(User);
      if (bingo_counting == M)
         user_win = 1;

      bingo_counting = count_bingo(Com);
      if (bingo_counting == M)
         com_win = 1;

      if (user_win == 1 || com_win == 1)
         break;

      turn++;
      system("cls");
   }
   system("cls");
   printf("<User's Bingo>\n");
   print_bingo(User);
   printf("\n<Computer's Bingo>\n");
   print_bingo(Com);
   if(user_win == 1 && com_win == 1)
      printf("���ӿ��� �������, %d����ŭ�� turn�� �������ϴ�.\n", turn);
   else if(com_win == 1)
      printf("�¸��ڴ� Computer �̸�, %d����ŭ�� turn�� �������ϴ�.\n", turn);
   else 
      printf("�¸��ڴ� User �̸�, %d����ŭ�� turn�� �������ϴ�.\n", turn);
   

   system("pause");
}
void initiate_bingo(int input[N][N]) {
	int input_number = 1;
	int i;
	int j;
	for (i = 0; i < N; i++) {
		for (j = 0; j <N; j++) {
			while (1) {
				input_number = rand() % (N*N) + 1;
				if (double_checking(input, input_number)) {
					input[i][j] = input_number;
					break;
				}
			}
		}
	}
}
void print_bingo(int input[N][N]) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j <N; j++)
		         printf("%5d", input[i][j]);
		printf("\n");
	}
}
int get_number_byMe() {
	int number = 0;
	printf("\n���ڸ� �Է��ϼ���: ");
	while (1) {
		scanf("%d", &number);
		rewind(stdin);
		if (!(double_checking(User, number)))
		         break;
		printf("\n�ٸ� ���ڸ� �Է��ϼ���: ");
	}
	return number;
}
int get_number_byCom(int Com_bingo[N][N]) {
	int random_number = -1;
	while (1) {
		random_number = Com_bingo[rand() % N][rand() % N];
		if (random_number != -1)
		         break;
	}
	return random_number;
}
int process_bingo(int input[N][N], int x) {
	int i, j;
	for (i = 0;i<N;i++)
	      for (j = 0;j<N;j++)
	         if (input[i][j] == x)
	            input[i][j] = -1;
}
int count_bingo(int input[N][N]) {
	int line = 0;
	int is_same = 0;
	int i, j;
	for (i = 0;i<N;i++) {
		for (j = 0;j<N;j++)
		         if (input[i][j] == -1)
		            is_same++;
		if (is_same == N)
		         line++;
		is_same = 0;
	}
	for (i = 0;i<N;i++) {
		for (j = 0;j<N;j++)
		         if (input[j][i] == -1)
		            is_same++;
		if (is_same == N)
		         line++;
		is_same = 0;
	}
	for (i = 0;i<N;i++)
	      if (input[i][i] == -1)
	         is_same++;
	if (is_same == N)
	      line++;
	is_same = 0;
	for (i = 0;i<N;i++)
	      if (input[i][N - 1 - i] == -1)
	         is_same++;
	if (is_same == N)
	      line++;
	return line;
}
int double_checking(int input[N][N], int x) {
	int i, j;
	for (i = 0; i<N; i++)
	      for (j = 0; j<N; j++)
	         if (input[i][j] == x)
	            return 0;
	return 1;
}
