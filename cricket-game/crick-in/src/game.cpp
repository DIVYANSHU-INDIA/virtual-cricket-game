#include"game.h"
using namespace std;

Game::Game(){

	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Virat";
	players[1] = "Rohit";
	players[2] = "Dhawan";
	players[3] = "Pant";
	players[4] = "karthik";
	players[5] = "KLRahul";
	players[6] = "Jadeja";
	players[7] = "Hardik";
	players[8] = "Bumrah";
	players[9] = "BKumar";
	players[10] = "Ishant";



	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";

}
void Game::Welcome(){



	cout<<"------------------------------------------------------------"<<endl;
	cout<<"|=========================CRIC-IN==========================|"<<endl;
	cout<<"------------------------------------------------------------"<<endl;
	cout<<"|                                                          |"<<endl;
	cout<<"|         WELCOME TO YOUR OWN VIRTUAL CRICKET GAME         |"<<endl;
	cout<<"|                                                          |"<<endl;
	cout<<"|__________________________________________________________|"<<endl;
	cout<<endl;
	    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
		cout<<"|==========================================INSTRUCTION==========================================|"<<endl;
		cout<<"-------------------------------------------------------------------------------------------------"<<endl;
		cout<<"|  1. Create 2 Teams (Team-A and Team-B with Four Player each) from the given set of 11 Players |"<<endl;
		cout<<"|  2. Lead the Toss and decide the choice of Play.                                              |"<<endl;
		cout<<"|  3. Each Inning will be of Six balls.                                                         |"<<endl;
		cout<<"|  4. Scoring Zero will Leads your Batsman declared OUT!                                        |"<<endl;
		cout<<"|  5. 1st Selected Player from bowling team will Bowl all the six Balls.                        |"<<endl;
		cout<<"|_______________________________________________________________________________________________|"<<endl;


}
void Game::showAllPllayers(){
	cout<<endl;
	cout<<"------------------------------------------"<<endl;
	cout<<"|============Pool of Players==============|"<<endl;
	cout<<"-------------------------------------------"<<endl;
	for(int i = 0; i < totalPlayers ; i++){
              cout<<"\t\t["<<i<<"] "<<players[i]<<endl;

	}
}
int Game::takeIntegerInput(){

	int n;

      while(!(cin>> n)){
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
          cout<<"Invalid input! Please try again with valid Input";
      }

   return n;
}
bool Game::validateSelectedPlayer(int index){
	int n;

	vector<Player>player;

	player = teamA.players;

	n= player.size();
	for(int i = 0; i<n;i++){
		if(player[i].index == index){
			return false;
		}
	}

	player = teamB.players;
	n = player.size();
	for(int i = 0; i<n;i++){
			if(player[i].index == index){
				return false;
			}


}
                 return true;
}

void Game::showTeamPlayer(){

	vector<Player> teamAPlayers = teamA.players;
	vector<Player> teamBPlayers = teamB.players;

	cout<<endl<<endl<<endl;
	            cout<<"--------------------------\t\t----------------------------"<<endl;
	            cout<<"|=========Team-A=========|\t\t|==========Team-B==========|"<<endl;
	            cout<<"-------------------------"
	            		"\t\t---------------------------"<<endl;
	for(int i = 0; i<playersPerTeam; i++)
	{
	           cout<<"|\t"<<"["<<i<<"] "<< teamAPlayers[i].name<<"\t |"
			      <<"\t\t"
			      <<"|\t"<<"["<<i<<"] "<<teamBPlayers[i].name<<"\t   "
			    		  "|"<<endl;
	}
	cout<<"-------------------------\t\t----------------------------"<<endl;

}



