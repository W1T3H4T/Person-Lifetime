#include <iostream>
#include <string>
#include <random>

/*
 *  Copyright (c) 2024 David C. Means
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *  
 **/

class Person {
private:
    bool _alive;
    long long _timeOfBirth;  // Unix epoch value
    long long _yearsOfLife;

    //  All the stuff we should be doing
    void Eat() {
        std::cout << "Eating..." << std::endl;;
    }

    void TBBT() {
        std::cout << "Watching The Big Bang Theory..." << std::endl;;
    }

    void Drink() {
        std::cout << "Drinking..." << std::endl;;
    }

    void Bathroom() {
        std::cout << "Using the bathroom..." << std::endl;;
    }

    void StarTrek() {
        std::cout << "Watching Star Trek..." << std::endl;;
    }

    void StarWars() {
        std::cout << "Watching Star Wars..." << std::endl;;
    }

    void StarWars_All_Others() {
        std::cout << "Watching all other Star Wars movies/shows..." << std::endl;;
    }

    void StarTrek_All_Others() {
        std::cout << "Watching all other Star Trek series..." << std::endl;;
    }

    void Work() { 
        
        if ( _yearsOfLife > 15 ) { 
            if ( 23 > _yearsOfLife ) 
                std::cout << "Ugh.  I'm at work again." << std::endl;
            else
                std::cout << "Ugh.  All work and no play make Jack a dull boy." << std::endl;
        }
        else 
            std::cout << "Play time!" << std::endl;
    }

    void Sleep() { 
        std::cout << "I like to sleep..." << std::endl;
    }

    bool Still_Alive() {
        unsigned tries = 0;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 4200);

        _yearsOfLife++;
        while (_alive && tries++ < 42 ) {
            int random_number = dis(gen);
            if (random_number == 42 || ( random_number > 420 && _yearsOfLife > 83  ) ) { 
                _alive = false;
                std::cout << "It's time to go. I was " << _yearsOfLife << " years old." << std::endl;
            }
        }
        if ( _alive ) 
            std::cout << "I'm still alive after " << _yearsOfLife << " years!" << std::endl << std::endl;

        return _alive;
    }

public:
    // Constructor
    Person(long long timeOfBirth) : _alive(true), _timeOfBirth(timeOfBirth), _yearsOfLife(0) {
        std::cout << "Birthday Epoch: " << _timeOfBirth << std::endl;
    }

    // Public method
    void Alive() {
        while ( Still_Alive() ) {
            Eat();
            Drink();
            Bathroom();
            StarTrek();
            StarWars();
            StarWars_All_Others();
            StarTrek_All_Others();
            TBBT();
            Work();
            Sleep();
        }
    }
};

int main() {
    // Example usage
    Person person(1615478400);  // Unix epoch value for a specific date
    person.Alive();  // Perform actions while alive

    return 0;
}

