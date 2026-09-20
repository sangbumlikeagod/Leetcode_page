class Solution {
    private int c(int c1, int c2, int x, int y)
    {
        return (c1 - x) * (c1 - x) + (c2 - y) * (c2 - y);
    }
    public boolean checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        
        if (
            (x1 <= xCenter && xCenter <= x2) &&
            (y1 <= yCenter && yCenter <= y2)
        )
        {
            return true;
        }
        for (int x_1 = x1, x_2 = x2, y_1 = y1; y_1 <= y2; y_1++)
        {
            if (c(xCenter, yCenter, x_1, y_1) <= radius * radius)
            {
                return true;
            }
            if (c(xCenter, yCenter, x_2, y_1) <= radius * radius)
            {
                return true;
            }
        }
        for (int x_1 = x1, y_1 = y1, y_2 = y2; x_1 <= x2; x_1++)
        {
            if (c(xCenter, yCenter, x_1, y_1) <= radius * radius)
            {
                return true;
            }
            if (c(xCenter, yCenter, x_1, y_2) <= radius * radius)
            {
                return true;
            }
        }
        return false;
    }
}