#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct Hotel_Info{
	int price_per_person;
	vector<int> beds_available;
	bool good = false;
	int total_price;
};

int main() {

  int participants, budget, hotels, weeks;
	cin >> participants >> budget >> hotels >> weeks; 

	Hotel_Info hotel_list[hotels];
	int beds;

	for(int i = 0; i < hotels; i++){ 
		cin >> hotel_list[i].price_per_person; 

		for(int k = 0; k < weeks; k++){
			cin >> beds;
			hotel_list[i].beds_available.push_back(beds);
		}
	}

	int yes = 0;
	int min = INT_MAX;


	for(int i = 0; i < hotels; i++){
		hotel_list[i].total_price = hotel_list[i].price_per_person*participants;

		for(int k = 0; k < weeks; k++){
			if(hotel_list[i].beds_available[k] == 0 || hotel_list[i].beds_available[k] < participants)
				yes++;
		  else 
				hotel_list[i].good = true;
			
		}
	}

	for(int i = 0; i < hotels; i++){
		if(hotel_list[i].good && hotel_list[i].total_price < min)
				min = hotel_list[i].total_price;
	}

	if(yes == hotels || min > budget){
		cout << "stay home";
	} else{
		cout << min;
	}
	return 0;
}
