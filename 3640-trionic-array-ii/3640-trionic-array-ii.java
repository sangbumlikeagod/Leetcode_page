class NetDecreasing {
    private Integer ldx;
    private Integer rdx;

    private Long sum;
    
    public void subLast(int[] nums)
    {
        sum -= nums[rdx];
    }
    public void addElements(int x, int xdx)
    {
        sum += x;
        rdx = xdx;
    }

    public Long getMax() {
        return sum;
    }
    public NetDecreasing(int i, int[] nums) {
        ldx = i;
        rdx = i;
        sum =  (long) nums[i];
    }
}

class NetIncreasing {
    private Integer ldx;
    private Integer rdx;
    private Long totalSum;
    private Long totalMinSum;
    private Long totalMaxSum;
    private List<Long> totalMinSumSeries;

    public NetIncreasing(int i, int i_1, int[] nums)
    {
        ldx = i;
        totalSum = (long) nums[i] + nums[i_1];

        totalMaxSum = totalSum;  
        totalMinSum = (long) Math.min(Math.min(0, nums[i]), nums[i] + nums[i_1]);
        totalMinSumSeries = new ArrayList<>();

        totalMinSumSeries.add((long) 0);
        totalMinSumSeries.add(Math.min(totalMinSumSeries.getLast(), nums[i_1]));
        totalMinSumSeries.add(Math.min(totalMinSumSeries.getLast(), totalSum));
        // System.out.println("created" + totalSum + " Mins" + totalMinSumSeries);
    }
    public void addElements(int x)
    {
        this.totalSum += x;
        this.totalMaxSum = Math.max(this.totalMaxSum, totalSum);
        this.totalMinSumSeries.add(Math.min(totalSum, this.totalMinSumSeries.getLast()));
        // System.out.println("updated" + this.totalSum + " Mins" + this.totalMinSumSeries);
    }



    public Long getRightMaximum()
    {
        return this.totalSum - this.totalMinSumSeries.get(this.totalMinSumSeries.size()
         - 3);
    }
    public Long getLeftMaximum()
    {
        return totalMaxSum;
    }


}


class Solution {
    public long maxSumTrionic(int[] nums) {

        NetDecreasing currentNetDecreasing = null;
        NetDecreasing prevNetDecreasing = null;

        NetIncreasing prevNetIncreasing = null;
        NetIncreasing currentNetIncreasing = null;
        int n = nums.length;
        long answer = (long) -1e15;


 
        for (int i = 1; i < n; i++)
        {
            // 이전인덱스와의 차이부터 구함
            if (nums[i - 1] < nums[i])
            {
                // netIncrease
                if (currentNetIncreasing != null)
                {
                    currentNetIncreasing.addElements(nums[i]);

                }
                else
                {
                    // System.out.println("netIncrease " + i);
                    if (currentNetDecreasing != null)
                    {
                        currentNetDecreasing.subLast(nums);
                    }
                    prevNetDecreasing = currentNetDecreasing;
                    currentNetDecreasing = null;
                    currentNetIncreasing = new NetIncreasing(i, i - 1, nums);
                }
            }
            else if (nums[i - 1] > nums[i])
            {
                // netDecrease
                if (currentNetDecreasing != null)
                {
                    currentNetDecreasing.addElements(nums[i], i);
                }
                else
                {
                    // System.out.println("netDecrease " + i);
                    if (
                        prevNetIncreasing != null &&
                        prevNetDecreasing != null &&
                        currentNetIncreasing != null
                       )
                    {
                        // System.out.println("found " + i);
                        Long tmp = prevNetIncreasing.getRightMaximum();
                        // System.out.println("prev right Max " + tmp);

                        tmp += currentNetIncreasing.getLeftMaximum();
                        // System.out.println("current left Max " + tmp);
                        tmp += prevNetDecreasing.getMax();
                        // System.out.println("prev Decrease static Max " + tmp);
                        answer = Math.max(answer, tmp);
                    }
                    prevNetIncreasing = currentNetIncreasing;
                    currentNetIncreasing = null;
                    currentNetDecreasing = new NetDecreasing(i, nums);
                }
            }
            else
            {
                // 초기화
                 if (
                        prevNetIncreasing != null &&
                        prevNetDecreasing != null &&
                        currentNetIncreasing != null
                       )
                    {
                        // System.out.println("found " + i);
                        Long tmp = prevNetIncreasing.getRightMaximum();
                        // System.out.println("prev right Max " + tmp);

                        tmp += currentNetIncreasing.getLeftMaximum();
                        // System.out.println("current left Max " + tmp);
                        tmp += prevNetDecreasing.getMax();
                        // System.out.println("prev Decrease static Max " + tmp);
                        answer = Math.max(answer, tmp);
                    }
                currentNetDecreasing = null;
                currentNetIncreasing = null;
                prevNetIncreasing = null;
                prevNetDecreasing = null;
            }
        }

        if (
            prevNetIncreasing != null &&
            prevNetDecreasing != null &&
            currentNetIncreasing != null
            )
        {
            Long tmp = prevNetIncreasing.getRightMaximum();
            // System.out.println("prev right Max " + tmp);
            tmp += currentNetIncreasing.getLeftMaximum();
            // System.out.println("current left Max " + tmp);
            tmp += prevNetDecreasing.getMax();
            // System.out.println("prev Decrease static Max " + tmp);
            answer = Math.max(answer, tmp);
        }



        return answer;

    }
}