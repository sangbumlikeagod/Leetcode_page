class Solution {
    public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        int answer = 0;
        int[] days = new int[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int[] prefixDays = new int[14];
        for (int i = 0; i < 12; i++)
        {
            prefixDays[i + 2] = prefixDays[i + 1] + days[i];
        }
        // System.out.println(Arrays.toString(prefixDays));
        int AS = prefixDays[Integer.valueOf(arriveAlice.substring(0, 2))] + Integer.valueOf(arriveAlice.substring(3, 5));
        int AL = prefixDays[Integer.valueOf(leaveAlice.substring(0, 2))] + Integer.valueOf(leaveAlice.substring(3, 5)) + 1;
        int BS = prefixDays[Integer.valueOf(arriveBob.substring(0, 2))] + Integer.valueOf(arriveBob.substring(3, 5));
        int BL = prefixDays[Integer.valueOf(leaveBob.substring(0, 2))] + Integer.valueOf(leaveBob.substring(3, 5)) + 1;

        // System.out.println(AS + " " + AL);
        // System.out.println(BS + " " + BL);
        if (AS <= BS)
        {
            if (AL <= BS)
            {
                return 0;
            }
            if (AL <= BL)
            {
                return AL - BS;
            }
            if (BL < AL)
            {
                return BL - BS;
            }
        }
        else
        {
            if (BL <= AS)
            {
                return 0;
            }
            if (BL <= AL)
            {
                return BL - AS;
            }
            if (AL < BL)
            {
                return AL - AS;
            }
        }
        return -1;
    }
}