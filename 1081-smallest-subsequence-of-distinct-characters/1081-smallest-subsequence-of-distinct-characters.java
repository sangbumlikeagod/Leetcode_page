class Solution {
    public String smallestSubsequence(String s) {
        int l = s.length();
        List<Integer> mono = new ArrayList<>();
        int[] last = new int[26];
        for (int i = 0; i < l; i++)
        {
            last[s.charAt(i) - 'a'] = i;
        }
        int[] visited = new int[26];
        Arrays.fill(visited, -1);
        for (int i = 0; i < l; i++)
        {
            char c = s.charAt(i);
            int my = c - 'a';
            if (visited[my] != -1) 
            {
                visited[my] = i;
                continue;
            }

            while (
                !mono.isEmpty() &&
                mono.getLast() > my &&
                visited[mono.getLast()] != last[mono.getLast()]
                )
            {
                int ex = mono.removeLast();
                visited[ex] = -1;
            }
            mono.add(my);
            visited[my] = i;
        }

        StringBuffer answer = new StringBuffer();
        for (int m : mono)
        {
            answer.append((char) ('a' + m));
        }
        return answer.toString();
    }
}