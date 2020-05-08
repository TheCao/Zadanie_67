//Na dole tego zbioru zadań znajduje się tabelka z danymi(Dane67).Skopiuj te dane
//do pliku tekstowego(rozszerzenie.txt) i umieść go w katalogu z Twoim projektem,
//aby można było otwierać ten plik do odczytu.Odpowiedz na następujące pytania :
//-Jaka jest średnia liczb w pierwszej i ostatniej kolumnie ?
//-Które kolumny(numer) posiadają największą liczbę ?
//-Ile jest wierszy, w których nie występuje liczba podzielna przez 10 ?
//-Ile jest wierszy, w których pierwsze trzy liczby zachowują niemalejący porządek ?
//-Ile jest wierszy, w których są dokładnie 3 liczby z zakresu < 85; 100 >

#include <iostream>
#include "File.h"


int main()
{
    File File("dane.txt");

    //avg from first col
    std::cout << "Średnia w pierwszej kolumnie to: " << File.getAvgOnCol(1) << std::endl;

    // cols with max number 
    auto maxNumberPair = (File.whichColsHaveMaxNumber());
    std::cout << "kolumny z największa liczbą " << maxNumberPair.first << " to: ";
    
    std::for_each(maxNumberPair.second.cbegin(), maxNumberPair.second.cend(),
        [](int elem) {std::cout << elem << " "; });
    std::cout << std::endl;
    // cols with number not divisible for 10
    std::cout << "Ilość kolumn z liczbą niepodzielną przez 10 : " << File.countRowsWithOneNumberNotDivisibleByTen()
        << std::endl;

    //cols with not decreasing values
    std::cout << "Ilość kolumn z niemalejącymi 3 liczbami :" << File.countRowsWithFirstThreeNumbsAreNotDecreasing() 
        << std::endl;

    std::cout << "Ilość kolumn z 3 liczbami w zakresie 85-100: " << File.countRowsWithNumbsInRange(3, 85, 100) 
        << std::endl;


    return 0;
}

