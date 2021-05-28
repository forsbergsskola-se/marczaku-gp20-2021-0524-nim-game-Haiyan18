private:

int getComputerMove();
int nTaken = getComputerMove();

int findGoodMove(int matches);

bool isBadPosition(int matches);

int getUserMove();
void announceResult();
Player opponent(Player player);

int matches;
Player whoseTurn;