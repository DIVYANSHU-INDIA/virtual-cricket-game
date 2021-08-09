#include "game.h"


using namespace std;


int main() {

	Game game;
	game.Welcome();
//	 cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout<<"\n Press Enter to Continue";
	 getchar();
	game.showAllPllayers();

	cout << "\n Press Enter to Continue";
		 getchar();

 game.selectPlayers();
game.showTeamPlayer();
//		 cin.ignore(numeric_limits<streamsize>::max(),'\n');

cout<<"\n Press Enter to Continue";
 getchar();

 game.toss();

 game.startFirstInnings();

cout<<"\n Press Enter to Continue"<<endl;
		 				 		 getchar();

		 		game.startSecondInnings();
		 		cout<<"\n Press Enter to Continue"<<endl;
		 				 				 		 getchar();
		 		game.showFinalScoreCard();

	getchar();
	return 0;
}
