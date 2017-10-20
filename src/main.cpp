#include "Monster.h"
#include <iostream>
#include <fstream>
#include "json.hpp"
#include  <SFML/Graphics.hpp>

using json = nlohmann::json;

enum StateMonster
{
	IDLE,
	ATTACK
};

int main()
{


	



	std::ifstream file("data/Monster.json");
	json data;
	if (file.is_open())
		data = json::parse(file);
	else
	{
		std::cerr << "Unable to read the json file.\n";
		system("pause");
		return EXIT_FAILURE;
	}
	std::cout << data["monsters"][0]["HP"];
	Monster monster1 = Monster(data["monsters"][0]["HP"], 
		data["monsters"][0]["AP"], data["monsters"][0]["DP"],
		data["monsters"][0]["S"], data["monsters"][0]["Race"],
		sf::Vector2f(data["monsters"][0]["position"]["x"], 
			data["monsters"][0]["position"]["y"]),
		data["monsters"][0]["texture"],data ["monsters"][0]["font"]);

	Monster monster2 = Monster(data["monsters"][1]["HP"], data["monsters"][1]["AP"], data["monsters"][1]["DP"],
		data["monsters"][1]["S"], data["monsters"][1]["Race"],
		sf::Vector2f(data["monsters"][1]["position"]["x"], data["monsters"][1]["position"]["y"]), data["monsters"][1]["texture"], data ["monsters"][1]["font"]);


	
	sf::RenderWindow window(sf::VideoMode(700, 500), "SFML works!");
	window.setFramerateLimit(60.f);
	
	bool monster_turn = true;
	if (monster1.GetS() > monster2.GetS())
	{
		monster_turn = true;
	}
	else
		monster_turn = false;
	
	int damage;
	float speed = 5.0f;
	StateMonster statemonster = IDLE;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			
		}
		
		switch (statemonster)
		{
		


		}
		
	
			if (monster_turn)
		      {
			  damage =  monster1.attack(&monster2);
			  
		    }
		else
		{
			monster2.attack(&monster1);
		}

		monster_turn = !monster_turn;

		if (monster1.GetHP() <= 0.0 || monster2.GetHP() <= 0.0)
		{
			//window.close();
		}
		
		
		window.clear();
		monster1.draw(window);
		monster2.draw(window);
		
		window.display();
	}
	
//	int count = 0;

	/*while (monster1.GetHP() > 0.0 && monster2.GetHP() > 0.0)
	{
		if (monster1.GetS() > monster2.GetS())
		{
			monster1.attack(monster2);
			monster2.attack(monster1);
		}
		else
		{
			monster2.attack(monster1);
			monster1.attack(monster2);
		}
		count++;

	}
	if (monster1.GetHP() <= 0.0)
	{
		std::cout << "le second monstre gagne et au nombre de tour :" << count << "\n";
	}
	else if (monster2.GetHP() <= 0.0)
	{
		std::cout << "le premier monstre gagne et au nombre de tour :" << count << "\n";;
	}*/
	system("pause");
	return 0;
}
