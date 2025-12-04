class Solution {
    public int countCollisions(String directions) {
        int answer = 0;
        int n = directions.length();
        for (char c : directions.toCharArray())
        {
            if (c != 'S')
            {
                answer++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (directions.charAt(i) != 'L')
            {
                break;
            }
            answer--;
        } 
        for (int i = n - 1; i >= 0; i--)
        {
            if (directions.charAt(i) != 'R')
            {
                break;
            }
            answer--;
        } 
        return answer;
    }
}