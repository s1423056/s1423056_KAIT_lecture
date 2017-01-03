class player{
private:
	int fist;
	int point ;
	int npcnum;
	char name[80];
public:
	player();
	player(int num);
	int take();
	void setpoint(int score);
	int getfist();
};