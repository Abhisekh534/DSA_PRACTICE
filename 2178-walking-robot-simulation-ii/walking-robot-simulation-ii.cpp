class Robot {
public:
    int stepp = 0;
    int w, h, x;

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 2*((w-1) + (h-1));
    }
    
    void step(int num) {
        stepp+=num;
    }
    
    vector<int> getPos() {
        int z = stepp%x;
        if(z<w){
            return {z, 0};
        }else if(z<(w+h-1)){
            return {w-1, z-w+1};
        }else if(z<(2*w+h-2)){
            return {2*w+h-z-3, h-1};
        }else{
            return {0, 2*h+2*w -z-4};
        }
    }
    
    string getDir() {
        if(stepp==0) return "East";

        int z = stepp%x;

        if(z==0) return "South";
        if(z<w) return "East";
        if(z<(w+h-1)) return "North";
        if(z<(2*w+h-2)) return "West";
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