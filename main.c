#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 5
#define M 3

void initiate_bingo(int input[N][N]);
//빙고 테이블을 초기에 만들어줌 
void print_bingo(int input[N][N]);
//빙고 테이블 현재 상황을 화면에 출력 
int get_number_byMe();
//시용자가 빙고 번호 입력 선택 
int get_number_byCom(int Com_bingo[N][N]);
//컴퓨터가 임의로 빙고 번호 선택 
int process_bingo(int input[N][N], int x);
//선택된 숫자를 입력받아서 빙고 테이블 칸을 채움 
int count_bingo(int input[N][N]);
//빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환
int double_checking(int input[N][N], int x);
//빙고 판에 같은 숫자가 있는지 확인 
int User[N][N]={0};
int Com[N][N]={0};

void main(int argc, char *argv[]) {
   srand(time(NULL));
   int turn = 1;
   int get_integer = 0;
   int user_win = 0;
   int com_win = 0;

   initiate_bingo(User); // 사용자의 빙고테이블 초기화 
   initiate_bingo(Com); // 컴퓨터의 빙고테이블 초기화 
   while (1) {
      printf("<User's bingo>\n");
      print_bingo(User); // 사용자의 빙고테이블 현재 상황 출력 
      int bingo_counting = 0;
      get_integer = get_number_byMe(); //사용자가 숫자 입력 
      process_bingo(User, get_integer); //사용자의 빙고테이블에서 사용자가 입력한 숫자가 -1로 바뀌게함 
      process_bingo(Com, get_integer); //컴퓨터의 빙고테이블에서 컴퓨터가 입력한 숫자가 -1로 바뀌게함 

      bingo_counting = count_bingo(User);
      if (bingo_counting == M)
         user_win = 1; //사용자의 빙고줄이 M개이면 사용자 승 

      bingo_counting = count_bingo(Com);
      if (bingo_counting == M)
         com_win = 1; // 컴퓨터의 빙고줄이 M개이면 컴퓨터 승 

      if (user_win ==1 || com_win == 1)
         break; //사용자나 컴퓨터가 빙고줄을 M개 완성 하여 승리하면 게임 종료 

      get_integer = get_number_byCom(Com); //컴퓨터가 숫자 입력 
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

      turn++; // 게임에서 위 과정이 한번 반복될때마다 turn수 증가 
      system("cls");
   }
   system("cls");
   printf("<User's Bingo>\n");
   print_bingo(User);
   printf("\n<Computer's Bingo>\n");
   print_bingo(Com);
   if(user_win == 1 && com_win == 1) //비기는 경우 
      printf("게임에서 비겼으며, %d번만큼의 turn이 지났습니다.\n", turn);
   else if(com_win == 1) //컴퓨터가 이긴 경우 
      printf("승리자는 Computer 이며, %d번만큼의 turn이 지났습니다.\n", turn);
   else //사용자가 이긴 경우 
      printf("승리자는 User 이며, %d번만큼의 turn이 지났습니다.\n", turn);
   

   system("pause");
}

//빙고 테이블을 초기에 만들어 주는 함수
void initiate_bingo(int input[N][N]) {
	int input_number = 1;
	int i;
	int j;
	for (i = 0; i < N; i++) {
		for (j = 0; j <N; j++) {
			while (1) {
				input_number = rand() % (N*N) + 1; // 1부터 N*N까지 숫자를 빙고판에 랜덤으로 채워넣음 
				if (double_checking(input, input_number)) {
					input[i][j] = input_number;
					break; //빙고판에 중복되는 숫자 있는지 확인 
				}
			}
		}
	}
}  

//빙고테이블 현재 상황을 화면에 출력하는 함수
void print_bingo(int input[N][N]) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j <N; j++)
		         printf("%5d", input[i][j]);
		printf("\n");
	}
}

//사용자가 빙고판의 숫자 선택하는 함수 
int get_number_byMe() { //사용자의 숫자 입력 
	int number = 0;
	printf("\n숫자를 입력하세요: ");
	while (1) {
		scanf("%d", &number); //입력 받음 
		rewind(stdin); //버퍼를 비움 
		if (!(double_checking(User, number))) //사용자의 빙고판에 중복된 숫자인지 체크 
		         break;
		printf("\n다른 숫자를 입력하세요: ");
	}
	return number;
}

//컴퓨터가 빙고판의 숫자 선택하는 함수 
int get_number_byCom(int Com_bingo[N][N]) { //컴퓨터가 숫자를 선택 
	int random_number = -1;
	while (1) {
		random_number = Com_bingo[rand() % N][rand() % N];
		if (random_number != -1) //컴퓨터의 빙고판에서 숫자를 랜덤으로 가져오되 -1일 경우 다시 반복 
		         break;
	}
	return random_number;
}

//선택된 숫자를 입력받아서 빙고판의 수를 -1로 바꿔주는 함수 
int process_bingo(int input[N][N], int x) {
	int i, j;
	for (i = 0;i<N;i++)
	      for (j = 0;j<N;j++)
	         if (input[i][j] == x)
	            input[i][j] = -1;
}

//빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환하는 함수 
int count_bingo(int input[N][N]) {
	int line = 0;
	int is_same = 0;
	int i, j;
	for (i = 0;i<N;i++) {
		for (j = 0;j<N;j++)
		         if (input[i][j] == -1)
		            is_same++; // 가로 한줄에서 -1로 바뀐 수의 갯수 세어줌 
		if (is_same == N)
		         line++; // 가로 한줄의 -1의 갯수가 N개, 즉 모두 -1로 바뀌면 빙고줄 증가 
		is_same = 0; // -1의 갯수 초기화 시켜줌 
	} // 1행부터 N행까지 
	for (i = 0;i<N;i++) {
		for (j = 0;j<N;j++)
		         if (input[j][i] == -1)
		            is_same++; // 세로 한줄에서 -1로 바뀐 수의 갯수 세어줌 
		if (is_same == N)     
		         line++; // 세로 한줄의 -1의 갯수가 N개, 즉 모두 -1로 바뀌면 빙고줄 증가
		is_same = 0; // -1의 갯수 초기화    
	} // 1열부터 N열까지 
	for (i = 0;i<N;i++)
	      if (input[i][i] == -1)
	         is_same++;   
	if (is_same == N)
	      line++; // 오른쪽 아래로 향하는 대각선의 -1의 갯수가 N개, 즉 모두 -1로 바뀌면 빙고줄 증가 
	is_same = 0;
	for (i = 0;i<N;i++)
	      if (input[i][N - 1 - i] == -1)
	         is_same++;
	if (is_same == N)
	      line++; // 왼쪽 아래로 향하는 대각선의 -1의 갯수가 N개, 즉 모두 -1로 바뀌면 빙고줄 증가 
	return line; //빙고줄의 갯수 반환 
}

//빙고 판에 같은 숫자가 있는지 확인하는 함수 
int double_checking(int input[N][N], int x) {
	int i, j;
	for (i = 0; i<N; i++)
	      for (j = 0; j<N; j++)
	         if (input[i][j] == x)
	            return 0;
	return 1;
}
