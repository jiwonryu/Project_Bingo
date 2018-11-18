#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define N 3
#define M 3 

void initiate_bingo(int[N][] input) //빙고 테이블을 초기에 만들어줌
void print_bingo(int[N][] input) //빙고 테이블 현재 상황을 화면에 출력 
int get_number_byMe() //내가 빙고 번호 입력 선택 
int get_number_byCom(int[N][] Com_bingo) //컴퓨터가 임의로 빙고 번호 선택 
int process_bingo(int[N][] input, int x) //선택된 숫자를 입력받아서 빙고 테이블 칸을 채움 
int count_bingo(int[N][] input) //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환
int double_checking(int[N][] input, int x) //

int[N][N] User = NULL;
int[N][N] Com = NULL;

int main(int argc, char *argv[]) 
{
	srand(time(NULL));
	int turn = 1;
	int get_integer = 0;
	char[5] winner = NULL;

	initiate_bingo(User);
	initiate_bingo(Com);
	print_bingo();
	
	while(1)
	{
		int bingo_counting = 0;
		
		get_integer = get_number_byMe();
		process_bingo(User,get_integer); 
		bingo_counting = count_bingo(User);
		if(bingo_counting == M){
			strcpy(winner,"User");
			break;
		}
		
		process_bingo(Com,get_number_byCom());
		bingo_counting = count_bingo(Com);
		if(bingo_counting == M){
			strcpy(winner,"Computer");
			break;
		}
		
		turn++ ;
	}
	printf("승리자는 %s 이며, %d번만큼의 turn이 지났습니다.", winner,turn);
	
}

void initiate_bingo(int[N][] input) 
{
	
	int input_number = 1;
	
	for(int i = 0; i < N ; i++)
		for(int j = 0; j <N ; j++) {
		input_number = random%N*N + 1;
		double_checking(input,input_number);
		input[i][j] = input_number;
		}	
}

void print_bingo(int[N][] input) 
{
	for(int i = 0; i < N ; i++){
		for(int j = 0; j <N ; j++)
			printf("%5d",input[i][j]);
		printf("\n");
	}
}

int get_number_byMe(){
	
	char[5] number = NULL;
	int integer_number = 0;
	printf("숫자를 입력하세요: ");
	
	while(1) {
	scanf("%s",char);
	rewind(stdin);
	int i = 0;
	for(;i != '\0';i++) 
		if(!(input[i]>= '0' && input[i] <= '9'))
			break;
	if(number[i]=='\0')
		integer_number = atoi(number); 
		
	if(double_checking(User, integer_number))
		break;
		
	printf("\n 다른  숫자를 입력하세요: ")
	}
	
	return integer_number;
}

int get_number_byCom(int[N][] Com_bingo) {
	
	int random_number = -1
	
	while(1) {
	random_number = Com_bingo[rand%N][rand%N];
	if(random_number != -1)
		break;
	}
	
	return random_number;
} 

int process_bingo(int[N][] input, int x){
	
}

int count_bingo(int[N][] input) {
	
}

int double_checking (int[N][] input, int x) {
	
}


