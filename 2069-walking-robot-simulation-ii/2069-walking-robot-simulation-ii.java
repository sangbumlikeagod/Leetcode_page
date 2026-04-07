class Robot {
    private int direction;
    private int x;
    private int y;
    private int w;
    private int h;
    private boolean firstStepTaken = false;
    

    private int[] dx = {1, 0, -1, 0};
    private int[] dy = {0, 1, 0, -1};

    public Robot(int width, int height) {
        direction = 3;
        w = width;
        h = height;
        x = 0;
        y = 0;
    }
    
    public void step(int num) {
        firstStepTaken = true;
        num = skip_step(num);
        move_step(num);
    }

    private int skip_step(int num)
    {
        // w + h - 1 이내로만 남김
        int quotient = num / (w + h - 2);
        if (quotient % 2 == 1)
        {
            x = w - 1 - x;
            y = h - 1 - y;

            {
                direction = (direction + 2) % 4;
            }
        }
        return num % (w + h - 2);
    }
    private void move_step(int num)
    {
        while (num > 0)
        {
            if (direction == 0 && x == w - 1)
            {
                direction = (direction + 1) % 4;
            }
            else if (direction == 1 && y == h - 1)
            {
                direction = (direction + 1) % 4;
            }
            else if (direction == 2 && x == 0)
            {
                direction = (direction + 1) % 4;
            }
            else if (direction == 3 && y == 0)
            {
                direction = (direction + 1) % 4;
            }
            x += dx[direction];
            y += dy[direction];

            num--;
        }
    }
    
    public int[] getPos() {
        return new int[] {x, y};
    }

    
    public String getDir() {
        if (!firstStepTaken || direction == 0)
        {
            return "East";
        }
        else if (direction == 1)
        {
            return "North";
        }
        else if (direction == 2)
        {
            return "West";
        }
        else
        {
            return "South";
        }
    }
}

/**
 * Your Robot object will be instantiated and called as such:
 * Robot obj = new Robot(width, height);
 * obj.step(num);
 * int[] param_2 = obj.getPos();
 * String param_3 = obj.getDir();
 */