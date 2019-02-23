class Game2D{
private:
	GLFWwindow *win=NULL;	
	// bool failure;
	bool dev;

	typedef struct wp {
		int width;
		int height;
		string title;
		GLFWmonitor *monitor;
		GLFWwindow *share;
	}wp;
	
	wp win_params;
public:
	Game2D(bool);
	Game2D(string,bool);
	void run(function<void ()> ifunc,function<void ()> func);
	// void end(); // but not used
	~Game2D();
};
