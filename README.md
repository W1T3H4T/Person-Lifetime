# Person Class

The `Person` class in C++ represents an individual with basic actions and a random "Time_To_Go" feature. This class simulates a person's life by performing various activities until a random event triggers the end of their life.

## Features

- **Birthday Celebration:** The class displays the epoch time of the person's birthday when instantiated.

- **Actions:**
  - Eating
  - Drinking
  - Using the bathroom
  - Watching Star Trek
  - Watching Star Wars
  - Watching all other Star Wars movies/shows
  - Watching all other Star Trek series
  - Watching The Big Bang Theory
  - Working (conditional based on age)
  - Sleeping

- **Age Simulation:** The class simulates the person's age, and certain activities are influenced by their age.

- **Random Life Event:** A random event, triggered by a predefined condition, can lead to the person's demise.

## Usage

1. **Instantiate a Person:**

   ```cpp
 
   int main() {
       // Example: Create a person with a specific time of birth (Unix epoch value)
       Person person(1615478400);
       return 0;
   }
   ```

2. **Perform Actions:**

   The `Alive` method allows the person to perform various actions until it's time to go.

   ```cpp
   // Perform actions while alive
   person.Alive();
   ```

## Example

```cpp
#include "Person.h"

int main() {
    // Create a person with a specific time of birth (Unix epoch value)
    Person person(1615478400);

    // Perform actions while alive
    person.Alive();
    
    return 0;
}
```

## Note

This is a basic life simulation program and may need further customization based on specific requirements. The random event triggering the end of life adds an element of unpredictability. Feel free to explore and modify the `Person` class to suit your needs! 
