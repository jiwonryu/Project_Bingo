#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define N 4
#define M 3
void initiate_bingo(int input[N][N]);
//빙고 테이블을 초기에 만들어줌
void print_bingo(int input[N][N]);
//빙고 테이블 현재 상황을 화면에 출력 
int get_number_byMe();
//내가 빙고 번호 입력 선택 
int get_number_byCom(int Com_bingo[N][N]);
//컴퓨터가 임의로 빙고 번호 선택 
int process_bingo(int input[N][N], int x);
//선택된 숫자를 입력받아서 빙고 테이블 칸을 채움 
int count_bingo(int input[N][N]);
//빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환
int double_checking(int input[N][N], int x);
//
int User[N][N] = {
	0
}
;
int Com[N][N] = {
	0
}
;
void main(int argc, char *argv[]) {
	srand(time(NULL));
	int turn = 1;
	int get_integer = 0;
	char winner[5] = {
		0
	}
	;
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
		if (bingo_counting == M) {
			strcpy(winner, "User");
			break;
		}
		bingo_counting = count_bingo(Com);
		if (bingo_counting == M) {
			strcpy(winner, "Computer");
			break;
		}
		get_integer = get_number_byCom(Com);
		process_bingo(User, get_integer);
		process_bingo(Com, get_integer);
		bingo_counting = count_bingo(User);
		if (bingo_counting == M) {
			strcpy(winner, "User");
			break;
		}
		bingo_counting = count_bingo(Com);
		if (bingo_counting == M) {
			strcpy(winner, "Computer");
			break;
		}
		turn++;
		system("cls");
	}
	system("cls");
	printf("<User's Bingo>\n");
	print_bingo(User);
	printf("\n<Computer's Bingo>\n");
	print_bingo(Com);
	printf("\n승리자는 %s 이며, %d번만큼의 turn이 지났습니다.\n\n", winner, turn);
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
	//char number[5];
	int number = 0;
	//int integer_number = 0;
	printf("\n숫자를 입력하세요: ");
	while (1) {
		/*scanf("%s", number);
      rewind(stdin);
      int i = 0;
      for (;i != '\0';i++)
         if (!(number[i] >= '0' && number[i] <= '9'))
            break;
      if (number[i] == '\0') {
         integer_number = atoi(number);
         if (double_checking(User, integer_number))
            break;
      }*/
		scanf("%d", &number);
		rewind(stdin);
		if (!(double_checking(User, number)))
		         break;
		printf("\n다른 숫자를 입력하세요: ");
	}
	//return integer_number;
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
