private:

int getPlayer2Move();
int nTaken = getPlayer2Move();

int findGoodMove(int matches);

bool isBadPosition(int matches);

int getUserMove();
void announceResult();
Player opponent(Player player);

int matches;
Player whoseTurn;