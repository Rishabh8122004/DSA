class Robot {
public:
    int w, h;
    int x = 0, y = 0; // current position
    char D = 'E';     // current direction

    Robot(int width, int height) {
        w = width;
        h = height;
    }

    void next_position(int& temp_x, int& temp_y, char D) {
        if (D == 'E')
            temp_x++;
        else if (D == 'N')
            temp_y++;
        else if (D == 'W')
            temp_x--;
        else if (D == 'S')
            temp_y--;
        return;
    }

    void step(int num) {
        bool f = false;
        if (num > 0)
            f = true;
        num %= (2 * ((w - 1) + (h - 1))); // parametre
        if (num == 0 && f) {
            if (x == 0 && y == 0) D = 'S';
            else if (x == w - 1 && y == 0) D = 'E';
            else if (x == w - 1 && y == h - 1) D = 'N';
            else if(x == 0 && y == h - 1) D = 'W';
        }
        int temp_x, temp_y;
        while (num > 0) {
            if (x == 0 && y == 0) D = 'E';
            else if (x == w - 1 && y == 0) D = 'N';
            else if (x == w - 1 && y == h - 1) D = 'W';
            else if(x == 0 && y == h - 1) D = 'S';

            if (D == 'E') {
                temp_x = x;
                x += min(w - 1 - x, num);
                num -= abs(x - temp_x);
            } else if (D == 'N') {
                temp_y = y;
                y += min(h - 1 - y, num);
                num -= abs(y - temp_y);
            } else if (D == 'W') {
                temp_x = x;
                x -= min(x, num);
                num -= abs(temp_x - x);
            } else if (D == 'S') {
                temp_y = y;
                y -= min(y, num);
                num -= abs(temp_y - y);
            }
        }
    }

    vector<int> getPos() { return {x, y}; }

    string getDir() {
        if (D == 'E')
            return "East";
        else if (D == 'N')
            return "North";
        else if (D == 'W')
            return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */