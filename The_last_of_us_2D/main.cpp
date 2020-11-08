#include "Game.h"

int main()
{
	srand(static_cast<unsigned>(time(NULL)));
	Game theLastOfUs2D;
	while (theLastOfUs2D.running() && !theLastOfUs2D.getEndGame())
	{
		theLastOfUs2D.update();
		theLastOfUs2D.render();
	}
	return 0;
}