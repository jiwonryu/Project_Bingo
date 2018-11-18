#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define N 3
#define M 3 

void initiate_bingo(int[][] input) //빙고 테이블을 초기에 만들어줌
void print_bingo(int[][] input) //빙고 테이블 현재 상황을 화면에 출력 
int get_number_byMe() //내가 빙고 번호 입력 선택 
int get_number_byCom() //컴퓨터가 임의로 빙고 번호 선택 
int process_bingo() //선택된 숫자를 입력받아서 빙고 테이블 칸을 채움 
int count_bingo() //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환
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
		printf("숫자를 선택하세요: ");
		get_number_byMe();
		process_bingo(); 
		int bingo_counting = count_bingo();
		if(bingo_counting == M){
			strcpy(winner,"사용자");
			break;
		}
		get_number_byCom();
		
		turn++ ;
	}
	printf("승리자는 %s 이며, %d번만큼의 turn이 지났습니다.", winner,turn);
	
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
