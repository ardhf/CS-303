#ifndef ASSIGNMENT1_H_
#define ASSIGNMENT1_H_

class Assignment1 {
   private:
    static const int MAX_ARRAY_SIZE = 150;  // Max number of elements allowed inside the array
    int nums[MAX_ARRAY_SIZE];               // Array with a max of 150 elements
    int arrIndex = 0;                       // Keeps track of the number of elements currently in the array

   public:
       // Reads the file into an array
    void loadFile();

    /*
        Find the first instance of a given number.
        @param number  The number to search for in the array.
    */
    void findNumber(int numToSearch);

    /*
        Replace the integer at a given index with another given integer.
        @param index  Index of the number to replace.
        @param num    Number to replace with.
    */
    void replaceNumber(int index, int num);

    /*
        Adds an integer to the end of the array if there is space available.
        @param num  Number to add to the end of the array.
    */
    void addNumber(int);

    //  Prints the array to the user.
    void printArray();

    /*
        Removes an element from an array when given the index.
        @param index  Index of the element to remove.
    */
    void removeNumber(int index);
};

#endif