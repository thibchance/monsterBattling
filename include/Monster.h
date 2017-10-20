#pragma once



#ifndef MONSTER_H
#define MONSTER_H
#include <SFML/Graphics.hpp>
enum class MonsterType
{
	ORC = 1,
	TROLL = 2,
	Gobelin = 3,
	Lenght = 4
};

class Monster
{


public:
	Monster(double, double, double,double,int, sf::Vector2f,std::string,std::string );
	~Monster();

	int attack(Monster *Monster_Defense);
	void CheckRace(Monster &Monster_Defense);
	double GetS();
	double GetHP();
	void draw(sf::RenderWindow &window);
	
	

	//void Attackfirst(Monster &Monster_Defense);
	//void Print_Winning_Monster(Monster &Monster_Defense);

private: 
	
	double HP, AP, DP, S;
	sf::Sprite sprite;
	sf::Texture* texture;
	sf::Font* font;
	sf::Text text;
	MonsterType Race;
};

#endif // !MONSTER_H