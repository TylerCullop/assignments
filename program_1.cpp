/**
*  Program-1
*  Tyler Cullop
*
*  This program reads in images stored as rgb values in a space delimited file format.
*  1063 Data Structures
*  Spring 2017
*  08 02 2018
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

/**
Structure to hold an rgb value
*/
struct rgb {
	int r;
	int g;
	int b;
};

void grayScale(rgb** image, int width, int height) {
	int r, g, b, gray;
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			r = image[i][j].r;
			g = image[i][j].g;
			b = image[i][j].b;

			gray = (r + g + b) / 3;

			image[i][j].r = gray;
			image[i][j].g = gray;
			image[i][j].b = gray;
		}
	}
}

void removeRed(rgb** image, int width, int height) {

	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			image[i][j].r = 0;
		}
	}
}

void makeBlackLine(rgb** image, int width, int height, int line) {


	for (int j = 0; j<width; j++) {
		image[line][j].r = 0;
		image[line][j].g = 0;
		image[line][j].b = 0;
	}
}

void flipHorz(rgb** image, int width, int height) {
	int x = 0;
	int y = 0;
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width / 2; j++) {
			int image = image[x][y]
				image[x][y] = image[width - 1 - y][x]
				image[width - 1 - y][x]
		}
	}
}

voidflipVert(rgb** image, int width, int height) {
	int x = 0;
	int y = 0;
	for (int i = 0; i <= height / 2; i++) {
		for (int j = 0; j<width; j++) {
			int image = image[x][y]
				image[x][y] = image[height - 1 - x][y]
				image[height - 1 - x][y]

		}
	}
}


int main() {
	ifstream ifile;          //Input / output files
	ofstream ofile;
	ifile.open("bot.txt");
	ofile.open("bot2.txt");
	int r, g, b, gray;

	int width;               //width of image
	int height;              //height of image

	rgb **imgArray;         //Pointer var for our 2D array because we         
							//don't know how big the image will be!

	ifile >> width >> height;   //Read in width and height from top of input file
								//We need this so we can make the array the right 
								//size. After we get these two values, we can
								//now allocate memory for our 2D array.

	imgArray = new rgb*[height];    //This array points to every row

	for (int i = 0; i<height; i++) {
		imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
	}

	//Read the color data in from our txt file
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			ifile >> imgArray[i][j].r >> imgArray[i][j].g >> imgArray[i][j].b;
		}
	}

	//We could make any changes we want to the color image here
	removeRed(imgArray, width, height);

	makeBlackLine(imgArray, width, height, 50);

	flipHorz(imgArray, width, height);

	ofile << width << " " << height << endl;

	for (int i = 0; i<height; i++) {
		int x = 0;
		int y = 0;
		for (int j = 0; j<width / 2; j++) {
			int image = image[x][y]
				image[x][y] = image[width - 1 - y][x]
				image[width - 1 - y][x]
		}

		ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " " << imgArray[i][j].b << " ";

		ofile << endl;
	}


	flipVert(imgArray, width, height);
	int x = 0;
	int y = 0;
	for (int i = 0; i <= height / 2; i++) {
		for (int j = 0; j<width; j++) {
			int image = image[x][y]
				image[x][y] = image[height - 1 - x][y]
				image[height - 1 - x][y]
		}
		ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " " << imgArray[i][j].b << " ";

		ofile << endl;
	}


	//Write out our color data to a new file
	ofile << width << " " << height << endl;
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " " << imgArray[i][j].b << " ";
		}
		ofile << endl;
	}


	return 0;
}