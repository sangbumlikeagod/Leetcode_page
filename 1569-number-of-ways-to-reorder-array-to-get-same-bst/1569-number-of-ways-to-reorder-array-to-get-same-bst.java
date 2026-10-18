class Solution {
    private long MODULO = (long) 1e9 + 7;
    class BST {
        public Integer value;
        public Integer count;
        public BST left;
        public BST right;
        private BST(int num)
        {
            value = num;
            count = 1;
        }
        public void put(int num)
        {
            count++;
            if (num > value)
            {
                if (left == null)
                {
                    left = new BST(num);
                }
                else
                {
                    left.put(num);
                }
            }
            else if (num < value)
            {
                if (right == null)
                {
                    right = new BST(num);
                }
                else
                {
                    right.put(num);
                }
            }
        }
        public Integer biggerThan(int num)
        {
            if (value == num)
            {
                if (right != null)
                {
                    return right.count;
                }
                else
                {
                    return 0;
                }
            }
            else if (value > num)
            {
                return left.biggerThan(num);
            }

            {
                return right.biggerThan(num);
            }
        }
        public Integer smallerThan(int num)
        {
            if (value == num)
            {
                if (left != null)
                {
                    return left.count;
                }
                else
                {
                    return 0;
                }
            }
            else if (value > num)
            {
                return left.smallerThan(num);
            }

            {
                return right.smallerThan(num);
            }
        }
    }
    private long modInteger(long arg, long mod) {
            if (mod == 0) return 1;
            if (mod == 1) return arg;
            long modd = modInteger(arg, mod / 2);
            modd = (modd * modd) % MODULO;
            if (mod % 2 == 1)
            {
                modd *= arg;
                modd %= MODULO;
            }
            return modd;
    }
    public int numOfWays(int[] nums) {
        BST bst = new BST(nums[0]);
        int n = nums.length;
        long[] tables = new long[n + 1];
        long[] moduloTables = new long[n + 1];
        tables[0] = 1;
        for (int i = 1; i < n; i++)
        {
            bst.put(nums[i]);
            tables[i] = tables[i - 1] * i % MODULO;
        }
        // 이 수의 모듈로 역원들을 다 곱해버리면 뭐가 나올텐데
        tables[n] = tables[n - 1]* n % MODULO;
        for (int i = 1; i <= n; i ++)
        {
            moduloTables[i] = modInteger(tables[i], MODULO - 2);
        }


        // System.out.println(Arrays.toString(tables));
        // System.out.println(Arrays.toString(moduloTables));
        long answer = 1;

        Queue<BST> q = new LinkedList<>();
        q.add(bst);
        while (q.isEmpty() == false)
        {
            BST head =q.poll();
            if (head.left != null && head.right != null)
            {
                // System.out.println(head.value + " " + head.count + " " + head.left.count);
                // System.out.println(tables[head.count - 1]);
                // System.out.println(moduloTables[head.left.count]);
                // 곱하고 
                answer *= tables[head.count - 1];
                answer %= MODULO;
                // 모듈로 역수로 나누는 효과 낸다 
                answer *= moduloTables[head.left.count];
                answer %= MODULO;
                answer *= moduloTables[head.right.count];
                answer %= MODULO;
            }
            if (head.left != null)
            {
                q.add(head.left);
            }
            if (head.right != null)
            {
                q.add(head.right);
            }
        }
        return (int) answer - 1;
    }
}