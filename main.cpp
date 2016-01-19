#include<iostream>
#include<vector>

using namespace std;

int board[3][3];
int x, y;

int clearboard(int board[3][3]);
int printboard (int board[3][3]);
int wincheck(int board[3][3]);
int aiturn(int board[3][3]);
bool validmove(int x, int y);

int main() {


clearboard(board);

cout << "X go first"<<endl;

do{
    
    cout << "Input Move" << endl;
    cin >> x >> y;

    while(validmove(x, y) == false){
        cout << "Invalid Move! Try Again:" << endl;
        cin >> x >> y;
    }
    
board[x][y] = 1;

//aiturn(board);

printboard(board);

cout << wincheck(board) << endl;
    
}while (wincheck(board) == 0);

if(wincheck(board)==1) {
cout << "X's win"<<endl;
}else {
cout << "O's win"<<endl;
}


	return 0;
}

int aiturn(int board[3][3]){

	int counter = 0;

			for (int x = 0; x<3; x++){
			for(int y = 0; y<3;y++){

			if(board[x][y] == 0){
				counter++;

			}

		}

		}

		int possiblemoves[counter][2];
			int i =0;


		for (int x = 0; x<3; x++){
			for(int y = 0; y<3;y++){

			if(board[x][y] == 0){

				possiblemoves[i][0] = x;
				possiblemoves[i][1] = y;

				i++;

			}

		}

		}


		for (int i = 0; i<counter; i++){


				cout << possiblemoves[i][0] << possiblemoves[i][1] <<endl;

		
			}

		


	


	

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

bool validmove(int x, int y) {
    
    bool check = false;
    
   int i = 3;
        
        if(x < i || y < i){
            check = true;
        }

        

    
    return check;
    
}

int printboard(int board[3][3]) { //Print board
	
	for (int y = 0; y<3; y++){
		cout << "|";

		for(int x = 0; x<3; x++){

		if( board[x][y] == 0){

		cout << "   |";

		}

		if( board[x][y] == 1){

		cout << " X |";

		}

		if( board[x][y] == 2){

		cout << " O |";

		}
	}

		cout << endl;
	}



return 0;
}

int wincheck(int board[3][3]) { //check for win

	cout << "0"<<endl;

	for(int y =0; y<3; y++){
        
        if (board[y][0] == board[y][1] && board[y][0] == board[y][2] && board[y][0] != 0){
            return 1;
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

	return 0;
}
