#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int main()
{
	const char dollar('$');
	
	const int TYPES = 10;
	string caketypes[TYPES] = { "Red Velvet", 
													    "Death by Chocolate",
													    "Molten Lava Chocolate",
													    "Unicorn Rainbow Cake",
													    "Warm Pumpkin Spice",
													    "Blueberry Cheesecake",
													    "English Pudding Cake",
													    "Salted Turtle Cake",
													    "Hot Fudge Sundae",
	00523												    "Funfetti Sprinkles" }; //cakes
00000
	const int AMOUNT = 10;
	float cakeprices[AMOUNT] = { 29.95, 
											           44.95, 
											           49.95, 
											           24.95, 
											           29.95, 
											           34.95, 
											           29.95, 
											           39.95, 
											           24.95, 
											           19.95 }; //prices

	const int TIME = 10;
	float cakedays[TIME] = { 1, 
									          2, 
									          2, 
									          1, 
									          1, 
									          2,
									          2,
									          2,
									          1,
									          1 }; //days

	bool swap_by_price;
	string tempCake;
	float tempPrice, tempDay;

	do
	{
		swap_by_price = false;//Don't remove

		for (int c = 0; c < AMOUNT - 1; c++)
		{
			if (cakeprices[c] > cakeprices[c + 1])
			{
				tempPrice = cakeprices[c];//swapping with prices
				cakeprices[c] = cakeprices[c + 1];
				cakeprices[c + 1] = tempPrice;
				
				tempCake = caketypes[c];
				caketypes[c] = caketypes[c + 1];
				caketypes[c + 1] = tempCake;

				tempDay = cakedays[c];
				cakedays[c] = cakedays[c + 1];
				cakedays[c + 1] = tempDay;

				swap_by_price = true;
					
			}
		}

	} while (swap_by_price == true);
	
	cout << setw(21) << left << "CAKE" << setw(21) << right << "PRICE" << setw(21) << right << "ORDER TIME (DAYS)" << endl
		<< setw(21) << left << "----" << setw(21) << right << "-----" << setw(21) << right << "-----------------" << endl;
	
	for (int c = 0; c < 10; c++)
	{
		cout << setw(21) << left << caketypes[c] << setw(16) << right << dollar << cakeprices[c] << setw(13) << right << cakedays[c]  << endl;
	}

	int highestPrice = 0;
	int lowestPrice = 0;
	int totalAverage = 0;

	for (int x = 1; x < AMOUNT; x++)//average function
	{
		totalAverage += cakeprices[x];

		if (cakeprices[x] > cakeprices[highestPrice])
			highestPrice = x;
		if (cakeprices[x] < cakeprices[lowestPrice])
			lowestPrice = x;
	}

	int avg = totalAverage / 10;

	cout << "\nAverage cost of cake at the Sweet Dreams: " << dollar << avg << endl
		<< "Thank you for your order. Enjoy!" << endl;

	return 0;
}

