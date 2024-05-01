
#include <iostream>
#include <random>
#include <iomanip> // Pentru setarea precisiei afisarii
#include <vector>
#include <string>



template <typename T, size_t N>
size_t CE_GET_LAST_INDEX_(const T(&array)[N]) {
	return N > 0 ? N - 1 : 0; // Returneaza ultimul index al array-ului sau 0 daca array-ul este gol
}

//		Temperaturile Orașului
//	Scop: Scrie un program care stochează temperaturile medii
//	pentru fiecare zi a săptămânii pentru un oraș și apoi calculează
//	temperatura medie săptămânală.
//
//		Specificații:
//	Creează un array care să conțină temperaturile medii zilnice(poți folosi valori întregi
//	sau cu virgulă).
//	Calculează media temperaturilor pentru săptămână.
//	Afișează temperatura medie săptămânală, rotunjită la două zecimale.
//	Exemplu de Output :
//	Temperatura medie săptămânală este : 23.45 grade Celsius.


void TEMA_01_()
{
	// Declaram un array pentru a stoca temperaturile medii zilnice
	float fArrTemp_[7];

	// Citirea temperaturilor pentru fiecare zi a saptamanii
	for (int i = 0; i < 7; ++i) {
		std::cout << "Introduceti temperatura medie pentru ziua " << i + 1 << ": ";
		std::cin >> fArrTemp_[i];
	}

	// Calcularea temperaturii medii saptamanale
	float fTempSaptamanal_ = 0;
	for (int i = 0; i < 7; ++i) {
		fTempSaptamanal_ += fArrTemp_[i];
	}
	fTempSaptamanal_ /= 7;

	// Afisarea temperaturii medii saptamanale cu precizia de doua zecimale
	std::cout << "Temperatura medie saptamanala este: " << std::fixed << std::setprecision(2) << fTempSaptamanal_ << " grade Celsius." << std::endl;

}

// Screti un program ce sa printeze numai primul, al cinelea si ultimul element dintr-un array de 50 de casute
void TEMA_02_()
{
	const int intMaxArrayIndex_ = 50;
	int intGeneratedArray[intMaxArrayIndex_];

	for (int i = 0; i < intMaxArrayIndex_; i++) {

		std::random_device rd;
		std::uniform_int_distribution<int> distribution(0, 100);
		unsigned short intAIChoice = distribution(rd);

		intGeneratedArray[i] = intAIChoice;
	}

	std::cout << "Index-ul 0 este " << intGeneratedArray[0] << std::endl;
	std::cout << "Index-ul 5 este " << intGeneratedArray[5] << std::endl;
	std::cout << "Ultimul index este " << intGeneratedArray[intMaxArrayIndex_ - 1] << std::endl;

}

int CE_RANDOM_INT_(int localMin, int localMax)
{
	std::random_device rd;
	std::uniform_int_distribution<int> distribution(localMin, localMax);
	unsigned short intAIChoice = distribution(rd);
	return intAIChoice;
}

void CE_PRINT_MAP_(int arrMap[5][5])
{
	int userChoiceX = 0;
	int userChoiceY = 0;
	int savedMap_[5][5];

	do {

		std::cout << "	X: ";
		std::cin >> userChoiceX;

		std::cout << "	Y: ";
		std::cin >> userChoiceY;

		// Vreau sa setez ca numerele de la user sa fie de la 1 la 5 
		--userChoiceX;
		--userChoiceY;

		system("cls");

		std::cout << "	You need to find the treasure !" << std::endl
			<< "	You have coordinates from 1 to 5 !" << std::endl
			<< std::endl;

		for (int i = 0; i < 5; i++) {

			for (int j = 0; j < 5; j++) {

				if (i == userChoiceX && j == userChoiceY) {

					if (arrMap[userChoiceX][userChoiceY] == 1) {
						std::cout << " O ";
					}
					else {
						std::cout << " 0 ";
						savedMap_[i][j] = 0;
					}
				}
				else {
					
					if (savedMap_[i][j] != 0) {
						std::cout << " X ";
					}
					else {
						std::cout << " 0 ";
					}
					
				}
			}
			std::cout << std::endl;
		}

		if (arrMap[userChoiceX][userChoiceY] != 1) {
			std::cout << std::endl;
			std::cout << "Try Again !" << std::endl; 
			std::cout << std::endl;
		}
		else {
			std::cout << std::endl;
			std::cout << "You did it, the treasure was on X " << userChoiceX + 1 << " and Y " << userChoiceY + 1 << std::endl;
			std::cout << std::endl;
		}

	} while (arrMap[userChoiceX][userChoiceY] != 1);
}

void TEMA_03_()
{	
	int userChoiceX = 0;
	int userChoiceY = 0;

	int arrMap[5][5] =
	{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
	};

	std::cout << "	You need to find the treasure !" << std::endl 
			  << "	You have coordinates from 1 to 5 !" << std::endl
			  << std::endl;

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {
			std::cout << " X ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	arrMap[CE_RANDOM_INT_(0, 4)][CE_RANDOM_INT_(0, 4)] = 1;

	CE_PRINT_MAP_(arrMap);

}
		

int main()
{

	//TEMA_01_();
	//TEMA_02_();
	TEMA_03_();


	/*	

	int intCalificative[10] = {10,5,8,5,3,8,5,10,2,3};
	int size = sizeof(intCalificative) / sizeof(intCalificative[0]) - 1;

	std::cout << "Primult index este " << intCalificative[0] << std::endl;
	std::cout << "Ultima index este " << intCalificative[9] << std::endl;
	std::cout << "Last index " << CE_GET_LAST_INDEX_(intCalificative) << std::endl;

	for (int i = 0; i < 10; i++)
	{
	
		int suma_note = 0;
		suma_note += intCalificative[i];
		std::cout << "Calificative la indexul " << i << " este " << intCalificative[i];

	}*/


	/*  
	int arrX[2][3][2] = {
		{{1,2},{3,4},{5,6}},
		{{10,20},{30,40},{50,60}}
	};
	//std::cout << arrX[1][2][1] << std::endl;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				std::cout << "La indexul " << i << " " << j << " " << k << " avem val: " << arrX[i][j][k] << std::endl;
			}
		}
	}*/


	/*
	//sintaxa std::vector<tip_data> nume_vector;
	std::vector<std::string> lista_cumparaturi = { "Paine", "Mere" };

	//lista_cumparaturi.push_back("Paine");
	//lista_cumparaturi.push_back("Mere");

	for (int i = 0; i < lista_cumparaturi.size(); i++)
	{
		//std::cout << lista_cumparaturi[i] << std::endl;

		// .at(index) acelasi lucru ca [index] doar ca vrifica ca indexul sa nu fie out of bounds
		std::cout << lista_cumparaturi.at(i) << std::endl;
	}

	lista_cumparaturi.at(0).erase();
	std::cout << lista_cumparaturi.at(0) << std::endl;

	lista_cumparaturi.push_back("Lapte");
	lista_cumparaturi.pop_back(); // Sterge ultimul index introdus in vector


	//std::string este similar cu std::vector<char>
	std::string test = "Cuvant";
	for (int i = 0; i < test.size(); i++)
	{
		std::cout << test[i] << std::endl;
	}
	lista_cumparaturi.clear();
		*/
}