
class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        int l = positions.length;
        int[][] indexPositions = new int[l][2];
        for (int i = 0; i < l; i++)
        {
            indexPositions[i][0] = i;
            indexPositions[i][1] = positions[i];
            // indexPositions[i] = i;
        }
        Arrays.sort(indexPositions, (int[] a, int[] b) -> {
            return a[1] - b[1];
        });


        
        List<List<Integer>> answer = new ArrayList<>();
        List<List<Integer>> rights = new ArrayList<>();
        for (int i = 0; i < l; i++)
        {
            int nextIndex = indexPositions[i][0];
            int powerLeft = healths[nextIndex];
            if (directions.charAt(nextIndex) == 'L')
            {
                while (powerLeft > 0 && rights.isEmpty() == false)
                {
                    int rightPowers = rights.getLast().getFirst();
                    int rightIndex = rights.getLast().getLast();
                    if (powerLeft > rightPowers)
                    {
                        rights.removeLast();
                        powerLeft--;
                    }
                    else if (powerLeft == rightPowers)
                    {
                        rights.removeLast();
                        powerLeft = 0;
                        break;
                    }
                    else
                    {
                        // System.out.println("호우" + i);
                        rights.set(rights.size() - 1, List.of(rightPowers - 1, rightIndex));
                        powerLeft = 0;
                        break;
                    }
                }
                if (powerLeft != 0)
                {
                    answer.add(List.of(powerLeft, nextIndex));
                }
            }
            else
            {
                rights.add(List.of(powerLeft, nextIndex));
            }

        }
        answer.addAll(rights);
        Collections.sort(answer, (List<Integer> a, List<Integer> b) -> {
            return a.getLast() - b.getLast();
        });
        List<Integer> answer1D = new ArrayList<>();
        for (int i = 0; i < answer.size(); i++)
        {
            answer1D.add(answer.get(i).get(0));
        }
        return answer1D;
    }
}