
#include "Monster.h"
#include <iostream>
#define SIZE_TEXT_DAMAGE 25

//Monster::Monster()
//{
//}


//Monster::Monster() 
//{
//	/*int temprace = 0;
//
//	std::cout<<"choisir la race   1 = Orc, 2= Troll, 3= Gobelin \n";
//	std::cin >> temprace;
//	Race = (MonsterType)temprace;
//	std::cout << " veuillet saisir les HP,AP,DP,S \n";
//	std::cin >> HP, AP, DP, S;*/
//
//}

Monster::Monster(double, double, double, double, int, sf::Vector2f vect, std::string textureFilePath, std::string fontFilePath)
{
texture = new sf::Texture;
texture->loadFromFile(textureFilePath);
sprite;
sprite.setTexture(*texture);
sprite.setPosition(vect);
font = new sf::Font;
font->loadFromFile(fontFilePath);
text;
text.setFont(*font);
text.setString("");
text.setCharacterSize(SIZE_TEXT_DAMAGE);
text.setFillColor(sf::Color::Red);
text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

Monster::~Monster()
{
	delete texture;
	delete font;
}



int Monster::attack(Monster* Monster_Defense)
{
	double Damage = this->AP-Monster_Defense->DP;

	if (Damage -= 0)
	{
		Damage =  1;
	}

	 Monster_Defense->HP -= Damage;
	 if (Monster_Defense->HP > 0)
	 {
		 Monster_Defense->attack(this);
	 }
	 return Damage;
}

void Monster::CheckRace(Monster &Monster_Defense)
{
	if (this->Race == Monster_Defense.Race)
	{
		std::cout << " pas tape \n";
	}

}

double Monster::GetS()
{
	return S;
}

double Monster::GetHP()
{
	return HP;
}

void Monster::draw(sf::RenderWindow & window)
{
	window.draw(sprite);
	window.draw(text);
}



//void Monster::Print_Winning_Monster(Monster &Monster_Defense)
//{
//	if (this->HP <= 0)
//	{
//		std::cout << "le gagnant est " << Monster_Defense;
//	}
//
//}

//void Monster::Attackfirst(Monster &Monster_Defense)
//{
//	if (this->S > Monster_Defense.S)
//	{
//		this->attack()Monster_Defense;
//	}
//
//}




