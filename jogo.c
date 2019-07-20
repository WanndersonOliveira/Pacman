#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Personagem{
	char forma;
	int x;
	int y;
	int tipo;
	int ctrl;
};

/* A struct personagem define todos os atributos do personagem do jogo.
	* char forma : Define a forma que o personagem vai assumir;
	* int x,y: localização do personagem no game;
	* int tipo: tipo de personagem, que pode ser:
		tipo = 1 : Personagem principal;
		tipo = 2 : fantasma1;
		tipo = 3 : fantasma2;
		tipo = 4 : fantasma3;
		tipo = 5 : fantasma4;	
	* int ctrl : controla cada um dos fantasmas;
*/	

int main(){
	struct Personagem pacman;
	struct Personagem f1, f2, f3, f4;
	char tela[30][30]; //[y][x]
	int i,j;
	int score = 0;
	int randomico;
	char control;
	
	pacman.forma=67;
	pacman.x = 15;
	pacman.y = 22;
	pacman.tipo = 1;
	
	f1.forma=81;
	f1.x = 10;
	f1.y = 10;
	f1.tipo = 2;
	f1.ctrl = 0;
	
	f2.forma=81;
	f2.x = 17;
	f2.y = 12;
	f2.tipo = 3;
	f2.ctrl = 0;
	
	f3.forma=81;
	f3.x = 18;
	f3.y = 9;
	f3.tipo = 4;
	f3.ctrl = 0;
	
	f4.forma=81;
	f4.x = 11;
	f4.y = 11;
	f4.tipo = 5;
	f4.ctrl = 0;
	
	while(1){
		
		
	randomico = rand()%100;
	
	
	for(i = 0; i < 30; i++){
		for(j = 0; j < 30; j++){
			tela[i][j] = 32;
		}
	}
	
	//Delimitação da tela
	
	for(i = 0; i < 30; i++){
		tela[0][i] = 219;
		tela[i][0] = 219;
		tela[i][29] = 219;
		tela[29][i] = 219;
	}
	
	for(i = 2; i < 6; i++){
		tela[i][2] = 219;
		tela[2][i] = 219;
		tela[5][i] = 219;
		tela[7][i] = 219;
		tela[21][i] = 219;
		tela[23][i] = 219;
		tela[27][i] = 219;
		tela[i][5] = 219;
		tela[i][7] = 219;
		tela[i][14] = 219;
		tela[i][16] = 219;
		tela[i][21] = 219;
		tela[i][23] = 219;
		tela[i][27] = 219;
		tela[i][15] = 254;    //Distribuição das pastilhas
	}
	
	
	for(i = 7; i < 15;i++){
		tela[2][i] = 219;
		tela[5][i] = 219;
	}
	
	for(i = 7; i < 22; i++){
		tela[i][2] = 219;
		tela[i][5] = 219;
		tela[i][7] = 219;
		tela[i][21] = 219;
		tela[7][i] = 219;
		tela[21][i] = 219;
	}
	
	for(i = 16; i < 22; i++){
		tela[2][i] = 219;
		tela[5][i] = 219;
	}
	
	for(i = 23; i < 28;i++){
		tela[2][i] = 219;
		tela[5][i] = 219;
		tela[i][2] = 219;
		tela[i][5] = 219;
		tela[i][7] = 219;
		tela[i][21] = 219;
		tela[7][i] = 219;
		tela[21][i] = 219;
		tela[23][i] = 219;
		tela[27][i] = 219;
		tela[i][23] = 219;
		tela[i][27] = 219;
	}
	
	for(i = 7; i < 22; i++){
		tela[23][i] = 219;
		tela[27][i] = 219;
		tela[i][23] = 219;
		tela[i][27] = 219;
	}
	
	//Distribuição das pastilhas
	for(i = 1; i < 29; i++){
		tela[1][i] = 254;
		tela[i][1] = 254;
		tela[6][i] = 254;
		tela[i][6] = 254;
		tela[22][i] = 254;
		tela[i][22] = 254;
		tela[i][28] = 254;
		tela[28][i] = 254;
	}
	
	//Porta
	tela[7][15] = 220;
	
	//Posicionamento do personagem principal (PacMan)
	
	tela[pacman.y][pacman.x] = pacman.forma;
	
	
	//Posicionamento dos fantasmas
	tela[f1.y][f1.x] = f1.forma;
	tela[f2.y][f2.x] = f2.forma;
	tela[f3.y][f3.x] = f3.forma;
	tela[f4.y][f4.x] = f4.forma;
	
	
	//Exibição da tela
	for(i = 0; i < 30; i++){
		for(j = 0; j < 30; j++){
			printf("%c", tela[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\nSCORE: %d",score);
	
	if((int)control == 27){
		break;
	}
	
	if(kbhit()){
		control = getch();

		printf("\n\n%d", control);
			if(control == 'a'){
				if(pacman.x >= 2){	
				  pacman.x--;
				  score++;
				}
			} else if(control == 'd'){
				if(pacman.x < 28){
					pacman.x++;
					score++;
				}
			} else if(control == 'w'){
				if(pacman.y >= 2){
					pacman.y--;
					score++;
				}
			} else if(control == 's'){
				if(pacman.y < 28){
					pacman.y++;
					score++;
				}
			}	
	}
	
	//Movimento do fantasma f1
	
	if((f1.x > 15 && f1.y > 7)&&f1.ctrl == 0){
		f1.x--;
	}
	
	if((f1.x < 15 && f1.y > 7)&&f1.ctrl==0){
		f1.x++;
	}
	
	if((f1.x == 15&&f1.ctrl == 0)){
		f1.y--;
	}
	
	if(f1.y == 1 && f1.x < 28){
		f1.x++;
	}
	
	if(f1.x == 28 && f1.y < 22){
		f1.y++;
		f1.ctrl = 1;
	}
	
	if(f1.y == 22 && f1.x > 6){
		f1.x--;
	}
	
	if(f1.x == 6){
		f1.y--;
	}
	
	//Movimento do fantasma f2
	
	if((f2.x > 15 && f2.y > 7) && f2.ctrl==0){
		f2.x--;
	}
	
	if((f2.x < 15 && f2.y > 7)&&f2.ctrl==0){
		f2.x++;
	}
	
	if((f2.x == 15&&f2.ctrl == 0&&f2.y > 6)){
		f2.y--;
	}
	
	if(f2.y == 6&&f2.ctrl==0){
		f2.x++;
	}
	
	if(f2.y==6 && f2.x==22 && f2.ctrl==0){
		f2.y++;
		f2.ctrl++;
	}
	
	if(f2.x==22 && f2.ctrl==1){
		f2.y++;
	}
	
	if(f2.y==22 && f2.ctrl==1){
		f2.x--;
	}
	
	if(f2.x==6 && f2.ctrl==1){
		f2.y--;
	}
	
	if(f2.y==6 && f2.ctrl==1){
		f2.ctrl--;
	}
	
	//Movimentação do fantasma f3
	
	if((f3.x > 15 && f3.y > 7) && f3.ctrl==0){
		f3.x--;
	}
	
	if((f3.x < 15 && f3.y > 7)&&f3.ctrl==0){
		f3.x++;
	}
	
	if((f3.x == 15&&f3.ctrl == 0&&f3.y > 6)){
		f3.y--;
	}
	
	
	if(f3.y == 6&&f3.ctrl==0){
		if(f3.x == 27){
			f3.ctrl++;
		}
		
		f3.x++;
	}
	
	if(f3.x==28 && f3.ctrl==1){
		if(f3.y == 27){
			f3.ctrl++;
		}
		
		f3.y++;
	}
	
	if(f3.y == 28 && f3.ctrl == 2){
		if(f3.x==23){
			f3.ctrl--;
		}
		
		f3.x--;
	}
	
	if(f3.x == 22 && f3.ctrl == 1){
		f3.y--;
	}
	
	if(f3.y == 6 && f3.ctrl == 1){
		if(f3.x==27){
			f3.ctrl++;
		}
		
		f3.x++;
	}
	
	if(f3.x==28 && f3.ctrl==2){
		if(f3.y==21){
			f3.ctrl++;
		}
		
		f3.y++;
	}
	
	if(f3.y == 22 && f3.ctrl == 3){
		if(f3.x == 7){
			f3.ctrl--;
		}
		
		f3.x--;
	}
	
	if(f3.x==6 && f3.ctrl==2){
		if(f3.y==27){
			f3.ctrl++;
		}
		
		f3.y++;
	}
	
	if(f3.y==28 && randomico > 50 && f3.ctrl==3){
		if(f3.x==21){
			f3.ctrl=f3.ctrl-2;
		}
		
		f3.x++;
	}
	
	if(f3.y==28 && randomico < 50 && f3.ctrl==3){
		if(f3.x==2){
			f3.ctrl--;
		}
		
		f3.x--;
	}
	
	if(f3.x == 1 && f3.ctrl == 2){
		if(f3.y==2){
			f3.ctrl++;
		}
		
		f3.y--;
	}
	
	if(f3.y==1 && f3.ctrl == 3){
		if(f3.x==5){
			f3.ctrl--;
		}
		
		f3.x++;
	}
	
	if(f3.x==6 && f3.ctrl == 2){
		if(f3.y==5){
			f3.ctrl--;
		}
		
		f3.y++;
	}
	
	//Movimentação do fantasma 4
	
	if((f4.x > 15 && f4.y > 7) && f4.ctrl==0){
		f4.x--;
	}
	
	if((f4.x < 15 && f4.y > 7)&&f4.ctrl==0){
		f4.x++;
	}
	
	if((f4.x == 15&&f4.ctrl == 0&&f4.y > 6)){
		f4.y--;
	}
	
	if(f4.y == 6){
		f4.ctrl=1;
		f4.x++;
	}
	
	if(pacman.x < f4.x){
		f4.x--;
	}
		
	if(pacman.x > f4.x){
		f4.x++;
	}
	
	
	if((f3.x == pacman.x && f3.y == pacman.x) || (f2.x == pacman.x && f2.y==pacman.y) || (f1.x==pacman.x &&
		f1.y==pacman.y) || (f4.x==pacman.x && f4.y==pacman.y)){
			tela[10][10] = 'G';
			tela[10][11] = 'A';
			tela[10][12] = 'M';
			tela[10][13] = 'E';
			tela[10][15] = 'O';
			tela[10][16] = 'V';
			tela[10][17] = 'E';
			tela[10][18] = 'R';
			control = 27;
		}

	
	printf("\n%d", randomico);
	printf("\n%d", f4.ctrl);
	sleep(1);
	system("cls");
	}
	
}
