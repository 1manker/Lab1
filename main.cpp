//Lucas Manker
//CS 2030
//Lab01

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	//making sure 2 arguments were passed when launching the program
	if (argc != 2) {
		cout << "need filename."<<endl;
		return 1;
	}
	//assuming the argument passed was the filename and opening it
	else {
		ifstream ifile(argv[1]);
		//making sure file is actually open
		if (!ifile.is_open()) {
			cout << "could not find file";
			return 1;
		}
		else {
			//declaring variables, x will store the numbers the stream reads, y and z will hold the last two numbers read, the next 4 variables store the first 2 numbers and last 2.
			double x(0), y(0), z(0), fOne,fTwo,lOne,lTwo;
			int count=0;

			//looping as long as there are doubles to read.
			while(ifile>>x){
				count++;
				//alternating which variable holds the current number being read so that we can look back and get the first two numbers and last two numbers.
				if ((count % 2) == 0) {
					z = x;
				}
				else {
					y = x;
				}
				//if two numbers have been read then store those numbers in the first and second variables.
				if (count == 2) {
					fOne = y;
					fTwo = z;
				}
			}
			//determining how far the count got so it can be determined which variable currently stores the last number, and which one stores the second to last.
			if ((count % 2)==0) {
				lTwo = z;
				lOne = y;
			}
			else {
				lTwo = y;
				lOne = z;
			}
			cout << endl << "+++++++++++++++++++++++FILE INFO+++++++++++++++++++++++" << endl;
			cout << endl << "There are " << count << " numbers in this file." << endl;
			cout << "=======================================================" << endl;
			cout << "First Number:" << fOne << endl;
			cout << "=======================================================" << endl;
			cout << "Second Number:" << fTwo << endl;
			cout << "=======================================================" << endl;
			cout << "Second to Last Number:" << lOne << endl;
			cout << "=======================================================" << endl;
			cout << "Last Number:" << lTwo << endl;
			cout << "=======================================================" << endl;
			
		}

		ifile.close();
	}
	return 0;
}
