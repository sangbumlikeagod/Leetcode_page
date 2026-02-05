class NetDecreasing {
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
        rdx = i;
        sum =  (long) nums[i];
    }
}

class NetIncreasing {
    private Long totalSum;
    private Long totalMaxSum;
    private List<Long> totalMinSumSeries;

    public NetIncreasing(int i, int i_1, int[] nums)
    {
        totalSum = (long) nums[i] + nums[i_1];
        totalMaxSum = totalSum;  
        totalMinSumSeries = new ArrayList<>();

        totalMinSumSeries.add((long) 0);
        totalMinSumSeries.add(Math.min(totalMinSumSeries.getLast(), nums[i_1]));
        totalMinSumSeries.add(Math.min(totalMinSumSeries.getLast(), totalSum));
    }
    public void addElements(int x)
    {
        this.totalSum += x;
        this.totalMaxSum = Math.max(this.totalMaxSum, totalSum);
        this.totalMinSumSeries.add(Math.min(totalSum, this.totalMinSumSeries.getLast()));
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
    private Long getSectionSum(NetDecreasing prevNetDecreasing, NetIncreasing prevNetIncreasing, NetIncreasing currentNetIncreasing)
    {
        Long tmp = prevNetIncreasing.getRightMaximum();
        tmp += currentNetIncreasing.getLeftMaximum();
        tmp += prevNetDecreasing.getMax();
        return tmp;
    }

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
                    if (
                        prevNetIncreasing != null &&
                        prevNetDecreasing != null &&
                        currentNetIncreasing != null
                       )
                    {
                        answer = Math.max(answer, Math.max(answer, getSectionSum(prevNetDecreasing, prevNetIncreasing, currentNetIncreasing)));
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
                        answer = Math.max(answer, Math.max(answer, getSectionSum(prevNetDecreasing, prevNetIncreasing, currentNetIncreasing)));
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
            
            answer = Math.max(answer, getSectionSum(prevNetDecreasing, prevNetIncreasing, currentNetIncreasing));
        }



        return answer;

    }
}