void Game::selectPlayers(){

	cout<< endl;
	cout<<"---------------------------------------------------"<<endl;
	cout<<"|============Create Team-A and Team-B==============|"<<endl;
	cout<<"---------------------------------------------------"<<endl;
	for(int i = 0; i< playersPerTeam; i++){

		// Team A Selection

teamASelection:
	cout<< endl<< " Select Player "<<i+1<<" of Team A- ";

			int playerIndexTeamA = takeIntegerInput();

	if(playerIndexTeamA<0||playerIndexTeamA>10)
			{
				cout<<"Please Select From the given Players"<<endl;
				goto teamASelection;
			}
	else if(!validateSelectedPlayer(playerIndexTeamA)){
		cout<<endl<<"Player has Already being Selected Please Select another player"<<endl;
		  goto teamASelection;

			}

	else    {
				Player teamAPlayer;
				teamAPlayer.index = playerIndexTeamA;
				teamAPlayer.name = players[playerIndexTeamA];
				teamA.players.push_back(teamAPlayer);
		    }


// Team B selection


 teamBSelection:
	cout<< endl<< " Select Player "<<i+1<<" of Team B- ";
    int playerIndexTeamB = takeIntegerInput();


	if(playerIndexTeamB<0||playerIndexTeamB>10)

	            {

					cout<<"Please Select From the given Players"<<endl;
					goto teamBSelection;
				}
	else if(!validateSelectedPlayer(playerIndexTeamB)){
			cout<<endl<<"Player has Already being Selected Please Select another player"<<endl;
			goto teamBSelection;

				}

	else      {

				Player teamBPlayer;
				teamBPlayer.index = playerIndexTeamB;
				teamBPlayer.name = players[playerIndexTeamB];
				teamB.players.push_back(teamBPlayer);

	          }

	}
}
void Game::toss(){
	cout<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<"|=================Let's Toss==================|"<<endl;
	cout<<"-----------------------------------------------"<<endl<<endl;


	cout<<"Tossing Coin..."<<endl;

	srand(time(NULL));

	int randomValue = rand()%2; // 0 1

	switch(randomValue){
		case 0 :    cout<<"Team-A have won the Tosss"<<endl<<endl;
		                      tossChoice(teamA);
		                        break;
		case 1 :    cout<<"Team-B have won the Tosss"<<endl<<endl;
							  tossChoice(teamB);
				                break;


	}


}

void Game::tossChoice(Team tossWinnerTeam){

	cout<<"Enter 1 to Bat or 2 To Bowl first"<<endl
			<<"1. Bat"<<endl
			<<"2. Bowl"<<endl;
	int tossInput = takeIntegerInput();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	       switch(tossInput){

	       case 1:   cout<< endl<<tossWinnerTeam.name<< " Won the Toss and elected to bat first ! "<<endl<<endl;
	       	   	   	   if(tossWinnerTeam.name.compare("Team-A")==0){
	       	   	   		                             battingTeam = &teamA;
	       	   	   		                             bowlingTeam = &teamB;

	       	   	   	   }else{
	       	   	   	                                 battingTeam = &teamB;
	       	   	   		       	   	   	   		     bowlingTeam = &teamA;
	       	   	   	   }

	    	   	   	   break;
	       case 2:    cout<< endl<<tossWinnerTeam.name<< " Won the Toss and elected to bowl first ! "<<endl<<endl;
	                       if(tossWinnerTeam.name.compare("Team-A")==0){
	      	       	   	   		                      battingTeam = &teamA;
	      	       	   	   		                      bowlingTeam = &teamB;

	      	       	   	   	   }else{
	      	       	   	   	                          battingTeam = &teamB;
	      	       	   	   		       	   	   	   	  bowlingTeam = &teamA;

	      	       	   	   	   }
	       	    	   break;


	       default:   cout<< " Invalid! input Please Try Again "<<endl<<endl;
	                  tossChoice(tossWinnerTeam);
	    	            break;
	       }



}

void Game::startFirstInnings(){

	cout<<"\t\t ||| FIRST INNINGS STARTS ||| "<<endl<<endl;
		isFirstInnings = true;
		intializePlayers();
		playInnings();

}
void Game::intializePlayers(){
	//choose Batsman and Bowller
		batsman = &battingTeam->players[0];
		bowler   = &bowlingTeam->players[0];
		cout<<battingTeam->name<< " - "<<batsman->name<<" is batting "<<endl<<endl;
		cout<<bowlingTeam->name<< " - "<<bowler->name<<" is bowling "<<endl<<endl;
}

