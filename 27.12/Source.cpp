#include "Header.h"

int main()
{
	Players** arr = new Players * [3];
	arr[0] = new Human(100, 2);
	arr[1] = new Cat(50, 4);
	arr[2] = new Robot(150, 1);

	Competition** arr1 = new Competition * [4];
	arr1[0] = new Run(30);
	arr1[1] = new Wall(1);
	arr1[2] = new Run(30);
	arr1[3] = new Wall(2);

	for (int i = 0; i < 3; i++)
	{
		int score = 0;
		bool fail = false;
		for (int j = 0; j < 4; j++)
		{
			if (arr1[j]->TypeCompetition() == "Wall")
			{
				if (arr[i]->GetJump() >= arr1[j]->GetCompetition())
					continue;
				else
					fail = true;
			}
			else
			{
				score += arr1[j]->GetCompetition();
				if (arr[i]->GetDistance() >= score)
					continue;
				else
					fail = true;
			}
			if (fail)
			{
				cout << arr[i]->GetName() << " doesn't complete test " << arr1[j]->TypeCompetition() << " (test #" << j + 1 << ")\n";
				if (arr1[j]->TypeCompetition() == "Wall")
				{
					cout << arr[i]->GetName() << " can jump " << arr[i]->GetJump() << " m, and wall height is " << arr1[j]->GetCompetition()
						<< " m\n\n";
				}
				else
				{
					cout << arr[i]->GetName() << " can run " << arr[i]->GetDistance() << " km, and distance is " << score
						<< " km\n\n";
				}
			}
		}
		if (!fail)
			cout << arr[i]->GetName() << " completed all competition\n\n";
	}
}