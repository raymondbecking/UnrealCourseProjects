//Preprocessor Directive
#include <iostream>
#include <ctime>

void IntroductionText(int Difficulty)
{
    //Print Welcome message to the terminal (Expression Statements)
    std::cout << std::endl << "\nYou are Major, a \"synthetic full-body prosthesis augmented-cybernetic human\" employed as the field commander of Public Security Section 9, a anti-cybercrime law-enforcement division. \n";
    std::cout << "Your task is to solve cybercrimes. You will often need to use your hacking skills to find these cybercriminals.\n\n"; 
    std::cout << "The next Cybercriminal has a Wanted Level " << Difficulty << " Bounty placed on his head.\n";

}

bool PlayGame(int Difficulty)
{
    IntroductionText(Difficulty);

    //Declare 3 number code (Declaration Statements)
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print sum and product to the terminal (Expression Statements)
    std::cout <<std::endl;
    std::cout << "- There are 3 numbers in the code \n";
    std::cout << "- The codes add up to: " << CodeSum;
    std::cout << "\n- The codes multiply to: " << CodeProduct;

    int GuessA, GuessB, GuessC;

    std::cout << "\n\nPlease enter your guess:";
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    
    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct){
        std::cout << "\nThe code is correct and you have succesfully hacked the wanted level " << Difficulty << " Cybercriminal";
        return true;
    }
    else
    {
        std::cout << "\nThe code is incorrect!!! Hack FAILED, Please Try Again";
        return false;
    }
}

//Main Function
int main()
{
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    
    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if(bLevelComplete){
            LevelDifficulty++;
        }
    }
   
    std::cout << "\n\nYOU HAVE HACKED ALL CYBERCRIMINALS!\n";
    

    return 0;
}
