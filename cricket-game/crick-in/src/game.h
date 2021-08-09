#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include<stdio.h>
//#include<vector>
//#include<string>

#include"team.h"     //Player.h <string>, <vector>


class Game{
public:
	bool isFirstInnings;
	Team teamA, teamB;
	Team *battingTeam, *bowlingTeam;
	Player *batsman, *bowler;
	Game();
	int playersPerTeam;
	int maxBalls;
	int totalPlayers;
	std::string players[11];
	void Welcome();
	void showAllPllayers();
	int takeIntegerInput();
	void selectPlayers();
	bool validateSelectedPlayer(int);
	void showTeamPlayer();
	void toss();
	void tossChoice(Team);
	void startFirstInnings();
	void intializePlayers();
	void playInnings();
	void bat();
	bool validateInningsScore();
	void showGameScoreCard();
	void startSecondInnings();

	void showFinalScoreCard();
	std::string Winner;




};
