#include<iostream>
#include<vector>

using namespace std;


int clearboard(int board[3][3]);
int printboard (int board[3][3]);
int wincheck(int board[3][3]);
int aiturn(int board[3][3]);
bool validmove(int x, int y, int board[3][3]);
int minimax_value(int board_temp[3][3], int score, int player, int depth);


int main() {
int x, y;
int board[3][3];

clearboard(board);
printboard(board);


cout << "X go first"<<endl;

do{
    
    cout << "Input Move" << endl;
    cin >> x >> y;

    while(validmove(x, y, board) == false){
        cout << "Invalid Move! Try Again:" << endl;
        cin >> x >> y;
   	}
    
board[x][y] = 1;

if(wincheck(board) == 0){
	aiturn(board);
}

printboard(board);

}while (wincheck(board) == 0);

if(wincheck(board)==1) {
cout << "X's win"<<endl;
}else if(wincheck(board) == 10){
	cout << "Draw" << endl;
}else{
cout << "O's win"<<endl;
}

	return 0;
}





int minimax_value(int board_temp[3][3], int score, int player, int depth) {


		if (wincheck(board_temp) == -1){
							depth++;
							score = score  + 10 -depth;
			return score;
		}

		if (wincheck(board_temp) == 1){
							depth++;
							score = score - 10 + depth;
			return score;
		}

		if (wincheck(board_temp) == 0){

		for(int x = 0; x<3; x++){
			for(int y= 0; y<3;y++){
				if(board_temp[x][y] == 0){
					depth++;
					board_temp[x][y] = player;
					score = minimax_value(board_temp,score,player*-1, depth);
					depth = depth - 1;
					board_temp[x][y] = 0;

				}

			}
		}

		return score;
	
}
return 0;
}





int aiturn(int board[3][3]){
int board_temp[3][3];
int depth = 1;


for(int x = 0; x<3;x++){
	for(int y=0;y<3;y++){
		board_temp[x][y]=board[x][y];
	}
}

int score_store= -200000;
int score = 0;
int move_play[2] = {0,0};
int player = -1;

for(int x = 0; x< 3;x++){
	for(int y = 0; y< 3; y++){
		if(board[x][y] == 0){

			board_temp[x][y] = player;
			score = minimax_value(board_temp,score,player*-1, depth);
			board_temp[x][y] = 0;
			cout << x<< "  " << y << "   " << score<< endl;

		if(score>score_store){

			score_store = score;
			move_play[0] = x;
			move_play[1] = y;
		}
		score = 0;

		}
	}
}
		cout << move_play[0] <<"  "<< move_play[1] <<endl;

board[move_play[0]][move_play[1]] = -1;
		cout << "d2" <<endl;

return 0;
}






int clearboard(int board[3][3]) { //Clear Board function
	
	for (int x = 0; x<3; x++){

		for(int y = 0; y<3; y++){

		board[x][y] = 0;

		}
	}

	return 0; 


}






bool validmove(int x, int y, int board[3][3]) {
    
    bool check = false;
    
   int i = 3;
        
        if(x < i || y < i){
        	if(board[x][y] == 0){
            check = true;
        }
    }

        
    return check;
    
}







int printboard(int board[3][3]) { //Print board

	for(int r = 0 ; r< 3; r++){

		if ( r == 0){

			cout << "   |";
		}

		cout << " "<<r;
		cout << " |";

	}

	cout << endl ;	
	for (int y = 0; y<3; y++){

		cout << " "<< y << " ";
		cout << "|";

		for(int x = 0; x<3; x++){

		if( board[x][y] == 0){

		cout << "   |";

		}

		if( board[x][y] == 1){

		cout << " X |";

		}

		if( board[x][y] == -1){

		cout << " O |";

		}
	}

		cout << endl;
	}

return 0;
}






int wincheck(int board[3][3]) { //check for win

	for(int y =0; y<3; y++){
        
        if (board[y][0] == board[y][1] && board[y][0] == board[y][2] && board[y][0] != 0){
            return board[y][0];
        }

        if (board[0][y] == board[1][y] && board[0][y] == board[2][y] && board[2][y] != 0){
			return board[0][y];
		}

	}

	if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[2][2] != 0){
		return board[0][0];
	}
	if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != 0){
		return board[0][2];
	}

	for(int x = 0; x< 3; x++){
		for(int y = 0; y< 3; y++){
			if(board[x][y] == 0){
				return 0;
			}
		}
	}
	
	
	return 10; //10 code for draw
}





