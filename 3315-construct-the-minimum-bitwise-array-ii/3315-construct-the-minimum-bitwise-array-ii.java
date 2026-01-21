class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();
        int[] answer = new int[n]; 
        for (int i = 0; i < n; i++)
            {
                int num = nums.get(i);
                if ((num & 1) == 0)
                {
                    answer[i] = -1;
                }
                else
                {
                    int tmp = 0;
                    int x = 1;
                    boolean consequtiveOneEnd = false;
                    while (x < num)
                    {
                        if (consequtiveOneEnd)
                        {
                            tmp |= (num & x);
                        }
                        else
                        {
                            if (((x << 1) & num) != (x << 1))
                            {
                                 consequtiveOneEnd = true;   
                            }
                            else
                            {
                                tmp |= x;
                            }
                        }
                        x <<= 1;
                    }

                    answer[i] = tmp;
                }
            }
        return answer;
    }
}