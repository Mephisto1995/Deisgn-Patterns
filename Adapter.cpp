#include <iostream>
#include <vector>
#include <map>
using namespace std;

class IEnemy
{
public:
	virtual void Attack() = 0;
	virtual void Move() = 0;
};

class Ninja : public IEnemy
{
public:
	void Attack()
	{
		cout << "Ninja attacks!" << endl;
	}
	
	void Move()
	{
		cout << "Ninja roams through the shadows!" << endl;
	}
};

class Robot
{
public:
	void AirAttack()
	{
		cout << "Robot launches missile rockets!" << endl;
	}

	void StompGroundMoving()
	{
		cout << "Robot stomps the ground as it's reaching it's target!" << endl;
	}
};

class RobotAdapter : public IEnemy
{
public:
	RobotAdapter(Robot& robot):
		mRobot(robot)
	{}

	void Attack()
	{
		mRobot.AirAttack();
	}

	void Move()
	{
		mRobot.StompGroundMoving();
	}

private:
	Robot& mRobot;
};

void main()
{
	Ninja* Sekiro = new Ninja();
	Robot* fredTheRobot = new Robot();
	IEnemy* robotAdapter = new RobotAdapter(*fredTheRobot);

	//Ninja
	cout << "Ninja time: " << endl;
	cout << "Sekiro attacks: "; Sekiro->Attack();
	cout << "Sekiro moves: "; Sekiro->Move();

	// Robot
	cout << "\nRobot time: " << endl;
	cout << "Fred attacks: "; fredTheRobot->AirAttack();
	cout << "Fred moves: "; fredTheRobot->StompGroundMoving();

	// Adapter
	cout << "\nAdapter time: " << endl;
	cout << "Adapter attacks: "; robotAdapter->Attack();
	cout << "Adapter moves: "; robotAdapter->Move();

	// Free
	delete Sekiro; Sekiro = nullptr;
	delete fredTheRobot; fredTheRobot = nullptr;
	delete robotAdapter; robotAdapter = nullptr;

	cin.get();
}