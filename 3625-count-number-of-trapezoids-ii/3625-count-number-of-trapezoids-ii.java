class SlopeModel {
    private HashMap<Integer, Integer> hMap;
    private HashMap<Integer, HashMap<Integer, Integer>> hhMap;
    private HashMap<Integer, Integer> countMap;
    private Integer totalValue;
    public SlopeModel() {
        this.hMap = new HashMap<>();
        this.countMap = new HashMap<>();
        this.hhMap = new HashMap<>();
        this.totalValue = 0;
    }
    public void addNum() {
        this.totalValue++;
    }
    public int getNum() {
        return this.totalValue;
    }
    public int getDistincLineSize(){
        return this.hMap.size();
    }

    public void addLine(int[] x, int[] y, int ddx, int ddy)
    {
        // 둘이 x가 같은 값일때만 x절편으로 확인
        if (x[0] == y[0])
        {

            Integer lengthSquare = (y[0] - x[0]) * (y[0] - x[0]) + (y[1] - x[1]) * (y[1] - x[1]);
            this.countMap.put(lengthSquare,
                this.countMap.getOrDefault(lengthSquare, 0) + 1
            );

            HashMap<Integer, Integer> mmap = this.hhMap.getOrDefault(x[0], new HashMap<>());

            // 길이별로 갱신 
            mmap.put(lengthSquare, 
                mmap.getOrDefault(lengthSquare, 0) + 1
            );
            
            this.hhMap.put(x[0], 
                mmap
            );

            this.hMap.put(x[0], 
                this.hMap.getOrDefault(x[0], 0) + 1
            );
        }
        else
        {
            // float dx = (float) (y[0] - x[0]);
            // float dy = (float) (y[1] - x[1]);

            Integer lengthSquare = (y[0] - x[0]) * (y[0] - x[0]) + (y[1] - x[1]) * (y[1] - x[1]);
            this.countMap.put(lengthSquare,
                this.countMap.getOrDefault(lengthSquare, 0) + 1
            );


            
            // float slope = dy / dx;
            // x에서 0까지가는데 (어떤 방향이든) 
            // float y_section = ((float) (-x[0]) * slope) + (float) x[1];

            Integer iYSection = -x[0] * ddy + x[1] * ddx;

            HashMap<Integer, Integer> mmap = this.hhMap.getOrDefault(iYSection, new HashMap<>());

            // 길이별로 갱신 
            mmap.put(lengthSquare, 
                mmap.getOrDefault(lengthSquare, 0) + 1
            );
            
            this.hhMap.put(iYSection, 
                mmap
            );
            
            
            this.hMap.put(iYSection, 
                this.hMap.getOrDefault(iYSection, 0) + 1
            );
        }
    }

    

    public int execute()
    {
        int ret = 0;
        
        for(Integer key : this.hMap.keySet())
        {

            int samee = this.hMap.get(key);

            // System.out.println("\t현재 나와 같은애 " + samee);
            ret += (this.getNum() - samee) * samee;
            // System.out.println("\t내가 선택할 수 있는 애 " + (this.getNum() - samee));

            //이중에서 몇개는 겹칠거다 
            
        }
        return ret;
    }

    public int execute2()
    {
        int ret = 0;
        // System.out.println(this.hhMap);
        for(Integer keys : this.hhMap.keySet())
        {
            HashMap<Integer, Integer> keyMap = this.hhMap.get(keys);
            for (Integer squareLength : keyMap.keySet())
                {
                    // System.out.println(squareLength);
                    ret += (this.countMap.get(squareLength) - keyMap.get(squareLength)) * keyMap.get(squareLength);
                }
        }
        return ret / 2;
    }




}
class Solution {

    private int findGCD(int dx, int dy)
    {
        if (dx < 0) {dx *= -1;}
        if (dy < 0) {dy *= -1;}

        while (true)
        {
            if (dx < dy)
            {
                int tmp = dx;
                dx = dy;
                dy = tmp;
            }

            dx %= dy;
            if (dx == 0)
            {

                return dy;
            }
        }
    }
    private int slopeToInt(int dx, int dy) {
        return dx * 4000 + (dy + 2000);
    }
    public int countTrapezoids(int[][] points) {
        // 더빠르게하기위해선 뺄수도 있으나 굳이
        HashMap<Integer, SlopeModel> slopeModels = new HashMap<>();


        Arrays.sort(points, (a, b) -> {
            return a[0] - b[0];
        });

        int n = points.length;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if (dx == 0)
                {
                    dx = 0;
                    dy = 1;
                }
                else if (dy == 0)
                {
                    dx = 1;
                    dy = 0;
                }
                else
                {
                    int gcd = findGCD(dx, dy);
                    dx /= gcd;
                    dy /= gcd;
                }
                // System.out.println(dx + " " + dy);
                // if (dx == 11 && dy == -5)
                // {
                //     // System.out.println(Arrays.toString(points[j]));
                //     // System.out.println(Arrays.toString(points[i]));
                //     // System.out.println();
                // }
                int hashKey = slopeToInt(dx, dy);

                if (!slopeModels.containsKey(hashKey))
                {
                    slopeModels.put(hashKey, new SlopeModel());
                }
                SlopeModel slopeModel = slopeModels.get(hashKey);
                slopeModel.addLine(points[j], points[i], dx, dy);
                slopeModel.addNum();
            }
        }



        // for (int[] point : points)
        // {
        //     System.out.println(point[0] + " " + point[1]);
        // }
        int answer = 0;
        int duplicates = 0;
        for (Integer key : slopeModels.keySet())
        {
            SlopeModel slopeModel = slopeModels.get(key);
            if (slopeModel.getNum() == 1 || slopeModel.getDistincLineSize() == 1)
            {
                continue;
            }
            // System.out.println();
            // System.out.println("slope는 " + key / 4000 + ", " + (key % 4000 - 2000));
            // 여기서 이제 
            // System.out.println("총 데이터는 " + slopeModel.getNum());
            // System.out.println("unique 값 크기는 " + slopeModel.getDistincLineSize());
            answer += slopeModel.execute();
            int duplicate = slopeModel.execute2();
            duplicates += duplicate;

            // System.out.println("\t겹친 값 크기는 " + duplicate);
        }
        return (answer - duplicates) / 2;
    }
}