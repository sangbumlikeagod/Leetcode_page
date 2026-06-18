class Solution {
    private double getRemain(int minute)
    {
        return (double) 0.5 * minute;
    }
    public double angleClock(int hour, int minutes) {
        double m = minutes * 6;
        double n = hour * 30 + getRemain(minutes);
        double mn = Math.abs(m - n);
        return Math.min(mn, 360 - mn);
    }
}