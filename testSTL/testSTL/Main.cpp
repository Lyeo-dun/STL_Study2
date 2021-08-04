#include "MainUpdate.h"

int main(void)
{
	srand(GetTickCount64());
	MainUpdate Main;

	Main.Initialize();

	while (true)
	{	
		Main.Update();
		Main.Render();
	}

	Main.Release();

	return 0;
}