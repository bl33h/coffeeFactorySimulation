# coffeeFactorySimulation
This code simulates a coffee factory using pthreads for parallel processing. It models the production and storage of coffee. The program utilizes multiple threads for toasters and a baler. The toasters generate toasted coffee pounds, while the baler creates coffee bags and stores them in the storage. The simulation runs until specific conditions are met, such as reaching a certain number of coffee pounds or a specific count for the coffee produced by the toasters. Mutex locks are implemented to ensure thread safety when accessing and modifying the coffee control structure.

<p align="center">
  <br>
  <img src="https://cdn.dribbble.com/users/743767/screenshots/2876058/coffee_press_14e.gi" alt="pic" width="500">
  <br>
</p>
<p align="center" >
  <a href="#Files">Files</a> •
  <a href="#Features">Features</a> •
  <a href="#how-to-use">How To Use</a> 
</p>

## Files

- src: the file that implements de solution.
- flowchart: flowchart: the model construction.

## Features
The main features of the application include:
- Multithreading: The code uses pthreads to create and manage multiple threads concurrently, allowing for parallel execution of tasks.
- Mutex Locks: Mutex locks are implemented using the `pthread_mutex_t` structure to provide mutual exclusion and ensure thread safety when accessing shared resources, such as the coffee control structure.
- Structured Data: The code defines a `coffeeControl` structure to encapsulate and organize data related to coffee production and storage.
- Condition-based Loops: The code utilizes while loops with specific conditions to control the execution flow and simulate the coffee production process until certain criteria are met.
- Input/Output: The code utilizes standard input/output operations to display information about the coffee production, toasters, and storage quantities during the simulation.
- Time Delay: The `sleep` function is used to introduce a delay of one second between certain operations, simulating the passage of time or allowing for synchronization between threads.
- Error Handling: The code includes error handling mechanisms, such as checking the return values of pthread functions and handling potential errors related to mutex operations.
- File Inclusion: The code includes several header files, such as `<stdlib.h>`, `<stdio.h>`, and `<pthread.h>`, to provide necessary function declarations and definitions for the program's functionality.


## How To Use
To clone and run this application, you'll need [Git](https://git-scm.com) and a [C++ compiler](https://www.fdi.ucm.es/profesor/luis/fp/devtools/mingw.html) installed on your computer. From your command line:

```bash
# Clone this repository
$ git clone https://github.com/bl33h/coffeeFactorySimulation

# Open the folder
$ cd src

# Run the app
$ g++ coffeeFactorySimulation.cpp -o coffeeFactorySimulation
$ ./posixThreads
```

Alternatively, you can run the code using Google Colab:
1. [Open Google Colab](https://colab.research.google.com) in your web browser.
2. Click on "File" in the top menu, then select "Open notebook".
3. In the "GitHub" tab, enter the repository URL: https://github.com/bl33h/coffeeFactorySimulation
4. Choose the desired notebook file and click "Open".
5. Follow the instructions within the Colab notebook to execute the code.

Note: Running the code in Google Colab requires an internet connection and a Google account. It provides a convenient online environment for executing code without the need for local setup or dependencies.
