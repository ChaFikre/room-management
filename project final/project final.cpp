//Hotel room management system. it alows the user to book rooms from the available rooms.
#include <iostream>
#include <string>

using namespace std;

void display()
{
	cout << "\t\tHotel management"<<endl;

}

int choose_number_of_rooms(int number_of_rooms, int rooms) 
{
	do
	{

		cout << " How many rooms you want to book ?"<<endl; // get how many rooms the guest wish to book?

		cin >> rooms;

		system("cls");


		if (rooms<0 || rooms>number_of_rooms) //the number of rooms must be greater than 0 and less than total number of rooms the hotel has.
		{
			cout << "\t Please enter the number between 1 and 60 \n";
		}
	} while (rooms<0 || rooms>number_of_rooms);

	

	return rooms;
}


int determine_price(int choice, int number_of_rooms,int rooms)
{
	int price = 100;  // price of Single room of the first half parts of the hotel rooms.

	int discount = 0; //if the guest book  less than 11 rooms doesn't get any discount.
	
	
	if (choice > number_of_rooms / 2) // price of double rooms the other half parts of the hotel.
	{
		price = 150;
	}

	if (rooms > 10 && rooms <= 15) // book rooms more than 10 and less than 16 get 10% discount.
	{

		discount = price / 10;
	}
	else if(rooms > 15) //book rooms more than 15 and get 20% discount.
	{
		discount = price / 5;
	}
	price = price - discount;

	return price;
}

int main()
{
	const int number_of_rooms = 60;//constant for the array size and its total number of rooms the hotel has.
	int roomchoice[number_of_rooms];// user room choice;
	int rooms = 0;// user amount of rooms;

	int numberofnights;// number ofnights the guest want to stay.
	int price = 100;// price of a single room.
	int totalprice = 0; //initialize the total price.
	string name;
	display();

	
	rooms = choose_number_of_rooms(number_of_rooms, rooms);
	
	for (int i = 0; i < rooms; i++)
	{
		int j = 0;

		do
		{

		cout << "Book your room ";// Get the rooms from the guest.

		cin >> roomchoice[i];
			

			for (j; j < i; j++)

			{

				if (roomchoice[i] == roomchoice[j])
				{
					cout << "Room " <<roomchoice[i] << " is occupied please book your room again \n";
					break;

				}
			}

		} while (i > j);


		cout << "How many nights you want to stay ?"; //get the number of night guests want to stay.

		cin >> numberofnights;

		price = determine_price(roomchoice[i], number_of_rooms, rooms);

		totalprice = price * numberofnights;
		
		{


			cout << " you have booked room number. " << roomchoice[i] << endl;

            cout << "Total price for room " << roomchoice[i] <<" for "<< numberofnights << " nights is " << totalprice <<" € "<< endl;
		}

		cout << endl;

	
    }
		return 0;

	}
