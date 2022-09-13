#include <iostream>
#include <algorithm>

using namespace std;

int findElementIndexByValueInArrayWithBinarySearch(int key, int* targetArray);
void sortArrayWithQsort(int* targetArray, int sizeOfArray);

int main() {
    setlocale(LC_ALL, "rus");

    int targetArray[10];
    int value;
    int foundIndex = 0;

    cout << "Enter 10 numbers to fill array: " << endl;

    for (int i = 0; i < 10; i++) {
        cin >> targetArray[i];
    }

    for (int index = 0; index < 10; index++)
    {
        cout << targetArray[index] << " ";
    }
    cout << endl;

    sortArrayWithQsort(targetArray, 10);

    for (int index = 0; index < 10; index++)
    {
        cout << targetArray[index] << " ";
    }

    cout << endl << "Enter value: ";

    cin >> value;
    foundIndex = findElementIndexByValueInArrayWithBinarySearch(value, targetArray);

    if (foundIndex > -1)
    {
        cout << "Index of element " << value << " in array is: " << foundIndex << endl;
    }
    else
    {
        cout << "Sorry, but array doesn't contains such element";
    }

    system("pause");
    return 0;
}

int findElementIndexByValueInArrayWithBinarySearch(int value, int* targetArray)
{
    bool isSearchEnded = false;
    int searchLeftBound = 0;
    int searchRightBound = 9;
    int middle = 0;
    int foundIndex = 0;

    while ((searchLeftBound <= searchRightBound) && (isSearchEnded != true))
    {
        middle = (searchLeftBound + searchRightBound) / 2;

        if (targetArray[middle] == value)
        {
            isSearchEnded = true;
            foundIndex = middle;
        }
        if (targetArray[middle] > value)
        {
            searchRightBound = middle - 1;
        }
        else
        {
            searchLeftBound = middle + 1;
        }
    }

    return foundIndex;
}

void sortArrayWithQsort(/*out parameter*/ int* arrayToSort, int sizeOfArray) {
    int sortLeftBoundIndex = 0;
    int sortRightBoundIndex = sizeOfArray - 1;

    int middleElement = arrayToSort[sizeOfArray / 2];

    do {
        while (arrayToSort[sortLeftBoundIndex] < middleElement) {
            sortLeftBoundIndex++;
        }

        while (arrayToSort[sortRightBoundIndex] > middleElement) {
            sortRightBoundIndex--;
        }

        if (sortLeftBoundIndex <= sortRightBoundIndex) {
            int currentSortLeftBoundElement = arrayToSort[sortLeftBoundIndex];
            arrayToSort[sortLeftBoundIndex] = arrayToSort[sortRightBoundIndex];
            arrayToSort[sortRightBoundIndex] = currentSortLeftBoundElement;

            sortLeftBoundIndex++;
            sortRightBoundIndex--;
        }
    } while (sortLeftBoundIndex <= sortRightBoundIndex);

    if (sortRightBoundIndex > 0) {
        sortArrayWithQsort(arrayToSort, sortRightBoundIndex + 1);
    }
    if (sortLeftBoundIndex < sizeOfArray) {
        sortArrayWithQsort(&arrayToSort[sortLeftBoundIndex], sizeOfArray - sortLeftBoundIndex);
    }
}