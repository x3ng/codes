#include <vector>
#include <string>

using namespace std;

class Robot {
private:
    static constexpr int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    static constexpr const char* ds[4] = {"East", "North", "West", "South"};

    int x;
    int y;
    int d;

    int w;
    int h;
    int r;

    bool m = false;

public:
    Robot(int width, int height) : x(0), y(0), d(3), w(width), h(height) {
	r = 2 * (w + h) - 4;
    }

    void step(int num) {
	if (num > 0) {
	    m = true;
	}
	num %= r;
        while (num--) {
	    x += dirs[d][0];
	    y += dirs[d][1];
	    if (x<0 || x>=w || y<0 || y>=h) {
		x -= dirs[d][0];
		y -= dirs[d][1];
		d = (d + 1) % 4;
		x += dirs[d][0];
		y += dirs[d][1];
	    }
	}
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return m ? ds[d] : ds[0];
    }
};
