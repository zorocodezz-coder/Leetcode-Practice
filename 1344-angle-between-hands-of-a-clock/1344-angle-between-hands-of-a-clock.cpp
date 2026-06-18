class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = 30*hour+0.5*minutes;
        double minu = 6*minutes;
        double thetha = abs(hr-minu);
        return min(thetha,360-thetha);
    }
};