#include "Utils.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

	int length;
    int show = 0;
    int input;

    /* Ввод данных */
	cout << "Введите кол-во элементов сортируемого массива: ";
	cin >> length;
	float* arr = new float[length]; //Исходный массив
 	float* tempArr = new float[length]; //Массив для обработки
    cout << "Выберите один из вариантов:\n";
    cout << "1 - Ввести свои значения в массив;\n";
    cout << "2 - Ввести последовательные значения;\n";
    cout << "3 - Ввести рандомные значения;\n";
    cout << "4 - Ввести значения в обратном порядке;\n";
    cin >> input;
    switch(input) {
        case 1:{
            cout << "Введите элементы массива: \n";
            for (int i = 0; i < length; i++)
            {
                cout << "Элемент [" << i+1 << "] - ";
                cin >> arr[i];
            }
            break;
        }
        case 2:{
            for (int i = 0; i < length; i++)
            {
                arr[i] = i+1;
                cout << "Элемент [" << i+1 << "] - " << arr[i] << "\n";
            }
            break;
        }
        case 3:{
            for (int i = 0; i < length; i++) {
                arr[i] = rand() % 100;
                cout << "Элемент [" << i+1 << "] - " << arr[i] << "\n";
            }
            break;
        }
        case 4:{
            for (int i = 0; i < length; i++)
            {
                arr[i] = length-i;
                cout << "Элемент [" << i+1 << "] - " << arr[i] << "\n";
            }
            break;
        }
    }
    cout << "Введите 1, если нужно выводить отсортированные массивы, иначе введите другое значение.\n";
    cin >> show;
	copy_arr(arr, tempArr, length);

    /* Подсчёт и вывод времени для сортировки вставками */
    //showArr(tempArr,length);
	auto start = chrono::high_resolution_clock::now();
	insertionSort(tempArr, length);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	cout << "Время InsertionSort: " << duration.count() << " мс\n";
    if(show == 1)
        showArr(tempArr,length);
    copy_arr(arr, tempArr, length);

    /* Подсчёт и вывод времени для сортировки выбором */
    //showArr(tempArr,length);
	start = chrono::high_resolution_clock::now();
	selectionSort(tempArr, length);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Время SelectionSort: " << duration.count() << " мс\n";
    if(show == 1)
        showArr(tempArr,length);
	copy_arr(arr, tempArr, length);


    /* Подсчёт и вывод времени для сортировки пузырьком */
    //showArr(tempArr,length);
	start = chrono::high_resolution_clock::now();
	bubbleSort(tempArr, length);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Время BubbleSort: " << duration.count() << " мс\n";
    if(show == 1)
        showArr(tempArr,length);
	copy_arr(arr, tempArr, length);

    /* Подсчёт и вывод времени для сортировки слиянием */
    //showArr(tempArr,length);
	start = chrono::high_resolution_clock::now();
	mergeSort(tempArr, 0, length-1);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Время MergeSort: " << duration.count() << " мс\n";
    if(show == 1)
        showArr(tempArr,length);
	copy_arr(arr, tempArr, length);

    /* Подсчёт и вывод времени для сортировки Шелла */
    //showArr(tempArr,length);
	start = chrono::high_resolution_clock::now();
	shellSort(tempArr, length);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Время ShellSort: " << duration.count() << " мс\n";
    if(show == 1)
        showArr(tempArr,length);
	copy_arr(arr, tempArr, length);

    /* Подсчёт и вывод времени для быстрой сортировки */
    //showArr(tempArr,length);
	start = chrono::high_resolution_clock::now();
	quickSort(tempArr, 0, length - 1);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "Время QuickSort: " << duration.count() << " мс\n";
    if(show == 1)
        showArr(tempArr,length);
	copy_arr(arr, tempArr, length);

    system("pause");
    return 0;
}

void showArr(float* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
