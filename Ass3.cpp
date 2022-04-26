//Assume that, There are N Person and each person needs exactly one cab. 
//For each person you are given the start time and end time (both inclusive) during which that person will travel. 
//Find the Minimum number of cans required. Which Strategy will be best suitable to solve this problem.
#include<iostream>
#include<algorithm>
#include<array>
#include<chrono>

using namespace std;

int minimum_cabs(int**, int);
bool compare(int *, int *);

int main(void) {
  int n;
  cout << "Enter number of passengers: ";
  cin >> n;
  int** passengers = new int*[n];
  for (auto i = 0; i < n; i++) {
    cout << "Enter start and finish time of passenger" << i + 1 << ": ";
    passengers[i] = new int[2];
    cin >> passengers[i][0];
    cin >> passengers[i][1];
  }
  auto start = chrono::high_resolution_clock::now();
  int min_cabs = minimum_cabs(passengers, n);
  auto end = chrono::high_resolution_clock::now();

  auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
  cout << "Minimum Cabs required by start time: " << min_cabs << endl;
  cout << "Time taken by algorithm: " << duration << "ns." << endl;
}

bool compare(int *a, int *b) {
  if (a[1] == b[1]) return a[0] < b[0];
  return a[1] < b[1];
}

int minimum_cabs(int** arr, int n) {
  sort(arr, arr + n, compare);
  int min_ft_cab = 0; int count = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i][0] >= arr[min_ft_cab][1]) {
      min_ft_cab++;
    } else {
      count++;
    }
  }
  return count;
}