void Game::playInnings(){

	for(int i = 0; i<maxBalls; i++){

		cout<<"Press Enter to bowl";
		getchar();
		cout<<"Bowling......"<<endl;
		bat();
		if(!validateInningsScore()){
			           break;
		}
	}
}
void Game::bat(){
	srand(time(NULL));
	int runsScored = rand()%7;

	batsman->runsScored =  batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed+ 1;

	bowler->ballsBowled= bowler->ballsBowled +1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled+1;
	bowler->runsGiven = bowler->runsGiven+runsScored;



	if(runsScored != 0){
		cout<<endl<<bowler->name << " to "<< batsman->name <<" "<< runsScored<< " runs!"<<endl<<endl;
		showGameScoreCard();
	}else{
		cout<<endl<<bowler->name << " to "<< batsman->name <<" OUT! "<<endl<<endl;
		battingTeam->wicketLost = battingTeam->wicketLost +1;
		bowler->wicketsTaken = bowler->wicketsTaken+1;

		showGameScoreCard();

		int nextPlayerIndex = battingTeam->wicketLost;
		batsman = &battingTeam->players[nextPlayerIndex];
	}




}

bool Game::validateInningsScore(){
	if(isFirstInnings){
		if(battingTeam->wicketLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls ){
			cout<<"\t\t ||| FIRST ININGS ENDS ||| "<<endl<<endl;

			cout<< battingTeam->name <<" "<< battingTeam->totalRunsScored<<" - "
				<< battingTeam->wicketLost <<" ("<< bowlingTeam->totalBallsBowled
				<< ")" <<endl;
			cout<<bowlingTeam->name << " needs "<<battingTeam->totalRunsScored + 1
					<< " runs to win the match"<<endl<<endl;

			return false;

		}

	}else{
		if(battingTeam->wicketLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls|| battingTeam->totalRunsScored > bowlingTeam->totalRunsScored){
					if(battingTeam->totalRunsScored > bowlingTeam->totalRunsScored){
			                 cout<<" "<<battingTeam->name<<" WON! "<<endl<<endl;
			                 return false;

					}else
						if(battingTeam->totalRunsScored == bowlingTeam->totalRunsScored) {
			                 cout<<" "<<battingTeam->name<<" DRAWS! The Match  "  <<endl<<endl;
			                 return false;

					}else
						if(battingTeam->totalRunsScored < bowlingTeam->totalRunsScored) {
		                 cout<<" "<<bowlingTeam->name<<" WON! The Match  "  <<endl<<endl;
		                 return false;

				 }

	}

              }
	return true;

}

