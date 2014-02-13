/*
creating a seperate cpp file for every training video in 
the 3dBuzz's "Software Engineering in C++" series
(http://www.3dbuzz.com/training/view/software-engineering-in-cpp/software-engineering)

Will define all the functions within the the cpp files here so main.cpp
can execute the code
*/

void dataType(); // -> dataTypes.cpp
void decisionMaking(); // decisionMaking.cpp
void inputInt(); // --> getInput.cpp
void loops(); // -> loops.cpp
void arrays(); // --> arrays.cpp 
int functions(); // --> functions.cpp  ** functions.cpp includes "simple_math.h" BUT i don't have to declare it here to use it**
void pointers(); // --> pointers.cpp
void dynamic_memory(); // --> void dynamic_memory.cpp
void cStyleString(); // c_style_string.cpp
void userDataTypes(); // userDataTypes.cppxxzz swss
void linkedList(); // linkedLists.cpp
void ll_main(); // linkedLists.cpp
void introOOP(); // introOO.cpp
void main_linkedListOOP(); // linkedListOOP
void stack_main(); // stack_main.cpp
void multipleInheritance_abstract_interfaces(); // multipleInheritance_abstract_interface.cpp
int factorial (int n); // algs_intro.cpp
int find(int *arr, int start, int end, int item); // binary_search.cpp
void SolveTowerOfHanoi(int count, char source, char destination, char spare); //TowersOfHanoi.cpp
void bubbleSort(int *arr, int arr_len); // algs_sorts.cpp
void selectionSort(int *arr, int arr_len); // algs_sorts.cpp
void insertionSort(int *arr, int arr_len); // algs_sorts.cpp
void mergeSort(int *arr, int start, int end); // algs_sorts.cpp
void quickSort(int *arr, int start, int end); //algs_sorts.cpp
void introSimpleGraphs(); // graphs.cpp
void betterGraph(); // betterGraph.cpp
void tree__main(); // tree.cpp