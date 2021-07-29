#include "MainUpdate.h"

int main(void)
{

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