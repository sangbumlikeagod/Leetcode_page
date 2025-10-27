class Solution {
    public int numberOfBeams(String[] bank) {
        int lastRow = 0;
        int answer = 0;
        for (String str : bank)
            {
                int row = 0;
                for (char c : str.toCharArray())
                    {
                        if (c == '1')
                        {
                            row++;
                        }
                    }
                answer += lastRow * row;
                if (row != 0)
                {
                    lastRow = row;
                }
            }
        return answer;
    }
}