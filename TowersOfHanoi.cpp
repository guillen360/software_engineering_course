#include <iostream>

void SolveTowerOfHanoi(int count, char source, char destination, char spare) // for poles 'A', 'B', 'C'
{
	if (count == 1)
	{
		std::cout << "move disk from pole source " << source <<
			" to pole " << destination << std::endl;
	} else 
	{
		SolveTowerOfHanoi(count - 1, source, spare, destination);
		SolveTowerOfHanoi(1, source, destination, spare);
		SolveTowerOfHanoi(count - 1, spare, destination, source);
	}

}