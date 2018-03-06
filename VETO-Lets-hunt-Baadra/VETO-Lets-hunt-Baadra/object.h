class mapSlot 
{
public:
	int x;
	int y;
	double modifier;

	mapSlot(int f_x = 0, int f_y = 0, double f_modifier = 1) {
		this->x = f_x;
		this->y = f_y;
		this->modifier = f_modifier;
	}
private:
};

class computerEnemy 
{
public:
	double x;
	double y;
	double yv = 0;
	int width = 30;
	int height = 43;
	double modifier;
	double downborder;
	double destination;
	bool ishidden = true;

	void show();
	void hide();

	computerEnemy(int f_x = 0, int f_y = 0, double f_modifier = 0) {
		this->x = f_x;
		this->y = f_y;
		this->modifier = f_modifier;
		this->downborder = this->y;
		this->destination = this->y - this->height;
	}
private:
};