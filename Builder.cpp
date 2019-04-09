#include <iostream>
#include <vector>
using namespace std;

class IRobotPlan
{
public:
	virtual void SetRobotHead(const string& info) = 0;
	virtual void SetRobotTorso(const string& info) = 0;
	virtual void SetRobotArms(const string& info) = 0;
	virtual void SetRobotLegs(const string& info) = 0;
};

class Robot : public IRobotPlan
{
public:
	void SetRobotHead(const string& info) override
	{
		mRobotHead = info;
	}

	void SetRobotTorso(const string& info) override
	{
		mRobotTorso = info;
	}

	void SetRobotArms(const string& info) override
	{
		mRobotArms = info;
	}

	void SetRobotLegs(const string& info) override
	{
		mRobotLegs = info;
	}

	string GetRobotHead() const { return mRobotHead; }
	string GetRobotTorso() const { return mRobotTorso; }
	string GetRobotArms() const { return mRobotArms; }
	string GetRobotLegs() const { return mRobotLegs; }

	string ToString()
	{
		string retVal;
		retVal += "Head: " + mRobotHead + "\n";
		retVal += "Toso: " + mRobotTorso + "\n";
		retVal += "Arms: " + mRobotArms + "\n";
		retVal += "Legs: " + mRobotLegs + "\n";
		return retVal;
	}

private:
	string mRobotHead;
	string mRobotTorso;
	string mRobotArms;
	string mRobotLegs;
};

class IRobotBuilder
{
public:
	virtual void BuildRobotHead() = 0;
	virtual void BuildRobotTorso() = 0;
	virtual void BuildRobotArms() = 0;
	virtual void BuildRobotLegs() = 0;
	virtual Robot& GetRobot() = 0;
};

// Concrete builder class that'll assemble all the parts for our robot
class OldRobotBuilder : public IRobotBuilder
{
public:

	OldRobotBuilder()
	{
		mRobot = new Robot();
	}

	~OldRobotBuilder()
	{
		delete mRobot;
	}
	
	void BuildRobotHead()
	{
		mRobot->SetRobotHead("Tin head");
	}

	void BuildRobotTorso()
	{
		mRobot->SetRobotTorso("Tin torso");
	}

	void BuildRobotArms()
	{
		mRobot->SetRobotArms("Blowtorch arms");
	}

	void BuildRobotLegs()
	{
		mRobot->SetRobotLegs("Roller Skates");
	}

	Robot& GetRobot()
	{
		return *mRobot;
	}

private:
	Robot* mRobot;
};

class RobotEngineer
{
public:
	RobotEngineer(IRobotBuilder& robotBuilder) :
		mRobotBuilder(robotBuilder)
	{}

	Robot& GetRobot()
	{
		return mRobotBuilder.GetRobot();
	}

	void MakeRobot()
	{
		mRobotBuilder.BuildRobotHead();
		mRobotBuilder.BuildRobotTorso();
		mRobotBuilder.BuildRobotArms();
		mRobotBuilder.BuildRobotLegs();
	}

private:
	IRobotBuilder& mRobotBuilder;
};

void main()
{
	IRobotBuilder* oldStyleRobot = new OldRobotBuilder();
	RobotEngineer* robotEngineer = new RobotEngineer(*oldStyleRobot);

	robotEngineer->MakeRobot();
	Robot firstRobot = robotEngineer->GetRobot();
	cout << firstRobot.ToString().c_str() << endl;

	delete oldStyleRobot;
	delete robotEngineer;

	cin.get();
}