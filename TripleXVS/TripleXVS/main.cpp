#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <ctime>

using namespace std;

string replaceFirstOccurrence(
	string& s,
	const string& toReplace,
	const string& replaceWith)
{
	std::size_t pos = s.find(toReplace);
	if (pos == std::string::npos)
	{
		return s;
	}

	return s.replace(pos, toReplace.length(), replaceWith);
}

bool LoadIntroductionText(int _levelDifficulty)
{
	ifstream myfile("ASCII_ART.txt");

	string line;
	list<string> TextFileList;

	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);

			TextFileList.push_back(line);
		}
		myfile.close();
	}

	for (string line : TextFileList)
	{
		replaceFirstOccurrence(line, "{0}", to_string(_levelDifficulty));
		cout << line << endl;
	}



	if (TextFileList.size() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}


};


bool Game(int _levelDifficulty)
{
	LoadIntroductionText(_levelDifficulty);

	int GuessA, GuessB, GuessC = 0;

	const int CodeA = rand() % _levelDifficulty + 1;
	const int CodeB = rand() % _levelDifficulty + 1;
	const int CodeC = rand() % _levelDifficulty + 1;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	cout << endl;

	cout << "+ There are 3 numbers to the code.\n\n";
	cout << "+ The codes added together equal: " << CodeSum;
	cout << "\n+ The code multiplied together gives: " << CodeProduct;

	cout << "\nPlease enter the codes...\n";
	cin >> GuessA >> GuessB >> GuessC;

	cout << "You entered: " << GuessA << GuessB << GuessC << endl;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	if ((GuessSum == CodeSum) & (GuessProduct == CodeProduct)) {

		cout << "Well Done!\n";
		return true;
	}
	else {
		cout << "Mission Failed! The astroid has entered the atmosphere!\n";
		return false;
	}
}


int main()
{
	srand(time(NULL));
	int LevelDifficulty = 1;
	const int MaxLevelDifficulty = 5;

	while (LevelDifficulty <= MaxLevelDifficulty)
	{
		bool isLevelCompleted = Game(LevelDifficulty);
		cin.clear();
		cin.ignore();

		if (isLevelCompleted)
		{
			LevelDifficulty++;
		}
	}

	cout << "\n\n\n *******Good Job Agent! You saved the planet!!*******\n\n ";
	return 0;
}