#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <tchar.h>
// Need OpenCV
//#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
//#include "opencv2/imgproc.hpp"
//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>

#define USERS_TXT "Data files/users.txt"
#define PROPERTY_TXT "Data files/property.txt"
#define OWNERS_TXT "Data files/owners.txt"
#define PHOTO_TXT "Data files/photos.txt"
#define VISITED_TXT "Myhome/visited.txt"
#define MESSAGE_TXT "Myhome/message.txt"

using namespace std;
//using namespace cv;

string user_name;

// Need OpenCV
// Concatenate multiple images by taking vector of images
//cv::Mat makeCanvas(std::vector<cv::Mat>& vecMat, int windowHeight, int nRows) {
//	int N = vecMat.size();
//	nRows = nRows > N ? N : nRows;
//	int edgeThickness = 10;
//	int imagesPerRow = ceil(double(N) / nRows);
//	int resizeHeight = floor(2.0 * ((floor(double(windowHeight - edgeThickness) / nRows)) / 2.0)) - edgeThickness;
//	int maxRowLength = 0;
//
//	std::vector<int> resizeWidth;
//	for (int i = 0; i < N;) {
//		int thisRowLen = 0;
//		for (int k = 0; k < imagesPerRow; k++) {
//			double aspectRatio = double(vecMat[i].cols) / vecMat[i].rows;
//			int temp = int(ceil(resizeHeight * aspectRatio));
//			resizeWidth.push_back(temp);
//			thisRowLen += temp;
//			if (++i == N) break;
//		}
//		if ((thisRowLen + edgeThickness * (imagesPerRow + 1)) > maxRowLength) {
//			maxRowLength = thisRowLen + edgeThickness * (imagesPerRow + 1);
//		}
//	}
//	int windowWidth = maxRowLength;
//	cv::Mat canvasImage(windowHeight, windowWidth, CV_8UC3, Scalar(0, 0, 0));
//
//	for (int k = 0, i = 0; i < nRows; i++) {
//		int y = i * resizeHeight + (i + 1) * edgeThickness;
//		int x_end = edgeThickness;
//		for (int j = 0; j < imagesPerRow && k < N; k++, j++) {
//			int x = x_end;
//			cv::Rect roi(x, y, resizeWidth[k], resizeHeight);
//			cv::Size s = canvasImage(roi).size();
//			cv::Mat target_ROI(s, CV_8UC3);
//			if (vecMat[k].channels() != canvasImage.channels()) {
//				if (vecMat[k].channels() == 1) {
//					cv::cvtColor(vecMat[k], target_ROI, COLOR_BGR2GRAY);
//				}
//			}
//			else {
//				vecMat[k].copyTo(target_ROI);
//			}
//			cv::resize(target_ROI, target_ROI, s);
//			if (target_ROI.type() != canvasImage.type()) {
//				target_ROI.convertTo(target_ROI, canvasImage.type());
//			}
//			target_ROI.copyTo(canvasImage(roi));
//			x_end += resizeWidth[k] + edgeThickness;
//		}
//	}
//	return canvasImage;
//}

//---------------------------------------------Class Defination--------------------------------------------
class RealEstateSys
{
protected:
	string name, password, phone, email;
public:
	virtual void login() = 0;
	virtual void menu() = 0;
};

class Admin :public RealEstateSys
{
public:
	void login();
	void menu();
	void uploadPhoto();
	void uploadBrochure();
	void addProperty();
	void addOwner();
	void viewVisited();
	void viewInterested();
};

class User :public RealEstateSys
{
public:
	void login();
	void menu();
	void userRegistration();
	void listByArea();
	void listByPrice();
	void listByPincode();
	void listByNew();
	void listByResale();
	void listByBuy();
	void listByRent();
	void listByRooms();
	void listByCityState();
	void listByType();
	void downloadBrochure();
	// void viewPhoto();
};

//-----------------------------------------------End Defination--------------------------------------------

//-----------------------------------------------Class Admin-----------------------------------------------

void Admin::login()
{
	system("CLS");

	name = "admin";
	password = "admin";

	string getName, getPassword;
	char ch;

	cout << "\n------------------------Admin Login----------------------\n" << endl;
	cout << " Enter name     : ";
	cin >> getName;
	cout << " Enter password : ";
	ch = _getch();
	while (ch != 13)
	{
		if (ch == 8)
		{
			if (getPassword.length() > 0)
			{
				getPassword.pop_back();
				cout << "\b \b";
			}
		}
		else
		{
			cout << "*";
			getPassword.push_back(ch);
		}
		ch = _getch();
	}
	cout << "\n\n--------------------------------------------------------\n";

	if (getName == name && getPassword == password)
	{
		cout << "\nLogin successful!!" << endl;
		system("pause");
		menu();
	}
	else
	{
		cout << "Invalid password or name!!\n\n";
		system("pause");
		login();
	}
}

