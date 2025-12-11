class CPair {
    public Integer first;
    public Integer second;

    CPair(Integer f, Integer s) {
        this.first = f;
        this.second = s;
    }
};
class Solution {

    HashMap<Integer, CPair> hXap = new HashMap<>();
    HashMap<Integer, CPair> hYap = new HashMap<>();
    public int countCoveredBuildings(int n, int[][] buildings) {
        int answer = 0;
        for (int[] building : buildings)
        {
            CPair newPair = new CPair(1000000000, -1000000000);
            CPair pair1 = hXap.getOrDefault(building[0], newPair);

            pair1.first = Math.min(pair1.first, building[1]);
            pair1.second = Math.max(pair1.second, building[1]);

            hXap.put(building[0], pair1);

            CPair newPair2 = new CPair(1000000000, -1000000000);
            CPair pair2 = hYap.getOrDefault(building[1], newPair2);
            pair2.first = Math.min(pair2.first, building[0]);
            pair2.second = Math.max(pair2.second, building[0]);

            hYap.put(building[1], pair2);
        }

        for (int[] building : buildings)
        {
            CPair pair = hXap.get(building[0]);
            CPair pair2 = hYap.get(building[1]);

            if (
                building[1] != pair.first &&
                building[1] != pair.second && 
                building[0] != pair2.second && 
                building[0] != pair2.first
            )
            {
                answer++;
            }
        }
        return answer;
    }
}