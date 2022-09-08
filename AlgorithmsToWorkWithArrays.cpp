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

    cout << "Введите 10 чисел для заполнения массива: " << endl;

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

    cout << endl << "Введите ключ: ";

    cin >> value;
    foundIndex = findElementIndexByValueInArrayWithBinarySearch(value, targetArray);

    if (foundIndex > -1)
    {
        cout << "Индекс элемента " << value << " в массиве равен: " << foundIndex << endl;
    }
    else
    {
        cout << "Извините, но такого элемента в массиве нет";
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
    int sortStartIndex = 0;
    int sortEndIndex = sizeOfArray - 1;

    int middleElement = arrayToSort[sizeOfArray / 2];

    do {
        while (arrayToSort[sortStartIndex] < middleElement) {
            sortStartIndex++;
        }

        while (arrayToSort[sortEndIndex] > middleElement) {
            sortEndIndex--;
        }

        if (sortStartIndex <= sortEndIndex) {
            int temporarySortStartElement = arrayToSort[sortStartIndex];
            arrayToSort[sortStartIndex] = arrayToSort[sortEndIndex];
            arrayToSort[sortEndIndex] = temporarySortStartElement;

            sortStartIndex++;
            sortEndIndex--;
        }
    } while (sortStartIndex <= sortEndIndex);

    if (sortEndIndex > 0) {
        sortArrayWithQsort(arrayToSort, sortEndIndex + 1);
    }
    if (sortStartIndex < sizeOfArray) {
        sortArrayWithQsort(&arrayToSort[sortStartIndex], sizeOfArray - sortStartIndex);
    }
}