void Admin::addProperty()
{
	system("CLS");

	string PropertyId, Pincode, City, State, Type, Area, Rooms, Price, Buy_Rent, Sale_Resale, PropertyName;
	string getPropertyId, getPincode, getCity, getState, getType, getArea, getRooms, getPrice, getBuy_Rent, getSale_Resale, getPropertyName;

	int property_found = 0;
	int choice;
	int propId = 0;

	char ch;
	cout << "\n---------------------------ADD PROPERTY-------------------------" << endl;
	cout << "\nEnter property name : ";
	cin >> getPropertyName;
	cout << "Enter property type: [1] Flat  [2] Bunglow  [3] Villa\n";
	cout << "Enter choice : ";
	cin >> choice;
	if (choice == 1)
		getType = "Flat";
	else if (choice == 2)
		getType = "Bunglow";
	else if (choice == 3)
		getType = "Villa";
	else
	{
		cout << "Invalid choice";
		menu();
	}
	cout << "Enter area(in sq.ft.) : ";
	cin >> getArea;
	cout << "Enter number of rooms : ";
	cin >> getRooms;
	cout << "Enter pincode : ";
	cin >> getPincode;
	cout << "Enter City : ";
	cin >> getCity;
	cout << "Enter State : ";
	cin >> getState;
	cout << "Property for : [1] Sale  [2] Rent ";
	cout << "\nEnter your choice : ";
	cin >> choice;
	if (choice == 1)
		getBuy_Rent = "Sale";
	else if (choice == 2)
		getBuy_Rent = "Rent";
	else
	{
		cout << "Invalid choice";
		menu();
	}
	cout << "Property is : [1] New  [2] Resale ";
	cout << "\nEnter your choice : ";
	cin >> choice;
	if (choice == 1)
		getSale_Resale = "New";
	else if (choice == 2)
		getSale_Resale = "Resale";
	else
	{
		cout << "Invalid Input";
		menu();
	}
	cout << "Enter Price : ";
	cin >> getPrice;
	cout << "\n---------------------------------------------------------------\n";

	ifstream propertyFileStream(PROPERTY_TXT);
	if (!propertyFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	string line;
	while (getline(propertyFileStream, line))
	{
		stringstream ss(line);
		getline(ss, PropertyId, ',');
		getline(ss, PropertyName, ',');
		getline(ss, Type, ',');
		getline(ss, Area, ',');
		getline(ss, Rooms, ',');
		getline(ss, Pincode, ',');
		getline(ss, City, ',');
		getline(ss, State, ',');
		getline(ss, Buy_Rent, ',');
		getline(ss, Sale_Resale, ',');
		getline(ss, Price, ',');
		if (getPropertyName == PropertyName && getType == Type && getArea == Area && getCity == City)
		{
			property_found = 1;
			break;
		}
	}

	propId = stoi(PropertyId);
	propertyFileStream.close();

	if (property_found == 1)
	{
		cout << "\nProperty already exists!! " << endl;
		system("pause");
		menu();
	}
	else
	{
		propId++;
		ofstream data(PROPERTY_TXT, ios::app);
		data << propId << "," << getPropertyName << "," << getType << "," << getArea << "," << getRooms << "," << getPincode << "," << getCity << "," << getState << "," << getBuy_Rent << "," << getSale_Resale << "," << getPrice << endl;
		data.close();
		cout << "Property added successfully!" << endl;
		system("pause");
		menu();
	}
}

void Admin::addOwner()
{
	string propertyid, ownerid, ownerName, ownerPhone, ownerMail;
	string getPropertyid, getOwnerid, getOwnerName, getOwnerPhone, getOwnerMail;
	int ownerFound = 0;
	int newOwnerid = 0;
	int propertyFound = 0;

	cout << "\nEnter property ID: ";
	cin >> getPropertyid;
	cout << "Enter Owner's Name: ";
	cin >> getOwnerName;
	cout << "Enter Owner's phone number: ";
	cin >> getOwnerPhone;
	cout << "Enter Owner's mail ID: ";
	cin >> getOwnerMail;

	ifstream propertyFileStream(PROPERTY_TXT);
	if (!propertyFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	string line;
	while (getline(propertyFileStream, line))
	{
		stringstream ss(line);
		getline(ss, propertyid, ',');
		if (getPropertyid == propertyid)
		{
			propertyFound = 1;
			break;
		}
	}
	propertyFileStream.close();

	if (propertyFound == 1)
	{
		ifstream ownerFileStream(OWNERS_TXT);
		if (!ownerFileStream.is_open())
		{
			cout << "Can't open file";
		}
		string line;
		while (getline(ownerFileStream, line))
		{
			stringstream ss(line);
			getline(ss, propertyid, ',');
			getline(ss, ownerid, ',');
			getline(ss, ownerName, ',');
			getline(ss, ownerPhone, ',');
			getline(ss, ownerMail, ',');
			if (getOwnerPhone == ownerPhone || getOwnerMail == ownerMail)
			{
				cout << "\nOwner already exists with this phone number or mail id!!\n";
				system("pause");
				menu();
				break;
			}
			else
			{
				ownerFound = 1;
			}
		}
		newOwnerid = stoi(ownerid);
		ownerFileStream.close();

		if (ownerFound == 1)
		{
			newOwnerid++;
			ofstream data(OWNERS_TXT, ios::app);
			data << getPropertyid << "," << newOwnerid << "," << getOwnerName << "," << getOwnerPhone << "," << getOwnerMail << endl;
			data.close();
			cout << "\nOwner details added successfully" << endl;
			system("pause");
			menu();
		}
	}
	else
	{
		cout << "\nProperty not found!!" << endl;
		system("pause");
		menu();
	}
}

void Admin::uploadPhoto()
{
	string propertyId;
	string getPropertyid;
	string temp;

	int random;
	int propertyFound = 0;

	cout << "\nEnter property id: ";
	cin >> getPropertyid;

	ifstream propertyFileStream(PROPERTY_TXT);
	if (!propertyFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	string line;
	while (getline(propertyFileStream, line))
	{
		stringstream ss(line);
		getline(ss, propertyId, ',');
		if (getPropertyid == propertyId)
		{
			propertyFound = 1;
			break;
		}
	}
	propertyFileStream.close();

	if (propertyFound == 1)
	{
		srand((unsigned)time(NULL));
		random = 1000 + (rand() % 9999);
		temp = to_string(random);
		string taddress = "Photos\\" + temp + ".jpg";
		string raddress = "Photos/" + temp + ".jpg";

		wstring wideAddress;
		for (int i = 0; i < taddress.length(); ++i)
			wideAddress += wchar_t(taddress[i]);

		const wchar_t* faddress = wideAddress.c_str();

		wchar_t filename[MAX_PATH];

		OPENFILENAME ofn;
		ZeroMemory(&filename, sizeof(filename));
		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFilter = L"Image Files (*.jpg)\0*.jpg\0All Files (*.jpg*)\0*.*\0";
		ofn.lpstrFile = filename;
		ofn.nMaxFile = MAX_PATH;
		ofn.lpstrTitle = L"Select a File";
		ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

		if (GetSaveFileName(&ofn))
		{
			wprintf(L"\nThe path is : %s\n", ofn.lpstrFile);
			std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
			if (in.tellg() > 50000000) {
				cout << "\nFile size exceeded!!\n";
				system("pause");
				menu();
			};
			system("pause");
		}

		BOOL b = CopyFile(filename, faddress, TRUE);
		if (b == FALSE) {
			cout << "Photo upload failed!! Error: " << GetLastError() << endl;
			system("pause");
			menu();
		}
		else {
			ofstream data(PHOTO_TXT, ios::app);
			data << getPropertyid << "," << raddress << endl;
			data.close();
			cout << "\nImage saved successfully!!\n" << endl;
			system("pause");
			menu();
		}
	}
	else
	{
		cout << "\nProperty not found!!" << endl;
		system("pause");
		menu();
	}
}

void Admin::uploadBrochure()
{
	string propertyId;
	string getPropertyid;

	int propertyFound = 0;

	cout << "\nEnter property id: ";
	cin >> getPropertyid;

	ifstream propertyFileStream(PROPERTY_TXT);
	if (!propertyFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	string line;
	while (getline(propertyFileStream, line))
	{
		stringstream ss(line);
		getline(ss, propertyId, ',');
		if (getPropertyid == propertyId)
		{
			propertyFound = 1;
			break;
		}
	}
	propertyFileStream.close();

	if (propertyFound == 1)
	{
		string taddress = "Brochure\\" + propertyId + ".pdf";

		wstring wideAddress;
		for (int i = 0; i < taddress.length(); ++i)
			wideAddress += wchar_t(taddress[i]);

		const wchar_t* faddress = wideAddress.c_str();

		wchar_t filename[MAX_PATH];

		OPENFILENAME ofn;
		ZeroMemory(&filename, sizeof(filename));
		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFilter = L"Pdf Files (*.pdf)\0*.pdf\0All Files (*.pdf*)\0*.*\0";
		ofn.lpstrFile = filename;
		ofn.nMaxFile = MAX_PATH;
		ofn.lpstrTitle = L"Select a File";
		ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

		if (GetSaveFileName(&ofn))
		{
			wprintf(L"\nThe path is : %s\n", ofn.lpstrFile);
			std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
			if (in.tellg() > 50000000) {
				cout << "\nFile size exceeded!!\n";
				system("pause");
				menu();
			};
			system("pause");
		}

		BOOL b = CopyFile(filename, faddress, TRUE);
		if (b == FALSE) {
			cout << "\nBrochure already exists!!" << endl;
			system("pause");
			menu();
		}
		else {
			cout << "\nBrochure saved successfully!!\n" << endl;
			system("pause");
			menu();
		}
	}
	else
	{
		cout << "\nProperty not found!!" << endl;
		system("pause");
		menu();
	}
}

void Admin::viewVisited()
{
	string propertyid, name, date;
	string getpropertyid;
	string line;
	int count = 0, property_found = 0;
	cout << "\nEnter property id: ";
	cin >> getpropertyid;
	ifstream visitedFileStream(VISITED_TXT);
	if (!visitedFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	while (getline(visitedFileStream, line))
	{
		stringstream ss(line);
		getline(ss, propertyid, ',');
		getline(ss, name, ',');
		getline(ss, date, ',');
		date = date.substr(0, 2) + date.substr(2, 2) + date.substr(4, 4);
		if (getpropertyid == propertyid)
		{
			cout << propertyid << "," << name << "," << date << endl;
			count++;
			property_found = 1;
		}
	}
	visitedFileStream.close();
	if (property_found == 1)
	{
		cout << "\nTotal number of users who browsed property id " << getpropertyid << " is " << count << ".\n";
		system("pause");
		menu();
	}
	else
	{
		cout << "\nProperty not found!!\n";
		system("pause");
		menu();
	}
}

void Admin::viewInterested()
{
	int propertyId;
	cout << "Enter Property Id : ";
	cin >> propertyId;
	cout << "\n";

	string property_Id, userName, name;
	ifstream messageFileStream(MESSAGE_TXT);
	if (!messageFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	string line;
	while (getline(messageFileStream, line))
	{
		stringstream ss(line);
		getline(ss, property_Id, ',');
		getline(ss, userName, ',');

		if (propertyId == stoi(property_Id))
		{
			if (_strcmpi(name.c_str(), userName.c_str()) != 0)
			{
				cout << userName;
			}
		}
		name.assign(userName);

	}
	cout << "\nInterested in property Id : " << propertyId << endl;
	messageFileStream.close();

	system("pause");
	menu();
}

void Admin::menu()
{
	int choice;

	system("CLS");

	cout << "\n------------------------Admin Menu----------------------\n" << endl;
	cout << " [1] Add a property\n";
	cout << " [2] Add owner details\n";
	cout << " [3] Add brochure\n";
	cout << " [4] Add photos\n";
	cout << " [5] View visited users\n";
	cout << " [6] View interested users\n";
	cout << " [0] Quit\n";
	cout << "\n--------------------------------------------------------\n";
	cout << "Enter choice: ";
	cin >> choice;

	switch (choice) {
	case 1:
		addProperty();
		break;
	case 2:
		addOwner();
		break;
	case 3:
		uploadBrochure();
		break;
	case 4:
		uploadPhoto();
		break;
	case 5:
		viewVisited();
		break;
	case 6:
		viewInterested();
		break;
	case 0:
		system("CLS");
		exit(0);
		break;
	default:
		cout << "Invalid input!!\n\n";
		system("pause");
		menu();
	}
}

//-------------------------------------------------End Admin-----------------------------------------------



//------------------------------------------------Class User-----------------------------------------------

void User::userRegistration()
{
	system("CLS");

	string getName, getPassword, getPhone, getEmail;
	int user_found = 0;

	char ch;
	cout << "\n-------------------User Registration--------------------\n" << endl;
	cout << " Enter name     : ";
	cin >> getName;
	cout << " Enter password : ";
	ch = _getch();
	while (ch != 13)
	{
		getPassword.push_back(ch);
		cout << "*";
		ch = _getch();
	}
	cout << endl;

	cout << " Enter phone no.: ";
	cin >> getPhone;

	cout << " Enter email    : ";
	cin >> getEmail;
	cout << "\n--------------------------------------------------------\n";

	ifstream userFileStream(USERS_TXT);
	if (!userFileStream.is_open())
	{
		cout << "can't open file" << endl;
	}
	string line;
	while (getline(userFileStream, line))
	{
		stringstream ss(line);
		getline(ss, name, ',');
		getline(ss, password, ',');
		getline(ss, phone, ',');
		getline(ss, email, ',');
		if (getName == name || getEmail == email || getPhone == phone)
		{
			user_found = 1;
			break;
		}
	}
	userFileStream.close();

	if (user_found == 1)
	{
		cout << "\nUser already exists!! Try login in" << endl;
		system("pause");
		menu();
	}
	else
	{
		ofstream data(USERS_TXT, ios::app);
		data << getName << "," << getPassword << "," << getPhone << "," << getEmail << endl;
		data.close();
		cout << "Registration successful!!" << endl;
		system("pause");
		login();
	}
}

void User::listByArea()
{
	string PropertyId, Pincode, City, State, Type, Area, Rooms, Price, Buy_Rent, Sale_Resale, PropertyName;
	string line;

	int found = 0;
	int head = 0;
	int l_area, u_area;

	cout << "\nLower limit: ";
	cin >> l_area;
	cout << "Upper limit: ";
	cin >> u_area;
	cout << "\n";

	ifstream propertyFileStream(PROPERTY_TXT);
	if (!propertyFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	while (getline(propertyFileStream, line))
	{
		stringstream ss(line);

		getline(ss, PropertyId, ',');
		getline(ss, PropertyName, ',');
		getline(ss, Type, ',');
		getline(ss, Area, ',');
		getline(ss, Rooms, ',');
		getline(ss, Pincode, ',');
		getline(ss, City, ',');
		getline(ss, State, ',');
		getline(ss, Buy_Rent, ',');
		getline(ss, Sale_Resale, ',');
		getline(ss, Price, ',');

		if (stoi(Area) >= l_area && stoi(Area) <= u_area)
		{

			if (head == 0)
			{
				cout << "Id | " << "Name      | " << "Type    | " << "Area   | " << "Rooms | " << "Pincode | " << "City       | " << "State       | " << "Sale/Rent | " << "Sale/Resale | " << "Price" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
				head++;
			}
			cout << PropertyId;
			for (int i = 0; i < (3 - PropertyId.length()); i++) { cout << " "; }
			cout << "| ";
			cout << PropertyName;
			for (int i = 0; i < (10 - PropertyName.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Type;
			for (int i = 0; i < (8 - Type.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Area;
			for (int i = 0; i < (7 - Area.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Rooms;
			for (int i = 0; i < (6 - Rooms.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Pincode;
			for (int i = 0; i < (8 - Pincode.length()); i++) { cout << " "; }
			cout << "| ";
			cout << City;
			for (int i = 0; i < (11 - City.length()); i++) { cout << " "; }
			cout << "| ";
			cout << State;
			for (int i = 0; i < (12 - State.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Buy_Rent;
			for (int i = 0; i < (10 - Buy_Rent.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Sale_Resale;
			for (int i = 0; i < (12 - Sale_Resale.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Price;
			cout << endl;
			found = 1;
		}
	}
	propertyFileStream.close();

	if (found == 0)
	{
		cout << "No property exists between given area range!!\n\n";
	}
	else
	{
		cout << "\n";
	}
	system("pause");
	menu();
}

void User::listByPrice()
{
	string PropertyId, Pincode, City, State, Type, Area, Rooms, Price, Buy_Rent, Sale_Resale, PropertyName;
	string line;

	int found = 0;
	int head = 0;
	int l_price, u_price;

	cout << "\nLower limit: ";
	cin >> l_price;
	cout << "Upper limit: ";
	cin >> u_price;
	cout << "\n";

	ifstream propertyFileStream(PROPERTY_TXT);
	if (!propertyFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	while (getline(propertyFileStream, line))
	{
		stringstream ss(line);

		getline(ss, PropertyId, ',');
		getline(ss, PropertyName, ',');
		getline(ss, Type, ',');
		getline(ss, Area, ',');
		getline(ss, Rooms, ',');
		getline(ss, Pincode, ',');
		getline(ss, City, ',');
		getline(ss, State, ',');
		getline(ss, Buy_Rent, ',');
		getline(ss, Sale_Resale, ',');
		getline(ss, Price, ',');

		if (stoi(Price) >= l_price && stoi(Price) <= u_price)
		{
			if (head == 0)
			{
				cout << "Id | " << "Name      | " << "Type    | " << "Area   | " << "Rooms | " << "Pincode | " << "City       | " << "State       | " << "Sale/Rent | " << "Sale/Resale | " << "Price" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
				head++;
			}
			cout << PropertyId;
			for (int i = 0; i < (3 - PropertyId.length()); i++) { cout << " "; }
			cout << "| ";
			cout << PropertyName;
			for (int i = 0; i < (10 - PropertyName.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Type;
			for (int i = 0; i < (8 - Type.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Area;
			for (int i = 0; i < (7 - Area.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Rooms;
			for (int i = 0; i < (6 - Rooms.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Pincode;
			for (int i = 0; i < (8 - Pincode.length()); i++) { cout << " "; }
			cout << "| ";
			cout << City;
			for (int i = 0; i < (11 - City.length()); i++) { cout << " "; }
			cout << "| ";
			cout << State;
			for (int i = 0; i < (12 - State.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Buy_Rent;
			for (int i = 0; i < (10 - Buy_Rent.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Sale_Resale;
			for (int i = 0; i < (12 - Sale_Resale.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Price;
			cout << endl;
			found = 1;
		}
	}
	propertyFileStream.close();

	if (found == 0)
	{
		cout << "No property exists between given price range!!\n\n";
	}
	else
	{
		cout << "\n";
	}
	system("pause");
	menu();
}

void User::listByPincode()
{
	string PropertyId, Pincode, City, State, Type, Area, Rooms, Price, Buy_Rent, Sale_Resale, PropertyName;
	string line;

	int found = 0;
	int head = 0;
	int i_pincode;

	cout << "\nEnter pincode: ";
	cin >> i_pincode;
	cout << "\n";

	ifstream propertyFileStream(PROPERTY_TXT);
	if (!propertyFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	while (getline(propertyFileStream, line))
	{
		stringstream ss(line);

		getline(ss, PropertyId, ',');
		getline(ss, PropertyName, ',');
		getline(ss, Type, ',');
		getline(ss, Area, ',');
		getline(ss, Rooms, ',');
		getline(ss, Pincode, ',');
		getline(ss, City, ',');
		getline(ss, State, ',');
		getline(ss, Buy_Rent, ',');
		getline(ss, Sale_Resale, ',');
		getline(ss, Price, ',');

		if (stoi(Pincode) == i_pincode)
		{
			if (head == 0)
			{
				cout << "Id | " << "Name      | " << "Type    | " << "Area   | " << "Rooms | " << "Pincode | " << "City       | " << "State       | " << "Sale/Rent | " << "Sale/Resale | " << "Price" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
				head++;
			}
			cout << PropertyId;
			for (int i = 0; i < (3 - PropertyId.length()); i++) { cout << " "; }
			cout << "| ";
			cout << PropertyName;
			for (int i = 0; i < (10 - PropertyName.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Type;
			for (int i = 0; i < (8 - Type.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Area;
			for (int i = 0; i < (7 - Area.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Rooms;
			for (int i = 0; i < (6 - Rooms.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Pincode;
			for (int i = 0; i < (8 - Pincode.length()); i++) { cout << " "; }
			cout << "| ";
			cout << City;
			for (int i = 0; i < (11 - City.length()); i++) { cout << " "; }
			cout << "| ";
			cout << State;
			for (int i = 0; i < (12 - State.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Buy_Rent;
			for (int i = 0; i < (10 - Buy_Rent.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Sale_Resale;
			for (int i = 0; i < (12 - Sale_Resale.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Price;
			cout << endl;
			found = 1;
		}
	}
	propertyFileStream.close();

	if (found == 0)
	{
		cout << "No property exists for given pincode!!\n\n";
	}
	else
	{
		cout << "\n";
	}
	system("pause");
	menu();
}

void User::listByNew()
{
	string PropertyId, Pincode, City, State, Type, Area, Rooms, Price, Buy_Rent, Sale_Resale, PropertyName;
	string line;
	int found = 0;
	int head = 0;
	cout << "\n";

	ifstream propertyFileStream(PROPERTY_TXT);
	if (!propertyFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	while (getline(propertyFileStream, line))
	{
		stringstream ss(line);

		getline(ss, PropertyId, ',');
		getline(ss, PropertyName, ',');
		getline(ss, Type, ',');
		getline(ss, Area, ',');
		getline(ss, Rooms, ',');
		getline(ss, Pincode, ',');
		getline(ss, City, ',');
		getline(ss, State, ',');
		getline(ss, Buy_Rent, ',');
		getline(ss, Sale_Resale, ',');
		getline(ss, Price, ',');

		if (_strcmpi(Sale_Resale.c_str(), "new") == 0)
		{
			if (head == 0)
			{
				cout << "Id | " << "Name      | " << "Type    | " << "Area   | " << "Rooms | " << "Pincode | " << "City       | " << "State       | " << "Sale/Rent | " << "Sale/Resale | " << "Price" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
				head++;
			}
			cout << PropertyId;
			for (int i = 0; i < (3 - PropertyId.length()); i++) { cout << " "; }
			cout << "| ";
			cout << PropertyName;
			for (int i = 0; i < (10 - PropertyName.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Type;
			for (int i = 0; i < (8 - Type.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Area;
			for (int i = 0; i < (7 - Area.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Rooms;
			for (int i = 0; i < (6 - Rooms.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Pincode;
			for (int i = 0; i < (8 - Pincode.length()); i++) { cout << " "; }
			cout << "| ";
			cout << City;
			for (int i = 0; i < (11 - City.length()); i++) { cout << " "; }
			cout << "| ";
			cout << State;
			for (int i = 0; i < (12 - State.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Buy_Rent;
			for (int i = 0; i < (10 - Buy_Rent.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Sale_Resale;
			for (int i = 0; i < (12 - Sale_Resale.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Price;
			cout << endl;
			found = 1;
		}
	}
	propertyFileStream.close();

	if (found == 0)
	{
		cout << "There is no new property!!\n\n";
	}
	else
	{
		cout << "\n";
	}
	system("pause");
	menu();
}

void User::listByResale()
{
	string PropertyId, Pincode, City, State, Type, Area, Rooms, Price, Buy_Rent, Sale_Resale, PropertyName;
	string line;
	int found = 0;
	int head = 0;
	cout << "\n";

	ifstream propertyFileStream(PROPERTY_TXT);
	if (!propertyFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	while (getline(propertyFileStream, line))
	{
		stringstream ss(line);

		getline(ss, PropertyId, ',');
		getline(ss, PropertyName, ',');
		getline(ss, Type, ',');
		getline(ss, Area, ',');
		getline(ss, Rooms, ',');
		getline(ss, Pincode, ',');
		getline(ss, City, ',');
		getline(ss, State, ',');
		getline(ss, Buy_Rent, ',');
		getline(ss, Sale_Resale, ',');
		getline(ss, Price, ',');

		if (_strcmpi(Sale_Resale.c_str(), "resale") == 0)
		{
			if (head == 0)
			{
				cout << "Id | " << "Name      | " << "Type    | " << "Area   | " << "Rooms | " << "Pincode | " << "City       | " << "State       | " << "Sale/Rent | " << "Sale/Resale | " << "Price" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
				head++;
			}
			cout << PropertyId;
			for (int i = 0; i < (3 - PropertyId.length()); i++) { cout << " "; }
			cout << "| ";
			cout << PropertyName;
			for (int i = 0; i < (10 - PropertyName.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Type;
			for (int i = 0; i < (8 - Type.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Area;
			for (int i = 0; i < (7 - Area.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Rooms;
			for (int i = 0; i < (6 - Rooms.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Pincode;
			for (int i = 0; i < (8 - Pincode.length()); i++) { cout << " "; }
			cout << "| ";
			cout << City;
			for (int i = 0; i < (11 - City.length()); i++) { cout << " "; }
			cout << "| ";
			cout << State;
			for (int i = 0; i < (12 - State.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Buy_Rent;
			for (int i = 0; i < (10 - Buy_Rent.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Sale_Resale;
			for (int i = 0; i < (12 - Sale_Resale.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Price;
			cout << endl;
			found = 1;
		}
	}
	propertyFileStream.close();
	if (found == 0)
	{
		cout << "There is no property for resale!!\n\n";
	}
	else
	{
		cout << "\n";
	}
	system("pause");
	menu();
}

void User::listByBuy()
{
	string PropertyId, Pincode, City, State, Type, Area, Rooms, Price, Buy_Rent, Sale_Resale, PropertyName;
	string line;

	int found = 0, i;
	int head = 0;
	cout << "\n";

	ifstream propertyFileStream(PROPERTY_TXT);
	if (!propertyFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	while (getline(propertyFileStream, line))
	{
		stringstream ss(line);

		getline(ss, PropertyId, ',');
		getline(ss, PropertyName, ',');
		getline(ss, Type, ',');
		getline(ss, Area, ',');
		getline(ss, Rooms, ',');
		getline(ss, Pincode, ',');
		getline(ss, City, ',');
		getline(ss, State, ',');
		getline(ss, Buy_Rent, ',');
		getline(ss, Sale_Resale, ',');
		getline(ss, Price, ',');

		if (_strcmpi(Buy_Rent.c_str(), "Sale") == 0)
		{
			if (head == 0)
			{
				cout << "Id | " << "Name      | " << "Type    | " << "Area   | " << "Rooms | " << "Pincode | " << "City       | " << "State       | " << "Sale/Rent | " << "Sale/Resale | " << "Price" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
				head++;
			}
			cout << PropertyId;
			for (int i = 0; i < (3 - PropertyId.length()); i++) { cout << " "; }
			cout << "| ";
			cout << PropertyName;
			for (int i = 0; i < (10 - PropertyName.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Type;
			for (int i = 0; i < (8 - Type.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Area;
			for (int i = 0; i < (7 - Area.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Rooms;
			for (int i = 0; i < (6 - Rooms.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Pincode;
			for (int i = 0; i < (8 - Pincode.length()); i++) { cout << " "; }
			cout << "| ";
			cout << City;
			for (int i = 0; i < (11 - City.length()); i++) { cout << " "; }
			cout << "| ";
			cout << State;
			for (int i = 0; i < (12 - State.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Buy_Rent;
			for (int i = 0; i < (10 - Buy_Rent.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Sale_Resale;
			for (int i = 0; i < (12 - Sale_Resale.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Price;
			cout << endl;
			found = 1;
		}
	}
	propertyFileStream.close();

	if (found == 0)
	{
		cout << "No property exists to Buy!!\n\n";
	}
	else
	{
		cout << "\n";
	}
	system("pause");
	menu();
}

void User::listByRent()
{
	string PropertyId, Pincode, City, State, Type, Area, Rooms, Price, Buy_Rent, Sale_Resale, PropertyName;
	string line;

	int found = 0, i;
	int head = 0;
	cout << "\n";

	ifstream propertyFileStream(PROPERTY_TXT);
	if (!propertyFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	while (getline(propertyFileStream, line))
	{
		stringstream ss(line);

		getline(ss, PropertyId, ',');
		getline(ss, PropertyName, ',');
		getline(ss, Type, ',');
		getline(ss, Area, ',');
		getline(ss, Rooms, ',');
		getline(ss, Pincode, ',');
		getline(ss, City, ',');
		getline(ss, State, ',');
		getline(ss, Buy_Rent, ',');
		getline(ss, Sale_Resale, ',');
		getline(ss, Price, ',');

		if (_strcmpi(Buy_Rent.c_str(), "Rent") == 0)
		{
			if (head == 0)
			{
				cout << "Id | " << "Name      | " << "Type    | " << "Area   | " << "Rooms | " << "Pincode | " << "City       | " << "State       | " << "Sale/Rent | " << "Sale/Resale | " << "Price" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
				head++;
			}
			cout << PropertyId;
			for (int i = 0; i < (3 - PropertyId.length()); i++) { cout << " "; }
			cout << "| ";
			cout << PropertyName;
			for (int i = 0; i < (10 - PropertyName.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Type;
			for (int i = 0; i < (8 - Type.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Area;
			for (int i = 0; i < (7 - Area.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Rooms;
			for (int i = 0; i < (6 - Rooms.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Pincode;
			for (int i = 0; i < (8 - Pincode.length()); i++) { cout << " "; }
			cout << "| ";
			cout << City;
			for (int i = 0; i < (11 - City.length()); i++) { cout << " "; }
			cout << "| ";
			cout << State;
			for (int i = 0; i < (12 - State.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Buy_Rent;
			for (int i = 0; i < (10 - Buy_Rent.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Sale_Resale;
			for (int i = 0; i < (12 - Sale_Resale.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Price;
			cout << endl;
			found = 1;
		}
	}
	propertyFileStream.close();

	if (found == 0)
	{
		cout << "No property exists to Rent!!\n\n";
	}
	else
	{
		cout << "\n";
	}
	system("pause");
	menu();
}

void User::listByRooms()
{
	string PropertyId, Pincode, City, State, Type, Area, Rooms, Price, Buy_Rent, Sale_Resale, PropertyName;
	string line;

	int found = 0;
	int head = 0;
	int no_rooms, i;

	cout << "\nEnter number of rooms: ";
	cin >> no_rooms;
	cout << "\n";

	ifstream propertyFileStream(PROPERTY_TXT);
	if (!propertyFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	while (getline(propertyFileStream, line))
	{
		stringstream ss(line);

		getline(ss, PropertyId, ',');
		getline(ss, PropertyName, ',');
		getline(ss, Type, ',');
		getline(ss, Area, ',');
		getline(ss, Rooms, ',');
		getline(ss, Pincode, ',');
		getline(ss, City, ',');
		getline(ss, State, ',');
		getline(ss, Buy_Rent, ',');
		getline(ss, Sale_Resale, ',');
		getline(ss, Price, ',');

		if (stoi(Rooms) == no_rooms)
		{
			if (head == 0)
			{
				cout << "Id | " << "Name      | " << "Type    | " << "Area   | " << "Rooms | " << "Pincode | " << "City       | " << "State       | " << "Sale/Rent | " << "Sale/Resale | " << "Price" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
				head++;
			}
			cout << PropertyId;
			for (int i = 0; i < (3 - PropertyId.length()); i++) { cout << " "; }
			cout << "| ";
			cout << PropertyName;
			for (int i = 0; i < (10 - PropertyName.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Type;
			for (int i = 0; i < (8 - Type.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Area;
			for (int i = 0; i < (7 - Area.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Rooms;
			for (int i = 0; i < (6 - Rooms.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Pincode;
			for (int i = 0; i < (8 - Pincode.length()); i++) { cout << " "; }
			cout << "| ";
			cout << City;
			for (int i = 0; i < (11 - City.length()); i++) { cout << " "; }
			cout << "| ";
			cout << State;
			for (int i = 0; i < (12 - State.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Buy_Rent;
			for (int i = 0; i < (10 - Buy_Rent.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Sale_Resale;
			for (int i = 0; i < (12 - Sale_Resale.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Price;
			cout << endl;
			found = 1;
		}
	}
	propertyFileStream.close();

	if (found == 0)
	{
		cout << "No property exists for given number of rooms!!\n\n";
	}
	else
	{
		cout << "\n";
	}
	system("pause");
	menu();
}

void User::listByCityState()
{
	string PropertyId, Pincode, City, State, Type, Area, Rooms, Price, Buy_Rent, Sale_Resale, PropertyName;
	string line;

	int found = 0;
	int head = 0;
	string getCity, getState;

	cout << "\nCity : ";
	cin >> getCity;
	cout << "State: ";
	cin >> getState;
	cout << "\n";

	ifstream propertyFileStream(PROPERTY_TXT);
	if (!propertyFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	while (getline(propertyFileStream, line))
	{
		stringstream ss(line);

		getline(ss, PropertyId, ',');
		getline(ss, PropertyName, ',');
		getline(ss, Type, ',');
		getline(ss, Area, ',');
		getline(ss, Rooms, ',');
		getline(ss, Pincode, ',');
		getline(ss, City, ',');
		getline(ss, State, ',');
		getline(ss, Buy_Rent, ',');
		getline(ss, Sale_Resale, ',');
		getline(ss, Price, ',');

		if (_strcmpi(State.c_str(), getState.c_str()) == 0 && _strcmpi(City.c_str(), getCity.c_str()) == 0)
		{
			if (head == 0)
			{
				cout << "Id | " << "Name      | " << "Type    | " << "Area   | " << "Rooms | " << "Pincode | " << "City       | " << "State       | " << "Sale/Rent | " << "Sale/Resale | " << "Price" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
				head++;
			}
			cout << PropertyId;
			for (int i = 0; i < (3 - PropertyId.length()); i++) { cout << " "; }
			cout << "| ";
			cout << PropertyName;
			for (int i = 0; i < (10 - PropertyName.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Type;
			for (int i = 0; i < (8 - Type.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Area;
			for (int i = 0; i < (7 - Area.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Rooms;
			for (int i = 0; i < (6 - Rooms.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Pincode;
			for (int i = 0; i < (8 - Pincode.length()); i++) { cout << " "; }
			cout << "| ";
			cout << City;
			for (int i = 0; i < (11 - City.length()); i++) { cout << " "; }
			cout << "| ";
			cout << State;
			for (int i = 0; i < (12 - State.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Buy_Rent;
			for (int i = 0; i < (10 - Buy_Rent.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Sale_Resale;
			for (int i = 0; i < (12 - Sale_Resale.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Price;
			cout << endl;
			found = 1;
		}
	}
	propertyFileStream.close();

	if (found == 0)
	{
		cout << "No property exists for given city and state!!\n\n";
	}
	else
	{
		cout << "\n";
	}
	system("pause");
	menu();
}

void User::listByType()
{
	string PropertyId, Pincode, City, State, Type, Area, Rooms, Price, Buy_Rent, Sale_Resale, PropertyName;
	string line;

	int found = 0;
	int head = 0;
	string type;
	cout << "\nTypes: [1] Flat [2] Bunglow [3] Villa\n";
	cout << "\nEnter type: ";
	cin >> type;
	if (type == "1") { type = "Flat"; }
	if (type == "2") { type = "Bunglow"; }
	if (type == "3") { type = "Villa"; }
	cout << "\n";

	ifstream propertyFileStream(PROPERTY_TXT);
	if (!propertyFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	while (getline(propertyFileStream, line))
	{
		stringstream ss(line);

		getline(ss, PropertyId, ',');
		getline(ss, PropertyName, ',');
		getline(ss, Type, ',');
		getline(ss, Area, ',');
		getline(ss, Rooms, ',');
		getline(ss, Pincode, ',');
		getline(ss, City, ',');
		getline(ss, State, ',');
		getline(ss, Buy_Rent, ',');
		getline(ss, Sale_Resale, ',');
		getline(ss, Price, ',');

		if (_strcmpi(Type.c_str(), type.c_str()) == 0)
		{
			if (head == 0)
			{
				cout << "Id | " << "Name      | " << "Type    | " << "Area   | " << "Rooms | " << "Pincode | " << "City       | " << "State       | " << "Sale/Rent | " << "Sale/Resale | " << "Price" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
				head++;
			}
			cout << PropertyId;
			for (int i = 0; i < (3 - PropertyId.length()); i++) { cout << " "; }
			cout << "| ";
			cout << PropertyName;
			for (int i = 0; i < (10 - PropertyName.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Type;
			for (int i = 0; i < (8 - Type.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Area;
			for (int i = 0; i < (7 - Area.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Rooms;
			for (int i = 0; i < (6 - Rooms.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Pincode;
			for (int i = 0; i < (8 - Pincode.length()); i++) { cout << " "; }
			cout << "| ";
			cout << City;
			for (int i = 0; i < (11 - City.length()); i++) { cout << " "; }
			cout << "| ";
			cout << State;
			for (int i = 0; i < (12 - State.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Buy_Rent;
			for (int i = 0; i < (10 - Buy_Rent.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Sale_Resale;
			for (int i = 0; i < (12 - Sale_Resale.length()); i++) { cout << " "; }
			cout << "| ";
			cout << Price;
			cout << endl;
			found = 1;
		}
	}
	propertyFileStream.close();

	if (found == 0)
	{
		cout << "There is no property with " << type << " type!!\n\n";
	}
	else
	{
		cout << "\n";
	}
	system("pause");
	menu();
}

// Need OpenCV to view
//void User::viewPhoto()
//{
//	string getpropertyid;
//	string propertyid, imgPath;
//
//	int index = 0, row;
//	vector<Mat> images;
//	Mat dst;
//
//	cout << "\nEnter property id: ";
//	cin >> getpropertyid;
//
//	int propertyFound = 0;
//
//	ifstream propertyFileStream(PROPERTY_TXT);
//	if (!propertyFileStream.is_open())
//	{
//		cout << "Can't open file!";
//	}
//
//	string name, getdate, date, line;
//	string d, m, y;
//	time_t now = time(0);
//	tm* ltm = localtime(&now);
//	d = to_string(ltm->tm_mday);
//	m = to_string(1 + ltm->tm_mon);
//	y = to_string(1900 + ltm->tm_year);
//	getdate = d + m + y;
//
//	while (getline(propertyFileStream, line))
//	{
//		stringstream ss(line);
//		getline(ss, propertyid, ',');
//		if (getpropertyid == propertyid)
//		{
//			propertyFound = 1;
//			break;
//		}
//	}
//	propertyFileStream.close();
//
//	if (propertyFound == 1)
//	{
//
//		ifstream photoFileStream(PHOTO_TXT);
//		if (!photoFileStream.is_open())
//		{
//			cout << "Can't open file!";
//		}
//		string line;
//		while (getline(photoFileStream, line))
//		{
//			stringstream ss(line);
//			getline(ss, propertyid, ',');
//			getline(ss, imgPath, ',');
//			if (getpropertyid == propertyid)
//			{
//				images.resize(index + 1);
//				images[index] = imread(imgPath);
//				index++;
//			}
//		}
//		photoFileStream.close();
//
//		if (index == 0)
//		{
//			cout << "\nNo images found for given property!!\n";
//			system("pause");
//			menu();
//		}
//		else
//		{
//			ofstream data(VISITED_TXT, ios::app);
//			data << getpropertyid << "," << user_name << "," << d << "/" << m << "/" << y << endl;
//			data.close();
//
//			if (images.size() / 2 == 0) { row = 1; }
//			else { row = images.size() / 2; }
//			Mat img = makeCanvas(images, 500, row);
//			namedWindow("Display Frame", WINDOW_NORMAL);
//			resizeWindow("Display Frame", 1000, 500);
//			system("cls");
//			cout << "Displaying images.....";
//			imshow("Display Frame", img);
//			waitKey(0);
//			destroyAllWindows();
//			menu();
//		}
//	}
//	else
//	{
//		cout << "\nProperty not found!!" << endl;
//		system("pause");
//		menu();
//	}
//}

void User::downloadBrochure()
{
	string propertyId;
	string getPropertyid;

	int propertyFound = 0;
	int choice;

	cout << "\nEnter property id: ";
	cin >> getPropertyid;

	ifstream propertyFileStream(PROPERTY_TXT);
	if (!propertyFileStream.is_open())
	{
		cout << "Can't open file!";
	}
	string line;
	while (getline(propertyFileStream, line))
	{
		stringstream ss(line);
		getline(ss, propertyId, ',');
		if (getPropertyid == propertyId)
		{
			propertyFound = 1;
			break;
		}
	}
	propertyFileStream.close();

	if (propertyFound == 1)
	{
		string taddress = "Brochure\\" + getPropertyid + ".pdf";
		string dt_address = "Downloads\\" + getPropertyid + ".pdf";

		wstring wideAddress;
		for (int i = 0; i < taddress.length(); ++i)
			wideAddress += wchar_t(taddress[i]);

		const wchar_t* faddress = wideAddress.c_str();

		ShellExecute(NULL, L"open", faddress, NULL, NULL, SW_SHOWNORMAL);
		system("pause");

		cout << "\n[1] Download [2] Continue\n";
		cout << "Enter choice: ";
		cin >> choice;

		if (choice == 1)
		{
			wstring d_wideAddress;
			for (int i = 0; i < dt_address.length(); ++i)
				d_wideAddress += wchar_t(dt_address[i]);

			const wchar_t* daddress = d_wideAddress.c_str();

			BOOL b = CopyFile(faddress, daddress, TRUE);
			if (b == FALSE) {
				cout << "\nCan't download!! " << endl;
				system("pause");
				menu();
			}
			else {
				ofstream data(MESSAGE_TXT, ios::app);
				data << getPropertyid << "," << user_name << endl;
				data.close();
				cout << "\nBrochure download successfully!!\n" << endl;
				system("pause");
				menu();
			}
		}
		else if (choice == 2)
		{
			menu();
		}
		else
		{
			cout << "\nInvalid choice!!\n";
			system("pause");
			menu();
		}
	}
	else
	{
		cout << "\nProperty not found!!" << endl;
		system("pause");
		menu();
	}
}

void User::login()
{
	system("CLS");

	int user_found = 0;
	string getName, getPassword;
	char ch;

	cout << "\n-----------------------User Login-----------------------\n" << endl;
	cout << " Enter name     : ";
	cin >> getName;
	cout << " Enter password : ";
	ch = _getch();
	while (ch != 13)
	{
		if (ch == 8)
		{
			if (getPassword.length() > 0)
			{
				getPassword.pop_back();
				cout << "\b \b";
			}
		}
		else
		{
			cout << "*";
			getPassword.push_back(ch);
		}
		ch = _getch();
	}
	cout << "\n\n--------------------------------------------------------\n";

	ifstream userFileStream(USERS_TXT);
	if (!userFileStream.is_open())
	{
		cout << "can't open file" << endl;
	}
	string line;
	while (getline(userFileStream, line))
	{
		stringstream ss(line);
		getline(ss, name, ',');
		getline(ss, password, ',');
		if (getName == name && getPassword == password)
		{
			user_name = getName;
			user_found = 1;
			break;
		}
	}
	userFileStream.close();

	if (user_found == 1)
	{
		cout << "\nLogin successful!!" << endl;
		system("pause");
		menu();
	}
	else
	{
		cout << "Invalid password or name!!\n\n";
		system("pause");
		login();
	}
}

void User::menu()
{
	int choice;

	system("CLS");

	cout << "\n-------------------------User Menu-----------------------\n" << endl;
	cout << " [1]  List properties by area\n";
	cout << " [2]  List properties by pincode\n";
	cout << " [3]  List properties by price range\n";
	cout << " [4]  List properties by new\n";
	cout << " [5]  List properties by resale\n";
	cout << " [6]  List properties by buy\n";
	cout << " [7]  List properties by rent\n";
	cout << " [8]  List properties by rooms\n";
	cout << " [9]  List properties by city/state\n";
	cout << " [10] List properties by Type\n";
	cout << " [11] Download Brochure\n";
	cout << " [0]  Quit\n";
	cout << "\n--------------------------------------------------------\n";
	cout << "Enter choice: ";
	cin >> choice;

	switch (choice) {
	case 1:
		listByArea();
		break;
	case 2:
		listByPincode();
		break;
	case 3:
		listByPrice();
		break;
	case 4:
		listByNew();
		break;
	case 5:
		listByResale();
		break;
	case 6:
		listByBuy();
		break;
	case 7:
		listByRent();
		break;
	case 8:
		listByRooms();
		break;
	case 9:
		listByCityState();
		break;
	case 10:
		listByType();
		menu();
		break;
	case 11:
		downloadBrochure();
		break;
	case 0:
		system("CLS");
		exit(0);
		break;
	default:
		cout << "Invalid input!!\n\n";
		system("pause");
		menu();
	}
}

//--------------------------------------------------End User-----------------------------------------------


//---------------------------------------------------Main--------------------------------------------------

int main()
{
	system("CLS");

	RealEstateSys* ptr;
	User userObj;

	int choice;
	cout << "\n--------Welcome to Real Estate Management System--------\n" << endl;
	cout << " [1] Login as admin" << endl;
	cout << " [2] Login as user" << endl;
	cout << " [3] Register new user" << endl;
	cout << " [0] Quit" << endl;
	cout << "\n--------------------------------------------------------\n";
	cout << "Enter choice: ";
	cin >> choice;

	switch (choice) {
	case 1:
		ptr = new Admin;
		ptr->login();
		delete ptr;
		break;
	case 2:
		ptr = new User;
		ptr->login();
		delete ptr;
		break;
	case 3:
		userObj.userRegistration();
		break;
	case 0:
		system("CLS");
		exit(0);
		break;
	default:
		cout << "Invalid input!!\n\n";
		system("pause");
		main();
	}
	return 0;
}

//-----------------------------------------------End Main--------------------------------------------------