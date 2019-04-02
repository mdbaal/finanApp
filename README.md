# FinanApp 1
Financial management Console application

### Description
FinanApp is a financial management application.
You can very easily keep track of your income and expenses for various things.
for example:
1. Your bank savings
2. A period of time, i.e. months, weeks, etc
3. Savings for a vacation
4. Your clubs treasury

This is the first of 3 application I have planned and it's a console application.

---

### How to install/download/build

#### Getting the exe
1. Go to my website https://mircogames.nl/
2. There scroll to projects and download the zip file containing the .exe

#### Using cmake - Visual Studio
1. Clone/download the repository
2. Create a 'build' directory
3. Go into the build directory and open the console
4. Enter 'cmake..' and wait for the project to be made
5. Open the visual studio project and build it
6. Copy the summaries folder into the folder with the .exe
7. Put the folder with the .exe somewhere on your pc and it's ready for use

---
### How to use Example
All lines starting with * are commands.

```
*new january
created summary january

*add food -50
added food 50 to summary january

*add work 40
added work 40 to summary january

*view
viewing january
food: -50
work: 40
########
total: -10

*remove food
removed food -50 from summary january

*view
viewing january
work: 40
########
total: 40

```

---

### List of all commands
* new <name> - create a new summary
* delete <name> - delete a summary
* list - shows all summaries created
* load <name> - load a summary
* save - saves the current summary
* copy <name> - copies the given summary and loads the copy
* rename <name1> <name2> - renames the summary to the new name
* view - print the current summary on screen
* add <name> <value> - add a new entry to the current summary
* remove <name> - remove an entry from the current summary
* help - shows a list of all commands
* clear - clears the screen
* exit / quit - exits the program
  
