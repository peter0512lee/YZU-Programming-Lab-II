#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

class Monster {
    private:
        int HP;
        int MaxHP;
        int Attack;
        int Defense;
    public:
        Monster(int hp, int mxhp, int atk, int def):HP(hp),MaxHP(mxhp),Attack(atk),Defense(def){}
        void setHP(int hp){ HP = hp; }
        int getHP() const { return HP; }
        int getMaxHP() const { return MaxHP; }
        int getAttack() const { return Attack; }
        int getDefense() const { return Defense; }
        void showStats(){
            std::cout << std::setw(10) << "Monster(" << std::setw(3) << getHP() << " / " << std::setw(3) << getMaxHP() << " )" << std::endl; 
        }
        void attack(Monster &m){
            m.setHP(m.getHP() - (getAttack() - m.getDefense()));
        }
};

class Dragon : public Monster
{
private:
	double rate;
public:
	Dragon(double r) : Monster(200, 200, 20, 20), rate(r){}

	void showStats()
	{
		std::cout << "Dragon (" << getHP() << "/" << getMaxHP() << ")" << std::endl;
	}

	void attack(Monster &m) 
	{	
		m.setHP(m.getHP() - (getAttack() - m.getDefense()) - rate * (rand() % 10 + 1));
	}

};

class Unicorn : public Monster
{
public:

	Unicorn() : Monster(250, 250, 30, 10){}

	void showStats()
	{
		std::cout << "Unicorn (" << getHP() << "/" << getMaxHP() << ")" << std::endl;
	}

	void attack(Monster &m)
	{
		int A[4] = { 0, 0, 1, 0 };		
		m.setHP(m.getHP() - (getAttack() - m.getDefense()));
		if (A[rand()%4] == 1)
			m.setHP(m.getHP() - (getAttack() - m.getDefense()));
	}

};

#endif // MONSTER_H
