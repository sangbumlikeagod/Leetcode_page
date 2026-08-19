class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        
            
        Arrays.sort(reservedSeats, (a, b) -> a[0] - b[0]);
        int answer = 2 * n;
        
        for (int idx = 0, i = 0; idx < reservedSeats.length;)
        {

            int[] seats = new int[11];
            i = reservedSeats[idx][0];
            while (
                idx < reservedSeats.length && 
                reservedSeats[idx][0] == i
            )
            {
                seats[reservedSeats[idx++][1]]++;
            }
            
            for (int j = 1; j <= 10; j++)
            {
                seats[j] += seats[j - 1];
            }

            int minus = 0;
            if (seats[5] != seats[1])
            {
                minus++;
            }
            if (seats[9] != seats[5])
            {
                minus++;
            }

            if (minus == 2 && seats[7] == seats[3])
            {
                minus--;
            }
            answer -= minus;
            // System.out.println(i + " " + idx + " " + answer); 
        }
        return answer;
    }
}