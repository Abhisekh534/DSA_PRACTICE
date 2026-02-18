class Robot {
public:
    int dir = 0; //0 = east, 1 = north, 2 = west, 3 = south
    int stepp = 0;
    int x = 0, y = 0, w, h, xx;

    Robot(int width, int height) {
        w = width;
        h = height;
        xx = 2*((w-1) + (h-1));
    }
    
    void step(int num) {
        stepp+=num;
    }
    
    vector<int> getPos() {
        int z = stepp%xx;
        if(z<w){
            return {z, 0};
        }else if(z<(w+h-1)){
            return {w-1, z-w+1};
        }else if(z<(2*w+h-2)){
            return {2*w-z+h-3, h-1};
        }else{
            return {0, 2*h+2*w -z-4};
        }
    }
    
    string getDir() {
        if(stepp==0) return "East";
        int z = stepp%xx;

        if(z>0 && z<w) return "East";
        if(z>0 && z<(w+h-1)) return "North";
        else if(z>0 && z<(2*w+h-2)) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */