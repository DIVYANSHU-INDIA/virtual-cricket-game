#include<vector>
// #include<string>

#include"player.h"    //<string>

class Team{
	public:
	 	 std::string name;
	 	 int totalRunsScored;
	 	 int wicketLost;
	 	 int totalBallsBowled;
	 	 std::vector<Player> players;
	 	 Team();

};
