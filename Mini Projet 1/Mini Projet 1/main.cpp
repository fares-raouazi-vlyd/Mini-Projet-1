#include <iostream>
#include <cstdlib>
#include <time.h>
int GenerateRandomNumber(int min, int max)
{
	srand(time(NULL));

	int random = rand() % (max+1);
	return random;
}
int GetPlayerGuess()
{
	int guess;
	std::cout << "Saisir un nombre entre 1 et 100 : " << std::endl;
	std::cin >> guess;
	return guess;
}
int CheckGuess(int guess, int mysteryNumber)
{
	if (guess < mysteryNumber)
	{
		return -1;
	}
	if(guess > mysteryNumber)
	{
		return 1;
	}
	if (guess == mysteryNumber)
	{
		return 0;
	}
}
int ChooseDifficulty()
{
	int difficulty;
	std::cout << "Niveaux proposes" << std::endl;
	std::cout << "1 : facile = 8 tentatives" << std::endl; 
	std::cout << "2 : moyen = 5 tentatives" << std::endl; 
	std::cout << "3 : difficile = 3 tentatives" << std::endl;
	std::cin >> difficulty;
	switch (difficulty)
	{
	case 1:
		return 8;
		break;
	case 2:
		return 5;
		break;
	case 3:
		return 3;
		break;
	default:
		std::cout << "Valeur inconnue" << std::endl;
		return ChooseDifficulty();
		break;
	}
}
int CalculateScore(int attemptsLeft, int difficulty)
{
	int score = 0;
	switch (difficulty)
	{
	case 8:
		score = attemptsLeft * 30;
		return score;
		break;
	case 5:
		score = attemptsLeft * 20;
		return score;
		break;
	case 3:
		score = attemptsLeft * 10;
		return score;
		break;
	default:
		std::cout << "Error !" << std::endl;
		return score;
		break;
	}
}
int AskToPLayAgain()
{
	int replay;
	std::cout << "Voulez-vous rejouer ? (1 : Oui, 0 : Non) : " << std::endl;
	std::cin >> replay;
	return replay;
}
int PlayGame()
{
	int tentative = ChooseDifficulty();
	std::cout << "Nombre de tentatives : " << tentative << std::endl;
	int random = GenerateRandomNumber(0,100);
	for (int i = tentative; i > 0; i--)
	{
		switch (CheckGuess(random, GetPlayerGuess()))
		{
		case -1:
			std::cout << "Trop Haut !" << std::endl;
			break;
		case 1:
			std::cout << "Trop Bas !" << std::endl;
			break;
		case 0:
			std::cout << "Bravo, vous avez trouve le nombre mystere !" << std::endl;
			return CalculateScore(i, tentative);
			break;
		default:
			std::cout << "Erreur !" << std::endl;
			break;
		}
	}
}
int main ()
{
	std::cout << "Votre score est de : " << PlayGame() << std::endl;
	switch (AskToPLayAgain())
	{
	case 1:
		main();
		break;
	case 0:
		std::cout << "Merci d'avoir jouer !" << std::endl;
		break;
	default:
		std::cout << "Valeur invalide" << std::endl;
		break;
	}
	return 0;
}