void Game::showGameScoreCard(){
	cout<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	cout<<"\t "<< battingTeam->name <<" "<< battingTeam->totalRunsScored<< " - "
		<< battingTeam->wicketLost<<" ("<< bowlingTeam->totalBallsBowled << ") | "<<batsman->name
		<<" "<< batsman->runsScored<<" (" <<batsman->ballsPlayed << ") \t"<<bowler->name<< " "
		<<bowler->ballsBowled<<" - "<<bowler->runsGiven<<" - "<<bowler->wicketsTaken<<"\t"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;

}
void Game::startSecondInnings(){
	cout<<"\t\t ||| SECOND INNINGS STARTS ||| "<<endl<<endl;

	Team *p;
	p = battingTeam;
	battingTeam = bowlingTeam;
	bowlingTeam = p;

	  isFirstInnings = false;
	  intializePlayers();
	  playInnings();


}
void Game::showFinalScoreCard(){

	cout<<endl;
	cout<<"\t\t||| MATCH ENDS |||"<<endl<<endl;
	cout<<battingTeam->name<<" "<<battingTeam->totalRunsScored<< "-"<<battingTeam->wicketLost<<"("<<battingTeam->totalBallsBowled<<")"<<endl;
	cout<<"========================================"<<endl;
	cout<<"|PLAYER	       BATTING	       BOWLING|"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"| ["<<"0"<<"]"<<battingTeam->players[0].name<<"\t"<<battingTeam->players[0].runsScored
			<<"("<<battingTeam->players[0].ballsPlayed<<")"<<"\t\t "<<battingTeam->players[0].ballsBowled
			<<"- "<<battingTeam->players[0].runsGiven<<"-"<<battingTeam->players[0].wicketsTaken<<" |"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"| ["<<"1"<<"]"<<battingTeam->players[1].name<<" \t"<<battingTeam->players[1].runsScored
				<<"("<<battingTeam->players[1].ballsPlayed<<")"<<"\t\t "<<battingTeam->players[1].ballsBowled
				<<"- "<<battingTeam->players[1].runsGiven<<"-"<<battingTeam->players[1].wicketsTaken<<" |"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"| ["<<"2"<<"]"<<battingTeam->players[2].name<<" \t"<<battingTeam->players[2].runsScored
					<<"("<<battingTeam->players[2].ballsPlayed<<")"<<"\t\t "<<battingTeam->players[2].ballsBowled
					<<"- "<<battingTeam->players[2].runsGiven<<"-"<<battingTeam->players[2].wicketsTaken<<" |"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"| ["<<"1"<<"]"<<battingTeam->players[3].name<<" \t"<<battingTeam->players[3].runsScored
					<<"("<<battingTeam->players[3].ballsPlayed<<")"<<"\t\t "<<battingTeam->players[3].ballsBowled
					<<"- "<<battingTeam->players[3].runsGiven<<"-"<<battingTeam->players[3].wicketsTaken<<" |"<<endl;
	cout<<"======================================="<<endl;
	cout<<endl;
	cout<<endl;

	cout<<battingTeam->name<<" "<<bowlingTeam->totalRunsScored<< "-"<<bowlingTeam->wicketLost<<"("<<bowlingTeam->totalBallsBowled<<")"<<endl;
		cout<<"========================================"<<endl;
		cout<<"|PLAYER	      BATTING	       BOWLING|"<<endl;
		cout<<"----------------------------------------"<<endl;
		cout<<"| ["<<"0"<<"]"<<bowlingTeam->players[0].name<<"\t"<<bowlingTeam->players[0].runsScored
				<<"("<<bowlingTeam->players[0].ballsPlayed<<")"<<"\t\t "<<battingTeam->players[0].ballsBowled
				<<"- "<<battingTeam->players[0].runsGiven<<"-"<<bowlingTeam->players[0].wicketsTaken<<" |"<<endl;
		cout<<"----------------------------------------"<<endl;

		cout<<"| ["<<"1"<<"]"<<bowlingTeam->players[1].name<<" \t"<<bowlingTeam->players[1].runsScored
					<<"("<<bowlingTeam->players[1].ballsPlayed<<")"<<"\t\t "<<bowlingTeam->players[1].ballsBowled
					<<"- "<<bowlingTeam->players[1].runsGiven<<"-"<<bowlingTeam->players[1].wicketsTaken<<" |"<<endl;
		cout<<"----------------------------------------"<<endl;
		cout<<"| ["<<"2"<<"]"<<bowlingTeam->players[2].name<<" \t"<<bowlingTeam->players[2].runsScored
						<<"("<<bowlingTeam->players[2].ballsPlayed<<")"<<"\t\t "<<bowlingTeam->players[2].ballsBowled
						<<"- "<<bowlingTeam->players[2].runsGiven<<"-"<<bowlingTeam->players[2].wicketsTaken<<" |"<<endl;
		cout<<"----------------------------------------"<<endl;
		cout<<"| ["<<"1"<<"]"<<bowlingTeam->players[3].name<<" \t"<<bowlingTeam->players[3].runsScored
						<<"("<<bowlingTeam->players[3].ballsPlayed<<")"<<"\t\t "<<bowlingTeam->players[3].ballsBowled
						<<"-"<<bowlingTeam->players[3].runsGiven<<"-"<<bowlingTeam->players[3].wicketsTaken<<" |"<<endl;

		cout<<"========================================="<<endl;




}























